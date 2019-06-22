#include "PlayerCommon.h"

struct CharaData_status PlayerData[3];

char *pStatusData_File[] = {
	"StatusData\\save1_data.txt",	//SAVE1
	"StatusData\\save2_data.txt",	//SAVE2
	"StatusData\\save3_data.txt",	//SAVE3
	"StatusData\\present_data.txt",	//現在データ
	"StatusData\\initial_data.txt",	//初期データ
};

FILE* fp;

C_PlayerCommon::C_PlayerCommon(void)
{
}

C_PlayerCommon::~C_PlayerCommon(void)
{
}

void C_PlayerCommon::LoadPlayerData(int read_no)
{	
	fopen_s(&fp,pStatusData_File[read_no],"r");
	if(fp==NULL){
		MessageBox(NULL,TEXT("ステータスデータの読み込みに失敗しました"),NULL,MB_OK);
		return;	//ファイル読み込み失敗
	}

	for(int i=0;i<3;i++){//0:シオン 1:ヴァン 2:リオ
		fscanf_s(fp,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n"
			,&PlayerData[i].m_id,&PlayerData[i].m_atk,&PlayerData[i].m_def,&PlayerData[i].m_mag,&PlayerData[i].m_res
			,&PlayerData[i].m_mg,&PlayerData[i].m_maxmg,&PlayerData[i].m_agl,&PlayerData[i].m_dex,&PlayerData[i].m_hp
			,&PlayerData[i].m_maxhp,&PlayerData[i].m_ap,&PlayerData[i].m_maxap,&PlayerData[i].m_ap_r,&PlayerData[i].m_mov
			,&PlayerData[i].m_luk,&PlayerData[i].m_mp);
	}

	fclose(fp);	//ファイルを閉じる
}

void C_PlayerCommon::SavePlayerData(int record_no)
{
	fopen_s(&fp,pStatusData_File[record_no],"w");
	if(fp==NULL){
		MessageBox(NULL,TEXT("ステータスデータの書き込みに失敗しました"),NULL,MB_OK);
		return;	//ファイル読み込み失敗
	}
	for(int i=0;i<3;i++){//0:シオン 1:ヴァン 2:リオ
		fprintf(fp,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n"
			,PlayerData[i].m_id,PlayerData[i].m_atk,PlayerData[i].m_def,PlayerData[i].m_mag,PlayerData[i].m_res
			,PlayerData[i].m_mg,PlayerData[i].m_maxmg,PlayerData[i].m_agl,PlayerData[i].m_dex,PlayerData[i].m_hp
			,PlayerData[i].m_maxhp,PlayerData[i].m_ap,PlayerData[i].m_maxap,PlayerData[i].m_ap_r,PlayerData[i].m_mov
			,PlayerData[i].m_luk,PlayerData[i].m_mp);
	}

	fclose(fp);	//ファイルを閉じる
}


void C_PlayerCommon::Init()
{
}

void C_PlayerCommon::Draw()
{

}
