// BattleCrashFix.cpp
// 英雄无敌3 HD Mod 插件：战斗崩溃修复
// 修复1：[障碍] RemoveObstacle 双重释放崩溃 (0x466710)
// 修复2：[光环] 独角兽抗魔光环与被丧心病狂/蛊惑单位交互时的崩溃 (0x43E790)
// 修复3：[阻止清理] FindAndRemove 损坏 vector 保护 (0x43E720)
// 配置文件 BattleCrashFix.ini 放在 DLL 同目录下，可独立开关每个修复。

// 全部使用 HiHook（SPLICE_ + EXTENDED_/THISCALL_），不使用 LoHook。

#pragma execution_character_set("utf-8")

#include "homm3.h"

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <windows.h>

Patcher*         _P  = nullptr;
PatcherInstance* _PI = nullptr;

static wchar_t g_wlog_path[MAX_PATH * 2];
static wchar_t g_wini_path[MAX_PATH * 2];

static const int MAX_LOG_FILES_TO_KEEP = 30;
static const int MAX_LOG_FILES_TO_SCAN = 1024;

struct LogFileEntryW {
    wchar_t path[MAX_PATH * 2];
    FILETIME last_write;
};

static int __cdecl CompareLogFileEntryW(const void* a, const void* b)
{
    const LogFileEntryW* la = (const LogFileEntryW*)a;
    const LogFileEntryW* lb = (const LogFileEntryW*)b;
    int cmp = CompareFileTime(&la->last_write, &lb->last_write);
    if (cmp != 0) return cmp;
    return _wcsicmp(la->path, lb->path);
}

// ==================== 配置项 ====================

static bool g_disable_obstacle = false;
static bool g_disable_aura     = false;

// ==================== 地址常量 ====================

static const DWORD ADDR_REMOVE_OBSTACLE      = 0x466710;
static const DWORD ADDR_UPDATE_AURA_LINKS    = 0x43E790;
static const DWORD ADDR_VECTOR_FIND_AND_REMOVE = 0x43E720;

static const int SPELL_BERSERK   = 59;  // 丧心病狂
static const int SPELL_HYPNOTIZE = 60;  // 蛊惑

static const DWORD OFS_TYPE                   = 0x34;
static const DWORD OFS_SIDE                   = 0xF4;
static const DWORD OFS_ACTIVE_SPELLS_DURATION = 0x198;

// ==================== 路径与日志 ====================

static void WriteLog(const char* tag, const char* fmt, ...)
{
    if (!g_wlog_path[0]) return;

    FILE* f = nullptr;
    if (_wfopen_s(&f, g_wlog_path, L"a") != 0 || !f) return;

    long pos = ftell(f);
    if (pos == 0) {
        fwrite("\xEF\xBB\xBF", 1, 3, f);
    }

    SYSTEMTIME st;
    GetLocalTime(&st);
    fprintf(f, "[%04u-%02u-%02u %02u:%02u:%02u.%03u] [%s] ",
        st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds, tag);

    va_list ap;
    va_start(ap, fmt);
    vfprintf(f, fmt, ap);
    va_end(ap);

    fprintf(f, "\n");
    fclose(f);
}

static void CleanupOldLogFilesW(const wchar_t* log_dir, const wchar_t* log_base, const wchar_t* current_log_path)
{
    if (!log_dir || !log_dir[0] || !log_base || !log_base[0]) return;

    wchar_t pattern[MAX_PATH * 2];
    _snwprintf_s(pattern, _countof(pattern), _TRUNCATE, L"%s\\%s_*.log", log_dir, log_base);

    LogFileEntryW* entries = (LogFileEntryW*)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, MAX_LOG_FILES_TO_SCAN * sizeof(LogFileEntryW));
    if (!entries) return;
    int count = 0;
    bool current_found = false;

    WIN32_FIND_DATAW fd;
    HANDLE h = FindFirstFileW(pattern, &fd);
    if (h == INVALID_HANDLE_VALUE) { HeapFree(GetProcessHeap(), 0, entries); return; }
    do {
        if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) continue;
        if (count >= MAX_LOG_FILES_TO_SCAN) break;

        _snwprintf_s(entries[count].path, _countof(entries[count].path), _TRUNCATE, L"%s\\%s", log_dir, fd.cFileName);
        entries[count].last_write = fd.ftLastWriteTime;
        if (current_log_path && _wcsicmp(entries[count].path, current_log_path) == 0) current_found = true;
        ++count;
    } while (FindNextFileW(h, &fd));
    FindClose(h);

    int keep_existing = current_found ? MAX_LOG_FILES_TO_KEEP : (MAX_LOG_FILES_TO_KEEP - 1);
    if (keep_existing < 0) keep_existing = 0;
    if (count <= keep_existing) { HeapFree(GetProcessHeap(), 0, entries); return; }

    qsort(entries, count, sizeof(entries[0]), CompareLogFileEntryW);
    int delete_count = count - keep_existing;
    for (int i = 0; i < delete_count; ++i) DeleteFileW(entries[i].path);
    HeapFree(GetProcessHeap(), 0, entries);
}

static void SetupPaths(HMODULE hModule)
{
    wchar_t wpath[MAX_PATH] = {0};
    GetModuleFileNameW(hModule, wpath, MAX_PATH);

    wchar_t wdir[MAX_PATH] = {0};
    wchar_t wbase[MAX_PATH] = {0};

    const wchar_t* slash = wcsrchr(wpath, L'\\');
    if (!slash) slash = wcsrchr(wpath, L'/');
    const wchar_t* name = slash ? slash + 1 : wpath;

    if (slash) {
        int len = (int)(slash - wpath);
        if (len >= MAX_PATH) len = MAX_PATH - 1;
        memcpy(wdir, wpath, len * sizeof(wchar_t));
    }

    wcsncpy_s(wbase, name, _TRUNCATE);
    wchar_t* dot = wcsrchr(wbase, L'.');
    if (dot) *dot = 0;

    _snwprintf_s(g_wini_path, _countof(g_wini_path), _TRUNCATE,
        L"%s\\%s.ini", wdir[0] ? wdir : L".", wbase[0] ? wbase : L"BattleCrashFix");

    SYSTEMTIME st;
    GetLocalTime(&st);
    _snwprintf_s(g_wlog_path, _countof(g_wlog_path), _TRUNCATE,
        L"%s\\%s_%04u%02u%02u_%02u%02u%02u.log",
        wdir[0] ? wdir : L".", wbase[0] ? wbase : L"BattleCrashFix",
        st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);

    CleanupOldLogFilesW(wdir[0] ? wdir : L".", wbase[0] ? wbase : L"BattleCrashFix", g_wlog_path);
}

// ==================== INI 读取 ====================

static void LoadConfig()
{
    g_disable_obstacle = GetPrivateProfileIntW(L"Options", L"DisableObstacle", 0, g_wini_path) != 0;
    g_disable_aura     = GetPrivateProfileIntW(L"Options", L"DisableAura",     0, g_wini_path) != 0;

    WriteLog("初始化", "配置：DisableObstacle=%s DisableAura=%s",
        g_disable_obstacle ? "是" : "否",
        g_disable_aura     ? "是" : "否");
}

// ==================== 工具函数 ====================

static bool IsProbablyReadableDword(DWORD address)
{
    if (address < 0x10000)
        return false;
    __try {
        volatile DWORD value = *(DWORD*)address;
        (void)value;
        return true;
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {
        return false;
    }
}

// ==================== 修复1：[障碍] RemoveObstacle ====================
//
// RemoveObstacle @ 0x466710, thiscall(ecx=CombatMgr*, [esp+4]=obstacleNum), ret 4
//
// 原函数在 0x466813 处：mov ecx,[edi]，读取 obstacle.def。
// 如果 def=NULL（已被移除），后续 mov edx,[ecx] 会崩溃。
//
// HiHook 策略：包裹整个函数，在调用原函数前检查 obstacle 的 def 是否有效。
// 如果无效，清除 duration 并跳过原函数。

static bool IsValidObstacle(DWORD combatMgr, int obstacleNum)
{
    __try {
        // CombatManager+0x13D5C = obstacleInfo 向量起始指针（begin）。
        // CombatManager+0x13D60 = obstacleInfo 向量结束指针（end）。
        DWORD vecBegin = *(DWORD*)(combatMgr + 0x13D5C);
        DWORD vecEnd   = *(DWORD*)(combatMgr + 0x13D60);
        DWORD count = (vecEnd - vecBegin) / 0x18;  // H3Obstacle 结构大小为 0x18

        if (obstacleNum < 0 || (DWORD)obstacleNum >= count)
            return false;

        DWORD obstacle = vecBegin + obstacleNum * 0x18;
        DWORD def = *(DWORD*)(obstacle + 0x00);
        DWORD duration = *(DWORD*)(obstacle + 0x10);

        if (!def || !IsProbablyReadableDword(def)) {
            // 清除 duration，防止清理循环再次调用。
            *(DWORD*)(obstacle + 0x10) = 0;
            WriteLog("障碍", "跳过 obstacle#%u def=0x%08X dur=%u (已移除或无效)",
                obstacleNum, def, duration);
            return false;
        }
        return true;
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {
        return false;
    }
}

static int __stdcall HH_RemoveObstacle(HiHook* h, DWORD combatMgr, int obstacleNum)
{
    if (!IsValidObstacle(combatMgr, obstacleNum)) {
        return 0;  // 原函数返回 void，这里返回任意值
    }

    // 记录移除信息。
    DWORD vecBegin = *(DWORD*)(combatMgr + 0x13D5C);
    DWORD obstacle = vecBegin + obstacleNum * 0x18;
    DWORD def = *(DWORD*)(obstacle + 0x00);
    DWORD duration = *(DWORD*)(obstacle + 0x10);
    WriteLog("障碍", "移除 obstacle#%u addr=0x%08X def=0x%08X dur=%u",
        obstacleNum, obstacle, def, duration);

    CALL_2(void, __thiscall, h->GetDefaultFunc(), combatMgr, obstacleNum);
    return 0;
}

// ==================== 修复2：[光环] UpdateAuraLinks ====================
//
// UpdateAuraLinks @ 0x43E790, thiscall(ecx=target monster*), ret 0
//
// 如果 target 处于丧心病狂(59)或蛊惑(60)状态，跳过整个函数。

static int __stdcall HH_UpdateAuraLinks(HiHook* h, DWORD target)
{
    if (target && IsProbablyReadableDword(target)) {
        __try {
            DWORD berserk_dur   = *(DWORD*)(target + OFS_ACTIVE_SPELLS_DURATION + SPELL_BERSERK   * 4);
            DWORD hypnotize_dur = *(DWORD*)(target + OFS_ACTIVE_SPELLS_DURATION + SPELL_HYPNOTIZE * 4);

            if (berserk_dur > 0 || hypnotize_dur > 0) {
                DWORD type = *(DWORD*)(target + OFS_TYPE);
                DWORD side = *(DWORD*)(target + OFS_SIDE);
                const char* status = berserk_dur > 0 ? "丧心病狂" : "蛊惑";
                DWORD dur = berserk_dur > 0 ? berserk_dur : hypnotize_dur;
                WriteLog("光环", "跳过 target=0x%08X type=%u side=%u %s中(duration=%u)",
                    target, type, side, status, dur);
                return 0;  // 跳过原函数
            }
        }
        __except (EXCEPTION_EXECUTE_HANDLER) {
            WriteLog("光环", "异常 target=0x%08X", target);
        }
    }

    // 正常执行。
    CALL_1(void, __thiscall, h->GetDefaultFunc(), target);
    return 0;
}

// ==================== 修复3：[阻止清理] FindAndRemove 保护 ====================
//
// Vector::FindAndRemove @ 0x43E720, fastcall(ecx=vec*, edx=value), ret 0
//
// 检查 vector 的 begin / end / endCapacity 有效性。

static int __stdcall HH_VectorFindAndRemove(HiHook* h, DWORD vec, DWORD value)
{
    if (!vec || !IsProbablyReadableDword(vec)) {
        WriteLog("阻止清理", "跳过 vec=0 (结构无效)");
        return 0;
    }

    __try {
        DWORD begin  = *(DWORD*)(vec + 0);
        DWORD end    = *(DWORD*)(vec + 4);
        DWORD endCap = *(DWORD*)(vec + 8);

        if (begin == 0 && end == 0) {
            // 空向量，不调用原函数。
            return 0;
        }

        if (begin < 0x10000 || end < 0x10000 || endCap < 0x10000) {
            WriteLog("阻止清理", "跳过 vec=0x%08X begin=0x%08X end=0x%08X 无效", vec, begin, end);
            return 0;
        }

        if (end > endCap) {
            WriteLog("阻止清理", "跳过 vec=0x%08X end>endCap (end=0x%08X cap=0x%08X)", vec, end, endCap);
            return 0;
        }

        DWORD count = (end - begin) >> 2;
        if (count > 40) {
            WriteLog("阻止清理", "跳过 vec=0x%08X count=%u 过大", vec, count);
            return 0;
        }
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {
        WriteLog("阻止清理", "异常 vec=0x%08X", vec);
        return 0;
    }

    // 正常执行。
    CALL_2(void, __fastcall, h->GetDefaultFunc(), vec, value);
    return 0;
}

// ==================== 插件入口 ====================

static void StartPlugin()
{
    if (!g_disable_obstacle) {
        _PI->WriteHiHook(ADDR_REMOVE_OBSTACLE, SPLICE_, EXTENDED_, THISCALL_, HH_RemoveObstacle);
        WriteLog("初始化", "  [障碍] RemoveObstacle @ 0x%08X 已注册（HiHook SPLICE_ THISCALL_）", ADDR_REMOVE_OBSTACLE);
    } else {
        WriteLog("初始化", "  [障碍] 已通过 ini 禁用");
    }

    if (!g_disable_aura) {
        _PI->WriteHiHook(ADDR_UPDATE_AURA_LINKS, SPLICE_, EXTENDED_, THISCALL_, HH_UpdateAuraLinks);
        WriteLog("初始化", "  [光环] UpdateAuraLinks @ 0x%08X 已注册（HiHook SPLICE_ THISCALL_）", ADDR_UPDATE_AURA_LINKS);

        _PI->WriteHiHook(ADDR_VECTOR_FIND_AND_REMOVE, SPLICE_, EXTENDED_, FASTCALL_, HH_VectorFindAndRemove);
        WriteLog("初始化", "  [阻止清理] FindAndRemove @ 0x%08X 已注册（HiHook SPLICE_ FASTCALL_）", ADDR_VECTOR_FIND_AND_REMOVE);
    } else {
        WriteLog("初始化", "  [光环] 已通过 ini 禁用");
    }
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID reserved)
{
    static bool initialized = false;
    if (reason == DLL_PROCESS_ATTACH && !initialized) {
        initialized = true;

        SetupPaths(hModule);
        WriteLog("初始化", "BattleCrashFix 正在加载。");

        _P = GetPatcher();
        if (!_P) {
            WriteLog("初始化", "GetPatcher 失败。");
            return TRUE;
        }

        _PI = _P->CreateInstance("HD.Plugin.BattleCrashFix");
        if (!_PI) {
            WriteLog("初始化", "CreateInstance 失败。");
            return TRUE;
        }

        LoadConfig();
        StartPlugin();
    }
    return TRUE;
}

