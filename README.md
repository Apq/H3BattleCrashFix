# BattleCrashFix — 战斗崩溃修复

修复英雄无敌3 HD Mod 版本中两类战斗崩溃问题。

## 修复内容

### [Obstacle] 驱除障碍崩溃

施放「驱除障碍」移除力场等魔法障碍物后偶尔崩溃。

**原因**：`RemoveObstacle`(0x466710) 清除 `def` 指针但不清除 `duration`，回合清理循环再次调用导致空指针。

**修复**：HiHook SPLICE_ THISCALL_ 包裹 `RemoveObstacle @ 0x466710`，调用前检查 obstacle def 有效性，无效则清除 duration 并跳过。

### [Aura] 独角兽抗魔光环崩溃

独角兽挨着被「丧心病狂」(Berserk) 或「蛊惑」(Hypnotize) 的己方单位时必崩。

**原因**：`UpdateAuraLinks`(0x43E790) 建立独角兽与相邻友军的双向关联；被丧心病狂的单位在 spellsData vectors 中留下悬垂指针，`Vector::FindAndRemove`(0x43E720) 操作损坏 vector 时崩溃。

**修复**：两个 HiHook：
- `UpdateAuraLinks @ 0x43E790`（SPLICE_ THISCALL_）：target 处于 Berserk/Hypnotize 时跳过关联建立
- `FindAndRemove @ 0x43E720`（SPLICE_ FASTCALL_）：检查 vector 数据有效性，无效时安全返回

## 依赖

仅依赖原版游戏 EXE + HD Mod 框架（`patcher_x86.hpp`）。不依赖 ZCN2.dll、H3.TextColor.dll、ERA、SoD_SP 或其他插件。

## 部署

```
HD3_Data\Packs\战斗崩溃修复\BattleCrashFix.dll
```

## 构建

```
MSBuild BattleCrashFix.vcxproj /p:Configuration=Release /p:Platform=Win32
```

需要 Visual Studio（v145 工具集）和 `deps/` 目录中的头文件。

## 配置

`BattleCrashFix.ini` 可独立开关每个修复（0=开启，1=禁用）：

```ini
[Options]
DisableObstacle=0
DisableAura=0
```

## 日志

每次游戏启动生成一个 `.log` 文件，包含 `[障碍]`、`[光环]`、`[阻止清理]` 标签。自动保留最近 30 个。
