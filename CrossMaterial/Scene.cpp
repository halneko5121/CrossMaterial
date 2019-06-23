#include "Scene.h"

void C_Scene::SoundLoad(char *m_scene_name)
{
	FILE *fp;
	char l_sound_name[MAX_STRING];	//�T�E���h�f�[�^��ǂݍ��ވׂ̕�����i�[�p
	char l_read_buffer[MAX_STRING];	//�t�@�C���f�[�^�J�E���g�p
	int max_sound = 0;
	char** m_p_sound_file;	//�T�E���h�t�@�C����

	memset(l_read_buffer,'\0', sizeof(char) * MAX_STRING);

	strcpy(l_sound_name,"Sound\\");	//�T�E���h�t�H���_���w��
	strcat(l_sound_name,m_scene_name);//�V�[�������w��
	strcat(l_sound_name,".txt");	//.txt���Ō�ɖ����ƃ_���ł��傤�B
	
	fp = fopen(l_sound_name,"r");	//�e�L�X�g�t�@�C����ǂݍ���
	
	if(fp == NULL)	return;			//�e�L�X�g�t�@�C�������݂��Ȃ���΁A�ǂݍ��݂𒆎~����B

	while(fscanf(fp,"%s,",l_read_buffer) != EOF)	//�T�E���h�f�[�^�̐����J�E���g����B
	{
		max_sound++;
	}

	fseek(fp,0L,SEEK_SET);			//�e�L�X�g�t�@�C���̐擪�ɃA�h���X��߂��B

	m_p_sound_file = new char*[max_sound];	//�T�E���h�f�[�^���ɉ��������������m��

	for(int i=0;i<max_sound;i++)			//�T�E���h�f�[�^�̌��𐔂���B
	{
		m_p_sound_file[i] = new char[MAX_STRING];
	}
	
	for(int i=0;i<max_sound;i++)	//�T�E���h�f�[�^�����i�[
	{
		fscanf(fp,"%s,",m_p_sound_file[i]);
	}

	fclose(fp);
}

void C_Scene::NowLoading(int scene_flag, int scene_number)
{
	if(!m_flag_fade){
		m_alpha_load = m_graphics->FadeIn(10,m_alpha_load);
	}
	else{ 
		m_alpha_load = m_graphics->FadeOut(10,m_alpha_load);
	}

	if(m_alpha_load >= 255){
		m_flag_fade = true;
	}
	else if (m_alpha_load <= 0){
		m_flag_fade = false;
		m_count_fade++;
	}

	if(m_count_fade > 3){
		m_scene_flag		= scene_flag;
		m_scene_number[0]	= scene_number;
		SetSceneNum(m_scene_flag,m_scene_number);
		m_count_fade = 0;
	}
}

void C_Scene::NowLoading(int scene_flag)
{
	if(!m_flag_fade){
		m_alpha_load = m_graphics->FadeIn(10,m_alpha_load);
	}
	else{ 
		m_alpha_load = m_graphics->FadeOut(10,m_alpha_load);
	}

	if(m_alpha_load >= 255){
		m_flag_fade = true;
		m_count_fade++;
	}
	else if (m_alpha_load <= 0){
		m_flag_fade = false;
	}
	
	if(m_count_fade > 3){
		m_scene_flag		= scene_flag;
		m_count_fade = 0;
	}
}

void C_Scene::NowLoading()
{
	if(!m_flag_fade){
		m_alpha_load = m_graphics->FadeIn(10,m_alpha_load);
	}
	else{ 
		m_alpha_load = m_graphics->FadeOut(10,m_alpha_load);
	}

	if(m_alpha_load >= 255){
		m_flag_fade = true;
		m_count_fade++;
	}
	else if (m_alpha_load <= 0){
		m_flag_fade = false;
	}
}