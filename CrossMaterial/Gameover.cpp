#include "Gameover.h"

F_RECT rect_gameover[] =
{					
	{0,0,0,0},	//ƒ_ƒ~[
};

C_Gameover::C_Gameover()
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

C_Gameover::~C_Gameover()
{
}

void C_Gameover::Init()
{


}

void C_Gameover::Control(int* key)
{

}

void C_Gameover::Draw()
{

}

void C_Gameover::Sound()
{

}

void C_Gameover::Release()
{

}
