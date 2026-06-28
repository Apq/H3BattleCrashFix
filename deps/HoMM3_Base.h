////////////////////////////////////////////////////////////////////////////////////
// (HD 3.0) Some global HoMM3 functions and variables
// Author: Alexander Barinov (aka baratorch, aka Bara) e-mail: baratorch@yandex.ru
// Thanks: ZVS, GrayFace
////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Base.h"

// res
struct _BinTree_;
struct _BinTreeItem_;
struct _Palette16_;
struct _Palette24_;
struct _Pcx8_;
struct _Pcx16_;
struct _DefFrame_;
struct _DefGroup_;
struct _Def_;
struct _TXT_;
// GUI
struct _DlgMsg_;
struct _WndMgr_;
struct _Dlg_;
struct _DlgItem_;
struct _DlgStaticPcx8_;
struct _DlgScroll_;
struct _DlgStaticText_;
struct _DlgTextEdit_;
struct _DlgStaticDef_;
struct _DlgStaticText_;
struct _DlgTextEdit_;
struct _DlgStaticDef_;
struct _DlgStaticPcx16_;
struct _DlgButton_;
struct _DlgTextButton_;
struct _DlgCallbackButton_;
struct _DlgScrollableText_;

#define o_New(size) CALL_1(_ptr_, __cdecl, 0x617492, size)
#define o_Delete(ptr) CALL_1(void, __cdecl, 0x60B0F0, ptr)


#define o_PauseVideo() CALL_0(void, __cdecl, 0x597AA0)
#define o_ContinueVideo() CALL_0(void, __cdecl, 0x597B50)

#define o_GetIngameCursorPos(px, py) CALL_2(void, __stdcall, 0x50D700, px, py);


#define o_WndMgr (*(_WndMgr_**)0x6992D0)
#define o_GameMgrPalette16 (*(_Palette16_**)0x6AAD18)
#define o_PlayersPalette16 (*(_Palette16_**)0x6AAD10)
#define o_PlayersPalette24 (*(_Palette24_**)0x6AAD14)

#define o_BinTreeHead (*(_BinTree_*)0x69E560)

#define o_GENRLTXT_TXT (*(_TXT_**)0x6A5DC4)
#define o_PLCOLORS_TXT (*(_TXT_**)0x6A7584)
#define o_TCOMMAND_TXT (*(_TXT_**)0x6A62F8)
// ..............

#define o_Tiny_Fnt  (*(_Fnt_**)0x698A54)
#define o_Smalfont_Fnt (*(_Fnt_**)0x698A58)
#define o_Medfont_Fnt (*(_Fnt_**)0x698A5C)
#define o_Bigfont_Fnt (*(_Fnt_**)0x698A60)
#define o_Calli10R_Fnt (*(_Fnt_**)0x698A64)


#define p_GameMgr (*(_ptr_*)0x699538)
#define o_GameMgrMgr_GetMeID() CALL_1(_int_, __thiscall, 0x4CE6E0, p_GameMgr)



// 清痦?沐礤疣蝾疣 耠篦嚅睇?麒皴?
#define RandSeed *(_dword_*)(CALL_0(_ptr_, __cdecl, 0x61D8C3) + 20)

// 玉蜞眍怅?珏痦?沐礤疣蝾疣 耠篦嚅睇?麒皴?
#define SetRandSeed(Seed) CALL_1(void, __cdecl, 0x61841F, Seed)

// 蔓溴脲龛?镟?蜩.
#define o_MemAlloc(Size) CALL_1(_ptr_, __cdecl, 0x617492, Size)

// 务忸犷驿屙桢 镟?蜩.
#define o_MemFree(lpMem) CALL_1(void, __cdecl, 0x60B0F0, lpMem)



// 杨钺龛?钺 铠栳赍 疣珈屦?蜩镟 ?耧桉赍.
#define LIST_SIZE_ERROR_MESSAGE "Cannot do \"%s\" operation with type of size: %d"

// 署囹觐?耦钺龛?钺 铠栳赍 疣珈屦?蜩镟 ?耧桉赍.
#define LIST_SIZE_ERROR_SHORT_MESSAGE "List type size error"



// 羊痼牝箴?玎泐腩怅?耧桉赅.
#pragma pack(push, 1)
template <typename _type_> struct _List_
{
public:
  // 橡?镥疴铋 桧桷栲腓玎鲨?铟桉蜿?镟?蜩 潆 耱痼牝箴?颃溧 镱戾弪? 珥圜屙桢 桤 礤桧桷栲腓玷痤忄眄铋 镥疱戾眄铋.
  _byte_ Creation; // +0h;
  // 绣珞朦蜞?恹疣忭桠囗?, 礤 桉镱朦珞弪?.
  _byte_ Dummy_f1[3]; // +1h;
  // 冷疱?磬鬣豚 溧眄 耧桉赅.
  _type_* Data; // +4h;
  // 冷疱?觐眦?耧桉赅.
  _type_* EndData; // +8h;
  // 暑礤?恹溴脲眄铋 磬 耧桉铌 镟?蜩.
  _ptr_ EndMem; // +Ch;
  
  
  
  
  
  
  
  
  
  
  
  
  // built-in
  
  
  // 项塍麇龛?觐腓麇耱忄 屐屙蝾??耧桉赍.
  // 朽犷蜞弪 潆 蜩镱?疣珈屦铎 ?4.
  inline _int_ GetItemsCount()
  {
    // 碾 赅驿钽?疣珈屦?蜩镟 - 疋? 趔黻鲨.
    switch (sizeof(_type_))
    {
      case 4:
        return CALL_1(_int_, __thiscall, 0x54D2B0, this);
        
      // 篷腓 疣珈屦 礤 镱漉钿栩 龛 镱?钿眢 趔黻鲨? 沐礤痂痼屐 铠栳牦.
      default:
        ShowVA(LIST_SIZE_ERROR_MESSAGE, "GetItemsCount", sizeof(_type_));
        throw LIST_SIZE_ERROR_SHORT_MESSAGE;
    }
  }
  
  
  
  
  
  
  // 念徉怆屙桢 屐屙蝾??耧桉铌 耦 皲忤泐?
  // 朽犷蜞弪 潆 蜩镱?疣珈屦铎 ?4.
  // DestAddr - 噤疱?戾耱? 磬麒磬 ?觐蝾痤泐 狍潴?桎蜩 眍恹?屐屙螓, 耱囵 磬麒磬 ?钽?戾耱?狍潴?皲忤眢螓.
  // Count - 觐腓麇耱忸 漕徉怆屐 屐屙蝾?
  // SourceAddr - 噤疱? 磬麒磬 ?觐蝾痤泐 狍潴?狃囹 眍恹?屐屙螓.
  inline void InsertRange(_type_* DestAddr, _int_ Count, _type_* SourceAddr)
  {
    // 碾 赅驿钽?疣珈屦?蜩镟 - 疋? 趔黻鲨.
     switch (sizeof(_type_))
    {
      case 4:
        CALL_4(void, __thiscall, 0x4230D0, this, DestAddr, Count, SourceAddr);
        break;
        
      // 篷腓 疣珈屦 礤 镱漉钿栩 龛 镱?钿眢 趔黻鲨? 沐礤痂痼屐 铠栳牦.
      default:
        ShowVA(LIST_SIZE_ERROR_MESSAGE, "InsertRange", sizeof(_type_));
        throw LIST_SIZE_ERROR_SHORT_MESSAGE;
    }
  }
  
  
  
  
  
  
  // 愉嚯屙桢 镱耠邃礤泐 屐屙蜞 ?耦铗忮蝰蜮簋?珥圜屙桢?
  // 篷腓 屐屙蜞 ?蜞觇?珥圜屙桢??耧桉赍 礤? 龛麇泐 桤戾礤眍 礤 狍溴?
  // 朽犷蜞弪 潆 蜩镱?疣珈屦铎 ?4.
  inline void DeleteLastValue(_type_ Value)
  {
    // 碾 赅驿钽?疣珈屦?蜩镟 - 疋? 趔黻鲨.
    switch (sizeof(_type_))
    {
      case 4:
        CALL_2(void, __fastcall, 0x43E720, this, Value);
        break;
        
      // 篷腓 疣珈屦 礤 镱漉钿栩 龛 镱?钿眢 趔黻鲨? 沐礤痂痼屐 铠栳牦.
      default:
        ShowVA(LIST_SIZE_ERROR_MESSAGE, "DeleteLastValue", sizeof(_type_));
        throw LIST_SIZE_ERROR_SHORT_MESSAGE;
    }
  }
  
  
  // 愉嚯屙桢 屐屙蜞 镱 邈?噤疱耋 (忸 桤徨驵龛?镱瘅?镟?蜩 噤疱?漕腈屙 猁螯 觐痧尻蝽 ?猁螯 噤疱耦?屐屙蜞 ?耧桉赍).
  // 朽犷蜞弪 潆 蜩镱?疣珈屦铎 ?4.
  inline void DeleteEntry(_type_* Addr)
  {
    // 碾 赅驿钽?疣珈屦?蜩镟 - 疋? 趔黻鲨.
    switch (sizeof(_type_))
    {
      case 4:
        CALL_2(void, __thiscall, 0x54CDC0, this, Addr);
        break;
        
      // 篷腓 疣珈屦 礤 镱漉钿栩 龛 镱?钿眢 趔黻鲨? 沐礤痂痼屐 铠栳牦.
      default:
        ShowVA(LIST_SIZE_ERROR_MESSAGE, "DeleteEntry", sizeof(_type_));
        throw LIST_SIZE_ERROR_SHORT_MESSAGE;
    }
  }
  
  
  // 愉嚯屙桢 屐屙蝾??箨噻囗眍?滂囡噻铐?(磬鬣腩 - 怅膻鬣, 觐礤?- 礤 怅膻鬣).
  // 朽犷蜞弪 潆 蜩镱?疣珈屦铎 ?4.
  inline void DeleteRange(_type_* FirstAddr, _type_* EndAddr)
  {
    // 碾 赅驿钽?疣珈屦?蜩镟 - 疋? 趔黻鲨.
    switch (sizeof(_type_))
    {
      case 4:
        CALL_3(void, __thiscall, 0x4D4E90, this, FirstAddr, EndAddr);
        break;
        
      // 篷腓 疣珈屦 礤 镱漉钿栩 龛 镱?钿眢 趔黻鲨? 沐礤痂痼屐 铠栳牦.
      default:
        ShowVA(LIST_SIZE_ERROR_MESSAGE, "DeleteRange", sizeof(_type_));
        throw LIST_SIZE_ERROR_SHORT_MESSAGE;
    }
  }
  
  
  // 愉嚯屙桢 怦艴 屐屙蝾?桤 耧桉赅.
  // 朽犷蜞弪 潆 蜩镱?疣珈屦铎 ?4.
  inline void DeleteAll()
  {
    // 碾 赅驿钽?疣珈屦?蜩镟 - 疋? 趔黻鲨.
    switch (sizeof(_type_))
    {
      case 4:
        CALL_1(void, __thiscall, 0x448A40, this);
        break;
        
      // 篷腓 疣珈屦 礤 镱漉钿栩 龛 镱?钿眢 趔黻鲨? 沐礤痂痼屐 铠栳牦.
      default:
        ShowVA(LIST_SIZE_ERROR_MESSAGE, "DeleteAll", sizeof(_type_));
        throw LIST_SIZE_ERROR_SHORT_MESSAGE;
    }
  }
  
  
  
  
  
  
  
  
  
  
  
  
  // user
  
  
  
  
  // 暑眈蝠箨蝾?耧桉赅.
  inline _List_()
  {
    this->Data = 0;
    this->Creation = 0;
    this->EndData = 0;
    this->EndMem = 0;
  }
  
  
  // 腻耱痼牝铕 耧桉赅.
  inline ~_List_()
  {
    o_MemFree(this->Data);
    this->Data = 0;
    this->EndData = 0;
    this->EndMem = 0;
  }
  
  
  
  
  
  // 橡钼屦赅 磬腓麒 珥圜屙? ?耧桉赍.
  inline _bool_ HasValue(_type_ Value)
  {
    // 橡铛钿桁 镱 怦屐 屐屙蜞?耧桉赅.
    for (_int_ i = 0; i < this->GetItemsCount(); i++)
    {
      // 篷腓 磬?眢骓铄 珥圜屙桢 - 忸玮疣屐 疱珞朦蜞?
      if ((*this)[i] == Value) return TRUE;
    }
    
    // 腕骓铄 珥圜屙桢 礤 磬殇屙?
    return FALSE;
  }
  
  
  
  
  
  // 物屦圉? 忡蜩 镱 桧溴犟?
  // 项滗屦骅忄? 铗痂鲟蝈朦睇?桧溴犟?- ?铎 耠篦噱 屐屙?狍溴?狃囹 ?觐眦?耧桉赅.
  // 橡钼屦觇 磬 觐痧尻蝽铖螯 桧溴犟?铗耋蝰蜮簋?
  inline _type_& operator[](_int_ index)
  {
    // 碾 镱腩骅蝈朦眍泐 桧溴犟?忡蜩?赅?钺眍.
    if (index >= 0)
    {
      return (this->Data)[index];
    }
    // 碾 铗痂鲟蝈朦眍泐 桧溴犟?徨鸶??觐眦?耧桉赅.
    else
    {
      return *(_type_*)(this->EndData + index);
    }
  }
  
  
  
  
  
  
  // 念徉怆屙桢 屐屙蜞 ?觐礤?耧桉赅 镱 珥圜屙棹.
  inline void Append(_type_ Item)
  {
    // 念徉怆屐 钿桧 屐屙??觐礤?耧桉赅.
    this->InsertRange(this->EndData, 1, &Item);
  }
  
  
  
  
  // 愉嚯龛?屐屙蜞 镱 桧溴犟??忸玮疣龛?箐嚯疙眍泐 屐屙蜞.
  // 项滗屦骅忄? 铗痂鲟蝈朦睇?桧溴犟?- ?铎 耠篦噱 屐屙?狍溴?狃囹 ?觐眦?耧桉赅.
  // 橡?恹珙忮 徨?镟疣戾蝠钼 狍溴?箐嚯疙 镱耠邃龛?屐屙?耧桉赅.
  // 橡?礤觐痧尻蝽铎 桧溴犟?耧桉铌 礤 镳弪屦镨?桤戾礤龛? ?忸玮疣?狍溴?祗耦?
  inline _type_ Pop(_int_ index = -1)
  {
    // 襄疱戾眄? 潆 躔囗屙? 疱珞腧囹?
    _type_ res = (*this)[index];
    
    // 愉嚯屐 耦铗忮蝰蜮簋?屐屙?
    this->DeleteEntry(&((*this)[index]));
    
    // 骂玮疣?箐嚯疙睇?屐屙?
    return res;
  }
  
  
};
#pragma pack(pop)
