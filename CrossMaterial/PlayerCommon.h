#pragma once
/************************************************************************************
 *																					*
 *	役割：味方キャラに共通部分を管理する。											*
 *																					*
 *	説明：味方キャラの共通部分を管理する。											*
 *																					*
 *	作成日：2008年11月 8日															*
 *																					*
 *	更新日：2009年 2月 5日															*
 *													by 三上　亘						*
 *												更新者 兼武	 芳典					*
 ************************************************************************************/

/*================================
	
		INCLUDEたち

=================================*/
#include "CharaCommon.h"

/*================================
	
		Defineたち

=================================*/

enum FILE_DATA
{
	F_SAVE1,				//SAVE1
	F_SAVE2,				//SAVE2
	F_SAVE3,				//SAVE3
	F_PRESENT,				//現在のデータ
	F_INITIAL,				//初期データ
};
/*/*================================
	
		structたち

=================================*/

struct CharaData_player							//味方キャラ特有のステータス
{
	//各味方キャラ固定のもの
	int			m_kind_matrix;					//マトリクス種類判別用
	//マテリアルによって変化
	int  		m_material_id;					//マテリアルをセットするための受け皿
												//どのマテリアルかの判定　1 火 2水 3土 4風 など 
	int			m_skill1,m_skill2;				//技の種類	(装備しているマテリアルで変化)
	int			m_ap_use1,m_ap_use2;			//消費AP
};

class C_PlayerCommon :	public C_CharaCommon
{
private:
	CharaData_player player;
public:
	void LoadPlayerData(int read_no);
	void SavePlayerData(int record_no);
	C_PlayerCommon(void);
	~C_PlayerCommon(void);
	void Init();
	void Draw();
};
