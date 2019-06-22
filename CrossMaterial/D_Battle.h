#pragma once

/************************************************************************************
 *																					*
 *	役割：バトル部分でのDefineの定義												*
 *																					*
 *	説明：																			*
 *																					*
 *	作成日：2008年 月 日															*
 *																					*
 *	更新日：2008年 月 日															*
 *													by	平野　努					*
 *																					*
 ************************************************************************************/

enum TEXTURE_DATA_BATTLE
{
	//ステータス描画
	T_STATUS_BG,		//背景
	T_STATUS_FC,		//フォント・コンソール
	T_STATUS_NAME,		//キャラの名前
	T_STATUS_ZION_CG,	//シオンの立ち絵
	T_STATUS_VAN_CG,	//ヴァンの立ち絵
	T_STATUS_RIO_CG,	//リオの立ち絵
	T_STATUS_FACE_CG,	//キャラ絵(顔)

	T_BATTLE_FIELD1,	//バトル時の背景
	T_WIN_CONDITION_BG,	//勝利条件表示時の背景
	T_BATTLE_FONT,		//バトル時フォント

	T_MAPTIP,			//MAPTIPの統合ファイル

	T_CHAR_ZION,		//キャラ絵
	T_CHAR_VAN,			//キャラ絵
	T_CHAR_RIO,			//キャラ絵
	
	T_CHAR_SAHAGIN1,	//キャラ絵
	T_CHAR_SAHAGIN2,	//キャラ絵
	T_CHAR_LIZARDMAN1,	//キャラ絵
	T_CHAR_LIZARDMAN2,	//キャラ絵
	T_CHAR_LIZARDMAN3,	//キャラ絵(フードの男)
	T_CHAR_NAME1,		//キャラの名前
	T_UP_EF,			//エフェクト(ステータス回復)
	T_ATK_EF,			//エフェクト(攻撃)
	T_ZION_SP_BG,		//奥義の背景
	T_VAN_SP_BG,		//奥義の背景
	T_RIO_SP_BG,		//奥義の背景
	T_TELOP,			//マテリアルセット時のテロップ
	T_FADE,				//フェードアウト時の絵
	T_WHITE_OUT,		//ホワイトアウト時の絵
	T_WHITE_OUT_VAN,	//ホワイトアウト時の絵(ヴァン)
	T_ATK_SP_EF,		//エフェクト(奥義)
	T_ATK_SP_EF2,
	T_SLASH,
	T_NOWLOADING,

	T_A,

	T_WAKU,

	MAX_BATTLE_TEXTURE,	//テクスチャの数
};

enum RECT_DATA_BATTLE	//矩形データ
{
	R_STATUS_BG,			//背景				0
	R_STATUS_ATTRIBUTE1,	//｢属性｣文字		1
	R_STATUS_HP,			//｢HP｣文字			2
	R_STATUS_AP,			//｢AP｣文字			3
	R_STATUS_MG,			//｢MG｣文字			4
	R_STATUS_ATK,			//｢ATK｣文字			5
	R_STATUS_DEF,			//｢DEF｣文字			6
	R_STATUS_DEX,			//｢DEX｣文字			7
	R_STATUS_AGL,			//｢AGL｣文字			8
	R_STATUS_MATRIX,		//｢マトリクス｣文字	9
	R_STATUS_MATERIAL,		//｢マテリアル｣文字	10
	R_STATUS_SPECIAL,		//｢特殊｣文字		11
	R_STATUS_AP_R,			//｢AP_P｣文字		12
	R_STATUS_MAG,			//｢MAG｣文字			13
	R_STATUS_RES,			//｢RES｣文字			14
	R_STATUS_MOV,			//｢MOV｣文字			15
	R_STATUS_LUK,			//｢LUK｣文字			16
	R_STATUS_ATTRIBUTE2,	//｢属性｣文字		17
	R_STATUS_USE_AP1,		//｢消費AP｣文字		18
	R_STATUS_USE_AP2,		//｢消費AP｣文字		19
	R_STATUS_SLASH1,		//｢／｣の文字		20
	R_STATUS_SLASH2,		//｢／｣の文字		21
	R_STATUS_SLASH3,		//｢／｣の文字		22
	R_STATUS_NUM100,		//数字の百桁		23
	R_STATUS_NUM10,			//数字の十桁		24
	R_STATUS_NUM1,			//数字の一桁		25
	R_STATUS_COVER1,		//｢火｣の文字		26
	R_STATUS_COVER2,		//｢火｣の文字		27
	R_STATUS_MATRIXNAME,	//マトリクス名		28
	R_STATUS_MATERIALNAME,	//マテリアル名		29
	R_STATUS_Z_UNDINE1,		//｢ｱｲｼｸﾙｴｯｼﾞ｣		30
	R_STATUS_Z_UNDINE2,		//｢ｱｸｱｷｭｱ｣			31
	R_STATUS_Z_SYLPH1,		//｢ﾋｰﾙｳｨﾝﾄﾞ｣		32
	R_STATUS_Z_SYLPH2,		//｢ﾐﾗｰｴｯｼﾞ｣			33
	R_STATUS_V_SALAMANDER1,	//｢爆炎剣｣			34
	R_STATUS_V_SALAMANDER2,	//｢剛招来｣			35
	R_STATUS_V_GNOME1,		//｢地砕塵｣			36
	R_STATUS_V_GNOME2,		//｢鋼招来｣			37
	R_STATUS_R_SALAMANDER1,	//｢ﾌﾞﾚｲｽﾞﾊﾞﾚｯﾄ｣		38
	R_STATUS_R_SALAMANDER2,	//｢ﾊﾞｰｽﾄ｣			39
	R_STATUS_R_UNDINE1,		//｢ﾌﾛｰｽﾞﾝﾊﾞﾚｯﾄ｣		40
	R_STATUS_R_UNDINE2,		//｢ｱｸｱｷｭｱ｣			41
	R_STATUS_Z_UN_DATAIL1,	//｢ｱｲｼｸﾙｴｯｼﾞ｣詳細	42
	R_STATUS_RECOVERY_DATAIL,//｢ｱｸｱ､ﾋｰﾙ｣詳細	43
	R_STATUS_Z_SY_DATAIL1,	//｢ﾐﾗｰｴｯｼﾞ｣詳細		44
	R_STATUS_V_SA_DATAIL1,	//｢爆炎剣｣詳細		45
	R_STATUS_V_SA_DATAIL2,	//｢剛招来｣詳細		46
	R_STATUS_V_GN_DATAIL1,	//｢地砕塵｣詳細		47
	R_STATUS_V_GN_DATAIL2,	//｢鋼招来｣詳細		48
	R_STATUS_R_SA_DATAIL1,	//｢ﾌﾞﾚｲｽﾞﾊﾞﾚｯﾄ｣詳細	49
	R_STATUS_R_SA_DATAIL2,	//｢ﾊﾞｰｽﾄ｣詳細		50
	R_STATUS_R_UN_DATAIL1,	//｢ﾌﾛｰｽﾞﾝﾊﾞﾚｯﾄ｣詳細	51
	R_STATUS_CHARA_NAME,	//｢ｷｬﾗのﾌﾙﾈｰﾑ｣		52
	R_STATUS_ZION_CG,		//｢シオンのＣＧ｣	53
	R_STATUS_VAN_CG,		//｢ヴァンのＣＧ｣	54
	R_STATUS_RIO_CG,		//｢リオのＣＧ｣		55
	
	R_BATTLE_FIELD1,		//バトル時の背景
	R_WIN_CONDITION_BG,		//勝利条件表示時の背景
	R_WIN_CONDITION,		//勝利条件
	R_LOSS_CONDITION,		//敗北条件
	R_WIN_ONE,				//勝利条件①
	R_WIN_TWO,				//勝利条件②
	R_LOSS_ONE,				//敗北条件①
	R_PLAYER_PHASE,			//自フェイズ
	R_ENEMY_PHASE,			//敵フェイズ
	R_MOVE,					//移動
	R_ATACK,				//攻撃
	R_SPECIAL,				//特殊
	R_DEFENCE,				//防御
	R_STATUS,				//ステータス
	R_STAND,				//待機
	//ステージ
	R_MAPTIP_CACTUS1,		//サボテン1
	R_MAPTIP_CACTUS2,		//サボテン2
	R_MAPTIP_ROCK1,			//岩石1
	R_MAPTIP_ROCK2,			//岩石2
	R_MAPTIP_SAND1,			//砂地1
	R_MAPTIP_SAND2,			//砂地2
	R_MAPTIP_SAND3,			//砂地3
	R_MAPTIP_SAND4,			//砂地4
	R_MAPTIP_GREEN1,		//草地1
	R_MAPTIP_GREEN2,		//草地2
	R_MAPTIP_GREEN3,		//草地3
	R_MAPTIP_GREEN4,		//草地4
	R_MAPTIP_CHOICE,		//カーソル
	R_MAPTIP_EREA,			//エリア
	//D_MAPTIP_MAX,			//MAPTIP矩形の最大数
	//キャラクター
	R_CHAR_WAIT_LEFTFRONT,		//キャラ待機(左前)
	R_CHAR_WAIT_LEFTBACK,		//キャラ待機(左後)
	R_CHAR_WAIT_RIGHTFRONT,		//キャラ待機(右前)
	R_CHAR_WAIT_RIGHTBACK,		//キャラ待機(右後)

	R_CHAR_ATTACK_LEFTFRONT1,	//キャラ攻撃(左前)
	R_CHAR_ATTACK_LEFTFRONT2,	//キャラ攻撃(左前)
	R_CHAR_ATTACK_LEFTFRONT3,	//キャラ攻撃(左前)
	R_CHAR_ATTACK_LEFTFRONT4,	//キャラ攻撃(左前)

	R_CHAR_ATTACK_LEFTBACK1,	//キャラ攻撃(左後)
	R_CHAR_ATTACK_LEFTBACK2,	//キャラ攻撃(左後)
	R_CHAR_ATTACK_LEFTBACK3,	//キャラ攻撃(左後)
	R_CHAR_ATTACK_LEFTBACK4,	//キャラ攻撃(左後)

	R_CHAR_ATTACK_RIGHTFRONT1,	//キャラ攻撃(右前)
	R_CHAR_ATTACK_RIGHTFRONT2,	//キャラ攻撃(右前)
	R_CHAR_ATTACK_RIGHTFRONT3,	//キャラ攻撃(右前)
	R_CHAR_ATTACK_RIGHTFRONT4,	//キャラ攻撃(右前)

	R_CHAR_ATTACK_RIGHTBACK1,	//キャラ攻撃(右後)
	R_CHAR_ATTACK_RIGHTBACK2,	//キャラ攻撃(右後)
	R_CHAR_ATTACK_RIGHTBACK3,	//キャラ攻撃(右後)
	R_CHAR_ATTACK_RIGHTBACK4,	//キャラ攻撃(右後)

	R_CHAR_ZION_ATTACK_LEFTFRONT1,	//シオン攻撃(左前)
	R_CHAR_ZION_ATTACK_LEFTFRONT2,	//シオン攻撃(左前)
	R_CHAR_ZION_ATTACK_LEFTFRONT3,	//シオン攻撃(左前)
	R_CHAR_ZION_ATTACK_LEFTFRONT4,	//シオン攻撃(左前)

	R_CHAR_ZION_ATTACK_RIGHTFRONT1,	//シオン攻撃(右前)
	R_CHAR_ZION_ATTACK_RIGHTFRONT2,	//シオン攻撃(右前)
	R_CHAR_ZION_ATTACK_RIGHTFRONT3,	//シオン攻撃(右前)
	R_CHAR_ZION_ATTACK_RIGHTFRONT4,	//シオン攻撃(右前)

	R_GAME_OVER,
	R_ZION_NAME,
	R_VAN_NAME,
	R_RIO_NAME,
	R_BATTLE_ICON,	//アイコン

	R_MATERIAL_UNDINE,	//マテリアル名	水
	R_MATERIAL_SYIPH,	//マテリアル名　風
	R_MATERIAL_GNOM,	//マテリアル名　土

	R_SIMPLE_BG,		//簡易地形ステータス背景
	R_SIMPLE_EFFECT,	//属性効果
	R_SIMPLE_CHARA_BG,	//簡易ステータスキャラ背景
	R_SIMPLE_NUM100,	//数字の百桁(簡易ステータス)
	R_SIMPLE_NUM10,		//数字十桁(簡易ステータス用)
	R_SIMPLE_NUM1,		//数字の一桁(簡易ステータス用)	

	R_SIMPLE_SLASH,		//｢／｣の文字(簡易ステータス用)
	R_SIMPLE_NAME,		//キャラのフルネーム(簡易ステータス用)
	R_SIMPLE_UPDOWN,	//｢↑｣、｢↓｣

	R_ZION_WAIT_LEFTFRONT,		//シオン待機(左前)
	R_ZION_WAIT_LEFTBACK,		//シオン待機(左後)
	R_ZION_WAIT_RIGHTFRONT,		//シオン待機(右前)
	R_ZION_WAIT_RIGHTBACK,		//シオン待機(右後)
	R_ZION_WAIT_LF_ATK_1,		//シオン左前攻撃
	R_ZION_WAIT_LF_ATK_2,		//シオン左前攻撃
	R_ZION_WAIT_LF_ATK_3,		//シオン左前攻撃
	R_ZION_WAIT_LF_ATK_4,		//シオン左前攻撃
	R_ZION_WAIT_LB_ATK_1,		//シオン左前攻撃
	R_ZION_WAIT_LB_ATK_2,		//シオン左前攻撃
	R_ZION_WAIT_LB_ATK_3,		//シオン左前攻撃
	R_ZION_WAIT_LB_ATK_4,		//シオン左前攻撃
	R_ZION_WAIT_RF_ATK_1,		//シオン左前攻撃
	R_ZION_WAIT_RF_ATK_2,		//シオン左前攻撃
	R_ZION_WAIT_RF_ATK_3,		//シオン左前攻撃
	R_ZION_WAIT_RF_ATK_4,		//シオン左前攻撃
	R_ZION_WAIT_RB_ATK_1,		//シオン左前攻撃
	R_ZION_WAIT_RB_ATK_2,		//シオン左前攻撃
	R_ZION_WAIT_RB_ATK_3,		//シオン左前攻撃
	R_ZION_WAIT_RB_ATK_4,		//シオン左前攻撃


	R_VAN_WAIT_LEFTFRONT,		//ヴァン待機(左前)
	R_VAN_WAIT_LEFTBACK,		//ヴァン待機(左後)
	R_VAN_WAIT_RIGHTFRONT,		//ヴァン待機(右前)
	R_VAN_WAIT_RIGHTBACK,		//ヴァン待機(右後)
	R_VAN_WAIT_LF_ATK_1,		//シオン左前攻撃
	R_VAN_WAIT_LF_ATK_2,		//シオン左前攻撃
	R_VAN_WAIT_LF_ATK_3,		//シオン左前攻撃
	R_VAN_WAIT_LF_ATK_4,		//シオン左前攻撃
	R_VAN_WAIT_LB_ATK_1,		//シオン左前攻撃
	R_VAN_WAIT_LB_ATK_2,		//シオン左前攻撃
	R_VAN_WAIT_LB_ATK_3,		//シオン左前攻撃
	R_VAN_WAIT_LB_ATK_4,		//シオン左前攻撃
	R_VAN_WAIT_RF_ATK_1,		//シオン左前攻撃
	R_VAN_WAIT_RF_ATK_2,		//シオン左前攻撃
	R_VAN_WAIT_RF_ATK_3,		//シオン左前攻撃
	R_VAN_WAIT_RF_ATK_4,		//シオン左前攻撃
	R_VAN_WAIT_RB_ATK_1,		//シオン左前攻撃
	R_VAN_WAIT_RB_ATK_2,		//シオン左前攻撃
	R_VAN_WAIT_RB_ATK_3,		//シオン左前攻撃
	R_VAN_WAIT_RB_ATK_4,		//シオン左前攻撃

	R_RIO_WAIT_LEFTFRONT,		//リオ待機(左前)
	R_RIO_WAIT_LEFTBACK,		//リオ待機(左後)
	R_RIO_WAIT_RIGHTFRONT,		//リオ待機(右前)
	R_RIO_WAIT_RIGHTBACK,		//リオ待機(右後)
	R_RIO_WAIT_LF_ATK_1,		//シオン左前攻撃
	R_RIO_WAIT_LF_ATK_2,		//シオン左前攻撃
	R_RIO_WAIT_LF_ATK_3,		//シオン左前攻撃
	R_RIO_WAIT_LF_ATK_4,		//シオン左前攻撃
	R_RIO_WAIT_LB_ATK_1,		//シオン左前攻撃
	R_RIO_WAIT_LB_ATK_2,		//シオン左前攻撃
	R_RIO_WAIT_LB_ATK_3,		//シオン左前攻撃
	R_RIO_WAIT_LB_ATK_4,		//シオン左前攻撃
	R_RIO_WAIT_RF_ATK_1,		//シオン左前攻撃
	R_RIO_WAIT_RF_ATK_2,		//シオン左前攻撃
	R_RIO_WAIT_RF_ATK_3,		//シオン左前攻撃
	R_RIO_WAIT_RF_ATK_4,		//シオン左前攻撃
	R_RIO_WAIT_RB_ATK_1,		//シオン左前攻撃
	R_RIO_WAIT_RB_ATK_2,		//シオン左前攻撃
	R_RIO_WAIT_RB_ATK_3,		//シオン左前攻撃
	R_RIO_WAIT_RB_ATK_4,		//シオン左前攻撃
	//各待機(敵)
	R_SAHAGIN1_WAIT_LEFTFRONT,		//サハギン1待機(左前)
	R_SAHAGIN1_WAIT_LEFTBACK,		//サハギン1待機(左後)
	R_SAHAGIN1_WAIT_RIGHTFRONT,		//サハギン1待機(右前)
	R_SAHAGIN1_WAIT_RIGHTBACK,		//サハギン1待機(右後)
	R_SAHAGIN2_WAIT_LEFTFRONT,		//サハギン2待機(左前)
	R_SAHAGIN2_WAIT_LEFTBACK,		//サハギン2待機(左後)
	R_SAHAGIN2_WAIT_RIGHTFRONT,		//サハギン2待機(右前)
	R_SAHAGIN2_WAIT_RIGHTBACK,		//サハギン2待機(右後)
	R_LIZARDMAN1_WAIT_LEFTFRONT,		//リザードマン1待機(左前)
	R_LIZARDMAN1_WAIT_LEFTBACK,		//リザードマン1待機(左後)
	R_LIZARDMAN1_WAIT_RIGHTFRONT,		//リザードマン1待機(右前)
	R_LIZARDMAN1_WAIT_RIGHTBACK,		//リザードマン1待機(右後)
	R_LIZARDMAN2_WAIT_LEFTFRONT,		//リザードマン2待機(左前)
	R_LIZARDMAN2_WAIT_LEFTBACK,		//リザードマン2待機(左後)
	R_LIZARDMAN2_WAIT_RIGHTFRONT,		//リザードマン2待機(右前)
	R_LIZARDMAN2_WAIT_RIGHTBACK,		//リザードマン2待機(右後)
	R_LIZARDMAN3_WAIT_LEFTFRONT,		//リザードマン3待機(左前)
	R_LIZARDMAN3_WAIT_LEFTBACK,		//リザードマン3待機(左後)
	R_LIZARDMAN3_WAIT_RIGHTFRONT,		//リザードマン3待機(右前)
	R_LIZARDMAN3_WAIT_RIGHTBACK,		//リザードマン3待機(右後)
	R_HOODMAN_WAIT_LEFTFRONT,		//フードの男待機(左前)
	R_HOODMAN_WAIT_LEFTBACK,		//フードの男待機(左後)
	R_HOODMAN_WAIT_RIGHTFRONT,		//フードの男待機(右前)
	R_HOODMAN_WAIT_RIGHTBACK,		//フードの男待機(右後)
	//エフェクト
	R_AQUA_CURE1,
	R_AQUA_CURE2,
	R_AQUA_CURE3,
	R_AQUA_CURE4,
	R_SALAMANDER1,
	R_SALAMANDER2,
	R_SALAMANDER3,
	R_SALAMANDER4,
	R_KOUSYORAI1,
	R_KOUSYORAI2,
	R_KOUSYORAI3,
	R_KOUSYORAI4,
	R_HEELWIND1,
	R_HEELWIND2,
	R_HEELWIND3,
	R_HEELWIND4,
	//攻撃エフェクト
	R_TISAIJIN1,
	R_TISAIJIN2,
	R_TISAIJIN3,
	R_TISAIJIN4,
	R_BAKUENKEN1,
	R_BAKUENKEN2,
	R_BAKUENKEN3,
	R_BAKUENKEN4,
	R_RIO_JUGEKI1,
	R_RIO_JUGEKI2,
	R_RIO_JUGEKI3,
	R_RIO_JUGEKI4,
	R_MAGUMA1,
	R_MAGUMA2,
	R_MAGUMA3,
	R_MAGUMA4,
	R_FROZEN_BULLET1,
	R_FROZEN_BULLET2,
	R_FROZEN_BULLET3,
	R_FROZEN_BULLET4,
	R_LIZARD_KAMI1,
	R_LIZARD_KAMI2,
	R_LIZARD_KAMI3,
	R_LIZARD_KAMI4,
	R_ICICLE_EDGE1,
	R_ICICLE_EDGE2,
	R_ICICLE_EDGE3,
	R_ICICLE_EDGE4,

	R_ICICLE_LEFTFLONT1,	//シオンアイシクルエッジ(左前)
	R_ICICLE_LEFTFLONT2,	//シオンアイシクルエッジ(左前)
	R_ICICLE_LEFTFLONT3,	//シオンアイシクルエッジ(左前)
	R_ICICLE_LEFTFLONT4,	//シオンアイシクルエッジ(左前)
	R_ICICLE_LEFTBACK1,		//シオンアイシクルエッジ(左後)
	R_ICICLE_LEFTBACK2,		//シオンアイシクルエッジ(左後)
	R_ICICLE_LEFTBACK3,		//シオンアイシクルエッジ(左後)
	R_ICICLE_LEFTBACK4,		//シオンアイシクルエッジ(左後)
	R_ICICLE_RIGHTFLONT1,	//シオンアイシクルエッジ(右前)
	R_ICICLE_RIGHTFLONT2,	//シオンアイシクルエッジ(右前)
	R_ICICLE_RIGHTFLONT3,	//シオンアイシクルエッジ(右前)
	R_ICICLE_RIGHTFLONT4,	//シオンアイシクルエッジ(右前)
	R_ICICLE_RIGHTBACK1,	//シオンアイシクルエッジ(右後)
	R_ICICLE_RIGHTBACK2,	//シオンアイシクルエッジ(右後)
	R_ICICLE_RIGHTBACK3,	//シオンアイシクルエッジ(右後)
	R_ICICLE_RIGHTBACK4,	//シオンアイシクルエッジ(右後)

	R_ZION_SP_BG,
	R_VAN_SP_BG,
	R_RIO_SP_BG,

	R_SP_ZION_NAME,
	R_SP_VAN_NAME,
	R_SP_RIO_NAME,

	R_TRIAN,
	R_TELOP,
	R_TELOP2,

	R_MATERIALSALAMANDER,
	R_MATERIALUNDINE,
	R_MATERIALSYLPH,
	R_MATERIALGNOME,

	R_FADE,
	R_WHITE_OUT,
	R_WHITE_OUT_VAN,

	R_EXPLODE1,
	R_EXPLODE2,
	R_EXPLODE3,
	R_EXPLODE4,

	R_CUT_EF1,
	R_CUT_EF2,
	R_CUT_EF3,
	R_CUT_EF4,

	R_CUT_EF01,
	R_CUT_EF02,
	R_CUT_EF03,
	R_CUT_EF04,

	R_CUT_EFZ01,
	R_CUT_EFZ02,
	R_CUT_EFZ03,
	R_CUT_EFZ04,

	R_CUT_EF_VAN01,
	R_CUT_EF_VAN02,
	R_CUT_EF_VAN03,
	R_CUT_EF_VAN04,

	R_SLASH,

	R_PHASE_BG,

	R_BAKUEN1,
	R_BAKUEN2,
	R_BAKUEN3,
	R_BAKUEN4,
	R_BAKUEN5,

	R_CURSOR_P,
	R_CURSOR_E,

	R_Z_V_WAIT_LF_1,		//シオン・ヴァン左前待機
	R_Z_V_WAIT_LF_2,		//シオン・ヴァン左前待機
	R_Z_V_WAIT_LF_3,		//シオン・ヴァン左前待機
	R_Z_V_WAIT_LF_4,		//シオン・ヴァン左前待機
	R_Z_V_WAIT_LB_1,		//シオン・ヴァン左後待機
	R_Z_V_WAIT_LB_2,		//シオン・ヴァン左後待機
	R_Z_V_WAIT_LB_3,		//シオン・ヴァン左後待機
	R_Z_V_WAIT_LB_4,		//シオン・ヴァン左後待機
	R_Z_V_WAIT_RF_1,		//シオン・ヴァン右前待機
	R_Z_V_WAIT_RF_2,		//シオン・ヴァン右前待機
	R_Z_V_WAIT_RF_3,		//シオン・ヴァン右前待機
	R_Z_V_WAIT_RF_4,		//シオン・ヴァン右前待機
	R_Z_V_WAIT_RB_1,		//シオン・ヴァン右後待機
	R_Z_V_WAIT_RB_2,		//シオン・ヴァン右後待機
	R_Z_V_WAIT_RB_3,		//シオン・ヴァン右後待機
	R_Z_V_WAIT_RB_4,		//シオン・ヴァン右後待機

	R_RIO_ENEMY_WAIT_LF_1,		//リオ・フードの男以外の敵左前待機
	R_RIO_ENEMY_WAIT_LF_2,		//リオ・フードの男以外の敵左前待機
	R_RIO_ENEMY_WAIT_LF_3,		//リオ・フードの男以外の敵左前待機
	R_RIO_ENEMY_WAIT_LF_4,		//リオ・フードの男以外の敵左前待機
	R_RIO_ENEMY_WAIT_LB_1,		//リオ・フードの男以外の敵左後待機
	R_RIO_ENEMY_WAIT_LB_2,		//リオ・フードの男以外の敵左後待機
	R_RIO_ENEMY_WAIT_LB_3,		//リオ・フードの男以外の敵左後待機
	R_RIO_ENEMY_WAIT_LB_4,		//リオ・フードの男以外の敵左後待機
	R_RIO_ENEMY_WAIT_RF_1,		//リオ・フードの男以外の敵右前待機
	R_RIO_ENEMY_WAIT_RF_2,		//リオ・フードの男以外の敵右前待機
	R_RIO_ENEMY_WAIT_RF_3,		//リオ・フードの男以外の敵右前待機
	R_RIO_ENEMY_WAIT_RF_4,		//リオ・フードの男以外の敵右前待機
	R_RIO_ENEMY_WAIT_RB_1,		//リオ・フードの男以外の敵右後待機
	R_RIO_ENEMY_WAIT_RB_2,		//リオ・フードの男以外の敵右後待機
	R_RIO_ENEMY_WAIT_RB_3,		//リオ・フードの男以外の敵右後待機
	R_RIO_ENEMY_WAIT_RB_4,		//リオ・フードの男以外の敵右後待機

	R_BOSS_WAIT_LF_1,		//フードの男左前待機
	R_BOSS_WAIT_LF_2,		//フードの男左前待機
	R_BOSS_WAIT_LF_3,		//フードの男左前待機
	R_BOSS_WAIT_LF_4,		//フードの男左前待機

	R_MATERIAL_SET,			//フォント"マテリアルセット"

	R_WAIT_LF,				//待機時矢印
	R_WAIT_LB,
	R_WAIT_RF,
	R_WAIT_RB,	

	R_FACE_ZION,			//シオン絵(簡易ステータス用)
	R_FACE_VAN,				//ヴァン絵(簡易ステータス用)
	R_FACE_RIO,				//リオ絵(簡易ステータス用)
	R_FACE_BOSS,			//フードの男絵(簡易ステータス用)
	R_FACE_SAHAGIN1,		//サハギン１絵(簡易ステータス用)
	R_FACE_SAHAGIN2,		//サハギン２絵(簡易ステータス用)
	R_FACE_LIZARDMAN1,		//リザードマン１絵(簡易ステータス用)
	R_FACE_LIZARDMAN2,		//リザードマン２絵(簡易ステータス用)

	R_STATENAME_ZION,			//シオン絵(簡易ステータス用)
	R_STATENAME_VAN,			//ヴァン絵(簡易ステータス用)
	R_STATENAME_RIO,			//リオ絵(簡易ステータス用)
	R_STATENAME_BOSS,			//フードの男絵(簡易ステータス用)
	R_STATENAME_SAHAGIN1,		//サハギン１絵(簡易ステータス用)
	R_STATENAME_SAHAGIN2,		//サハギン２絵(簡易ステータス用)
	R_STATENAME_LIZARDMAN1,		//リザードマン１絵(簡易ステータス用)
	R_STATENAME_LIZARDMAN2,		//リザードマン２絵(簡易ステータス用)

	R_BG_PLAYER,	//簡易ステータスBGプレイヤー用
	R_BG_ENEMY,		//簡易ステータスBGエネミー用

	R_HP_FONT,
	R_AP_FONT,
	R_MG_FONT,
	R_MOV_FONT,
	R_SLASH_FONT,
	R_GAGE_WAKU,

	R_GAGE_HP,
	R_GAGE_AP,
	R_GAGE_MG,

	R_GAGE_HP_MAX,
	R_GAGE_AP_MAX,
	R_GAGE_MG_MAX,

	R_NOWLOADING,

	R_A,

	MAX_BATTLE_DATA,
};

enum BATTLE_SOUND_DATA	//バトルのサウンドデータ
{
	//BGM
	S_BATTLE_BGM1,
	S_BATTLE_BGM2,
	//必殺技(シオン)
	S_MIRAGE_EDGE,
	S_HEEL_WIND,		
	S_ICICLE_EDGE,	
	S_AQUA_CURE_Z,	
	//必殺技(ヴァン)
	S_BAKUENKEN,		
	S_GOUSYORAI,		
	S_TISAIJIN,		
	S_KOUSYORAI,		
	//必殺技(リオ)
	S_BLAZE_BULLET,	
	S_BURST,			
	S_FROZEN_BULLET,	
	S_AQUA_CURE_R,	
	//攻撃(シオン)
	S_ZION_ATTACK1,
	S_ZION_ATTACK2,
	S_ZION_ATTACK3,
	//攻撃(ヴァン)
	S_VAN_ATTACK1,
	S_VAN_ATTACK2,
	S_VAN_ATTACK3,
	S_VAN_ATTACK4,
	S_VAN_ATTACK5,
	//攻撃(リオ)
	S_RIO_ATTACK1,
	S_RIO_ATTACK2,
	//奥義(シオン)
	S_ZION_ABUSORYUTOEND,
	//S_ZION_ABUSORYUTOEND2,
	//奥義(ヴァン)
	S_VAN_GOUVAKUREKOGEKI,

	//効果音
	S_SWORDSWING1,	//通常攻撃シオン
	S_SWORDSWING2,	//通常攻撃ヴァン
	S_GUN_SOUND,	//通常攻撃リオ

	S_EF_BAKUENKEN,		//特技爆炎剣
	S_EF_ICICLE_EDGE,	//特技アイシクルエッジ
	S_EF_AQUACURE,		//特技アクアキュア
	S_EF_MIRAGE_EDGE,	//特技ミラージュエッジ
	S_EF_HEEL_WIND,		//特技ヒールウィンド
	S_EF_GOUSYORAI,		//特技剛招来
	S_EF_TISAIJIN,		//特技地砕塵
	S_EF_KOUSYORAI,		//特技鋼招来
	S_EF_BLAZE_BULLET,	//特技ブレイズバレット
	S_EF_BURST,			//特技バースト
	S_EF_FROZEN_BULLET_SUCCESS,	//特技フローズンバレット(成功)
	S_EF_FROZEN_BULLET_MISS,	//特技フローズンバレット(失敗)
	S_EF_AQUA_CURE_R,	//特技アクアキュア

	S_SWORDSWING3,	//奥義シオン効果音
	S_EXPLODE,		//奥義ヴァン効果音
	S_GAN_ACTION,	//奥義リオ効果音

	S_OUGI_IN,
	S_CURSOR_MOVE,
	//アナウンス
	S_WIN_MAN,
	S_WIN_MAN2,
	S_LOSE_MAN,
	S_LOSE_MAN2,
	S_LOSE_MAN3,

	S_WIN_GIRL,
	S_WIN_GIRL2,
	S_LOSE_GIRL,
	S_LOSE_GIRL2,
	S_LOSE_GIRL3,

	S_MATERIAL_SET_MAN,
	S_MATERIAL_SET_GIRL,
	S_AP_FALSE,

	MAX_S_BATTLE,
};

enum CHAR_MENU	//バトル時メニュー
{
	CHAR_MOVE,		//移動
	CHAR_ATTACK,	//攻撃
	CHAR_SPECIAL,	//特殊
	CHAR_SP_EXTRA,	//蝶必殺技
	CHAR_STATE,		//ステータス
	CHAR_WAIT,		//待機

	COMMANDO_MAX
};

enum BATTLE_SCENE			//バトル時工程
{
	BATTLE_STATUS_MAKE,		//バトルのステータスを作る
	BATTLE_CONDITION,		//バトル勝利条件・敗北条件(戦闘開始前)
	BATTLE_MATERIAL_SET,	//バトル前にマテリアルをセットします
	BATTLE_COMBAT,			//バトル戦闘フィールド(戦闘開始)
	BATTLE_CLEAR,			//バトル終了後各描画(戦闘終了後)
};

enum DATA_NUMBER
{
	DATA_HP,	//HP
	DATA_AP,	//AP
	DATA_MG,	//MG
	DATA_MAXHP,	//MAXHP
	DATA_MAXAP,	//MAXAP
	DATA_MAXMG,	//MAXMG
	DATA_ATK,	//ATK
	DATA_DEF,	//DEF
	DATA_DEX,	//DEX
	DATA_AGL,	//AGL
	DATA_AP_R,	//AP_R
	DATA_MAG,	//MAG
	DATA_RES,	//RES
	DATA_MOV,	//MOV
	DATA_LUK,	//LUK
};

enum SIMPLE_DATA_NUMBER
{
	S_DATA_HP,		//HP
	S_DATA_AP,		//AP
	S_DATA_MG,		//MG
	S_DATA_MAXHP,	//MAXHP
	S_DATA_MAXAP,	//MAXAP
	S_DATA_MAXMG,	//MAXMG
	S_DATA_MOVE,	//MOVE
	S_DATA_ATK,		//ATK
	S_DATA_DEF,		//DEF
	S_DATA_MAG,		//MAG
	S_DATA_RES,		//RES
};

enum MAPTIP_OPERATION
{
	M_FULL,						//全属性
	M_SALAMANDER,				//火属性
	M_UNDINE,					//水属性
	M_SYLPH,					//風属性
	M_GNOME,					//土属性
	M_NOTHING,					//なし
};

enum SKILL_DETAIL
{
	SKILL_UP,			//アップ
	SKILL_DOWN,			//ダウン
	SKILL_DUMMY,		//「全」の文字を入れないため
	SKILL_NOTHING,		//なし
};

#define PLAYER_TURN		(1)	//プレイヤーターン
#define ENEMY_TURN		(2)	//エネミーターン
#define STATE_GAMEOVER	(1)	//ゲームオーバー
#define STATE_CLEAR		(2)	//クリア

#define RANGE_MIRAGE_EDGE	(1)	//ミラージュエッジの攻撃範囲
#define RANGE_HEEL_WIND		(3)	//ヒールウィンドの攻撃範囲
#define RANGE_ICICLE_EDGE	(2)	//アイシクルエッジの攻撃範囲
#define RANGE_AQUA_CURE_Z	(3)	//アクアキュアの攻撃範囲
#define RANGE_BAKUENKEN		(3)	//爆炎剣の攻撃範囲
#define RANGE_GOUSYORAI		(2)	//剛招来の攻撃範囲
#define RANGE_KOUSYORAI		(2)	//鋼招来の攻撃範囲
#define RANGE_TISAIJIN		(2)	//地砕塵の攻撃範囲
#define RANGE_BLAZE_BULLET	(4)	//ブレイズバレットの攻撃範囲
#define RANGE_BURST			(3)	//バーストの攻撃範囲
#define RANGE_FROZEN_BULLET	(4)	//フローズンバレットの攻撃範囲
#define RANGE_AQUA_CURE_R	(3)	//アクアキュアの攻撃範囲

#define AP_MIRAGE_EDGE		(7)	//ミラージュエッジの消費AP
#define AP_HEEL_WIND		(6)	//ヒールウィンドの消費AP
#define AP_ICICLE_EDGE		(6)	//アイシクルエッジの消費AP
#define AP_AQUA_CURE_Z		(7)	//アクアキュアの消費AP
#define AP_BAKUENKEN		(7)	//爆炎剣の消費AP
#define AP_GOUSYORAI		(5)	//剛招来の消費AP
#define AP_KOUSYORAI		(5)	//鋼招来の消費AP
#define AP_TISAIJIN			(7)	//地砕塵の消費AP
#define AP_BLAZE_BULLET		(5)	//ブレイズバレットの消費AP
#define AP_BURST			(5)	//バーストの消費AP
#define AP_FROZEN_BULLET	(5)	//フローズンバレットの消費AP
#define AP_AQUA_CURE_R		(6)	//アクアキュアの消費AP

#define GOUSYOURAI_EF_SIZE	(0.1)	//剛招来のステータス補正値
#define KOUSYOURAI_EF_SIZE	(0.1)	//鋼招来のステータス補正値
#define BURST_EF_SIZE		(0.1)	//バーストのステータス補正値

enum SKILL_TYPE
{
	ZION_SKILL_ATK = 1,		//シオン特殊攻撃
	VAN_SKILL_ATK,		//ヴァン特殊攻撃
	RIO_SKILL_ATK,		//リオ特殊攻撃(効果)
	ZION_SKILL_EFFECT,	//シオン特殊効果
	VAN_SKILL_EFFECT,	//ヴァン特殊効果
	RIO_SKILL_EFFECT,	//リオ特殊効果
};

enum CHARA_ID				//どのキャラかを判断するID
{
	BLANK_ID,
	ZION_ID,		//シオン
	VAN_ID,			//ヴァン
	RIO_ID,			//リオ
	SAHAGIN1_ID,		//サハギン1
	SAHAGIN2_ID,		//サハギン2
	LIZARD1_ID,		//リザード1
	LIZARD2_ID,		//リザード2
	LIZARD3_ID,		//リザード3
	BOSS_ID,		//フードの男
};

enum DIRECTION_NO
{
	LEFT_FLONT,		//左前
	LEFT_BACK,		//左後
	RIGHT_FLONT,	//右前
	RIGHT_BACK,		//右後
};

#define STATE_SPASE_RANGE	(1)		//ステータスにいれる仮の範囲