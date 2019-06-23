#pragma once

/************************************************************************************
 *																					*
 *	�����F�摜�t�@�C���������₷������B											*
 *																					*
 *	�����F�摜�f�[�^��4�_�����ꊇ���Ĉ����B										*
 *																					*
 *	�쐬���F2008�N 8�� 6��															*
 *																					*
 *	�X�V���F2009�N 1�� 20��															*
 *													by	�����@���F					*
 *													�X�V�O��@�j					*
 ************************************************************************************/
/*================================
	
		INCLUDE����

=================================*/
#include<d3d9.h>
#include<d3dx9tex.h>

/*================================
	
		Define����

=================================*/
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)

#define MAX_RECT			(20)			//��`�̍ő��
#define MAX_MAPTIP_LENGTE	(15)			//MAPTIP�̍ő吔(��)
#define MAX_MAPTIP_WIDE		(20)			//MAPTIP�̍ő吔(�c)

/*================================
	
		pragma comment

=================================*/

#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")

/*================================
	
		�\���̂���

=================================*/

struct CUSTOMVERTEX
{
	FLOAT x,y,z,rhw;
	DWORD color;
	FLOAT tu,tv;
};

struct F_RECT//�S��long�^�ŊG�̃T�C�Y�𑪂�̂Ɏg���ƕ֗�
{
	float top;
	float bottom;
	float left;
	float right;
};

struct FIELD_POS
{
	float x;			//�t�B�[���h�̒��S���W(x)
	float y;			//�t�B�[���h�̒��S���W(y)
};

struct COORDINATE	//���W�Ƃ����Ӗ�
{
	int x;
	int y;
};

class C_DGraphics//�N���X�̒�`
{
	private:
		IDirect3DDevice9*   pD3Device;
		float *height,*width;	//���ƍ���
		F_RECT *position;		//��`���
		DWORD *color;			//�F
		DWORD *color2;			//�F
		float *angle;			//�p�x
		float *size_x, *size_y;	//�g�嗦
		int num;				//�g���G�̖���]
		int alpha;
		float alpha_f;

		////		����N��
		////	F_RECT rect[MAX_RECT];
		int		flag_field[MAX_MAPTIP_LENGTE][MAX_MAPTIP_WIDE];			//�z��̒���MAPTIP�����ʂ���
		float	field_x[MAX_MAPTIP_LENGTE][MAX_MAPTIP_WIDE];			//���W��z�u(x��)
		float	field_y[MAX_MAPTIP_LENGTE][MAX_MAPTIP_WIDE];			//���W��z�u(y��)
		
	public:
		void InitData(int max_data);													//������

		void SetTextureNum(int texture_num);											//�e�N�X�`���[�̐������߂�

		void SetSize(float texture_size_x, float texture_size_y, int no);				//�G�̃T�C�Y�����߂�

		void SetDevice(IDirect3DDevice9 *pDevice);										//�f�o�C�X�̃Z�b�g

		void LoadTexture(char* pFileName, LPDIRECT3DTEXTURE9 &pTexture);				//�e�N�X�`���[�̓ǂݍ���
	
		void SetPostion(F_RECT rect, int no);											//��`���̃Z�b�g

		void SetPostion(float t, float l, float b, float r, int no);					//��`���̃Z�b�g

		void SetColor(DWORD texture_color, int no);										//�J���[�̃Z�b�g

		void SetColor2(DWORD texture_color,int no);										//�J���[�̃Z�b�g(�e�_)(2��28���ǉ�)

		void Draw(float x, float y, LPDIRECT3DTEXTURE9 &pTexture, int no, int no2);		//�h���[�֐�

		void DrawCC(float x, float y, LPDIRECT3DTEXTURE9 &pTexture, int no, int no2);	//�h���[�֐�(���S�_��^�񒆂Ɏ�����o�[�W����)

		void DrawCC2(float x, float y, LPDIRECT3DTEXTURE9 &pTexture, int no, int no2);	//�h���[�֐�(���S�_��^�񒆂Ɏ�����o�[�W����)vol.2(2��28���ǉ�)

		void SetAngle(float texture_angle, int no);										//�p�x�̃Z�b�g

		int   FadeOut(int fade_speed ,int texture_alpha);								//�t�F�[�h�A�E�g����
		int   FadeOut(int fade_speed ,int texture_alpha ,int fade_stop);				//�t�F�[�h�A�E�g����
		float FadeOut(float fade_speed ,float texture_alpha);							//�t�F�[�h�A�E�g����

		int   FadeIn(int fade_speed ,int texture_alpha);								//�t�F�[�h���� 
		int	  FadeIn(int fade_speed ,int texture_alpha ,int fade_stop);					//�t�F�[�h���� 
		float FadeIn(float fade_speed ,float texture_alpha);							//�t�F�[�h���� 

		IDirect3DDevice9* GetDevice() {return pD3Device;}								//�f�o�C�X�̏��𑼂ɓn�� 

		void RectChange(float &rect1,float &rect2);										//��`�̃`�F���W(�L�����̌����ύX)

		void RectReverse(int num);														//��`�̔��]

		void SetMaptip(int length,int wide,F_RECT rect[],int no_rect,float fieid_x[][20],float fieid_y[][20]);
		//MAPTIP��SET����֐�

};
