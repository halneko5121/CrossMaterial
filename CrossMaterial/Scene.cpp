#include "Scene.h"

void C_Scene::SoundLoad(char *m_scene_name)
{
	FILE *fp;
	char l_sound_name[MAX_STRING];	//サウンドデータを読み込む為の文字列格納用
	char l_read_buffer[MAX_STRING];	//ファイルデータカウント用
	int max_sound = 0;
	char** m_p_sound_file;	//サウンドファイル名

	memset(l_read_buffer,'\0', sizeof(char) * MAX_STRING);

	strcpy(l_sound_name,"Sound\\");	//サウンドフォルダを指定
	strcat(l_sound_name,m_scene_name);//シーン名を指定
	strcat(l_sound_name,".txt");	//.txtが最後に無いとダメでしょう。
	
	fp = fopen(l_sound_name,"r");	//テキストファイルを読み込む
	
	if(fp == NULL)	return;			//テキストファイルが存在しなければ、読み込みを中止する。

	while(fscanf(fp,"%s,",l_read_buffer) != EOF)	//サウンドデータの数をカウントする。
	{
		max_sound++;
	}

	fseek(fp,0L,SEEK_SET);			//テキストファイルの先頭にアドレスを戻す。

	m_p_sound_file = new char*[max_sound];	//サウンドデータ名に応じたメモリを確保

	for(int i=0;i<max_sound;i++)			//サウンドデータの個数を数える。
	{
		m_p_sound_file[i] = new char[MAX_STRING];
	}
	
	for(int i=0;i<max_sound;i++)	//サウンドデータ名を格納
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