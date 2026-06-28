////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 寰肩姯妗€閾楀盎?patcher_x86.dll 
// 鐤ｈ€х棨鑰辩枺?寮? 鐤嬮捄閽跨湇(寰ㄨ€ц睔铦?
// 鍣旇澗鐦冭?闀冲檾? 鎷庣梻鐪?绂诲盎瑗︾?(baratorch), e-mail: baratorch@yandex.ru
// 绾涚棬?鐤卞毌妗ゅ湁姊?榫涚弨閾欑棨蹇倐顜?韬炶?(LoHook) 閾楅鑰?闀辩帋妗佽€卞扛蹇勭， ?Berserker (妗?ERA)
////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 蹇槂? 4.2

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// 铚楀鍔虫壈.
//
// ! 寰肩姯妗€铦堣祬 闀抽們閾栬湠鎬嗭５寮?
//  - 绠愰捄鐫?绠滄妗锋閽煎洍鐫?椴ョ湚鐤ｈ厯鐝欏縿鐪勵帓 
//    妗ц€辩椉鎴剧湚?娼嗭５ 绡戣湠鐪嶆€?闀熻澕褰??韬炶?
//    ?瑙?椴ヨ劜蹇?闀抽捊鐤ｇ?
//  - 婕曢暠鑵犳牘鍜徃顜?妗ц€辩椉鎴剧湚? 婊傜帋鑰ㄥ睈鐘宝 娼嗘¨ 閾掕婕??瓒旈换椴?
//    瑙愰暔鐥碱搥绨?瑙??瑙愮棫灏昏澖顜?闀ョ柋鐪嶈€?閾掕婕?jmp ?call c 
//    閾楃湇鑰旇潏鏈︾湇?鍣ょ柋瑗﹂波褰?
// ! 寰肩姯妗€铦堣祬 闀辩幃閾嶏５寮?
//  - 绡戣湠纾€嗘鍥?璧?闀抽摉铻?铚??鑰犻搱鐫?闀熻澕?
//  - 绡戣湠纾€嗘鍥?鎭硅€﹁绠撮捈绀ゆ伖?韬炶, 鐜庢埦顙戯５ 閾曟　妗у毌顝割帓 瓒旈换椴??
//    ?椴ヨ劜蹇?瑙愭捍 纾?鐤嬮搳, 绀?鐜庣姺?椤??鐤辨报鑰辩枺?闀抽摓缇艰€︾枺,
//    鑰鳖憮? ?蹇哥幃鐤ｈ潏 ?閾曟　妗у毌顝割帠 瑙?
//  - 绡戣湠纾€嗘鍥?鎭硅€﹁绠撮捈绀ゆ伖?韬炶 閽挎¨ 纾?婕閾?
//    绀?妗夎顠? ?婕曢暠鑵狅５铮?闀?顟涢搸 瓒旈换椴ㄩ搻鍤徃閾栬灟 韬炶?
//    绡戣湠鐪嶆€嗗睓鐫?鐤ｇ潈顗?闀辫€犻們绀ゆ硱
//  - 绡戣湠纾€嗘鍥?榫涚弨閾欑棨蹇倐顜?韬炶 ?鎭硅€﹁绠撮捈绀ゆ伖?婕曡€辩閾??
//    鐤辨报鑰辩枺?闀抽摓缇艰€︾枺, 鑰鳖憮? 鐜庤潏鐥遍搸?瑙愭酱 ?鍣ょ柋鑰?蹇哥幃鐤ｈ湠 ?瑙?
//  - 閾楁埦?铻?鑶荤姺?闀熻澕 ?韬? 绡戣湠鐪嶆€嗗睓鐫??闀辩顙?顟涢搵 寰肩姯妗€铦堣.
//  - 绠哥，铻?鐜庢捍杞宠湲閽煎洍 鑵?閾掔柋婧磋劜鐪勵帠 绁? 妗夐暠鏈︾彏顡€鏍?寰肩姯妗€铦堢墻
//  - 绠哥，铻?璧呰?绁?(妗夐暠鏈︾彏顡€鏍?寰肩姯妗€铦堢墻) 绡戣湠鐪嶅郡?閾掔柋婧磋劜鐪勵帠 闀熻澕/韬?
//  - 闀卞楹掕灟 闀辫厾顜?婕曡€辩 瑙?鎬﹀睈 闀熻澕鍥?韬炶祬? 绡戣湠鐪嶆€嗗睓鐫?妗?婕妗?绁涙紩?
//    ?闀辩顙?顟涢搵 寰肩姯妗€铦堣
//  - 鑴叉贝??鐚佽€辩棨 閽虹，鐥奸獏铻?瑙愮湙鑵撶墲绨嬵嫏?闀熻澕?妗?鐤ｇ彞顜?绁涙紩?
//    (妗夐暠鏈︾彏顡€妗?顟?寰肩姯妗€铦堢墻) 1) 閾楁埦楝ｏ５?鑵╂矏 铚炶?瑙愮湙鑵撶墲?璧?
//        - 绡戣湠纾€嗘甯艰澃铮?闀熻澕?韬炶 鐤ｇ彞閽?鐤ｇ張灞?纾?閽挎¨ 鍣ょ柋?
//        - 绡戣湠纾€嗘甯艰澃铮?闀熻澕?韬炶 闀ョ柋鐗帍甯碱嫏?閽挎¨ 婕閽?鑰?鑰㈠灞欐、?
//        - 绡戣湠纾€嗘甯艰澃铮?闀熻澕?闀卞慨鐦?韬炶??纾捄閾曢摋
//    ?铚?椹?2) 婧у縿铮?蹇哥張閾堢湇鑰?闀辫€㈤摋鐤辫灟 婧х (閽侯嫏?鑵撹€辨¨? 鎬﹁壌 闀熻澕褰?
//    ?韬炶?绡戣湠鐪嶆€嗗睓鐫??闀辩顙?顟涢搵 寰肩姯妗€铦堣 ?瑙愰换鐤辫澖顜?绁涙埦鐪?鎬靛睈灞?
////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// 瀹嬭悓褰㈠悤鑵?
//
// 闀?绠搷楝ｉ緵??patcher_x86.dll 鑵╂报鐥ゅ縿榫?閾楄顠惧睓? 榛╅捄?鎬呰喕楹掕灟 閭?
// 绀ら捄韬呮粋绁??铦?椹?闀熼暘?鑰︾師鍥?缇挎 patcher_x86.ini c 閭冩¨鑰卞慨鐪勯搵
// 鐜庨暔椤? Logging = 1 (Logging = 0 - 閾楄顠惧櫛?鑵╂报鐥ゅ縿榫?鑰ラ捈?
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// 闂茬紗浜?濡婅濉戜繌鍚曡吙?
//
// 1) 璧呴┛顜?绁?婕曡厛灞?1 鐤?鎭圭幃鍥?瓒旈换椴?GetPatcher(), 鑰﹁簲鍥楁 鐤辩彏鏈﹁湠?
//  纾暢妗佸宝: Patcher* _P = GetPatcher();
// 2) 鐜庤潏??闀辩顙?鎴捐澗婧?Pather::CreateInstance 鐪㈤獡?鑰︾師鍥? 
// 顟撶弿绁??Pat椐俥rInstance 鑰?鐤嬮搳?绠滄鍤徃顜?妗佸睓灞?
//  纾暢妗佸宝: Pat椐俥rInstance* _PI = _P->CreateInstance("MyMod");
// 3)  鐜庤潏?妗夐暠鏈︾彊蹇勮灟 鎴捐澗娼?瑙屽洬鑰?Pat椐俥r ?Pat椐俥rInstance
// 绀ら暠鑰╅們鑰卞慨鐪?娼嗭５ 鐤ｇ姺铻??闀熻澕鍥??韬炶祬鎵?
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#define _byte_ unsigned __int8
#define _word_ unsigned __int16
#define _dword_ unsigned __int32


//鐖ㄧ壆閾?CALL_? 闀辩幃閾嶏５顠?鎭圭惃蹇勮灟 闀抽搳鐜搷顝哥皨 瓒旈换椴?闀?閾掔柋婧磋劜鐪勯搸?鍣ょ柋鑰?
//妗夐暠鏈︾彏顠? ?铦?楹掕€?娼嗭５ 鎭圭彊蹇?瓒旈换椴?
//闀卞楹囩渼顜??闀辩顙?HiHook::GetDefaultFunc ?HiHook::GetOriginalFunc
#define CALL_0(return_type, call_type, address) \
 ((return_type (call_type *)(void))address)()
#define CALL_1(return_type, call_type, address, a1) \
 ((return_type (call_type *)(_dword_))(address))((_dword_)(a1))
#define CALL_2(return_type, call_type, address, a1, a2) \
 ((return_type (call_type *)(_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2))
#define CALL_3(return_type, call_type, address, a1, a2, a3) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3))
#define CALL_4(return_type, call_type, address, a1, a2, a3, a4) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4))
#define CALL_5(return_type, call_type, address, a1, a2, a3, a4, a5) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4),(_dword_)(a5))
#define CALL_6(return_type, call_type, address, a1, a2, a3, a4, a5, a6) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4),(_dword_)(a5),(_dword_)(a6))
#define CALL_7(return_type, call_type, address, a1, a2, a3, a4, a5, a6, a7) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4),(_dword_)(a5),(_dword_)(a6),(_dword_)(a7))
#define CALL_8(return_type, call_type, address, a1, a2, a3, a4, a5, a6, a7, a8) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4),(_dword_)(a5),(_dword_)(a6),(_dword_)(a7),(_dword_)(a8))
#define CALL_9(return_type, call_type, address, a1, a2, a3, a4, a5, a6, a7, a8, a9) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4),(_dword_)(a5),(_dword_)(a6),(_dword_)(a7),(_dword_)(a8),(_dword_)(a9))
#define CALL_10(return_type, call_type, address, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4),(_dword_)(a5),(_dword_)(a6),(_dword_)(a7),(_dword_)(a8),(_dword_)(a9),(_dword_)(a10))
#define CALL_11(return_type, call_type, address, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4),(_dword_)(a5),(_dword_)(a6),(_dword_)(a7),(_dword_)(a8),(_dword_)(a9),(_dword_)(a10),(_dword_)(a11))
#define CALL_12(return_type, call_type, address, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4),(_dword_)(a5),(_dword_)(a6),(_dword_)(a7),(_dword_)(a8),(_dword_)(a9),(_dword_)(a10),(_dword_)(a11),(_dword_)(a12))
#define CALL_13(return_type, call_type, address, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4),(_dword_)(a5),(_dword_)(a6),(_dword_)(a7),(_dword_)(a8),(_dword_)(a9),(_dword_)(a10),(_dword_)(a11),(_dword_)(a12),(_dword_)(a13))
#define CALL_14(return_type, call_type, address, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4),(_dword_)(a5),(_dword_)(a6),(_dword_)(a7),(_dword_)(a8),(_dword_)(a9),(_dword_)(a10),(_dword_)(a11),(_dword_)(a12),(_dword_)(a13),(_dword_)(a14))
#define CALL_15(return_type, call_type, address, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4),(_dword_)(a5),(_dword_)(a6),(_dword_)(a7),(_dword_)(a8),(_dword_)(a9),(_dword_)(a10),(_dword_)(a11),(_dword_)(a12),(_dword_)(a13),(_dword_)(a14),(_dword_)(a15))
#define CALL_16(return_type, call_type, address, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4),(_dword_)(a5),(_dword_)(a6),(_dword_)(a7),(_dword_)(a8),(_dword_)(a9),(_dword_)(a10),(_dword_)(a11),(_dword_)(a12),(_dword_)(a13),(_dword_)(a14),(_dword_)(a15),(_dword_)(a16))
#define CALL_17(return_type, call_type, address, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4),(_dword_)(a5),(_dword_)(a6),(_dword_)(a7),(_dword_)(a8),(_dword_)(a9),(_dword_)(a10),(_dword_)(a11),(_dword_)(a12),(_dword_)(a13),(_dword_)(a14),(_dword_)(a15),(_dword_)(a16),(_dword_)(a17))

#define CALL_VA(return_type, adress, a1, ...) \
 ((return_type (__cdecl *)(_dword_, ...))(adress))((_dword_)(a1), __VA_ARGS__)


// _bool_ - 4-?寰夎降閽碱帠 鑵╂报楹囪€滄牆 铚? 璧?BOOL ?Win32 API
// 缇艰厯 閾熷睓?鐜庤簠楹囪澃铮? 绁涢獡?鐜庢埦榫涜灟 纾?BOOL 妗?閽跨湇寰夎降閽碱帠 bool 纾暢妗佸宝
#define _bool_ __int32

// 鎬?鍣ょ柋瑗??楝ｈ€?绠ㄥ櫥鍥瑰挮褰?閾掔柋婧磋劜鐫?顟涙 铚╅暠?
// 缇艰厯 蹇?绠愰捄绀?闀?婕閾? 绁涢┙铦?鐜庢埦榫涜灟 _ptr_ 纾?鑶荤姺?婕閾?铚? void* 妗?int 纾暢妗佸宝
typedef _dword_ _ptr_;



// 蹇?鎬﹁壌 鑰辩椉鐗濈鍦??妗ц潏鐥垮綐瑗?寰肩姯妗€铦堣 婕曡厛鐪?鐚佽灟 鎭圭枺蹇鍥楁、 - 4 寰夎降?
#pragma pack(push, 4)


//铚?"闀ョ柋鎴剧渼?", 妗夐暠鏈︾彏寮? 娼嗭５ 蹇哥幃鐤ｎ嫅灞愵帰 鎴捐澗婧ф増 Patcher::VarInit ?Patcher::VarFind 鐝ュ湝灞欐牆.
class Variable
{
public:
	// 蹇哥幃鐤ｎ嫅寮?鐝ュ湝灞欐、 '闀ョ柋鎴剧渼閾? (闀辫澗瑙愬鲸鐝欓暉鑰ラ搫 閽虹枺顙栭緵?
	virtual _dword_ __stdcall GetValue() = 0;
	// 绡戣湠纾€嗘鍣?鐝ュ湝灞欐、 '闀ョ柋鎴剧渼閾? (闀辫澗瑙愬鲸鐝欓暉鑰ラ搫 閽虹枺顙栭緵?
	virtual void __stdcall SetValue(_dword_ value) = 0;
	// 蹇哥幃鐤ｎ嫅寮?绠ㄥ櫥鍥瑰挮?纾?鐝ュ湝灞欐、 (閽虹枺顙栭緵??鐝ュ湝灞欐９ 楹囩柋?绠ㄥ櫥鍥瑰挮?绀ら暠铦捐寰ㄧ彊闀熻€?
	virtual _dword_* __stdcall GetPValue() = 0;
};

// 铚?'鐤辨报鑰?缍﹀殕閽?, 鐤ｇ張灞?- 32 寰艰湠 
// 妗夐暠鏈︾彏寮? ?HookContext
struct FlagsRegister
{
	_dword_ CF			: 1; //0
	_dword_ reserved_1	: 1; //1
	_dword_ PF			: 1; //2
	_dword_ reserved_3	: 1; //3
	_dword_ AF			: 1; //4
	_dword_ reserved_5	: 1; //5
	_dword_ ZF			: 1; //6
	_dword_ SF			: 1; //7
	_dword_ TF			: 1; //8
	_dword_ IF			: 1; //9
	_dword_ DF			: 1; //10
	_dword_ OF			: 1; //11
	_dword_ IOPL		: 2; //12-13
	_dword_ NT			: 1; //14
	_dword_ reserved_15	: 1; //15
	_dword_ RF			: 1; //16
	_dword_ VM			: 1; //17
	_dword_ AC			: 1; //18
	_dword_ VIF			: 1; //19
	_dword_ VIP			: 1; //20
	_dword_ ID			: 1; //21
	_dword_ reserved_22	: 1; //22
	_dword_ reserved_23	: 1; //23
	_dword_ reserved_24	: 1; //24
	_dword_ reserved_25	: 1; //25
	_dword_ reserved_26	: 1; //26
	_dword_ reserved_27	: 1; //27
	_dword_ reserved_28	: 1; //28
	_dword_ reserved_29	: 1; //29
	_dword_ reserved_30	: 1; //30
	_dword_ reserved_31	: 1; //31
};

// 缇婄椉鐗濈?HookContext
// 妗夐暠鏈︾彏寮? ?瓒旈换椴５?鑰╁檶閾楀檾顗?闀?LoHook 韬炵墻
struct HookContext
{
 int eax; //鐤辨报鑰?EAX, 榛╁睓妗?妗ゆ埦绀ら緵?
 int ecx; //鐤辨报鑰?ECX, 榛╁睓妗?妗ゆ埦绀ら緵?
 int edx; //鐤辨报鑰?EDX, 榛╁睓妗?妗ゆ埦绀ら緵?
 int ebx; //鐤辨报鑰?EBX, 榛╁睓妗?妗ゆ埦绀ら緵?
 int esp; //鐤辨报鑰?ESP, 榛╁睓妗?妗ゆ埦绀ら緵?
 int ebp; //鐤辨报鑰?EBP, 榛╁睓妗?妗ゆ埦绀ら緵?
 int esi; //鐤辨报鑰?ESI, 榛╁睓妗?妗ゆ埦绀ら緵?
 int edi; //鐤辨报鑰?EDI, 榛╁睓妗?妗ゆ埦绀ら緵?

 _ptr_ return_address; //鍣ょ柋?蹇哥幃鐤ｈ湠, 榛╁睓妗?妗ゆ埦绀ら緵?

 FlagsRegister flags; //鐤辨报鑰?缍﹀殕閽? 榛╁睓妗?妗ゆ埦绀ら緵?
 // 娼嗭５ 铮电惃瑙?闀抽捊鐤ｇ妗婇捈鍥? 绀?闀辨粭灞﹂獏蹇勵搥妗?寰艰澗鎭?闀? (纾暢. delphi)
 // flags 绁涢┙?鐚佽灟 閾掔柋婧磋劜?璧?_dword_ 铚╅暉.


 // 瓒旈换椴５ Push 妗侀倠?鍥楀毌閽芥鐪?婧磋匠铚、 瑙愮埁绀?闀抽摓缇艰€︾枺 PUSH 娼嗭５ 瑙愮湚灏昏€?LoHook 韬炶祬
 // 闀?妗夐暠鏈︾彊蹇勯緵??瑙愮湚灏昏€遍搸 韬炶祬 绡戣湠鐪嶆€嗗睓鐪嶆硱 ?闀辩顙?WriteLoHook 妗?CreateLoHook
 // 鐤ｇ張灞?闀?铚?瑙愯澗鐤ｏ５ 绁涢┙?鐚佽灟 闀辨埦顙栫， ?鑰卞盎 ?闀辩顙?顟涢搵 瓒旈换椴?閽界枺榫涢簢?128 寰夎降鍥?
 // 闀?妗夐暠鏈︾彊蹇勯緵??瑙愮湚灏昏€遍搸 韬炶祬 绡戣湠鐪嶆€嗗睓鐪嶆硱 ?闀辩顙?WriteLoHookEx 妗?CreateLoHookEx
 // 顟涢摋 鐤ｇ張灞?绡戣湠纾€嗘鍣辫澃铮?闀抽搳鐜搷顝?闀?鎭圭彊蹇?WriteLoHookEx 妗?CreateLoHookEx.
 inline void Push(int v)
 {
	 esp -= 4;
	 *(int*)(esp) = v;
 }

 // 瓒旈换椴５ Pop 妗侀倠?鍥楀毌閽芥鐪?婧磋匠铚、 瑙愮埁绀?闀抽摓缇艰€︾枺 POP 娼嗭５ 瑙愮湚灏昏€?LoHook 韬炶祬
 inline int Pop()
 {
	 int r = *(int*)(esp);
	 esp += 4;
	 return r;
 }
};



// 鐝ュ湝灞? 蹇哥幃鐤ｎ嫅灞愵帓 瓒旈换椴ㄥ綐 鑰╁檶鍥诡帍鍣辩?闀?LoHook 韬炵墻
#define EXEC_DEFAULT 1
#define NO_EXEC_DEFAULT 0
#define SKIP_DEFAULT 0


// 鐝ュ湝灞? 蹇哥幃鐤ｎ嫅閭嬬Η?Patch::GetType()
#define PATCH_  0
#define LOHOOK_ 1
#define HIHOOK_ 2


// 鐝ュ湝灞? 闀ョ柋婧у縿灞愵帓 PatcherInstance::Write() ?PatcherInstance::CreatePatch()
#define DATA_ 0
#define CODE_ 1


// 娉€辩枺鐗濈潎?瑙屽洬?Patch
// 鑰︾師鍥?顟撶弿绁??绁涢獡??
// 闀辩顙?鎴捐澗婕?瑙屽洬瑗?PatcherInstance
class Patch
{
public:
 // 蹇哥幃鐤ｎ嫅寮?鍣ょ柋?闀?瑙愯澗鐥ょ 绡戣湠纾€嗘鍣辫澃铮?闀熻澕
 virtual _ptr_ __stdcall GetAddress() = 0; 

 // 蹇哥幃鐤ｎ嫅寮?鐤ｇ張灞?闀熻澕?
 virtual _dword_ __stdcall GetSize() = 0; 

 // 蹇哥幃鐤ｎ嫅寮?绠滄鍤徃閾?妗侊５ 顟撶弿绁?鐤?PatcherInstance, ?闀辩顙?瑙愯澗鐥ゆ硱 鐚?鑰︾師鍥?闀熻澕
 virtual char* __stdcall GetOwner() = 0;

 // 蹇哥幃鐤ｎ嫅寮?铚?闀熻澕?
 // 娼嗭５ 绀?韬炶祬 鎬﹂倛婧?PATCH_
 // 娼嗭５ LoHook 鎬﹂倛婧?LOHOOK_
 // 娼嗭５ HiHook 鎬﹂倛婧?HIHOOK_
 virtual int  __stdcall GetType() = 0;

 // 蹇哥幃鐤ｎ嫅寮?true, 缇艰厯 闀熻澕 闀虫灞欏睓 ?false, 缇艰厯 绀?
 virtual _bool_ __stdcall IsApplied() = 0;

 // 闀虫灞欙５寮?闀熻澕 
 // 蹇哥幃鐤ｎ嫅寮?>= 0 , 缇艰厯 闀熻澕/韬?闀虫灞欐ˇ? 绡戦暐願€?
 // (蹇哥幃鐤ｎ嫅灞愰搫 鐝ュ湝灞欐、 铮垫€嗭５寮? 闀?娼㈤捈顜?鐪嶆埦鐥?闀熻澕??闀辫€犻們閽煎浌鍜徃閾栬湬
 // 闀熻澕褰? 闀虫灞欏睓鐫?闀?閾岀柋鑰辩湇鑰?婧х渼閽?鍣ょ柋瑗? 楹?鐘锋湨顗?楹掕€? 
 // 铦?闀辩師绀?鐚?闀虫灞欏睓 闀熻澕)
 // 蹇哥幃鐤ｎ嫅寮?-2, 缇艰厯 闀熻澕 绠?闀虫灞欏睓
 // 缁ｇ彏鏈﹁湠?鎭归暠鑵犲睓? 鎴捐澗婧?鐤ｈ€х棨鑰辩枺绀ょ渼?闀壐铦帮５ ?鑵?
 virtual _bool_ __stdcall Apply() = 0;

    // ApplyInsert 闀虫灞欙５寮?闀熻澕 ?绠ㄥ櫥鍥楁、?闀?娼㈤捈閽?鐪嶆埦鐤??
 // 闀辫€犻們閽煎浌鍜徃閾栬湬 闀熻澕褰? 闀虫灞欏睓鐫?闀?顟涢搸?鍣ょ柋鑰?
 // 蹇哥幃鐤ｎ嫅灞愵帓 鐝ュ湝灞? 鍥楀毌閽芥鐫?鑰﹂摋蹇澃鎬忣搥妗??Patch::Apply
 // 瓒旈换椴?ApplyInsert 绁涢獡?鍥垫潮鎴剧湚閾?闀ョ柋婧ц灟 鐝ュ湝灞欐、, 蹇哥幃鐤ｎ嫅灞愰搫 
 // 瓒旈换椴ㄥ綐 Undo, 榛╅捄?闀虫灞欐牘?闀熻澕 ?铦?椹?鎴捐€? 纾?瑙愯澗鐥?铦?鐚?婕?閾楁埦绀ら緵铮?
 virtual _bool_ __stdcall ApplyInsert(int zorder) = 0;

 /////////////////////////////////////////////////////////////////////////////////////////////////////
 // 浣撹澗?Undo
 // 鎮熸埦?寮?闀熻澕(韬? (?鑰犵鍣?缇艰厯 闀熻澕 闀虫灞欏睓 闀辫€犻們榫?- 蹇歌€ㄨ湠纾€嗘鍣?鐜庤潏鐥鳖帠 瑙?
 // 楠傜幃鐤ｎ嫅寮?楹掕€?>= 0, 缇艰厯 闀熻澕(韬? 鐚?閾楁埦绀?绡戦暐願€?
 // (蹇哥幃鐤ｎ嫅灞愰搫 鐝ュ湝灞欐、 铮垫€嗭５寮? 鐪嶆埦鐥?闀熻澕??闀辫€犻們閽煎浌鍜徃閾栬湬
 // 闀熻澕褰? 闀虫灞欏睓鐫?闀?婧х渼閾?鍣ょ柋鑰? 楹?鐘锋湨顗?楹掕€? 
 // 铦?闀辩師绀?鐚?闀虫灞欏睓 闀熻澕)
 // 楠傜幃鐤ｎ嫅寮?-2, 缇艰厯 闀熻澕 ?铚?绠?鐚?閾楁埦绀?(绀?鐚?闀虫灞欏睓)
 // 缁ｇ彏鏈﹁湠?鎭归暠鑵犲睓? 鎴捐澗婧?鐤ｈ€х棨鑰辩枺绀ょ渼?闀壐铦帮５ ?鑵?
 virtual _bool_ __stdcall Undo() = 0;


 /////////////////////////////////////////////////////////////////////////////////////////////////////
 // 浣撹澗?Destroy
 // 鑵昏€辩椉鐗濋摃
 // 鎮熸埦?寮??寰ㄧ幃閾夋€靛浌鐪?绠滄铦鹃┑寮?闀熻澕/韬?
 // 蹇哥幃鐤ｎ嫅寮?鎬﹂倛婧?1 (娼嗭５ 鑰﹀开缇艰湬绁涜€??鐘疯劜?鐤ｇ渼妗?蹇槂?鎵?寰肩姯妗€铦堣)
 // 缁ｇ彏鏈﹁湠?绠滄铦鹃┙榫涳５ 鐤ｈ€х棨鑰辩枺绀ょ渼?闀壐铦帮５ ?鑵?
 virtual _bool_ __stdcall Destroy() = 0;

 /////////////////////////////////////////////////////////////////////////////////////////////////////
 // 浣撹澗?GetAppliedBefore
 // 蹇哥幃鐤ｎ嫅寮?闀熻澕 闀虫灞欏睓鐫?闀ョ柋?婧х渼顜?
 // 蹇哥幃鐤ｎ嫅寮?NULL 缇艰厯 婧х渼顜?闀熻澕 闀虫灞欏睓 闀ョ柎顜?
 virtual Patch* __stdcall GetAppliedBefore() = 0;

 /////////////////////////////////////////////////////////////////////////////////////////////////////
 // 浣撹澗?GetAppliedAfter
 // 蹇哥幃鐤ｎ嫅寮?闀熻澕 闀虫灞欏睓鐫?闀辫€?婧х渼閽?
 // 蹇哥幃鐤ｎ嫅寮?NULL 缇艰厯 婧х渼顜?闀熻澕 闀虫灞欏睓 闀辫€犻們榫?
 virtual Patch* __stdcall GetAppliedAfter() = 0;

};


// 娉€辩枺鐗濈潎?瑙屽洬?LoHook (绠滃洬鑴叉紩蹇?閾?Patch, ?? 闀?鑰嬭湬 鑵?韬?铮垫€嗭５寮? 闀熻澕灞?
// 鑰︾師鍥?顟撶弿绁??绁涢獡??
// 闀辩顙?鎴捐澗婕?瑙屽洬瑗?PatcherInstance
class LoHook : public Patch
{
};


typedef int(__stdcall *_LoHookFunc_)(LoHook*, HookContext*);


// 鐝ュ湝灞? 闀ョ柋婧у縿灞愵帓 璧?鍥垫潮鎴剧湚 hooktype ?PatcherInstance::WriteHiHook ?PatcherInstance::CreateHiHook
#define CALL_ 0
#define SPLICE_ 1
#define FUNCPTR_ 2

// 鐝ュ湝灞? 闀ョ柋婧у縿灞愵帓 璧?鍥垫潮鎴剧湚 subtype ?PatcherInstance::WriteHiHook ?PatcherInstance::CreateHiHook
#define DIRECT_  0
#define EXTENDED_ 1
#define SAFE_  2

// 鐝ュ湝灞? 闀ョ柋婧у縿灞愵帓 璧?鍥垫潮鎴剧湚 calltype ?PatcherInstance::WriteHiHook ?PatcherInstance::CreateHiHook
#define ANY_  0
#define STDCALL_ 0
#define THISCALL_ 1
#define FASTCALL_ 2 
#define CDECL_  3
#define FASTCALL_1 1 

// 娉€辩枺鐗濈潎?瑙屽洬?HiHook (绠滃洬鑴叉紩蹇?閾?Patch, ?? 闀?鑰嬭湬 韪?韬?铮垫€嗭５寮? 闀熻澕灞?
// 鑰︾師鍥?顟撶弿绁??绁涢獡??闀辩顙?鎴捐澗婕?瑙屽洬瑗?PatcherInstance
class HiHook : public Patch
{
public:
 // 蹇哥幃鐤ｎ嫅寮?绠ㄥ櫥鍥瑰挮?纾?瓒旈换椴?(纾?绁涜€??瓒旈换椴??鑰犵鍣?SPLICE_),
 // 鐜庢埦顙栫渼绨?韬炶?
 // 椹鍥楁、! 钄撶惃蹇勶５ 瓒旈换椴?娼嗭５ 绀?闀虫灞欏睓鐪嶆硱 韬炶祬, 绁涢獡?闀卞楹掕灟
 // 绀ゅ殦铦毌顝搁搫 (鐪?鐤ｇ姺楹? 鐝ュ湝灞欐、.
 virtual _ptr_ __stdcall GetDefaultFunc() = 0;

 // 蹇哥幃鐤ｎ嫅寮?绠ㄥ櫥鍥瑰挮?纾?閾曟　妗у毌顝哥皨 瓒旈换椴?(纾?绁涜€??瓒旈换椴??鑰犵鍣?SPLICE_),
 // 鐜庢埦顙栫渼绨?韬炶?韬炶祬鎵? 闀?婧х渼閾?鍣ょ柋鑰?
 // (?? 蹇哥幃鐤ｎ嫅寮?GetDefaultFunc() 娼嗭５ 闀ョ柎閽?闀虫灞欏睓鐪嶆硱 韬炶祬 闀?婧х渼閾?鍣ょ柋鑰?
 // 椹鍥楁、! 钄撶惃蹇勶５ 瓒旈换椴?娼嗭５ 绀?闀虫灞欏睓鐪嶆硱 韬炶祬, 绁涢獡?闀卞楹掕灟
 // 绀ゅ殦铦毌顝搁搫 (鐪?鐤ｇ姺楹? 鐝ュ湝灞欐、.
 virtual _ptr_ __stdcall GetOriginalFunc() = 0;

 // 蹇哥幃鐤ｎ嫅寮?鍣ょ柋?蹇哥幃鐤ｈ湠 ?閾曟　妗у毌顝割帠 瑙?
 // 绁涢獡?妗夐暠鏈︾彊蹇勮灟 蹇瘉鐥?韬?瓒旈换椴?
 // SPLICE_ EXTENDED_ 妗?SAFE_ 韬炶祬, 榛╅捄?绠哥，铻?閾楃墻婧?閾?鐚佽睔 鎭圭幃鍥?
 // 娼嗭５ SPLICE_ DIRECT_ 韬炶祬 瓒旈换椴５ 蹇哥幃鐤ｎ嫅寮?鎬﹂倛婧?0 (?? 娼嗭５ DIRECT_ 韬炶祬 蹇哥張閾堢湇鑰?绠哥，铻?鍣ょ柋?蹇哥幃鐤ｈ湠 楹囩柋?绀?- 绀?
 virtual _ptr_ __stdcall GetReturnAddress() = 0;


 //# ver 2.1
 // 绡戣湠纾€嗘鍣?鐝ュ湝灞欐、 闀辨湨鐝欏縿铦堟湨鑰滄〈 婧х渼顜?韬炶祬
 virtual void __stdcall SetUserData(_dword_ data) = 0;
 // 蹇哥幃鐤ｎ嫅寮?鐝ュ湝灞欐、 闀辨湨鐝欏縿铦堟湨鑰滄〈 婧х渼顜?韬炶祬
 // 缇艰厯 绀?鐜庢骇鐪?闀辨湨鐝欏縿铦堣劜? 铦?鐤ｅ凯?0
 virtual _dword_ __stdcall GetUserData() = 0;
};


// 娉€辩枺鐗濈潎?瑙屽洬?PatcherInstance
// 鑰︾師鍥?闀卞楹掕灟 顟撶弿绁??绁涢獡??闀辩顙?鎴捐澗婕?CreateInstance ?GetInstance 瑙屽洬瑗?Patcher
// 绀ら暠鑰╅們鑰卞慨鐪?闀辩幃閾嶏５寮?鑰︾師鍣斿浌?绡戣湠纾€嗘鍥?闀熻澕??韬炶 ?瑙?
// 婕曞緣鎬嗭５铮?妗??婧寸柋蹇?鎬﹁壌 闀熻澕褰?韬炶? 鑰︾師鍥楃潎?寰肩姯妗€铦堣?patcher_x86.dll
class PatcherInstance
{
public:
 ////////////////////////////////////////////////////////////
 // 浣撹澗?WriteByte
 // 闀壐?閽跨２鍤呰澗蹇?楹掕€?闀?鍣ょ柋鑰?address
 // (鑰︾師鍣??闀虫灞欙５寮?DATA_ 闀熻澕)
 // 楠傜幃鐤ｎ嫅寮?绠ㄥ櫥鍥瑰挮?纾?闀熻澕
 virtual Patch* __stdcall WriteByte(_ptr_ address, int value) = 0;
 
 ////////////////////////////////////////////////////////////
 // 浣撹澗?WriteWord
 // 闀壐?婧荤瘹寰夎降閽奸搫 楹掕€?闀?鍣ょ柋鑰?address
 // (鑰︾師鍣??闀虫灞欙５寮?DATA_ 闀熻澕)
 // 楠傜幃鐤ｎ嫅寮?绠ㄥ櫥鍥瑰挮?纾?闀熻澕
 virtual Patch* __stdcall WriteWord(_ptr_ address, int value) = 0;
 
 ////////////////////////////////////////////////////////////
 // 浣撹澗?WriteDword
 // 闀壐?楹囪灀鐤辫附鍤呰澗蹇?楹掕€?闀?鍣ょ柋鑰?address
 // (鑰︾師鍣??闀虫灞欙５寮?DATA_ 闀熻澕)
 // 楠傜幃鐤ｎ嫅寮?绠ㄥ櫥鍥瑰挮?纾?闀熻澕
 virtual Patch* __stdcall WriteDword(_ptr_ address, int value) = 0;
 
 ////////////////////////////////////////////////////////////
 // 浣撹澗?WriteJmp
 // 闀壐?jmp to 閾掕?闀?鍣ょ柋鑰?address
 // (鑰︾師鍣??闀虫灞欙５寮?CODE_ 闀熻澕)
 // 楠傜幃鐤ｎ嫅寮?绠ㄥ櫥鍥瑰挮?纾?闀熻澕
 // 闀熻澕 鐜庣壆顜忓櫛?椴ヨ叐?瑙愯厯楹囪€卞扛 閾掕婕?
 // ?? 鐤ｇ張灞?闀熻澕?>= 5, 鐤ｇ彞妗?鐜庨暠鑵狅５铦? NOP'鍥? 
 virtual Patch* __stdcall WriteJmp(_ptr_ address, _ptr_ to) = 0;
 
 ////////////////////////////////////////////////////////////
 // 浣撹澗?WriteHexPatch
 // 闀壐?闀?鍣ょ柋鑰?address 闀辩弶閭冮捈鍥瑰挮顝搁摉铻?寰夎降,
 // 閾掔柋婧磋劜鐪勭皨 hex_str
 // (鑰︾師鍣??闀虫灞欙５寮?DATA_ 闀熻澕)
 // 楠傜幃鐤ｎ嫅寮?绠ㄥ櫥鍥瑰挮?纾?闀熻澕
 // hex_str - 鑰?鑰辩棨璧?绁涢┙?鑰︽捍鐤板浌?顗歌€辩，婕╁浌灞︽鐫?椴ㄩ捍?
 // 0123456789ABCDEF (铦炬湨瑙?蹇槓榫?鐤辨报鑰?) 閾栬湠鏈︾潎?鑰旂剺閾?
 // 闀?榛╁睓姊?鎴捐澗婕?hex_str 妗＄湇鐥傜椉顠?(闀抽搾绡戣祬顠?)
 // 绠愰捄鐪?妗夐暠鏈︾彊蹇勮灟 ?璧呴簢鑰卞慨 鍥垫潮鎴剧湚?顟涢捊?鎴捐澗婧?
 // 鑰滈搾妗婇捈鍥楃湇??闀辩顙?Binary copy ?OllyDbg
 /* 闀虫灞?
   pi->WriteHexPatch(0x57b521, "6A 01  6A 00");
 */
 virtual Patch* __stdcall WriteHexPatch(_ptr_ address, char* hex_str) = 0;
 
 ////////////////////////////////////////////////////////////
 // 浣撹澗?WriteCodePatchVA
 // ?閾曟　妗у毌顝搁搸 蹇ゆ捍 闀虫灞欏睓妗?鎴捐澗婧?绀?闀抽們闀辫睔姹斿吉?,
 // 鑰㈤摋鐥傝潏 (榫涢┙) 閾掓鍥楁、 鎴捐澗婧?閽洪搷閾熻 WriteCodePatch
 virtual Patch* __stdcall WriteCodePatchVA(_ptr_ address, char* format, _dword_* va_args) = 0;
 
 ////////////////////////////////////////////////////////////
 // 浣撹澗?WriteLoHook
 // 鑰︾師鍣?闀?鍣ょ柋鑰?address 榫涚弨閾欑棨蹇倐顜?韬?(CODE_ 闀熻澕) ?闀虫灞欙５寮?閭?
 // 蹇哥幃鐤ｎ嫅寮?绠ㄥ櫥鍥瑰挮?纾?韬?
 // func - 瓒旈换椴５ 鎭圭惃蹇勫睈? 闀?鑰╁檶鍥诡帍鍥楁 韬炶祬
 // 婕曡厛纾?妗佸吉?蹇?int __stdcall func(LoHook* h, HookContext* c);
 // ?HookContext* c 闀ョ柋婧ь捁? 娼嗭５ 榛╁睓?/妗ゆ埦绀ら緵铮?
 // 鐤辨报鑰辩槬 闀抽摓缇艰€︾枺 ?鍣ょ柋?蹇哥幃鐤ｈ湠
 // 缇艰厯 func 蹇哥幃鐤ｎ嫅寮?EXEC_DEFAULT, 铦?
 // 闀辫€?鐜庡慨鐦屽睓? func 鎭归暠鑵狅５寮? 鐜庤潏鐥鳖帠 韬炶?瑙?
 // 缇艰厯 - SKIP_DEFAULT - 鐜庤潏鐥鳖帠 瑙?绀?鎭归暠鑵狅５寮?
 //
 // 宄﹀繊鍔虫壈! 
 // 鐤ｇ張灞?闀?铚? 瑙愯澗鐤ｏ５ 绁涢┙?鐚佽灟 闀辨埦顙栫， ?鑰卞盎 瑙愮湚灏昏€?
 // ?闀辩顙?妗夐暠鏈︾彊蹇勯緵铮?c->esp ??>Push, 閽界枺榫涢簢?128 寰夎降鍥?
 // 缇艰厯 铦犻伣绠﹁澃铮?妗ч搫 閽界枺榫涢簢榫?妗夐暠鏈︾彏杞?鎴捐澗?WriteLoHookEx 妗?CreateLoHookEx.
 virtual LoHook* __stdcall WriteLoHook(_ptr_ address, _LoHookFunc_ func) = 0;
 
 ////////////////////////////////////////////////////////////
 // 浣撹澗?WriteHiHook
 // 鑰︾師鍣?闀?鍣ょ柋鑰?address 鎭硅€﹁绠撮捈绀ゆ伖?韬??闀虫灞欙５寮?閭?
 // 蹇哥幃鐤ｎ嫅寮?绠ㄥ櫥鍥瑰挮?纾?韬?
 //
 // new_func - 瓒旈换椴５ 鐜庢埦顙戭搥? 閾曟　妗у毌顝哥皨
 //
 // hooktype - 铚?韬炶祬:
 //  CALL_ -  韬?灞?璁轰繌?瓒旈换椴?闀?鍣ょ柋鑰?address
 //     闀辨粭灞﹂獏蹇勵捁? 閾掕娼?E8 ?FF 15, ?閾栬湠鏈︾潎?鑰犵??韬?绀?绡戣湠纾€嗘鍣辫澃铮?
 //     ??鑵?闀壐铦帮５ 妗х簺鐥ㄥ湁? 閽?顟涢搵 閾犳牫璧?
 //  SPLICE_ - 韬?绀ら暠鑰╅們鑰卞慨鐪?灞?鐗欓€?鏉傝お绉?闀?鍣ょ柋鑰?address
 //  FUNCPTR_ - 韬?纾?瓒旈换椴??绠ㄥ櫥鍥瑰挮?(闀虫灞欙５寮? 鐤辨舰? ?閾栫湇蹇搸 娼嗭５ 韬炶??铚炵姯妗峰湂 妗侀暠鐥?
 //
 // subtype - 闀辨綃鏍?韬炶祬:
 //  DIRECT_ - new_func 妗侀倠?铦?椹?蹇?榛??
 //     閾曟　妗у毌顝? 鐜庢埦顙戝睈? 瓒旈换椴５
 //     闀虫楝诲洍妗? 蹇炯铦?__thiscall f(this) 
 //        绁涢獡?妗夐暠鏈︾彊蹇勮灟 __fastcal f(this_)
 //        蹇炯铦?__thiscall f(this, ...)  绁涢獡?妗夐暠鏈︾彊蹇勮灟 
 //        __fastcall f(this_, no_used_edx, ...) 
 //  EXTENDED_ - 瓒旈换椴?new_func 闀ョ柎顜?鑰卞盎閽碱帣 鍥垫潮鎴剧湚閾?闀ョ柋婧у吉?
 //     绠ㄥ櫥鍥瑰挮?纾?顟撶弿绁??HiHook ? ?鑰犵鍣?
 //     鑰︽倍甯忓睓鏍?妗夎簠婕ら搵 ?姊?__thiscall ?__fastcall
 //     鐤辨报鑰辩棨鎭?鍥垫潮鎴剧湚?闀ョ柋婧ь捁? 鑰卞盎閽碱帣?鎬涢摃顜?
 // 浜﹁?閽虹枺鐝?瓒旈换椴５ new_func 婕曡厛纾?妗佸吉?蹇?
 // ? __stdcall new_func(HiHook* hook, ?) 娼嗭５ ? ? orig(?)
 //
 // 宄﹀繊鍔虫壈! EXTENDED_ FASTCALL_ 闀辨粭灞﹂獏蹇勫吉 铦炬湨瑙?瓒旈换椴??2-? ?鐘疯劜?鍥垫潮鎴剧湚鍥?
 // 娼嗭５ __fastcall c 1 鍥垫潮鎴剧湚閾?妗夐暠鏈︾彏杞?EXTENDED_ FASTCALL_1 / EXTENDED_ THISCALL_
 //
 //   SAFE_ - 铦?椹?瑗︾?榛??EXTENDED_, 閽跨，瑙?闀ョ柋?鎭圭彊蹇?(纾?鎬靛睈铮?鎭圭彊蹇? GetDefaultFunc() 蹇歌€ㄨ湠纾€嗘甯艰澃铮?
 //    鐝ュ湝灞? 鐤辨报鑰辩棨?闀抽摓缇艰€︾枺 EAX, ECX (缇艰厯 绀?FASTCALL_ ?绀?THISCALL_),
 //    EDX (缇艰厯 绀?FASTCALL_), EBX, ESI, EDI, 鐚佹€挎、 纾?绁涙埦鐪?鎭圭彊蹇?鐜庢埦顙栫渼閾?瓒旈换椴?
 //
 //  ?闀辨骇鎬嗭５顡€灞?鐘锋湨顗荤湀铚?鑰犵鍣?绠愰捄绀?妗夐暠鏈︾彊蹇勮灟 EXTENDED_
 //  鐪?DIRECT_ 鎭归暠鑵狅５寮? 鐚佽€辩柋?妗?鐜?閾楄€嬭湲? 绁涜€??鐪嶅扛?鐜庢埦顙戭搥褰?瓒旈换椴?
 //
 // calltype - 鑰︽倍甯忓睓妗??鎭圭彊蹇?閾曟　妗у毌顝搁搵 鐜庢埦顙戝睈閾??姊?
 //  STDCALL_
 //  THISCALL_
 //  FASTCALL_
 //  CDECL_
 // 绀ら捄韬呮粋绁?蹇棪?绠ㄥ櫥顜忓浌?鑰︽倍甯忓睓妗?娼嗭５ 铦炬硱 榛╅捄?EXTENDED_ 韬?闀冲檾妗︻徃?
 // 闀辫€辩棨妗?绁涜€??鐪嶅扛?鐜庢埦顙戭搥褰?瓒旈换椴?
 //
 // CALL_, SPLICE_ 韬?铮垫€嗭５寮? CODE_ 闀熻澕灞?
 // FUNCPTR_ 韬?铮垫€嗭５寮? DATA_ 闀熻澕灞?
 //
 virtual HiHook* __stdcall WriteHiHook(_ptr_ address, int hooktype, int subtype, int calltype, void* new_func) = 0;

 ///////////////////////////////////////////////////////////////////
 // 浣撹澗娼?Create...
 // 鑰︾師甯?闀熻澕/韬?铚?椹?璧??鑰﹂摋蹇澃铚皨顙?鎴捐澗娼?Write...,
 // 鐪?鍥?闂插繊纾愬捒?閭?
 // 蹇哥幃鐤ｎ嫅顠?绠ㄥ櫥鍥瑰挮?纾?闀熻澕/韬?
 virtual Patch* __stdcall CreateBytePatch(_ptr_ address, int value) = 0;
 virtual Patch* __stdcall CreateWordPatch(_ptr_ address, int value) = 0;
 virtual Patch* __stdcall CreateDwordPatch(_ptr_ address, int value) = 0;
 virtual Patch* __stdcall CreateJmpPatch(_ptr_ address, _ptr_ to) = 0;
 virtual Patch* __stdcall CreateHexPatch(_ptr_ address, char* hex_str) = 0;
 virtual Patch* __stdcall CreateCodePatchVA(_ptr_ address, char* format, _dword_* va_args) = 0;
 virtual LoHook* __stdcall CreateLoHook(_ptr_ address, void* func) = 0;
 virtual HiHook* __stdcall CreateHiHook(_ptr_ address, int hooktype, int subtype, int calltype, void* new_func) = 0;
 
 ////////////////////////////////////////////////////////////
 // 浣撹澗?ApplyAll
 // 闀虫灞欙５寮?鎬?闀熻澕?韬炶, 鑰︾師鍥楃潎?顟涙 顟撶弿绁?鐥?PatcherInstance
 // 鎬﹂倛婧?蹇哥幃鐤ｎ嫅寮?1 (娼嗭５ 鑰﹀开缇艰湬绁涜€??鐘疯劜?鐤ｇ渼妗?蹇槂?鎵?寰肩姯妗€铦堣)
 // (鑰? Patch::Apply)
 virtual _bool_ __stdcall ApplyAll() = 0;

 ////////////////////////////////////////////////////////////
 // 浣撹澗?UndoAll
 // 閾楁埦?寮?鎬?闀熻澕?韬炶, 鑰︾師鍥楃潎?顟涙 顟撶弿绁?鐥?PatcherInstance
 // ?? 娼嗭５ 璧呴┛閽?妗?闀熻澕褰?韬炶?鎭圭惃蹇勫吉 鎴捐澗?Undo
 // 鎬﹂倛婧?蹇哥幃鐤ｎ嫅寮?1 (娼嗭５ 鑰﹀开缇艰湬绁涜€??鐘疯劜?鐤ｇ渼妗?蹇槂?鎵?寰肩姯妗€铦堣)
 // (鑰? Patch::Undo)
 virtual _bool_ __stdcall UndoAll() = 0;

 ////////////////////////////////////////////////////////////
 // 浣撹澗?DestroyAll
 // 閾楁埦?寮??寰ㄧ幃閾夋€靛浌鐪?绠滄铦鹃┑寮?鎬?闀熻澕?韬炶, 鑰︾師鍥楃潎?顟涙 顟撶弿绁?鐥?PatcherInstance
 // ?? 娼嗭５ 璧呴┛閽?妗?闀熻澕褰?韬炶?鎭圭惃蹇勫吉 鎴捐澗?Destroy
 // 鎬﹂倛婧?蹇哥幃鐤ｎ嫅寮?1 (娼嗭５ 鑰﹀开缇艰湬绁涜€??鐘疯劜?鐤ｇ渼妗?蹇槂?鎵?寰肩姯妗€铦堣)
 // (鑰? Patch::Destroy)
 virtual _bool_ __stdcall DestroyAll() = 0;

 // ?閾曟　妗у毌顝搁搸 蹇ゆ捍 闀虫灞欏睓妗?鎴捐澗婧?绀?闀抽們闀辫睔姹斿吉?,
 // 鑰㈤摋鐥傝潏 (榫涢┙) 閾掓鍥楁、 鎴捐澗婧?閽洪搷閾熻 WriteDataPatch
 virtual Patch* __stdcall WriteDataPatchVA(_ptr_ address, char* format, _dword_* va_args);
 // ?閾曟　妗у毌顝搁搸 蹇ゆ捍 闀虫灞欏睓妗?鎴捐澗婧?绀?闀抽們闀辫睔姹斿吉?,
 // 鑰㈤摋鐥傝潏 (榫涢┙) 閾掓鍥楁、 鎴捐澗婧?閽洪搷閾熻 WriteDataPatch
 virtual Patch* __stdcall CreateDataPatchVA(_ptr_ address, char* format, _dword_* va_args);


 // 浣撹澗?GetLastPatchAt
 // 蹇哥幃鐤ｎ嫅寮?NULL, 缇艰厯 ?閾岀柋鑰辩湇鑰?鍣ょ柋瑗?address 绀?鐚?闀虫灞欏睓 榫?閽挎¨ 闀熻澕/韬?
 // 鑰︾師鍥楃潎?婧х渼顜?顟撶弿绁?鐥?PatcherInstance
 // 妗у湝?蹇哥幃鐤ｎ嫅寮?闀辫€犻們榫?闀虫灞欏睓顜?闀熻澕/韬??閾岀柋鑰辩湇鑰?鍣ょ柋瑗?address,
 // 鑰︾師鍥楃潎?婧х渼顜?顟撶弿绁?鐥?PatcherInstance
 virtual Patch* __stdcall GetLastPatchAt(_ptr_ address) = 0;

 // 浣撹澗?UndoAllAt
 // 閾楁埦?寮?闀熻澕?闀虫灞欏睓鐫?婧х渼顜?顟撶弿绁?鐥?PatcherInstance
 // ?閾岀柋鑰辩湇鑰?鍣ょ柋瑗?address 
 // 鎬﹂倛婧?蹇哥幃鐤ｎ嫅寮?1 (娼嗭５ 鑰﹀开缇艰湬绁涜€??鐘疯劜?鐤ｇ渼妗?蹇槂?鎵?寰肩姯妗€铦堣)
 // (鑰? Patch::Undo)
 virtual _bool_ __stdcall UndoAllAt(_ptr_ address) = 0;

 // 浣撹澗?GetFirstPatchAt
 // 蹇哥幃鐤ｎ嫅寮?NULL, 缇艰厯 ?閾岀柋鑰辩湇鑰?鍣ょ柋瑗?address 绀?鐚?闀虫灞欏睓 榫?閽挎¨ 闀熻澕/韬?
 // 鑰︾師鍥楃潎?婧х渼顜?顟撶弿绁?鐥?PatcherInstance
 // 妗у湝?蹇哥幃鐤ｎ嫅寮?闀ョ柎顜?闀虫灞欏睓顜?闀熻澕/韬??閾岀柋鑰辩湇鑰?鍣ょ柋瑗?address,
 // 鑰︾師鍥楃潎?婧х渼顜?顟撶弿绁?鐥?PatcherInstance
 virtual Patch* __stdcall GetFirstPatchAt(_ptr_ address) = 0;


 ////////////////////////////////////////////////////////////
 // 浣撹澗?Write
 // 闀壐?闀?鍣ょ柋鑰?address 婧х渼顜?瑙?妗?闀?铚?闀?鍣ょ柋鑰?data 鐤ｇ張灞﹂搸 size 寰夎降 
 // 缇艰厯 is_code == 1, 铦?鑰︾師鍣辫澃铮??闀壐铦帮５ CODE_ 闀熻澕, 缇艰厯 0 - DATA_ 闀熻澕.
 // 楠傜幃鐤ｎ嫅寮?绠ㄥ櫥鍥瑰挮?纾?闀熻澕
 virtual Patch* __stdcall Write(_ptr_ address, _ptr_ data, _dword_ size, _bool_ is_code = 0) = 0;
 ///////////////////////////////////////////////////////////////////
 // 浣撹澗?CreatePatch
 // 鑰︾師鍠?闀熻澕 铚?椹?璧??鎴捐澗?Write,
 // 鐪?鍥?闂插繊纾愬惒?閭?
 // 蹇哥幃鐤ｎ嫅顠?绠ㄥ櫥鍥瑰挮?纾?闀熻澕
 virtual Patch* __stdcall CreatePatch(_ptr_ address, _ptr_ data, _dword_ size, _bool_ is_code = 0) = 0;


 //## ver 2.1
  ////////////////////////////////////////////////////////////
 // 浣撹澗?WriteLoHookEx
 // 鍥楀毌閽芥灞?鎴捐澗娼?WriteLoHook, 鐪?妗侀倠?婕曢暠鑵犳牘鍜徃顜?鍥垫潮鎴剧湚
 // stack_delta - 鐤ｇ張灞?闀?铚?瑙愯澗鐦?绁涢獡?闀辨埦鑰辨牘??鑰鳖憮 瑙愮湚灏昏€?
 // 妗夐暠鏈︾彏铮?HookContext::esp ?HookContext::Push 蹇瘉鐥?func.
 //
 // 楠傜幃鐤ｎ嫅顠?绠ㄥ櫥鍥瑰挮?纾?LoHook 韬?
 virtual LoHook* __stdcall WriteLoHookEx(_ptr_ address, void* func, _dword_ stack_delta) = 0;
 // 浣撹澗?CreateLoHookEx
 // 鑰︾師鍣?韬?铚?椹?璧??WriteLoHookEx,
 // 鐪?鍥?闂插繊纾愬惒?閭?
 // 楠傜幃鐤ｎ嫅顠?绠ㄥ櫥鍥瑰挮?纾?LoHook 韬?
 virtual LoHook* __stdcall CreateLoHookEx(_ptr_ address, void* func, _dword_ stack_delta) = 0;


 // ?閾曟　妗у毌顝搁搸 蹇ゆ捍 闀虫灞欏睓妗?鎴捐澗婧?绀?闀抽們闀辫睔姹斿吉?,
 // 鑰㈤摋鐥傝潏 (榫涢┙) 閾掓鍥楁、 鎴捐澗婧?閽洪搷閾熻 WriteHexHook
 virtual LoHook* __stdcall WriteHexHookVA(_ptr_ address, _bool_ exec_default, char* hex_str, _dword_* va_args) = 0;
 // ?閾曟　妗у毌顝搁搸 蹇ゆ捍 闀虫灞欏睓妗?鎴捐澗婧?绀?闀抽們闀辫睔姹斿吉?,
 // 鑰㈤摋鐥傝潏 (榫涢┙) 閾掓鍥楁、 鎴捐澗婧?閽洪搷閾熻 CreateHexHook
 virtual LoHook* __stdcall CreateHexHookVA(_ptr_ address, _bool_ exec_default, char* hex_str, _dword_* va_args) = 0;



 // 鎴捐澗?BlockAt 绡戣湠纾€嗘鍣?鐘搶 纾?閾掔柋婧磋劜鐪勵帠 鍣ょ柋?(妗佸睓鐪?纾?瑙愰换鐤辫澖顜?鍣ょ柋??绀?纾?閾岀柋鑰辩湇鑰?
 // 娼嗭５ 婧х渼閽?顟撶弿绁?鐤?PatcherInstance
 // 闀辫€?楹囨硱 婧х渼顜?顟撶弿绁??PatcherInstance 绀?绁涢┙?闀虫灞欙５铻?
 // 闀熻澕?闀?顟涢搸?鍣ょ柋鑰?
 virtual void __stdcall BlockAt(_ptr_ address) = 0;

 //## ver 2.6

 // 鎴捐澗?BlockAllExceptVA 绡戣湠纾€嗘鍣?鐘搶 纾?鎬?鍣ょ柋瑗?鐗搸?绠ㄥ櫥鍥楃潎??va_args
 // 铚?椹?璧??鎴捐澗?BlockAt 閾掑宝妗婄?瑙愰换鐤辫澖顜?鍣ょ柋瑗︽増 ?绀?閾岀柋鑰辩湇鑰憋５鎵?
 // 娼嗭５ 婧х渼閽?顟撶弿绁?鐤?PatcherInstance
 // 闀辫€?楹囨硱 婧х渼顜?顟撶弿绁??PatcherInstance 绀?绁涢┙?闀虫灞欙５铻?
 // 闀熻澕?闀?鎬﹀睈 鍣ょ柋瑗?鐗搸?绠ㄥ櫥鍥楃潎?
 // 鑰ф閾?鍣ょ柋鑰??va_args 婕曡厛灞?鐜庤祬鐪垫鍥诡徏铮?0 (鐪㈣劜?
 virtual void __stdcall BlockAllExceptVA(_dword_ *va_args) = 0;


 //## ver 4.0
 // ?閾曟　妗у毌顝搁搸 蹇ゆ捍 闀虫灞欏睓妗?鎴捐澗婧?绀?闀抽們闀辫睔姹斿吉?,
 // 鑰㈤摋鐥傝潏 (榫涢┙) 閾掓鍥楁、 鎴捐澗婧?閽洪搷閾熻 WriteAsmPatch
 virtual Patch* __stdcall WriteAsmPatchVA(_ptr_ address, _dword_* va_args) = 0;

 // ?閾曟　妗у毌顝搁搸 蹇ゆ捍 闀虫灞欏睓妗?鎴捐澗婧?绀?闀抽們闀辫睔姹斿吉?,
 // 鑰㈤摋鐥傝潏 (榫涢┙) 閾掓鍥楁、 鎴捐澗婧?閽洪搷閾熻 CreateAsmPatch
 virtual Patch* __stdcall CreateAsmPatchVA(_ptr_ address, _dword_* va_args) = 0;

 // ?閾曟　妗у毌顝搁搸 蹇ゆ捍 闀虫灞欏睓妗?鎴捐澗婧?绀?闀抽們闀辫睔姹斿吉?,
 // 鑰㈤摋鐥傝潏 (榫涢┙) 閾掓鍥楁、 鎴捐澗婧?閽洪搷閾熻 WriteAsmHook
 virtual LoHook* __stdcall WriteAsmHookVA(_ptr_ address, _dword_* va_args) = 0;

 // ?閾曟　妗у毌顝搁搸 蹇ゆ捍 闀虫灞欏睓妗?鎴捐澗婧?绀?闀抽們闀辫睔姹斿吉?,
 // 鑰㈤摋鐥傝潏 (榫涢┙) 閾掓鍥楁、 鎴捐澗婧?閽洪搷閾熻 CreateAsmHook
 virtual LoHook* __stdcall CreateAsmHookVA(_ptr_ address, _dword_* va_args) = 0;


 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // WriteAsmPatch 闀壐?闀熻澕 闀?鍣ょ柋鑰?address
 // 蹇哥幃鐤ｎ嫅e?绠ㄥ櫥鍥瑰挮?纾?闀熻澕
 // 鍥垫潮鎴剧湚?... - 顟?鑰辩棨瑙? 鑰︽捍鐤板笝妗?瑙?纾?鍥毚鐏劜鐤?
 // 鐤ｈ€ч搲纾捁? 鎬?妗ц€辩椉鐗挎, 鐤ｈ€ч搲纾縿灞愵帓 OllyDbg 1.04 (鎬欒叐铻?婕?MMX ?amd 3DNow! 鎬呰喕楹掕潏鏈︾湇)
 // 宄﹀繊鍔虫壈! ?閾楄厯楹?閾?OllyDbg, 椴ヨ噷?楹掕€?绀?妗佸Γ顙?闀冲辑妗曡ウ 0x 妗?闀辫€辩砍鐘?h 楹掕湠顠? 璧?鍛愬牥閬楄叆娣勫彑!
 // 闀鳖憶閾?绀?鐜庣寔蹇勮降?闀ㄨウ铻?顗歌€ュ櫎椴熻潏鐥傞粶顜?楹掕€?铮靛凯?
 // ?閽跨湇?鑰辩棨璧?绁涢┙?鐚佽灟 绀よ€滈搷顝?妗ц€辩椉鐗挎牆, 鐤ｇ師鍜睓鐫?鑰旂剺閾嶉搸 ';'
 // 鏆?纾?鍥毚鐏劜鐤?绁涢┙?鑰︽捍鐤板浌?鎴捐溈?
 // 閽?鎬嗗睓妗?鎴捐溈?- label_name: (妗侊５ 鎴捐溈? 婧婚搫铦鹃簰?,
 // 妗夐暠鏈︾彊蹇勯緵?label_name (妗侊５ 寰?婧婚搫铦鹃簰铮?;
 // 鐖ㄧ姛妗佸毌顝? 娼嗘¨?妗佸睓?鎴捐溈?- 39 鑰旂剺閾嶉捈, 妗侊５ 绁涢┙?鑰︽捍鐤板浌?鐙嶈祱? 椴ㄩ捍? 鑰旂剺閾?'_' ?'.';
 // 瑙?绁涢┙?鑰︽捍鐤板浌?閿洪倐婕曟¨鑰辩椉鐗挎９ times (闀壐?鐜庢骇鐪勯搫 瑙愯厯楹囪€卞扛 鐤?鑰犻們绨嬵嫟?妗ц€辩椉鐗挎９)
 // 纾暢妗佸宝, 鐤辩彏鏈﹁湠铦?"times 3 nop" 鐙嶆捍?瑙?90 90 90
 // 瑙?绁涢┙?鑰︽捍鐤板浌?閿洪倐婕曟¨鑰辩椉鐗挎９ _ExecCopy <鍣ょ柋?, <鐤ｇ張灞? (闀壐?瑙?妗?闀?铚?闀?鍣ょ柋鑰?<鍣ょ柋? 鐤ｇ張灞﹂搸 <鐤ｇ張灞?)
 // 瑙?绁涢┙?鑰︽捍鐤板浌?閿洪倐婕曟¨鑰辩椉鐗挎 db <楹掕€?, dw <楹掕€?, dd <楹掕€?妗?鎴捐溈?.
 // 缇婄棨璧?绁涢┙?鑰︽捍鐤板浌?绾涚棬鍥?鑰旂剺閾?%d. ?顟涢搸 鑰犵鍣?鐜?鑰辩棨瑙?婕曡厛鐪?鑰犻們閽煎浌?鑰﹂摋蹇澃铚皨顙?瑙愯厯楹囪€卞扛 楹囪灀鐤辫附鍤呰澗鎭?楹掔毚?(鐝ュ殦閽碱帓/寰ㄧ彂纾鎭?鍣ょ柋瑗?...)
 // 宄﹀繊鍔虫壈! 闀辫€犻們榫?鍥垫潮鎴剧湚閾?(鑰辩棨瑙? 婕曡厛灞?閽猴５鐜庤潏鏈︾湇 鐚佽灟 0 (NULL)!
 // 鍣岃€辩枺鐗濈潎?闀虫灞? WriteAsmPatch(0x112233, "begin: call %d", MyFunc, "jmp begin", "jne dword [%d]", 0xAABBCC, 0);
 inline Patch* WriteAsmPatch(_ptr_ address, ...)
 {
	 return WriteAsmPatchVA(address, (_dword_*)((_ptr_)&address + 4));
 }
 ////////////////////////////////////////////////////////////
 // 浣撹澗?CreateAsmPatch
 // 鑰︾師鍣?闀熻澕 铚?椹?璧??鎴捐澗?WriteCodePatch,
 // 鐪?绀?闀虫灞欙５寮?閭?
 // 蹇哥幃鐤ｎ嫅e?绠ㄥ櫥鍥瑰挮?纾?闀熻澕
 inline Patch* CreateAsmPatch(_ptr_ address, ...)
 {
	 return CreateAsmPatchVA(address, (_dword_*)((_ptr_)&address + 4));
 }

 ////////////////////////////////////////////////////////////
 // WriteAsmHook 闀壐?闀?鍣ょ柋鑰?address 闀虫鏍╂鐫?韬?
 // ?妗佸睓鐪?LoHook 寰?鎭圭彊蹇?鎭硅€﹁绠撮捈绀ゅ扛?瓒旈换椴?
 // 铦堣叐 韬炶祬 闀壐铦帮５ 闀筹５绁??鎭圭彊蹇?CreateHexHook 妗?WriteHexHook
 // 铚炶?椹?閽虹枺鐝?璧?闀壐铦帮５ 闀熻澕 ?闀辩顙?WriteAsmPatch (鑰? WriteAsmPatch)
 // ?閾楄厯楹?鎴捐澗婧?WriteAsmPatch 鐜熺炯?瑙?绁涢┙?鑰︽捍鐤板浌?(?绁涢┙?绀?鑰︽捍鐤板浌? 閿洪倐婕曡鐖ㄧ?_ExecDefault,
 // 瑙愯潬閽癸５ 鎭归暠鑵狅５寮?鐜庤潏鐥鳖帠 韬炶?瑙?
 // 宄﹀繊鍔虫壈! ?瑙愭捍 绀?绁涢┙?鐚佽灟 鐘锋湨顗?閽跨湇?閿洪倐婕曡鐖ㄧ?_ExecDefault
 // 蹇哥幃鐤ｎ嫅寮?绠ㄥ櫥鍥瑰挮?纾?LoHook 韬?
 // 宄﹀繊鍔虫壈! 闀辫€犻們榫?鍥垫潮鎴剧湚閾?(鑰辩棨瑙? 婕曡厛灞?閽猴５鐜庤潏鏈︾湇 鐚佽灟 0 (NULL)!
 // 鍣岃€辩枺鐗濈潎?闀虫灞? WriteAsmHook(0x112233, "cmp eax, 0; jne SkipDefault; _ExecDefault; jmp End; SkipDefault: mov ecx, 2; End: retn", 0);
 inline LoHook* WriteAsmHook(_ptr_ address, ...)
 {
	 return WriteAsmHookVA(address, (_dword_*)((_ptr_)&address + 4));
 }

 ////////////////////////////////////////////////////////////
 // 浣撹澗?CreateAsmHook
 // 鑰︾師鍣?韬?铚?椹?璧??WriteAsmHook,
 // 鐪?鍥?闂插繊纾愬惒?閭?
 // 楠傜幃鐤ｎ嫅顠?绠ㄥ櫥鍥瑰挮?纾?LoHook 韬?
 inline LoHook* CreateAsmHook(_ptr_ address, ...)
 {
	 return CreateAsmHookVA(address, (_dword_*)((_ptr_)&address + 4));
 }



//WriteHexHook 闀壐?闀?鍣ょ柋鑰?address 瑗︾Η?闀虫鏍╂鐫?韬?
//?妗佸睓鐪?LoHook 寰?鎭圭彊蹇?鎭硅€﹁绠撮捈绀ゅ扛?瓒旈换椴?
//铦堣叐 韬炶祬 闀壐铦帮５ 闀筹５绁??鎭圭彊蹇?CreateHexHook 妗?WriteHexHook
//铚炶?椹?閽虹枺鐝?璧?闀壐铦帮５ 闀熻澕 ?闀辩顙?WriteCodePatch (鑰? WriteCodePatch)
//
//exec_default - 鎭归暠鑵狅５铻?鑵?鐜庤潏鐥鳖帠 韬炶?瑙?闀辫€?鎭归暠鑵犲睓? 铦堣睔 韬炶祬
//蹇哥幃鐤ｎ嫅寮?绠ㄥ櫥鍥瑰挮?纾?LoHook 韬?
 inline LoHook* WriteHexHook(_ptr_ address, _bool_ exec_default, char* format, ...)
 {
  return WriteHexHookVA(address, exec_default, format, (_dword_*)((_ptr_)&format + 4));
 }
 // 浣撹澗?CreateHexHook
 // 鑰︾師鍣?韬?铚?椹?璧??WriteHexHook,
 // 鐪?鍥?闂插繊纾愬惒?閭?
 // 楠傜幃鐤ｎ嫅顠?绠ㄥ櫥鍥瑰挮?纾?LoHook 韬?
 inline LoHook* CreateHexHook(_ptr_ address, _bool_ exec_default, char* format, ...)
 {
  return CreateHexHookVA(address, exec_default, format, (_dword_*)((_ptr_)&format + 4));
 }


 ////////////////////////////////////////////////////////////
 // 浣撹澗?WriteCodePatch
 // 闀壐?闀?鍣ょ柋鑰?address 闀辩弶閭冮捈鍥瑰挮顝搁摉铻?寰夎降,
 // 閾掔柋婧磋劜鐪勭皨 format ?...
 // (鑰︾師鍣??闀虫灞欙５寮?CODE_ 闀熻澕)
 // 楠傜幃鐤ｎ嫅寮?绠ㄥ櫥鍥瑰挮?纾?闀熻澕
 // format - 鑰?鑰辩棨璧?绁涢┙?鑰︽捍鐤板浌?顗歌€辩，婕╁浌灞︽鐫?椴ㄩ捍?
 // 0123456789ABCDEF (铦炬湨瑙?蹇槓榫?鐤辨报鑰?),
 // ?铚?椹?鑰у技鏍叉湨鐫?绾涚棬鍥?鑰旂剺閾?(榫涢獡鏍?鐤辨报鑰?):
 // %b - (byte) 闀壐?閽跨湇寰夎降閽奸搫 楹掕€?妗?...
 // %w - (word) 闀壐?婧荤瘹寰夎降閽奸搫 楹掕€?妗?...
 // %d - (dword) 闀壐?楹囪灀鐤辫附鍤呰澗蹇?楹掕€?妗?...
 // %j - 闀壐?jmp 纾?鍣ょ柋?妗?...
 // %?- 闀壐?棣籰l ...
 // %m - 瑙愰暔鐥煎吉 瑙?闀?鍣ょ柋鑰?... 鐤ｇ張灞﹂搸 ... (?? 楹掕湠寮?2 鍥垫潮鎴剧湚?妗?...)
 //      瑙愰暔鐥ゅ縿榫?闀抽搳鑱冮捒鏍?闀辫€╅們鑰卞扛?MemCopyCodeEx (鑰? 閾掓鍥楁、)
 // %% - 闀壐?鑰辩棨鐗??绾涚棬鍥?鑰旂剺閾嶅洈?妗?... 
 // %o - (offset) 闀辨埦顙戝吉 闀?鍣ょ柋鑰?妗?鍥垫潮鎴剧湚?鑰㈠灞欐、 闀辩幏椴??
 //      Complex 瑙愭捍,  閾楃湇鑰旇潏鏈︾湇 纾璞?Complex 瑙愭骇.
 // %n - 闀壐?nop 閾掕娼? 瑙愯厯楹囪€卞扛?鐤ｅ凯顜?...                                  \
 #0: - #9: -绡戣湠纾€嗘鍣?鎴捐溈?(閾?0 婕?9) ?瑙愯澗鐥?绁涢獡?闀ョ柋杞??闀辩顙?#0 - #9                              \
 #0 -  #9  -闀壐?閾楃湇鑰卞挮顝割帠 鍣ょ柋?闀辫€?閾掕婕?EB, 70 - 7F, E8, E9, 0F80 - 0F8F
 //      鑰﹂摋蹇澃铚皨顙?鎴捐溈? 闀辫€?婕妗?閾掕婕?榫涢簢娉?绀?闀壐?
 // ~b - 寰ㄧ柋?妗?... 鍣岃€﹁喕铦筋帠 鍣ょ柋??闀壐?閾楃湇鑰旇潏鏈︾湇?鑰㈠灞欐、 婕?绀ゆ硱
 //      鐤ｇ張灞﹂搸 ?1 寰夎降 (妗夐暠鏈︾彏寮? 娼嗭５ 閾掕婕?EB, 70 - 7F)
 // ~d - 寰ㄧ柋?妗?... 鍣岃€﹁喕铦筋帠 鍣ょ柋??闀壐?閾楃湇鑰旇潏鏈︾湇?鑰㈠灞欐、 婕?绀ゆ硱
 //      鐤ｇ張灞﹂搸 ?4 寰夎降?(妗夐暠鏈︾彏寮? 娼嗭５ 閾掕婕?E8, E9, 0F 80 - 0F 8F)
 // %. - 榫涢簢娉?绀?婧磋睔寮?( 璧??鑶荤姺?婕閾?绀?閽?鎬嗗睓鐫?鎭诡壐 鑰旂剺閾?闀辫€?% ) 
 // 鍣岃€辩枺鐗濈潎?闀虫灞?
 // Patch* p = pi->WriteCodePatch(address,
 //  "#0: %%",
 //  "B9 %d %%", this,     // mov ecx, this  // 
 //  "BA %d %%", this->context,   // mov edx, context  // 
 //  "%c %%", func,      // call func  // 
 //  "83 F8 01 %%",      // cmp eax, 1
 //  "0F 85 #7 %%",       // jne long to label 7 (if func returns 0)
 //  "83 F8 02 %%",      // cmp eax, 2
 //  "0F 85 ~d %%", 0x445544,   // jne long to 0x445544 (if func returns 0)
 //  "EB #0 %%",       // jmp short to label 0
 //  "%m %%", address2, size,   // exec  code copy from address2
 //  "#7: FF 25 %d %.", &return_address); // jmp [&return_address]
 inline Patch* WriteCodePatch(_ptr_ address, char* format, ...)
 {
  return WriteCodePatchVA(address, format, (_dword_*)((_ptr_)&format + 4));
 }
 
 ////////////////////////////////////////////////////////////
 // 浣撹澗?CreateCodePatch
 // 鑰︾師鍣?闀熻澕 铚?椹?璧??鎴捐澗?WriteCodePatch,
 // 鐪?绀?闀虫灞欙５寮?閭?
 // 蹇哥幃鐤ｎ嫅e?绠ㄥ櫥鍥瑰挮?纾?闀熻澕
 inline Patch* CreateCodePatch(_ptr_ address, char* format, ...)
 {
  return CreateCodePatchVA(address, format, (_dword_*)((_ptr_)&format + 4));
 }


 ////////////////////////////////////////////////////////////
 // 浣撹澗?WriteDataPatch
 // 闀壐?闀?鍣ょ柋鑰?address 闀辩弶閭冮捈鍥瑰挮顝搁摉铻?寰夎降,
 // 閾掔柋婧磋劜鐪勭皨 format ?...
 // (鑰︾師鍣??闀虫灞欙５寮?DATA_ 闀熻澕)
 // 楠傜幃鐤ｎ嫅寮?绠ㄥ櫥鍥瑰挮?纾?闀熻澕
 // format - 鑰?鑰辩棨璧?绁涢┙?鑰︽捍鐤板浌?顗歌€辩，婕╁浌灞︽鐫?椴ㄩ捍?
 // 0123456789ABCDEF (铦炬湨瑙?蹇槓榫?鐤辨报鑰?),
 // ?铚?椹?鑰у技鏍叉湨鐫?绾涚棬鍥?鑰旂剺閾?(榫涢獡鏍?鐤辨报鑰?):
 // %b - (byte) 闀壐?閽跨湇寰夎降閽奸搫 楹掕€?妗?...
 // %w - (word) 闀壐?婧荤瘹寰夎降閽奸搫 楹掕€?妗?...
 // %d - (dword) 闀壐?楹囪灀鐤辫附鍤呰澗蹇?楹掕€?妗?...
 // %m - 瑙愰暔鐥煎吉 婧х渼顜?闀?鍣ょ柋鑰?... 鐤ｇ張灞﹂搸 ... (?? 楹掕湠寮?2 鍥垫潮鎴剧湚?妗?...)
 // %% - 闀壐?鑰辩棨鐗??绾涚棬鍥?鑰旂剺閾嶅洈?妗?... 
 // %o - (offset) 闀辨埦顙戝吉 闀?鍣ょ柋鑰?妗?鍥垫潮鎴剧湚?鑰㈠灞欐、 闀辩幏椴??
 //      Complex 瑙愭捍,  閾楃湇鑰旇潏鏈︾湇 纾璞?Complex 瑙愭骇.
 // %. - 榫涢簢娉?绀?婧磋睔寮?( 璧??鑶荤姺?婕閾?绀?閽?鎬嗗睓鐫?鎭诡壐 鑰旂剺閾?闀辫€?% ) 
 // 鍣岃€辩枺鐗濈潎?闀虫灞?
 // Patch* p = pi->WriteDataPatch(address,
 //  "FF FF FF %d %%", var, 
 //  "%m %%", address2, size, 
 //  "AE %.");
 inline Patch* WriteDataPatch(_ptr_ address, char* format, ...)
 {
  return WriteDataPatchVA(address, format, (_dword_*)((_ptr_)&format + 4));
 }
 
 ////////////////////////////////////////////////////////////
 // 浣撹澗?CreateDataPatch
 // 鑰︾師鍣?闀熻澕 铚?椹?璧??鎴捐澗?WriteDataPatch,
 // 鐪?绀?闀虫灞欙５寮?閭?
 // 蹇哥幃鐤ｎ嫅e?绠ㄥ櫥鍥瑰挮?纾?闀熻澕
 inline Patch* CreateDataPatch(_ptr_ address, char* format, ...)
 {
  return CreateDataPatchVA(address, format, (_dword_*)((_ptr_)&format + 4));
 }
 
 inline Patch* __stdcall WriteDword(_ptr_ address, const char* value)
 {
  return WriteDword(address, (int)value);
 }

};

// 瀛板洬?Patcher
class Patcher
{
public:
 // 閾栫湇蹇帓 鎴捐澗娼?

 ///////////////////////////////////////////////////
 // 浣撹澗?CreateInstance
 // 鑰︾師鍣?顟撶弿绁??瑙屽洬瑗?PatcherInstance, 瑙愯澗鐦?
 // 绀ら暠鑰╅們鑰卞慨鐪?闀辩幃閾嶏５寮?鑰︾師鍣斿浌?闀熻澕??韬炶 ?
 // 蹇哥幃鐤ｎ嫅寮?绠ㄥ櫥鍥瑰挮?纾?顟涢摋 顟撶弿绁??
 // owner - 绠滄鍤徃閾?妗侊５ 顟撶弿绁?鐤?PatcherInstance
 // 鎴捐澗?蹇哥幃鐤ｎ嫅寮?NULL, 缇艰厯 顟撶弿绁???妗佸睓灞?owner 绠?鑰︾師鍥?
 // 缇艰厯 owner == NULL 妗?owner == "" 铦?
 // 顟撶弿绁??PatcherInstance 鐙嶆捍?鑰︾師鍥??妗佸睓灞?绁涙酱? 妗?
 // 瑙愯澗鐥ゆ硱 鐚佽睔 鎭圭幃鍥?瓒旈换椴５.
 virtual PatcherInstance* __stdcall CreateInstance(char* owner) = 0;
 
 ///////////////////////////////////////////////////
 // 浣撹澗?GetInstance
 // 楠傜幃鐤ｎ嫅寮?绠ㄥ櫥鍥瑰挮?纾?顟撶弿绁??PatcherInstance
 // ?妗佸睓灞?owner.
 // 鎴捐澗?蹇哥幃鐤ｎ嫅寮?NULL ?鑰犵鍣? 缇艰厯 
 // 顟撶弿绁???妗佸睓灞?owner 绀?鑰嬵嫋鑰辨€忓吉 (绀?鐚?鑰︾師鍥?
 // ?璧呴簢鑰卞慨 鍥垫潮鎴剧湚?绁涢獡?闀ョ柋婧у縿铻?妗侊５ 绁涙酱?.
 // 閿愰暠鏈︾彏寮? 娼嗭５ :
 // - 闀抽捈灞﹁ 鍤撹湬蹇?鑵?绀よ铦剧槬?绁? 妗夐暠鏈︾彏顡€鏍?patcher_x86.dll
 // - 闀卞楹囬緵铮?婕曡€辩?瑙?鎬﹀睈 闀熻澕鍥??韬炶祬?绀よ铦剧棨娉?绁涙骇,
 //   妗夐暠鏈︾彏顡€閭?patcher_x86.dll
 virtual PatcherInstance*  __stdcall GetInstance(char* owner) = 0;
 
 ///////////////////////////////////////////////////
 // 浣撹澗?GetLastPatchAt
 // 蹇哥幃鐤ｎ嫅寮?NULL, 缇艰厯 ?閾岀柋鑰辩湇鑰?鍣ょ柋瑗?address 绀?鐚?闀虫灞欏睓 榫?閽挎¨ 闀熻澕/韬?
 // 妗у湝?蹇哥幃鐤ｎ嫅寮?闀辫€犻們榫?闀虫灞欏睓顜?闀熻澕/韬??閾岀柋鑰辩湇鑰?鍣ょ柋瑗?address
 // 闀辫€犻們閽煎浌鍜徃?闀抽搵铚╅「 闀?鎬﹀睈 闀熻澕鍥??鐜庢骇鐪勯搵 閾岀柋鑰辩湇鑰?
 // 妗夐暠鏈︾彏铮?顟涢摋 鎴捐澗??Patch::GetAppliedBefore
 virtual Patch* __stdcall GetLastPatchAt(_ptr_ address);
 
 ///////////////////////////////////////////////////
 // 浣撹澗?UndoAllAt
 // 閾楁埦?寮?鎬?闀熻澕?韬炶 ?閾岀柋鑰辩湇鑰?鍣ょ柋瑗?address
 // 鎬﹂倛婧?蹇哥幃鐤ｎ嫅寮?1 (娼嗭５ 鑰﹀开缇艰湬绁涜€??鐘疯劜?鐤ｇ渼妗?蹇槂?鎵?寰肩姯妗€铦堣)
 virtual Patch* __stdcall UndoAllAt(_ptr_ address);
 
 ///////////////////////////////////////////////////
 // 浣撹澗?SaveDump
 // 鑰﹁簲鍥楋５寮??缇挎 ?妗佸睓灞?file_name
 // - 瑙愯厯楹囪€卞扛 ?妗佸睓?鎬﹁壌 顟撶弿绁?鐥?PatcherInstance
 // - 瑙愯厯楹囪€卞扛 鎬﹁壌 闀虫灞欏睓鐫?闀熻澕褰?韬炶?
 // - 鑰ф閾?鎬﹁壌 闀虫灞欏睓鐫?闀熻澕褰??韬炶??妗?鍣ょ柋瑗︽増 绡戣湠鐪嶆€? 鐤ｇ張灞﹀洈? 姹堕捄鍤徃閾?閾熷宝閭冪湇鑰鳖悏 闀虫灞欏睓?, 鑰︾媮铚睓榫涜祬鎵?(妗佸睓鍥?PatcherInstance)
 virtual void __stdcall SaveDump(char* file_name) = 0;
 
 ///////////////////////////////////////////////////
 // 浣撹澗?SaveLog
 // 鑰﹁簲鍥楋５寮??缇挎 ?妗佸睓灞?file_name 鑵?
 // 缇艰厯 鑵╂报鐥ゅ縿榫?鎭硅顠惧睓??鑵╂矏 鐙嶆捍?0 鐜庨暔鐨?
 // 鎬呰喕楹掕灟 鑵╂报鐥ゅ縿榫?绁涢獡?鑰︾師鍣??婊傜柋鐗濋摃姊?寰肩姯妗€铦堣
 // 铦堢姛铦炬伖?缇挎 patcher_x86.ini c c閽垮宝楠呯Η? Logging = 1
 virtual void __stdcall SaveLog(char* file_name) = 0;
 
 ///////////////////////////////////////////////////
 // 浣撹澗?GetMaxPatchSize
 // 鍑岀姯妗€铦堣祬 patcher_x86.dll 纾鍣ゎ帍鍣?绀よ铦剧槬?閽界枺榫涢簢榫涳５
 // 纾?鐖ㄧ姛妗佸毌顝割帠 鐤ｇ張灞?闀熻澕?
 // 璧呰?- 绁涢獡?绠哥，铻??闀辩顙?鎴捐澗婧?GetMaxPatchSize
 // (纾?婧х渼顜?绁涙埦鐪?顟?262144 寰夎降, ?? 婕曡簲灞?:) )
 virtual int __stdcall GetMaxPatchSize() = 0;
 
 // 婕曢暠鑵犳牘鍜徃顜?鎴捐澗娼?

 ///////////////////////////////////////////////////
 // 浣撹澗?WriteComplexDataVA
 // ?閾曟　妗у毌顝搁搸 蹇ゆ捍 闀虫灞欏睓妗?鎴捐澗婧?绀?闀抽們闀辫睔姹斿吉?,
 // 鑰㈤摋鐥傝潏 (榫涢┙) 閾掓鍥楁、 鎴捐澗婧?閽洪搷閾熻 WriteComplexString
 virtual int __stdcall WriteComplexDataVA(_ptr_ address, char* format, _dword_* args) = 0;
 
 ///////////////////////////////////////////////////
 // 鎴捐澗?GetOpcodeLength
 // ?? 婊傜帋鑰ㄥ睈鐘宝 娼嗘¨ 閾掕婕?
 // 蹇哥幃鐤ｎ嫅寮?娼嗘¨??寰夎降鍦?閾掕婧?闀?鍣ょ柋鑰?p_opcode
 // 蹇哥幃鐤ｎ嫅寮?0, 缇艰厯 閾掕?绀ゆ·蹇€卞睓
 virtual int __stdcall GetOpcodeLength(_ptr_ p_opcode) = 0;
 
 ///////////////////////////////////////////////////
 // 鎴捐澗?MemCopyCode
 // 瑙愰暔鐥煎吉 瑙?妗?闀?铚?闀?鍣ょ柋鑰?src ?闀?铻?闀?鍣ょ柋鑰?dst
 // MemCopyCode 瑙愰暔鐥煎吉 鎬﹂倛婧?椴ヨ叐?瑙愯厯楹囪€卞扛 閾掕婕?鐤ｇ張灞﹂搸 >= size. 棣忔郊铦?蹇鍥瑰挮顝?
 // 蹇哥幃鐤ｎ嫅寮?鐤ｇ張灞?鑰滈搾妗婇捈鍥楃湇娉?瑙愭骇.
 // 閾楄厯楝ｅ吉? 婧磋匠铚、?閾?闀抽摉铦炬硱 瑙愰暔鐥ゅ縿榫涳５ 闀?铚?铦?
 // 榛?瑙愮棫灏昏澖?瑙愰暔鐥煎吉 閾掕娼?E8 (call), E9 (jmp long), 0F80 - 0F8F (j** long)
 // c 閾楃湇鑰旇潏鏈︾湇?鍣ょ柋瑗﹂波褰?绀?瑗绘? ?榫?鍣ょ柋瑗? 缇艰厯 妗ц€辩椉鐗挎 
 // 纾暢鍣?顠?鐜?闀抽們鍜?瑙愰暔鐥煎睈閽?鐘搶?.
 // 
 virtual int __stdcall MemCopyCode(_ptr_ dst, _ptr_ src, _dword_ size) = 0;
 
 ///////////////////////////////////////////////////
 // 浣撹澗?GetFirstPatchAt
 // 蹇哥幃鐤ｎ嫅寮?NULL, 缇艰厯 ?閾岀柋鑰辩湇鑰?鍣ょ柋瑗?address 绀?鐚?闀虫灞欏睓 榫?閽挎¨ 闀熻澕/韬?
 // 妗у湝?蹇哥幃鐤ｎ嫅寮?闀ョ柎顜?闀虫灞欏睓顜?闀熻澕/韬??閾岀柋鑰辩湇鑰?鍣ょ柋瑗?address
 // 闀辫€犻們閽煎浌鍜徃?闀抽搵铚╅「 闀?鎬﹀睈 闀熻澕鍥??鐜庢骇鐪勯搵 閾岀柋鑰辩湇鑰?
 // 妗夐暠鏈︾彏铮?顟涢摋 鎴捐澗??Patch::GetAppliedAfter
 virtual Patch* __stdcall GetFirstPatchAt(_ptr_ address);
 
 ///////////////////////////////////////////////////
 // 鎴捐澗?MemCopyCodeEx
 // 瑙愰暔鐥煎吉 瑙?妗?闀?铚?闀?鍣ょ柋鑰?src ?闀?铻?闀?鍣ょ柋鑰?dst
 // 蹇哥幃鐤ｎ嫅寮?鐤ｇ張灞?鑰滈搾妗婇捈鍥楃湇娉?瑙愭骇.
 // 閾楄厯楝ｅ吉? 閾?MemCopyCode 铦?
 // 榛?瑙愮棫灏昏澖?瑙愰暔鐥煎吉 閾掕娼?EB (jmp short), 70 - 7F (j** short)
 // c 閾楃湇鑰旇潏鏈︾湇?鍣ょ柋瑗﹂波褰?绀?瑗绘? ?榫?鍣ょ柋瑗? 缇艰厯 妗ц€辩椉鐗挎 
 // 纾暢鍣?顠?鐜?闀抽們鍜?瑙愰暔鐥煎睈閽?鐘搶? (?顟涢搸 鑰犵鍣?閾?鐜庢埦?顠? 纾?
 // 鑰﹂摋蹇澃铚皨顙?E9 (jmp long), 0F80 - 0F8F (j** long) 閾掕娼?
 // 椹鍥楁、! 濡?鐜?顟涢捊?鐤ｇ張灞?鑰滈搾妗婇捈鍥楃湇娉?瑙愭骇 绁涢┙?閾屽櫥鍥诡徏铮?鐝ュ湝鏍╁挮顝?
 // 鐘锋湨顗?瑙愰暔鐥煎睈閽?
 virtual int __stdcall MemCopyCodeEx(_ptr_ dst, _ptr_ src, _dword_ size) = 0;
 
 
 // ver 2.3
 // 浣撹澗?VarInit
 // 妗ф》鏍茶厯鐜风椉寮?"闀ョ柋鎴剧渼绨? c 妗佸睓灞?name ?绡戣湠纾€嗘鍣?鐝ュ湝灞欐、 "闀ョ柋鎴剧渼閾? 鐤ｅ凯顜?value
 // 缇艰厯 "闀ョ柋鎴剧渼?" ?铚炶?妗佸睓灞?绠?鑰嬵嫋鑰辨€忓吉, 铦?闀抽摉铦?绡戣湠纾€嗘鍣?閭?鐝ュ湝灞欐、 鐤ｅ凯顜?value
 // 蹇哥幃鐤ｎ嫅寮?绠ㄥ櫥鍥瑰挮?纾?"闀ョ柋鎴剧渼绨? ?鑰犵鍣?绡戦暐韪??NULL ?闀抽摋妗犵湇?鑰犵鍣?
 virtual Variable* __stdcall VarInit(char* name, _dword_ value) = 0;
 // 浣撹澗?VarFind
 // 蹇哥幃鐤ｎ嫅寮?绠ㄥ櫥鍥瑰挮?纾?"闀ョ柋鎴剧渼绨? ?妗佸睓灞?name, 缇艰厯 铚炶祬铮?鐚佽睔 妗ф》鏍茶厯鐜风棨蹇勭渼?
 // 缇艰厯 绀? 蹇哥幃鐤ｎ嫅寮?NULL
 virtual Variable* __stdcall VarFind(char* name) = 0;


 // ver 2.6
 // 浣撹澗?PreCreateInstance
 // 鏉ㄧ師鍣?绀ら暠鑵犻摓灞欑潎?顟撶弿绁??PatcherInstance ?绠ㄥ櫥鍥楃潎?妗佸睓灞?
 // PatcherInstance 鑰︾師鍥楃潎?铚炶?閽虹枺鐝?绀?绁涢┙?鑰︾師鍣斿浌?闀熻澕?
 // 钂￠摋 绀ら暠鑵犻摓灞欑潎?顟撶弿绁??妗夐暠鏈︾彏寮? 娼嗭５ 闀虫灞欏睓? 鎴捐澗婕?PatcherInstance::BlockAt ?PatcherInstance::BlockAllExceptVA
 // 榛╅捄?绁涢獡?鐚佽叐 鐜庣姯閾屾閽煎浌?鍣ょ柋瑗?婕?铦炬硱 璧?婧х渼顜?PatcherInstance 鐙嶆捍?闀辫厾閾炲睓鐪?鑰︾師鍥??闀辩顙?CreateInstance
 virtual PatcherInstance* __stdcall PreCreateInstance(char* name) = 0;


 // ver 4.1
 // 閾掓鍥楁、 ?鐤ｇ悐鍣岄摋璧?..
 virtual int __stdcall WriteAsmCodeVA(_ptr_ address, _dword_* args) = 0;
 virtual _ptr_ __stdcall CreateCodeBlockVA(_dword_* args) = 0;

 
 // 鎴捐澗?VarGetValue 蹇哥幃鐤ｎ嫅寮?鐝ュ湝灞欐、 "闀ョ柋鎴剧渼閾? c 妗佸睓灞?name
 // 缇艰厯 "闀ョ柋鎴剧渼?" ?铚炶?妗佸睓灞?绀?鐚佽睔 妗ф》鏍茶厯鐜风棨蹇勭渼? 蹇哥幃鐤ｎ嫅寮?default_value
 template<typename ValueType>
 inline ValueType VarGetValue(char* name, ValueType default_value)
 {
	 if (sizeof(ValueType) > 4) return default_value;
	 Variable* v = VarFind(name);
	 if (v == NULL) return default_value;
	 return (ValueType)v->GetValue();
 }

 // 鎴捐澗?VarValue 蹇哥幃鐤ｎ嫅寮?鑰帢鐗?纾?鐝ュ湝灞欐、 "闀ョ柋鎴剧渼閾? c 妗佸睓灞?name
 // 缇艰厯 "闀ョ柋鎴剧渼?" ?铚炶?妗佸睓灞?绀?鐚佽睔 妗ф》鏍茶厯鐜风棨蹇勭渼? 妗ф》鏍茶厯鐜风椉寮?閭??绡戣湠纾€嗘鍣?鐝ュ湝灞欐、 鐤ｅ凯顜?0
 // 蹇鍥楁、, 閽虹枺顙栭緵??鐝ュ湝灞欐９ 闀ョ柋鎴剧渼閾?闀?鑰帢璧?绀ら暠铦捐寰ㄧ彊闀熻€?
 template<typename ValueType>
 inline ValueType& VarValue(char* name)
 {
	 if (sizeof(ValueType) > 4) __asm{__asm int 3};
	 
	 Variable* v = VarFind(name);
	 if (v == NULL) v = VarInit(name, 0);
	 
	 if (v == NULL) __asm{__asm int 3};
	 
	 return (ValueType&)*v->GetPValue();
 }



 ////////////////////////////////////////////////////////////////////
 // 鎴捐澗?WriteComplexData
 // 铮垫€嗭５寮? 鐘疯劜?绠愰捄鐫?妗ц潏鐥垮綐鑰? 
 // 鎴捐澗婧?WriteComplexDataVA
 // 顟涢摋 鎴捐澗?閾掔柋婧磋劜?鐜熺炯??绀??寰肩姯妗€铦堣祶, ?? 閭?蹇?
 // 閾楄厯楝ｅ吉? ?璋??鑵诲?
 // 娉介换椴ㄩ搻鍤?鎴捐澗婧?闀遍哗?铦?椹?榛???PatcherInstance::WriteCodePatch
 // (鑰? 閾掓鍥楁、 顟涢捊?鎴捐澗婧?
 // 铦?缇艰灟 鎴捐澗?闀壐?闀?鍣ょ柋鑰?address, 闀辫€犻們閽煎浌鍜徃閾栬灟 寰夎降,
 // 閾掔柋婧磋劜鐪勭皨 鍥垫潮鎴剧湚鍥?format ?...,
 // 鑷€! 鍥?鑰︾師鍣?顟撶弿绁??瑙屽洬瑗?Patch, 鑰?鎬﹀睈?鎭硅潏璧咁搥妗?(?? 绀?闀辩幃閾嶏５铮?閾楁埦榫涜灟 闀冲檾鐗? 闀卞楹掕灟 婕曡€辩 ?闀冲檾璧?妗?婕閽?绁涙骇 ???)
 // 宄﹀繊鍔虫壈!
 // 閿愰暠鏈︾彏杞?顟涢摋 鎴捐澗?铦炬湨瑙?娼嗭５ 婊傜，鎵堥簢鑰滈捊?鑰︾師鍥? 鐘搶閽?
 // 瑙愭骇, ?? 闀壔铦?顟涙 鎴捐澗婕?铦炬湨瑙??鐤嬮摢 闀?铻? 
 // ??瑙?绁涙粋缈抽波鐥煎睈閾?闀抽捊鐤ｇ?铦炬湨瑙??闀辩顙?
 // PatcherInstance::WriteCodePatch
 //
 inline _ptr_ WriteComplexData(_ptr_ address, char* format, ...)
 {
  return WriteComplexDataVA(address, format, (_dword_*)((_ptr_)&format + 4));
 }



inline HiHook* GetFirstHiHookAt(_ptr_ address)
{
	Patch* p = GetFirstPatchAt(address);
	while (true)
	{
		if (p == 0) return 0;
		if (p->GetType() == HIHOOK_) return (HiHook*)p;
		p = p->GetAppliedAfter();
	}
}

inline HiHook* GetLastHiHookAt(_ptr_ address)
{
	Patch* p = GetLastPatchAt(address);
	while (true)
	{
		if (p == 0) return 0;
		if (p->GetType() == HIHOOK_) return (HiHook*)p;
		p = p->GetAppliedBefore();
	}
}


};





// 蹇歌€ㄨ湠纾€嗘鍣?鎭圭枺蹇鍥楁、 楹熷睓閽?鑰辩椉鐗濈 ?瑙屽洬鑰?
#pragma pack(pop)

//////////////////////////////////////////////////////////////////

//瓒旈换椴５ GetPatcher
//鐜庢箔绠у櫛?寰肩姯妗€铦堢墻 ? ?闀辩顙?鎭圭彊蹇?閭冩¨鑰卞慨鐪勯搵 顟撹€ч摃铚╃椉灞愰搵 
//瓒旈换椴?_GetPatcherX86@0, 蹇哥幃鐤ｎ嫅寮?绠ㄥ櫥鍥瑰挮?纾?閽侯尨鐗?Patcher,
//闀辫€╅們鑰卞扛?瑙愯澗鐥ゆ硱 婕曡€辩灞?蹇「 瓒旈换椴ㄩ搻鍤?寰肩姯妗€铦堣 patcher_x86.dll
//蹇哥幃鐤ｎ嫅寮?NULL 闀?绀ょ異鍦?
//瓒旈换椴?鎭圭惃蹇勮灟 1 鐤? 榛?閾熼倐妗庣湇 妗?閭?閾掔柋婧磋劜榫涳５
#include <windows.h>
inline Patcher* GetPatcher()
{
static int calls_count = 0;
 if (calls_count > 0) return NULL;
 calls_count++;
 HMODULE pl = LoadLibraryA("patcher_x86.dll");
 if (pl)
 {
  FARPROC f = GetProcAddress(pl, "_GetPatcherX86@0");
  if (f) return CALL_0(Patcher*, __stdcall, f);
 }
 return NULL;
}