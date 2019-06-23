/************************************************************************************
 *																					*
 *	�����F�O���t�B�b�N�̃��C�u�����B											    *
 *																					*
 *	�����F���ꂪ���邾���ŕ`��͊����Ȃ�������́I									*
 *																					*
 *	�쐬���F2008�N 8�� 6��															*
 *																					*
 *	�X�V���F2009�N 1��20��															*
 *													by	�����@���F					*
 *													�X�V�O��@�j					*
 ************************************************************************************/


#include "DirectGraphics.h"


void C_DGraphics::SetDevice(IDirect3DDevice9 *pDevice)//�f�o�C�X�̃Z�b�g
{
	pD3Device = pDevice;
}

void C_DGraphics::InitData(int max_data)//������
{
	color = new DWORD[max_data];	//�������̊m�ہi�E���͌^���I�j
	angle = new float[max_data];	//�������̊m�ہi�E���͌^���I�j
	size_x = new float[max_data];	//�������̊m�ہi�E���͌^���I�j
	size_y = new float[max_data];	//�������̊m�ہi�E���͌^���I�j
	position = new F_RECT[max_data];//�������̊m�ہi�E���͌^���I�j
	color2 = new DWORD[4];			//2��28���ǉ�

	for(int i = 0; i < max_data; i++)//�g�p����摜�̖�����for���ł܂킷
	{
		color[i] = 0xFFFFFFFF;
		angle[i] = 0.f;
		size_x[i] = 1.f;
		size_y[i] = 1.f;
		if(i < 4){
			color2[i] = 0xFFFFFFFF;
		}
	}
}

void C_DGraphics::SetTextureNum(int texture_num)//�����t�@�C���̖������܂킷
{
	num = texture_num;

	height = new float[num];	//�摜�̍���
	width = new float[num];		//�摜�̕�

	for(int i = 0; i < num; i++)//������
	{
		height[i] = 0.f;
		width[i] = 0.f;
	}
}


void C_DGraphics::LoadTexture(char* pFileName, LPDIRECT3DTEXTURE9 &pTexture)//�e�N�X�`���[�̓ǂݍ���
{	
	if(FAILED(D3DXCreateTextureFromFileExA(pD3Device,
		pFileName,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_FILTER_NONE,
		D3DX_FILTER_NONE,
		D3DCOLOR_ARGB(255,0,255,0),
		NULL,NULL,&pTexture))){
			MessageBox(NULL,TEXT("pTexture�̐����Ɏ��s���܂��ソ"),NULL,MB_OK);
			return ;
	}

//	float height,width;
	D3DSURFACE_DESC desc;
	pTexture->GetLevelDesc(0,&desc);

	for(int i = 0; i < num; i++)
	{
		if(height[i] == 0.f)
		{
			height[i] = (float)desc.Height;
			width[i]  = (float)desc.Width;
			break;
		}
	}
}

void C_DGraphics::SetPostion(F_RECT rect, int no)							//���W���Z�b�g����
{
	position[no] = rect;
}

void C_DGraphics::SetSize(float texture_size_x, float texture_size_y, int no)//�傫�����Z�b�g����
{
	size_x[no] = texture_size_x;
	size_y[no] = texture_size_y;
}

void C_DGraphics::SetPostion(float t, float l, float b, float r, int no)	//��`���̃��Z�b�g
{
	position[no].top = t;
	position[no].left = l;
	position[no].right = r;
	position[no].bottom = b;
}

void C_DGraphics::SetColor(DWORD texture_color, int no)	//�J���[���Z�b�g����
{
	color[no] = texture_color;
}

void C_DGraphics::SetColor2(DWORD texture_color,int no)
{
	color2[no] = texture_color;
}

void C_DGraphics::SetAngle(float texture_angle, int no)//�p�x���Z�b�g����
{
	angle[no] = texture_angle;
}

/************************************************************************************
 *	����	�F�t�F�[�h�C������														*
 *	����	�Fint fade_speed	int texture_alpha:�e�N�X�`����alpha�l				*
 *	�߂�l	�Fint alpha																*
 *													by	�O��@�j					*
 ************************************************************************************/
int C_DGraphics::FadeIn(int fade_speed ,int texture_alpha) 
{
	alpha = texture_alpha;
	alpha += fade_speed;

	if(alpha >= 255 )	alpha = 255;

	return alpha;
}

/************************************************************************************
 *	����	�F�t�F�[�h�C������(float_ver)											*
 *	����	�Ffloat fade_speed	float texture_alpha:�e�N�X�`����alpha�l				*
 *	�߂�l	�Ffloat alpha															*
 *													by	�O��@�j					*
 ************************************************************************************/
float C_DGraphics::FadeIn(float fade_speed ,float texture_alpha) 
{
	alpha_f = texture_alpha;
	alpha_f += fade_speed;

	if(alpha_f >= 255 )	alpha_f = 255;

	return alpha_f;
}

/************************************************************************************
 *	����	�F�t�F�[�h�C������														*
 *	����	�Fint fade_stop: �t�F�[�h�������~����l								*
 *			�Fint fade_speed:����			 int texture_alpha:�e�N�X�`����alpha�l	*
 *	�߂�l	�Fint alpha																*
 *													by	�O��@�j					*
 ************************************************************************************/
int C_DGraphics::FadeIn(int fade_speed ,int texture_alpha, int fade_stop) 
{
	alpha = texture_alpha;
	alpha += fade_speed;

	if(alpha >= fade_stop )	alpha = fade_stop;

	return alpha;
}

/************************************************************************************
 *	����	�F�t�F�[�h�A�E�g����													*
 *	����	�Fint fade_speed	int texture_alpha:�e�N�X�`����alpha�l				*
 *	�߂�l	�Fint alpha																*
 *													by	�O��@�j					*
 ************************************************************************************/
int C_DGraphics::FadeOut(int fade_speed ,int texture_alpha) 
{
	alpha = texture_alpha;
	alpha -= fade_speed;

	if(alpha <= 0 )	alpha = 0;

	return alpha;
}

/************************************************************************************
 *	����	�F�t�F�[�h�A�E�g����(float_ver)											*					
 *	����	�Ffloat fade_speed	float texture_alpha:�e�N�X�`����alpha�l				*
 *	�߂�l	�Ffloat alpha															*
 *													by	�O��@�j					*
 ************************************************************************************/
float C_DGraphics::FadeOut(float fade_speed ,float texture_alpha) 
{
	alpha_f = texture_alpha;
	alpha_f -= fade_speed;

	if(alpha_f <= 0 )	alpha_f = 0;

	return alpha_f;
}

/************************************************************************************
 *	����	�F�t�F�[�h�A�E�g����													*
 *	����	�Fint fade_stop: �t�F�[�h�������~����l								*
 *			�Fint fade_speed:����			 int texture_alpha:�e�N�X�`����alpha�l	*
 *	�߂�l	�Fint alpha																*
 *													by	�O��@�j					*
 ************************************************************************************/
int C_DGraphics::FadeOut(int fade_speed ,int texture_alpha, int fade_stop) 
{
	alpha = texture_alpha;
	alpha -= fade_speed;

	if(alpha <= fade_stop )	alpha = fade_stop;

	return alpha;
}

void C_DGraphics::Draw(float x, float y, LPDIRECT3DTEXTURE9 &pTexture, int no, int no2)//���@�[�e�b�N�X��������
{
	float texture_sin,texture_cos;
	float u1,u2,v1,v2;
	float texture_size_x, texture_size_y;

	texture_size_x = abs((int)(position[no2].right - position[no2].left));
	texture_size_y = abs((int)(position[no2].bottom - position[no2].top));

	texture_sin = sinf(D3DXToRadian(angle[no2]));
	texture_cos = cosf(D3DXToRadian(angle[no2]));

	D3DXVECTOR2 vector[] = //��]����G�����Ƃ��Ɏg��
	{
		D3DXVECTOR2(0.f,0.f),
		D3DXVECTOR2(texture_size_x * size_x[no2],0.f),
		D3DXVECTOR2(texture_size_x * size_x[no2],texture_size_y * size_y[no2]),
		D3DXVECTOR2(0.f,texture_size_y * size_y[no2]),
	};

	v1 = position[no2].top		/ height[no];//u�Av�l�̋��߂����@��` / �S�̂̍���
	v2 = position[no2].bottom	/ height[no];
	u1 = position[no2].left		/ width[no];
	u2 = position[no2].right	/ width[no];

	
	CUSTOMVERTEX ver[4] =
	{
		{	0.f	,   0 , 0.5f,1.0f,color[no2],u1,v1}, //����
		{	0.f ,   0 , 0.5f,1.0f,color[no2],u2,v1}, //�E��
		{	0.f ,	0 , 0.5f,1.0f,color[no2],u2,v2}, //�E��
		{	0.f	,	0 , 0.5f,1.0f,color[no2],u1,v2}, //����
	};

	for(int i = 0;i < 4; i++)
	{
		ver[i].x = (vector[i].x * texture_cos) + (vector[i].y * -texture_sin) + x;//��]�̌���
		ver[i].y = (vector[i].x * texture_sin) + (vector[i].y *  texture_cos) + y;
	}

	pD3Device->SetTexture(0,pTexture);
	pD3Device->SetFVF(D3DFVF_CUSTOMVERTEX);
	pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN,2,ver,sizeof(CUSTOMVERTEX));

}

void C_DGraphics::DrawCC(float x, float y, LPDIRECT3DTEXTURE9 &pTexture, int no, int no2)//���@�[�e�b�N�X��������,���S�_��^�񒆂ɂƂ�
{
	float texture_sin,texture_cos;
	float u1,u2,v1,v2;
	float texture_size_x, texture_size_y;

	texture_size_x = (abs((int)(position[no2].right - position[no2].left)) * size_x[no2]);
	texture_size_y = (abs((int)(position[no2].bottom - position[no2].top)) * size_y[no2]);

	texture_sin = sinf(D3DXToRadian(angle[no2]));
	texture_cos = cosf(D3DXToRadian(angle[no2]));

	D3DXVECTOR2 vector[] = //��]����G�����Ƃ��Ɏg��
	{
		D3DXVECTOR2(-texture_size_x / 2.0f,-texture_size_y / 2.0f),
		D3DXVECTOR2( texture_size_x / 2.0f,-texture_size_y / 2.0f),
		D3DXVECTOR2( texture_size_x / 2.0f, texture_size_y / 2.0f),
		D3DXVECTOR2(-texture_size_x / 2.0f, texture_size_y / 2.0f),
	};

	v1 = position[no2].top		/ height[no];//u�Av�l�̋��߂����@�S�̂̍�������`��TOP
	v2 = position[no2].bottom	/ height[no];
	u1 = position[no2].left		/ width[no];
	u2 = position[no2].right	/ width[no];

	
	CUSTOMVERTEX ver[4] =
	{
		{	0.f	,   0 , 0.5f,1.0f,color[no2],u1,v1}, //����
		{	0.f ,   0 , 0.5f,1.0f,color[no2],u2,v1}, //�E��
		{	0.f ,	0 , 0.5f,1.0f,color[no2],u2,v2}, //�E��
		{	0.f	,	0 , 0.5f,1.0f,color[no2],u1,v2}, //����
	};

	for(int i = 0;i < 4; i++)
	{
		ver[i].x = (vector[i].x * texture_cos) + (vector[i].y * -texture_sin) + x;//��]�̌���
		ver[i].y = (vector[i].x * texture_sin) + (vector[i].y *  texture_cos) + y;
	}

	pD3Device->SetTexture(0,pTexture);
	pD3Device->SetFVF(D3DFVF_CUSTOMVERTEX);
	pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN,2,ver,sizeof(CUSTOMVERTEX));

}

void C_DGraphics::DrawCC2(float x, float y, LPDIRECT3DTEXTURE9 &pTexture, int no, int no2)//���@�[�e�b�N�X��������,���S�_��^�񒆂ɂƂ�
{
	float texture_sin,texture_cos;
	float u1,u2,v1,v2;
	float texture_size_x, texture_size_y;

	texture_size_x = (abs((int)(position[no2].right - position[no2].left)) * size_x[no2]);
	texture_size_y = (abs((int)(position[no2].bottom - position[no2].top)) * size_y[no2]);

	texture_sin = sinf(D3DXToRadian(angle[no2]));
	texture_cos = cosf(D3DXToRadian(angle[no2]));

	D3DXVECTOR2 vector[] = //��]����G�����Ƃ��Ɏg��
	{
		D3DXVECTOR2(-texture_size_x / 2.0f,-texture_size_y / 2.0f),
		D3DXVECTOR2( texture_size_x / 2.0f,-texture_size_y / 2.0f),
		D3DXVECTOR2( texture_size_x / 2.0f, texture_size_y / 2.0f),
		D3DXVECTOR2(-texture_size_x / 2.0f, texture_size_y / 2.0f),
	};

	v1 = position[no2].top		/ height[no];//u�Av�l�̋��߂����@�S�̂̍�������`��TOP
	v2 = position[no2].bottom	/ height[no];
	u1 = position[no2].left		/ width[no];
	u2 = position[no2].right	/ width[no];

	
	CUSTOMVERTEX ver[4] =
	{
		{	0.f	,   0 , 0.5f,1.0f,color2[0],u1,v1}, //����
		{	0.f ,   0 , 0.5f,1.0f,color2[1],u2,v1}, //�E��
		{	0.f ,	0 , 0.5f,1.0f,color2[2],u2,v2}, //�E��
		{	0.f	,	0 , 0.5f,1.0f,color2[3],u1,v2}, //����
	};

	for(int i = 0;i < 4; i++)
	{
		ver[i].x = (vector[i].x * texture_cos) + (vector[i].y * -texture_sin) + x;//��]�̌���
		ver[i].y = (vector[i].x * texture_sin) + (vector[i].y *  texture_cos) + y;
	}

	pD3Device->SetTexture(0,pTexture);
	pD3Device->SetFVF(D3DFVF_CUSTOMVERTEX);
	pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN,2,ver,sizeof(CUSTOMVERTEX));

}

void C_DGraphics::RectChange(float &rect1,float &rect2) //��`�̓���ւ��@�L�����̌����ύX�Ɏg�p
{
	float databank; 
	databank = rect1;
	rect1 = rect2;
	rect2 = databank;
}

/************************************************************************************
 *	����	�F��`�𔽓]������														*
 *	����	�Fint num	��`�̔ԍ�													*
 *	�߂�l	�F�Ȃ�																	*
 *													by	�O��@�j					*
 ************************************************************************************/
void C_DGraphics::RectReverse(int num)			
{
	F_RECT copy;

	copy.left	= position[num].left;
	copy.right	= position[num].right;

	position[num].left = copy.right;
	position[num].right= copy.left;

}
 
/************************************************************************************
 *	����	�F�}�b�v�`�b�v�̃Z�b�e�B���O											*
 *	����	�Fint length	�c�̃}�X��												*	
 *			�@int wide		���̃}�X��												*
 *			�@int rect		MAPTIP�̋�`											*
 *			�@int no_rect	��`No													*
 *			�@int field_x	SET����z��x���p										*
 *			�@int field_y	SET����z��y���p										*
 *	�߂�l	�F�Ȃ�																	*
 *													by	�O��@�j					*
 ************************************************************************************/
void C_DGraphics::SetMaptip(int length,int wide,F_RECT rect[],int no_rect,float fieid_x[][20],float fieid_y[][20])
{
	float slide_x  = 0;
	float slide_y  = 0;					//�X���C�h�������(x��),(y��)
	float maptip_x = 0;
	float maptip_y = 0;

	float maptip_over;					//�X���C�h�����鐔�l�̏��

	flag_field[length][wide];
	
	slide_x = (rect[no_rect].right  - rect[no_rect].left) / 2;
	slide_y = (rect[no_rect].bottom - rect[no_rect].top)  / 4;
	maptip_over = slide_x * (float)wide * (float)length / 10;
	//�X���C�h�����鐔�l�����̒l�ȏ�ɂȂ�����܂�0����

	for(int i = 0;i < length;i++){
		maptip_x += slide_x;
		maptip_y += slide_y;
		if(maptip_x > maptip_over){
			maptip_x = 0.f;
			maptip_y = 0.f;
		}
		for(int j = 0;j < wide;j++){
			field_x[i][j]	= (j + 1) * slide_x - maptip_x;			//�`��𒆐S���W�ł����ꍇ��(j + 1)
			field_y[i][j]	= (j + 1) * slide_y + maptip_y;			//���㒆�S�Ȃ炢��Ȃ�
		}
	}

}

