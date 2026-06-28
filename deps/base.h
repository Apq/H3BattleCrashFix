// /////////////////////////////////////////////////////////////////////////////////
// Some HD 3.0 and HotA base stuff
////////////////////////////////////////////////////////////////////////////////////

#pragma once

#ifdef UNICODE
 #undef UNICODE
#endif

#ifdef WIN32_LEAN_AND_MEAN 
 #undef WIN32_LEAN_AND_MEAN
#endif

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <string>
#include <new>
using std::string;

//typedef unsigned __int8  _byte_;
//typedef unsigned __int16 _word_;
//typedef unsigned __int32 _dword_;
//typedef signed __int8  _char_;
//typedef signed __int8  _int8_;
//typedef signed __int16  _int16_;
//typedef signed __int32  _int_;
//typedef _dword_    _ptr_;
//typedef float    _float_;
//typedef _int_    _bool_;

// 皱臌?徨珑磬觐恹?徉轵.
#define _byte_ unsigned __int8
// 皱腩?徨珑磬觐忸?耠钼?
#define _word_ unsigned __int16
// 皱腩?徨珑磬觐忸?溻铋眍?耠钼?
#define _dword_ unsigned __int32

// 谚焘铍.
#define _char_ char

// 皱臌?珥嚓钼 徉轵.
#define _int8_ signed __int8
// 皱腩?珥嚓钼铄 耠钼?
#define _int16_ signed __int16
// 皱腩?珥嚓钼铄 溻铋眍?耠钼?
#define _int32_ signed __int32
// 皱腩?珥嚓钼铄 篦弪忮鸶眄铄 耠钼?
#define _int64_ signed __int64

// 洛耱忮眄铄 溻铋眍?耠钼?
#define _float_ float

// 祟汨麇耜栝 徉轵.
#define _bool8_ _char_
// 祟汨麇耜铄 溻铋眍?耠钼?
#define _bool32_ _int32_

// 祟汨麇耜栝 (溻铋眍?耠钼?.
#define _bool_ _bool32_

// 皱臌?(珥嚓钼铄 溻铋眍?耠钼?.
#define _int_ _int32_

// 羊痤觐恹?(C-耱桦?.
#define _cstr_ _char_*

// 雨噻囹咫?(徨珑磬觐忸?溻铋眍?耠钼?.
//#define _ptr_ _dword_
typedef _dword_ _ptr_;


// 蔓珙恹 趔黻鲨?镱 噤疱襦?
// 襄疴 3 镟疣戾蝠?
// 诣?忸玮疣屐钽?珥圜屙?, 耦汶帏屙桢 恹珙忄 ?箨噻囹咫?磬 趔黻鲨?(?膻犷?蜩镥, 忭?镳孱狃噻箦蝰 噔蝾爨蜩麇耜?.

// 铃?囵泱戾眚钼.
#define CALL_0(return_type, call_type, address) \
 ((return_type (call_type *)(void))address)()

// ?1 囵泱戾眚铎.
#define CALL_1(return_type, call_type, address, a1) \
 ((return_type (call_type *)(_dword_))(address))((_dword_)(a1))

// ?2 囵泱戾眚囔?
#define CALL_2(return_type, call_type, address, a1, a2) \
 ((return_type (call_type *)(_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2))

// ?3 囵泱戾眚囔?
#define CALL_3(return_type, call_type, address, a1, a2, a3) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3))

// ?4 囵泱戾眚囔?
#define CALL_4(return_type, call_type, address, a1, a2, a3, a4) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4))

// ?5 囵泱戾眚囔?
#define CALL_5(return_type, call_type, address, a1, a2, a3, a4, a5) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4),(_dword_)(a5))

// ?6 囵泱戾眚囔?
#define CALL_6(return_type, call_type, address, a1, a2, a3, a4, a5, a6) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4),(_dword_)(a5),(_dword_)(a6))

// ?7 囵泱戾眚囔?
#define CALL_7(return_type, call_type, address, a1, a2, a3, a4, a5, a6, a7) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4),(_dword_)(a5),(_dword_)(a6),(_dword_)(a7))

// ?8 囵泱戾眚囔?
#define CALL_8(return_type, call_type, address, a1, a2, a3, a4, a5, a6, a7, a8) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4),(_dword_)(a5),(_dword_)(a6),(_dword_)(a7),(_dword_)(a8))

// ?9 囵泱戾眚囔?
#define CALL_9(return_type, call_type, address, a1, a2, a3, a4, a5, a6, a7, a8, a9) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4),(_dword_)(a5),(_dword_)(a6),(_dword_)(a7),(_dword_)(a8),(_dword_)(a9))

// ?10 囵泱戾眚囔?
#define CALL_10(return_type, call_type, address, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4),(_dword_)(a5),(_dword_)(a6),(_dword_)(a7),(_dword_)(a8),(_dword_)(a9),(_dword_)(a10))

// ?11 囵泱戾眚囔?
#define CALL_11(return_type, call_type, address, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4),(_dword_)(a5),(_dword_)(a6),(_dword_)(a7),(_dword_)(a8),(_dword_)(a9),(_dword_)(a10),(_dword_)(a11))

// ?12 囵泱戾眚囔?
#define CALL_12(return_type, call_type, address, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4),(_dword_)(a5),(_dword_)(a6),(_dword_)(a7),(_dword_)(a8),(_dword_)(a9),(_dword_)(a10),(_dword_)(a11),(_dword_)(a12))

// ?13 囵泱戾眚囔?
#define CALL_13(return_type, call_type, address, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4),(_dword_)(a5),(_dword_)(a6),(_dword_)(a7),(_dword_)(a8),(_dword_)(a9),(_dword_)(a10),(_dword_)(a11),(_dword_)(a12),(_dword_)(a13))

// ?14 囵泱戾眚囔?
#define CALL_14(return_type, call_type, address, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4),(_dword_)(a5),(_dword_)(a6),(_dword_)(a7),(_dword_)(a8),(_dword_)(a9),(_dword_)(a10),(_dword_)(a11),(_dword_)(a12),(_dword_)(a13),(_dword_)(a14))

// ?15 囵泱戾眚囔?
#define CALL_15(return_type, call_type, address, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4),(_dword_)(a5),(_dword_)(a6),(_dword_)(a7),(_dword_)(a8),(_dword_)(a9),(_dword_)(a10),(_dword_)(a11),(_dword_)(a12),(_dword_)(a13),(_dword_)(a14),(_dword_)(a15))

// ?16 囵泱戾眚囔?
#define CALL_16(return_type, call_type, address, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4),(_dword_)(a5),(_dword_)(a6),(_dword_)(a7),(_dword_)(a8),(_dword_)(a9),(_dword_)(a10),(_dword_)(a11),(_dword_)(a12),(_dword_)(a13),(_dword_)(a14),(_dword_)(a15),(_dword_)(a16))

// ?17 囵泱戾眚囔?
#define CALL_17(return_type, call_type, address, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4),(_dword_)(a5),(_dword_)(a6),(_dword_)(a7),(_dword_)(a8),(_dword_)(a9),(_dword_)(a10),(_dword_)(a11),(_dword_)(a12),(_dword_)(a13),(_dword_)(a14),(_dword_)(a15),(_dword_)(a16),(_dword_)(a17))

// __cdecl ?镥疱戾眄 觐腓麇耱忸?囵泱戾眚钼.
#define CALL_VA(return_type, adress, a1, ...) \
 ((return_type (__cdecl *)(_dword_, ...))(adress))((_dword_)(a1), __VA_ARGS__)

// 襄疱戾龛??镥疱戾眄簋 镟疣戾蝠?this 趔黻鲨?__thiscall (恹镱腠螯 礤镱耩邃耱忮眄?镥疱?恹珙忸?.
#define SET_THIS(this_var) {__asm mov this_var, ecx}

// 诣?恹疣忭桠囗? - 徨?恹疣忭桠囗?.
#define NOALIGN __declspec(align(1))

// 襄疱溧鬣 箫疣怆屙? 铗豚澉桕?
#define BREAKPOINT __asm{__asm int 3}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 吾?怆屐 耱囗溧痱睇?钺?怆屙?, 羼腓 桴 礤?

// 象耱? 觐眈蜞眚?
#ifndef NULL
 #define NULL 0
#endif
// 锐蜩磬.
#ifndef TRUE
 #define TRUE 1
#endif
// 祟纥.
#ifndef FALSE
 #define FALSE 0
#endif
// 锑犟桁箪 桤 溻篚 珥圜屙栝.
#ifndef max
 #define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif
// 惕龛祗?棂 溻篚 珥圜屙栝.
#ifndef min
 #define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

// 填潴朦.
#define Abs(value) ( ((value) > 0) ? (value) : -(value) )

// 锑蝈爨蜩麇耜铄 铌痼汶屙桢.
#define Round(value) ((_int_)((double)(value) + 0.5))
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 暑镨痤忄龛?镟?蜩 ?噔蝾爨蜩麇耜桁 镳桠邃屙桢?蜩镱?
#define MemCopy(dst, src, size) memcpy((void*)(dst), (void*)(src), (size_t)(size))
// 青镱腠屙桢 镟?蜩 ?噔蝾爨蜩麇耜桁 镳桠邃屙桢?蜩镱?
#define MemSet(ptr, value, size) memset((void*)(ptr), (char)(value), (size_t)(size))
// 吾眢脲龛?镟?蜩 ?噔蝾爨蜩麇耜桁 镳桠邃屙桢?蜩镱?
#define MemZero(ptr, size) MemSet(ptr, 0, size)

// 蔓溴脲龛?镟?蜩 ?噔蝾镳桠邃屙桢??忸玮疣龛屐 怦蝠铄眄钽?蜩镟.
#define MemAlloc(size) ((_ptr_)malloc((size_t)(size)))
// 务忸犷铈溴龛?镟?蜩 ?噔蝾镳桠邃屙桢?蜩镟.
#define MemFree(ptr) free((void*)(ptr))
// 襄疱恹溴脲龛?镟?蜩 ?噔蝾镳桠邃屙桢??忸玮疣龛屐 怦蝠铄眄钽?蜩镟.
#define MemRealloc(ptr, size) ((_ptr_)realloc((void*)(ptr), (size_t)(size)))

// 项塍麇龛?疣珈屦?恹溴脲眄铋 镟?蜩 ?噔蝾镳桠邃屙桢?蜩镱?
#define MemGetSize(ptr) ((_dword_)_msize((void*)(ptr)))

// 琼嚓钼铄 溻铋眍?耠钼?镱 噤疱耋.
#define IntAt(address) (*(_int_*)(address))
// 拟铋眍?耠钼?镱 噤疱耋.
#define DwordAt(address) (*(_dword_*)(address))
// 拎轵 镱 噤疱耋.
#define ByteAt(address) (*(_byte_*)(address))
// 央钼?镱 噤疱耋.
#define WordAt(address) (*(_word_*)(address))
// C-耱痤赅 镱 噤疱耋.
#define CStrAt(address) (*(_cstr_*)(address))
// 雨噻囹咫?镱 噤疱耋.
#define PtrAt(address) (*(_ptr_*)(address))

// 玉蜞眍忤螯 忮耱忮眄铄 溻铋眍?耠钼?镱 噤疱耋.
#define SetFloatAt(address, value) (*(_float_*)(address) = (_float_)(value))
// 玉蜞眍忤螯 溻铋眍?耠钼?镱 噤疱耋.
#define SetDwordAt(address, value) (*(_dword_*)(address) = (_dword_)(value))
// 玉蜞眍忤螯 耠钼?镱 噤疱耋.
#define SetWordAt(address, value) (*(_word_*)(address) = (_word_)(value))
// 玉蜞眍忤螯 徉轵 镱 噤疱耋.
#define SetByteAt(address, value) (*(_byte_*)(address) = (_byte_)(value))
// 玉蜞眍忤螯 镳铌.
#define SetJmpAt(address, to_address) do{*(_byte_*)(address) = 0xE9; *(_int_*)(address + 1) = (_int_)(to_address) -  (_int_)(address) - 5; break;}while(true)

// 袜驵蜞 腓 箨噻囗磬 觌噔桫?
_bool_ IsKeyPressed(int nVirtKey);

// 项塍麇龛?桁屙?羿殡?桤 矬蜩 ?礤祗.
char* GetShortFileName(char* filename);
// 橡钼屦赅 漕矬耱桁铖蜩 桁屙?羿殡?
_bool_ IsFileNameValid(char* name);

// 橡钼屦赅 耋耱忸忄龛 羿殡?镱 桁屙?
//inline _bool_ FileExists(char* filename)
//{
//  return (GetFileAttributes(filename) != INVALID_FILE_ATTRIBUTES)
//}
#define FileExists(file_name) (GetFileAttributes((char*)(file_name)) != INVALID_FILE_ATTRIBUTES)

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 岭铌 镟?蜩, 磬 牮囹睇?镱 疣珈屦?觐蝾痤祗 犭铌 祛驽?噔蝾爨蜩麇耜?疣聒桊螯? 镟?螯 镱蝾赅 桦?爨耨桠?
#define MIN_ARRAY_MEMBLOCK_SIZE 64

// 噪嚆 桤戾礤龛 镱玷鲨?聍栩囗?/玎镨耔 - 铗眍耔蝈朦眍 磬鬣豚 镱蝾赅.
#define soFromBeginning FILE_BEGIN
// 噪嚆 桤戾礤龛 镱玷鲨?聍栩囗?/玎镨耔 - 铗眍耔蝈朦眍 蝈牦?镱玷鲨?
#define soFromCurrent FILE_CURRENT
// 噪嚆 桤戾礤龛 镱玷鲨?聍栩囗?/玎镨耔 - 铗眍耔蝈朦眍 觐眦?镱蝾赅.
#define soFromEnd  FILE_END

// 拎珙恹?桧蝈痿彘?镱蝾赅.
class TStream
{
public:
 // 腻耱痼牝铕.
 virtual void Free() = 0;
 // 昨屙桢 桤 镱蝾赅 (忸玮疣?篑镥铖蜩 黩屙?).
 virtual _bool_ Read(void* dst, _dword_ size) = 0;
 // 青镨顸 ?镱蝾? 忸玮疣?篑镥铖蜩 玎镨耔.
 virtual _bool_ Write(void* src, _dword_ size) = 0;
 // 玉蜞眍怅?镱玷鲨?聍栩囗?/玎镨耔 ?镱蝾赍.
 virtual _int_ Seek(_int_ offset, _int_ origin) = 0;
 // 项塍麒螯 疣珈屦 镟?蜩 镱蝾赅.
 virtual _int_ Size() = 0;
 
 // 剜犭铐-趔黻鲨 黩屙? 屐屙蜞 膻犷泐 蜩镟 溧眄 桤 镱蝾赅.
 template<typename DataType> _bool_ Read(const DataType& value)
 {
  return Read((void*)&value, sizeof(DataType));
 }
 // 剜犭铐-趔黻鲨 玎镨耔 屐屙蜞 膻犷泐 蜩镟 溧眄 ?镱蝾?
 template<typename DataType> _bool_ Write(const DataType& value)
 {
  return Write((void*)&value, sizeof(DataType));
 }
};


// 项蝾??镟?蜩.
class TMemoryStream : public TStream
{
public:
 // 腻耱痼牝铕 镱蝾赅 ?镟?蜩.
 virtual void Free();
 // 昨屙桢 桤 镱蝾赅 ?镟?蜩 (忸玮疣?篑镥铖蜩 黩屙?).
 virtual _bool_ Read(void* dst, _dword_ size);
 // 青镨顸 ?镱蝾??镟?蜩 ?噔蝾爨蜩麇耜桁 疣聒桊屙桢?邈?镟?蜩 (犭铌囔?, 忸玮疣?篑镥铖蜩 玎镨耔.
 virtual _bool_ Write(void* src, _dword_ size);
 // 玉蜞眍怅?镱玷鲨?聍栩囗?/玎镨耔 ?镱蝾赍 (忸玮疣?-1 镳?礤忮痦铎 镟疣戾蝠?- 耢妁屙梃).
 virtual _int_ Seek(_int_ offset, _int_ origin);
 // 项塍麒螯 疣珈屦 镟?蜩 镱蝾赅 ?镟?蜩.
 virtual _int_ Size();

 // 雨噻囹咫?磬 镟?螯 镱蝾赅.
 _ptr_ memory;
 // 项玷鲨 牦瘃铕?玎镨耔/聍栩囗? 镱蝾赅.
 _int_ position;
 // 朽珈屦 镟?蜩 镱蝾赅.
 _int_ size;
 // 暑眈蝠箨蝾?矬耱钽?镱蝾赅 ?镟?蜩.
 static TMemoryStream* Create();
 // 暑眈蝠箨蝾?镱蝾赅 ?镟?蜩.
 static TMemoryStream* Create(_dword_ size);
 // 褥屙屙桢 疣珈屦?玎龛爨屐铋 镱蝾觐?镟?蜩.
 void SetSize(_dword_ size);
 // 项塍麒螯 箨噻囹咫?磬 镟?螯 镱蝾赅.
 void* Memory()
 {
  return (void*)this->memory;
 }
};


// 噪嚆 觐眈蝠箨蝾疣 羿殡钼钽?镱蝾赅 - 耦玟囹?羿殡.
#define fmCreate   0xFFFF
// 噪嚆 觐眈蝠箨蝾疣 羿殡钼钽?镱蝾赅 - 铗牮?羿殡 潆 黩屙?.
#define fmOpenRead       0x0000
// 噪嚆 觐眈蝠箨蝾疣 羿殡钼钽?镱蝾赅 - 铗牮?羿殡 潆 玎镨耔.
#define fmOpenWrite      0x0001
// 噪嚆 觐眈蝠箨蝾疣 羿殡钼钽?镱蝾赅 - 铗牮?羿殡 潆 黩屙? ?玎镨耔.
#define fmOpenReadWrite  0x0002


// 脏殡钼 镱蝾?
class TFileStream : public TStream
{
protected:
 // 脏殡 潆 黩屙?/玎镨耔 镱蝾赅.
 HANDLE h_file;

public:
 // 腻耱痼牝铕 羿殡钼钽?镱蝾赅.
 virtual void Free();
 // 昨屙桢 桤 羿殡钼钽?镱蝾赅 (忸玮疣?篑镥铖蜩 黩屙?).
 virtual _bool_ Read(void* dst, _dword_ size);
 // 青镨顸 ?羿殡钼 镱蝾?(忸玮疣?篑镥铖蜩 玎镨耔).
 virtual _bool_ Write(void* src, _dword_ size);
 // 襄疱戾龛?镱玷鲨?聍栩囗?/玎镨耔 ?羿殡钼铎 镱蝾赍.
 virtual _int_ Seek(_int_ offset, _int_ origin);
 //  项塍麇龛?疣珈屦?羿殡钼钽?镱蝾赅.
 virtual _int_ Size();

 // 暑眈蝠箨蝾?羿殡钼钽?镱蝾赅.
 static TFileStream* Create(_cstr_ file_name, _word_ mode);
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// 锑犟桁嚯? 潆桧?耱痤觇 耦钺龛 镳?镱漶蜞眍怅?镟疣戾蝠钼 纛痨囹?
#define MAX_MSGVA_LENGTH 256

// 项赅?耦钺龛.
#define ShowMessage(msg) MessageBoxA(NULL, (LPCSTR)(msg), (LPCSTR)"", MB_OK)

// 项赅?耦钺龛 ?镟疣祆弪疣扈 纛痨囹?
inline void ShowVA(const char *pFormat, ... )
{
 // 扬桉铌 镟疣戾蝠钼.
 va_list Args;
 va_start(Args, pFormat);
 // 侮铐鬣蝈朦磬 耱痤赅.
 char Buffer[MAX_MSGVA_LENGTH];
 // 青镨覃忄屐 铌铐鬣蝈朦眢?耱痤牦 ?镟疣戾蝠囔?
 vsprintf(Buffer, pFormat, Args);
 va_end(Args);
 // 蔓忸滂?耦钺龛?
 ShowMessage(Buffer);
}


// 橡孱狃噻钼囗桢 耱痤觇 ?珥嚓钼铄 32-徼蝽铄 麒耠?
inline _int_ StrToInt(_cstr_ str)
{
 //int n = 0;
 //char* digits =  "0123456789";
 //BOOL char_is_not_digit = TRUE;

 //for (int i = 0; i < strlen(str); i++)
 //{
 // for (int d = 0; d < 10; d++)
 // {
 //  if (str[i] == digits[d])
 //  {
 //   n = n * 10 + d;
 //   char_is_not_digit = FALSE;
 //   break;
 //  }
 // }
 // if (char_is_not_digit) break;
 //}
 //return n;
 // 阻耠?
 _int_ result;
 sscanf(str, "%d", &result);
 return result;
}

// 哜?弪? 腓 箨噻囗睇?耔焘铍 耱痤觇 耔焘铍铎 桤 磬犷疣.
inline _bool_ IsDelimiter(_cstr_ Delimiters, _cstr_ S, _int_ Index)
{
 // 橡铛钿梃 镱 怦屐 耔焘铍囔 桤 磬犷疣.
 for (int i = strlen(Delimiters); i >= 0; i--)
 {
  if (Delimiters[i] == S[Index])
   return TRUE;
 }
 return FALSE;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 剜犭铐 滂磬扈麇耜钽?爨耨桠?潆 膻犷泐 蜩镟 屐屙蝾?
template <typename ElementType> class TArray
{
public:
 // 泥眄.
 ElementType* data;
 // 暑腓麇耱忸 屐屙蝾?爨耨桠?
 int length;
 // 朽珈屦 玎龛爨屐铋 爨耨桠铎 镟?蜩.
 int data_size;

 // 暑眈蝠箨蝾?
 TArray()
 {
  this->data = NULL;
  this->length = 0;
  this->data_size = 0;
 }

 //  腻耱痼牝铕.
 ~TArray()
 {
  // 务忸犷驿噱?玎?蝮?爨耨桠铎 镟?螯.
  MemFree(this->data);
 }

 // 项塍麇龛?觐腓麇耱忄 屐屙蝾?爨耨桠?
 _int_ Length()
 {
  return this->length;
 }

 // 玉蜞眍怅?觐腓麇耱忄 屐屙蝾?爨耨桠?
 void SetLength(_int_ new_len)
 {
  // 篷腓 潆桧?爨耨桠?礤 疣忭?0...
  if (new_len) 
  {
   // 惕龛爨朦磬 镟?螯, 漕耱囹铟磬, 黩钺?忪羼蜩螯 new_len 屐屙蝾?
   int need_min_size = new_len * sizeof(ElementType);
   // 念恹溴?屐? 镟?螯, 牮囹磬 MIN_ARRAY_MEMBLOCK_SIZE.
   int new_size = ( need_min_size / MIN_ARRAY_MEMBLOCK_SIZE + ((need_min_size % MIN_ARRAY_MEMBLOCK_SIZE) != 0) ) * MIN_ARRAY_MEMBLOCK_SIZE;
   if (new_size != this->data_size)
   {
    // 蔓溴?屐 眍怏?镟?螯 ?觐镨痼屐 蝮溧 溧眄.
    //this->data = (ElementType*)MemRealloc(this->data, new_size);
    ElementType* new_data = (ElementType*)MemAlloc(new_size);
    MemCopy(new_data, data, min(data_size, new_size));
    MemFree(data);
    data = new_data;

    // 青镱腠屐 漕镱腠栩咫?恹溴脲眄簋 镟?螯 眢?扈.
    if (new_size > this->data_size)
     MemZero((_ptr_)this->data + this->data_size, new_size - this->data_size);
    this->data_size = new_size;
   }
   // 玉蜞磬怆桠噱?眍怏?潆桧?
   this->length = new_len;
  }
  // 篷腓 眍忄 潆桧?疣忭?0, 铖忸犷驿噱?镟?螯 爨耨桠?
  else
  {
   MemFree(this->data);
   this->data = NULL;
   this->data_size = 0;
   this->length = 0;
  }
 }

 // 络蜩?屐屙蜞 镱 桧溴犟?
 ElementType& operator[](int index)
 {
  // 软溴犟 噔蝾爨蜩麇耜?箧桁噱蝰 漕 眢骓钽?滂囡噻铐?
  index = min(length - 1, max(0, index)); // if < 0 then =0, if > last then =last 
  return data[index];
 }

 // 念徉怆屙桢 眍忸泐 屐屙蜞 ?觐礤?爨耨桠?
 void Add(const ElementType& value)
 {
  // 逾咫梓桠噱?疣珈屦 爨耨桠?
  SetLength(this->length + 1);
  // 暑镨痼屐 眍恹?屐屙??觐礤?
  MemCopy(&(this->data[this->length - 1]), &value, sizeof(ElementType)); 
 }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 羊痤赅 ?潆桧铋 (磬耠邃箦蝰 铗 滂磬扈麇耜钽?爨耨桠?耔焘铍钼).
class TString: public TArray<_char_>
{
protected:
 // 羊痤赅, 躔囗 疱珞朦蜞?铒屦圉梃.
 static TString op_result;

public:
 // 暑眈蝠箨蝾?
 TString(const _cstr_ cstr);
 // 象耱? 耱痤赅.
 TString();
 // 腻耱痼牝铕.
 //~TString();

 // 橡孱狃噻钼囗桢 耱痤觇 ?C-耱桦?
 _char_* c_str()
 {
  return this->data;
 }

 // 玉蜞眍怅?潆桧?耱痤觇.
 void SetLength(int new_len);
 // 念徉怆屙桢 耔焘铍??耱痤赍.
 void Add(const _char_ &chr);
 
 // 橡桊噔龛忄龛??耱痤赍 ?潆桧铋.
 TString& operator=(TString& r_str);
 // 橡桊噔龛忄龛??C-耱痤赍.
 TString& operator=(const _cstr_ r_str);
 // 橡桊噔龛忄龛??耔焘铍?
 TString& operator=(_char_ r_chr);
 
 // 念徉怆屙桢 耱痤觇 ?潆桧铋.
 TString& operator+=(TString& r_str);
 // 念徉怆屙桢 C-耱痤觇.
 TString& operator+=(const _cstr_ r_str);
 // 念徉怆屙桢 耔焘铍?
 TString& operator+=(_char_ r_chr);

 // 央铈屙桢 耦 耱痤觐??潆桧铋..
 friend TString& operator+(TString &l_tstr, TString &r_tstr);
 // 央铈屙桢 ?C-耱痤觐?
 friend TString& operator+(TString &l_tstr, _cstr_ r_cstr);
 // 橡噔铄 耠铈屙桢 ?C-耱痤觐?
 friend TString& operator+(_cstr_ l_cstr, TString &r_tstr);
 // 央铈屙桢 ?耔焘铍铎.
 friend TString& operator+(TString &l_tstr, _char_ r_chr);
 // 橡噔铄 耠铈屙桢 ?耔焘铍铎.
 friend TString& operator+(_char_ l_chr, TString &r_tstr);
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



NOALIGN struct _Struct_
{
    template <typename _type_>
    inline _type_ & Field(int offset) {return *(_type_*)((_ptr_)this + offset);}
    
    template <typename _type_>
    inline _type_ * PField(int offset) {return (_type_*)((_ptr_)this + offset);}
    
    inline _ptr_    Offset(int offset)    {return ((_ptr_)this + offset);}
};



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



// 杨玟囗桢 爨耨桠?
template<typename _type_> void MakeArray(_type_** array_off, _int_ count)
{
  // 篷腓 爨耨桠 箧?玎镱腠屙, 铖忸犷驿噱?邈?
  if (*array_off)
  {
    // 腻龛鲨嚯桤桊箦?钺牝?
    for (_int_ i = 0; i < count; i++)
    {
      ((*array_off)[i]).~_type_();
    }
    
    MemFree(*array_off);
  }
  
  // 蔓溴?屐 镟?螯 镱?眍恹?爨耨桠.
  if (count)
  {
    *array_off = (_type_*)MemAlloc(sizeof(_type_)*count);
    
    // 软桷栲腓玷痼屐 钺牝?
    for (_int_ i = 0; i < count; i++)
    {
      new(&((*array_off)[i])) _type_();
    }
  
  }
  else
  {
    *array_off = NULL;
  }
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/* #include "..\patcher_x86_commented.hpp"
extern Patcher* _P;
extern PatcherInstance* _PI;

// 项塍麇龛?镟疣戾蝠钼 HD.
extern FARPROC HdCommon_Get;
#define HDC_Get(name, default_value) HdCommon_Get?CALL_2(_dword_,__stdcall,HdCommon_Get,name,default_value):default_value

// 玉蜞眍怅?镟疣戾蝠钼 HD.
extern FARPROC HdCommon_Set;
#define HDC_Set(name, value) HdCommon_Set?CALL_2(_bool_,__stdcall,HdCommon_Set,name,value):FALSE */



#define strempty(string) do{string[0] = 0;}while(false)



#define va_cstr(pFormat, ...) Base::va_cstr(pFormat, __VA_ARGS__)

#define _L(ru, en) (Base::SystemLanguageIsRussian() ? (ru) : (en))


#define _LW(ru, en) (Base::SystemLanguageIsRussian()  ? (L##ru) : (L##en))