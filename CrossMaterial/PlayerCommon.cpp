#include "PlayerCommon.h"

struct CharaData_status PlayerData[3];

char *pStatusData_File[] = {
	"StatusData\\save1_data.txt",	//SAVE1
	"StatusData\\save2_data.txt",	//SAVE2
	"StatusData\\save3_data.txt",	//SAVE3
	"StatusData\\present_data.txt",	//���݃f�[�^
	"StatusData\\initial_data.txt",	//�����f�[�^
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
		MessageBox(NULL,TEXT("�X�e�[�^�X�f�[�^�̓ǂݍ��݂Ɏ��s���܂���"),NULL,MB_OK);
		return;	//�t�@�C���ǂݍ��ݎ��s
	}

	for(int i=0;i<3;i++){//0:�V�I�� 1:���@�� 2:���I
		fscanf_s(fp,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n"
			,&PlayerData[i].m_id,&PlayerData[i].m_atk,&PlayerData[i].m_def,&PlayerData[i].m_mag,&PlayerData[i].m_res
			,&PlayerData[i].m_mg,&PlayerData[i].m_maxmg,&PlayerData[i].m_agl,&PlayerData[i].m_dex,&PlayerData[i].m_hp
			,&PlayerData[i].m_maxhp,&PlayerData[i].m_ap,&PlayerData[i].m_maxap,&PlayerData[i].m_ap_r,&PlayerData[i].m_mov
			,&PlayerData[i].m_luk,&PlayerData[i].m_mp);
	}

	fclose(fp);	//�t�@�C�������
}

void C_PlayerCommon::SavePlayerData(int record_no)
{
	fopen_s(&fp,pStatusData_File[record_no],"w");
	if(fp==NULL){
		MessageBox(NULL,TEXT("�X�e�[�^�X�f�[�^�̏������݂Ɏ��s���܂���"),NULL,MB_OK);
		return;	//�t�@�C���ǂݍ��ݎ��s
	}
	for(int i=0;i<3;i++){//0:�V�I�� 1:���@�� 2:���I
		fprintf(fp,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n"
			,PlayerData[i].m_id,PlayerData[i].m_atk,PlayerData[i].m_def,PlayerData[i].m_mag,PlayerData[i].m_res
			,PlayerData[i].m_mg,PlayerData[i].m_maxmg,PlayerData[i].m_agl,PlayerData[i].m_dex,PlayerData[i].m_hp
			,PlayerData[i].m_maxhp,PlayerData[i].m_ap,PlayerData[i].m_maxap,PlayerData[i].m_ap_r,PlayerData[i].m_mov
			,PlayerData[i].m_luk,PlayerData[i].m_mp);
	}

	fclose(fp);	//�t�@�C�������
}


void C_PlayerCommon::Init()
{
}

void C_PlayerCommon::Draw()
{

}
