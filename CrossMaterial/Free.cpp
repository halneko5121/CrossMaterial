#include "Free.h"


F_RECT rect_free[] =
{	
	{0,0,0,0},	//�_�~�[
};

char* LaodFreeFile[] = {
	{""},
	{"\0"},
};

C_Free::C_Free(C_DGraphics *graphic)
{
	graphics = graphic;

	use_texture = 0;			

	scene_check = new int[MAX_SCENE];
	scene_check[0] = 0;
	
	for(int i = 0;LaodFreeFile[i] != "\0"; i++)		//�g���G�̖�����m�点��
	{
		use_texture++;	
	}

	graphics->SetTextureNum(use_texture);					//�e�N�X�`���̖������Z�b�g����

	graphics->InitData(R_FREE_MAX);						//��`�̐��������������m�ۂ���B

	pTexture = new LPDIRECT3DTEXTURE9[use_texture];		//�摜�f�[�^�̐��������������m�ۂ���B

	for(int i=0; i<R_FREE_MAX; i++)
	{	
		graphics->SetPostion(rect_free[i],i);				//��`�����Z�b�g����
	}	

	for(int i=0; i < use_texture; i++)						//�e�N�X�`���̓ǂݍ��݂��s���B
	{
		graphics->LoadTexture(LaodFreeFile[i],pTexture[i]); 
	}

	//for(int i=0; i < MAX_S_END; i++){
	//	LoadSound(LoadSoundFree[i],i);					//Free�����̂�BGM
	//}
}

C_Free::~C_Free()
{
}

void C_Free::Init()
{


}

void C_Free::FreeBase(){	//��{

}

void C_Free::FreeClass(){	//����

}

void C_Free::Control(int * key)
{

}

void C_Free::Draw()
{
}
void C_Free::Sound()
{

}
void C_Free::Release()
{

}
