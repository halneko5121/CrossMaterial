/*--------------------------------------------

		DirectSound���C�u����(fmt,bext�`��)
		�����@�FDirectSound�̃��C�u����
		�쐬�ҁF����
		�쐬���F2008�N10��6��
		�X�V���F2008�N11��05��

---------------------------------------------*/

#include "DirectSound.h"

//�O���[�o���ϐ�
LPDIRECTSOUND8 l_pDSoundBS;
LPDIRECTSOUNDBUFFER l_pDPrimaryBS;
LPDIRECTSOUNDBUFFER l_pSoundDataBS[MAX_SOUND];
//HRESULT hr;

HRESULT InitDSound(HWND a_hWnd)
{
	//������
	l_pDSoundBS=NULL;
	l_pDPrimaryBS=NULL;

	for(long i=0;i<MAX_SOUND;i++)
	{
		l_pSoundDataBS[MAX_SOUND];
	}

	//�C���^�[�t�F�[�X�̎擾
	HRESULT hr = DirectSoundCreate8(NULL,&l_pDSoundBS,NULL);
	if(FAILED(hr))
	{
		MessageBox(NULL,TEXT("�C���^�[�t�F�[�X�̎擾�Ɏ��s���܂���"),NULL,MB_OK);
		return E_FAIL;
	}

	//�������x��
	hr = l_pDSoundBS->SetCooperativeLevel(a_hWnd,DSSCL_PRIORITY);
	if(FAILED(hr))
	{
		MessageBox(NULL,TEXT("�������x�̐ݒ�Ɏ��s���܂���"),NULL,MB_OK);
		return E_FAIL;
	}

	//DSBUFFERDESC�\���̂̐ݒ�
	DSBUFFERDESC BufferDesc;
	ZeroMemory(&BufferDesc,sizeof(DSBUFFERDESC));
	//�v���C�}���o�b�t�@�̎w��
	BufferDesc.dwSize = sizeof(DSBUFFERDESC);
	BufferDesc.dwFlags = DSBCAPS_CTRLVOLUME | DSBCAPS_CTRLPAN | DSBCAPS_PRIMARYBUFFER;
	BufferDesc.dwBufferBytes = NULL;
	BufferDesc.lpwfxFormat = NULL;

	//�v���C�}���o�b�t�@�쐬
	hr = l_pDSoundBS->CreateSoundBuffer(&BufferDesc,&l_pDPrimaryBS,NULL);
	if(FAILED(hr))
	{
		MessageBox(NULL,TEXT("�v���C�}���o�b�t�@�̍쐬�ɂɎ��s���܂���"),NULL,MB_OK);
		return E_FAIL;
	}

	WAVEFORMATEX PbWFormatBS;
	ZeroMemory(&PbWFormatBS,sizeof(WAVEFORMATEX));
	//�`��(PCM)
	PbWFormatBS.wFormatTag = WAVE_FORMAT_PCM;
	//�X�e���I
	PbWFormatBS.nChannels = WAV_CHANNNEL;
	//�T���v�����O���[�g44.1kHz
	PbWFormatBS.nSamplesPerSec = WAV_SAMPLESPERSEC;
	//16�r�b�g
	PbWFormatBS.wBitsPerSample = WAV_BITSPERSAMPLE;
	//nSamplesPerSec��wBitsPerSample�̐ς�8�Ŋ������l
	PbWFormatBS.nBlockAlign = (PbWFormatBS.nChannels * PbWFormatBS.wBitsPerSample) / 8;
	//nSamplesPerSec��nBlockAlign�̐ς𓙂�������
	PbWFormatBS.nAvgBytesPerSec = PbWFormatBS.nSamplesPerSec * PbWFormatBS.nBlockAlign;
	
	hr = l_pDPrimaryBS->SetFormat(&PbWFormatBS);
	if (FAILED(hr))
	{
		//�����v���C�}���o�b�t�@�̃t�H�[�}�b�g�ݒ肪���s�����烁�b�Z�[�W���A���Ă���
		MessageBox(NULL,TEXT("�v���C�}���o�b�t�@�̃t�H�[�}�b�g�ݒ�Ɏ��s���܂���"),NULL,MB_OK);
		return E_FAIL;	//���b�Z�[�W��Ԃ�
	}

	return S_OK;
}

void LoadSound(char* a_FileName,long a_ID)
{
	DSBUFFERDESC BufDesc = {sizeof(DSBUFFERDESC)};
	LPDIRECTSOUNDBUFFER lpTempBuf;
	LPBYTE lpData = NULL;
	WAVEFORMATEX wfMat;

	//Wave�t�@�C���t�H�[�}�b�g���ƃf�[�^�擾
	DWORD dataSize = GetWavData(a_FileName,&lpData,&wfMat);
	//����Wave�t�@�C���t�H�[�}�b�g���ƃf�[�^�擾���s�����烁�b�Z�[�W��\��
	if(dataSize == 0)
	{
		MessageBox(NULL,TEXT("Wave�t�@�C���t�H�[�}�b�g���ƃf�[�^�擾�Ɏ��s���܂���"),NULL,MB_OK);
		if(lpData != NULL)
		{
			SAFE_DELETE_ARRYY(lpData);
		}
	}

	//DirectSoundBuffer�ݒ�	
	BufDesc.dwFlags		 = DSBCAPS_LOCSOFTWARE;
	BufDesc.dwBufferBytes   = dataSize;
	BufDesc.lpwfxFormat	 = &wfMat;

	//DirectSoundBuffer����
	HRESULT hr = l_pDSoundBS->CreateSoundBuffer(&BufDesc,&lpTempBuf,NULL);
	//����DirectSoundBuffer���������s�����烁�b�Z�[�W��\��
	if(FAILED(hr))
	{
		MessageBox(NULL,TEXT("DirectSoundBuffer�����Ɏ��s���܂���"),NULL,MB_OK);
		if(lpData != NULL)
		{
			SAFE_DELETE_ARRYY(lpData);
		}
	}

	//DirectSoundBuffer�擾
	hr = lpTempBuf->QueryInterface(IID_IDirectSoundBuffer8,(void**)&l_pSoundDataBS[a_ID]);
	lpTempBuf->Release();
	if(FAILED(hr))
	{
		MessageBox(NULL,TEXT("DirectSoundBuffer�擾�Ɏ��s���܂���"),NULL,MB_OK);
		if(lpData != NULL)
		{
			SAFE_DELETE_ARRYY(lpData);
		}
	}
	
	//�o�b�t�@���b�N
	//�O���[�o���ϐ�
	LPVOID lpSoundData1,lpSoundData2;	
	//lpSoundData1�̓o�b�t�@�̍ŏ��Ƀ��b�N���ꂽ�����ւ̃|�C���^���󂯎��ϐ��̃A�h���X
	//lpSoundData2�̓L���v�`�� �o�b�t�@�� 2 �ԖڂɃ��b�N���ꂽ�����ւ̃|�C���^���󂯎��ϐ��̃A�h���X
	//NULL ���Ԃ��ꂽ�ꍇ�AlpSoundData1 �p�����[�^�̓L���v�`�� �o�b�t�@�̃��b�N���ꂽ�����S�̂��w��
	DWORD size1,size2;
	//size1(lpSoundData1 �̃u���b�N�̃o�C�g�����󂯎��ϐ��̃A�h���X���̒l�� dwBytes ��菬�����ꍇ�A���b�N�̓��b�v����A
	//lpSoundData2 �̓o�b�t�@�̐擪�ɂ���� 2 �̃f�[�^ �u���b�N���w��)
	//size2(lpSoundData2 �̃u���b�N�̃o�C�g�����󂯎��ϐ��̃A�h���X�BlpSoundData2 �� NULL �̏ꍇ�A�l�� 0 �ł���)
	hr = l_pSoundDataBS[a_ID]->Lock(0,dataSize,&lpSoundData1,&size1,&lpSoundData2,&size2,DSBLOCK_ENTIREBUFFER);
	//DSBLOCK_ENTIREBUFFER�̓o�b�t�@�S�̂����b�N����BdwBytes �p�����[�^�͖��������
	//�o�b�t�@���b�N�����s�����烁�b�Z�[�W��\��
	if(FAILED(hr))
	{
		MessageBox(NULL,TEXT("�o�b�t�@���b�N�Ɏ��s���܂���"),NULL,MB_OK);
		if(lpData != NULL)
		{
			SAFE_DELETE_ARRYY(lpData);
		}
	}

	memcpy(lpSoundData1,lpData,dataSize);	//�T�E���h�f�[�^�̓ǂݍ���
	l_pSoundDataBS[a_ID]->Unlock(lpSoundData1,size1,lpSoundData2,size2);	//���b�N����
	if(lpData != NULL)
	{
		SAFE_DELETE_ARRYY(lpData);
	}
}

DWORD GetWavData(char* a_pFile , LPBYTE *a_lpData , WAVEFORMATEX *a_lpwf)
{
	FILE *fp = NULL;
	DWORD result = 0;	//�߂�l
	long riffDataSize;	//�����f�[�^���P�̃t�@�C���Ɋi�[���邽�߂̋��ʃt�H�[�}�b�g�T�C�Y
	long fMatDataSize;	//�t�H�[�}�b�g�f�[�^�T�C�Y
	long dataSize;		//�f�[�^�T�C�Y
	long formatSize;	//�t�H�[�}�b�g�T�C�Y
	char chunk[5] = "";	//�`�����N
	char TempBuff[1024];

	*a_lpData = NULL;

	fp = fopen(a_pFile,"rb");		//�t�@�C���I�[�v��
	if(fp == NULL)
	{
		//�t�@�C�����Ȃ����܂��̓p�X���Ⴄ
		if(fp !=NULL)
		{
			fclose(fp);
		}
		return 0;
	}
	fread(chunk,sizeof(char),4,fp);//RIFF�̕�����
	if(strcmp("RIFF",chunk))
	{
		//RIFF�����������͂Ȃ�Ȃ�
		if(fp !=NULL)
		{
			fclose(fp);
		}
		return 0;
	}
	fread(&riffDataSize,sizeof(long),1,fp);	//RILF�f�[�^�T�C�Y
	fread(chunk,sizeof(char),4,fp);			//WAVE�̕�����
	if(strcmp("WAVE",chunk))
	{
		//WAVE�����������͂Ȃ�Ȃ�
		if(fp !=NULL)
		{
			fclose(fp);
		}
		return 0;
	}

//bext�`����wave�t�@�C��
	fread(chunk,sizeof(char),4,fp);	//bext �܂��́Afmt�̕�����
	if(!strcmp("bext",chunk))
	{
		fread(&fMatDataSize,sizeof(long),1,fp);	//bext�f�[�^�T�C�Y
		fread(TempBuff,fMatDataSize,1,fp);
		fread(chunk,sizeof(char),4,fp);	//fmt�̕�����
	}

//fmt�`����wave�t�@�C��
	if(strcmp("fmt ",chunk))
	{
		//fmt�����������͂Ȃ�Ȃ�
		if(fp != NULL)
		{
			fclose(fp);
		}
		return 0;
	}
	fread(&fMatDataSize,sizeof(long),1,fp);	//fmt�f�[�^�T�C�Y
	formatSize = sizeof(WAVEFORMATEX);		//�t�H�[�}�b�g���擾
	fread(a_lpwf,formatSize,1,fp);

	//PCM�̎�
	if(a_lpwf->wFormatTag == 1)
	{
		//�ǉ��f�[�^�Ȃ�
		a_lpwf->cbSize = 0;
	}
	fseek(fp,fMatDataSize-sizeof(WAVEFORMATEX),SEEK_CUR);

	//Data�`�����N����
	while(true)
	{
		fread(chunk,sizeof(char),4,fp);
		if(feof(fp))
		{
			//EOF���������ꂽ�炨������
			if(fp !=NULL)
			{
				fclose(fp);
			}
			return 0;
		}
		if(strcmp("data",chunk) == 0)
		{
			break;
		}
		else
		{
			DWORD size;
			fread(&size,sizeof(DWORD),1,fp);
			fseek(fp,size,SEEK_CUR);
		}
	}
	fread(&dataSize,sizeof(long),1,fp);//�f�[�^�T�C�Y
	*a_lpData = new BYTE[dataSize];
	fread(*a_lpData,sizeof(BYTE),dataSize,fp);
	result = dataSize;
	if(fp != NULL)
	{
		fclose(fp);
	}
	return result;
}

void SoundPlay(bool a_loop , long a_ID)
{
	if(!l_pSoundDataBS[a_ID])
	{
		//�����Đ��������T�E���h�f�[�^��������
		MessageBox(NULL,TEXT("�Đ����悤�Ƃ��Ă���T�E���h�f�[�^������܂���"),NULL,MB_OK);
		return;
	}
	if(SoundCheck(a_ID))
	{
		MessageBox(NULL,TEXT("�Đ�����Ă��܂�"),NULL,MB_OK);
		return;
	}
	HRESULT hr = l_pSoundDataBS[a_ID]->Play(NULL,NULL,DSBPLAY_LOOPING & a_loop);
	if(FAILED(hr))
	{
		//���[�v���Ȃ�������
		l_pSoundDataBS[a_ID]->Release();	//�Ăъm��
	}
}

bool SoundCheck(long a_ID)
{
	DWORD state;
	l_pSoundDataBS[a_ID]->GetStatus(&state);	//���̏�Ԃ��擾
	if(state == DSBSTATUS_PLAYING)	//�Đ�����Ă�����
	{
		return true;
	}
	return false;
}

//�܂��{�����[�����������i�T�E���hID�ł̈����̕������{�����[���`�F���W���ł��Ȃ��j
void VolumeChange(LONG a_vol/* , long a_ID*/)
{
	HRESULT hr;
	//if(!l_pSoundDataBS[a_ID])
	//{
	//	//�Đ����悤�Ƃ��Ă���T�E���h�f�[�^���Ȃ���
	//	MessageBox(NULL,TEXT("�Đ����悤�Ƃ��Ă���T�E���h�f�[�^������܂���"),NULL,MB_OK);
	//	return;
	//}
	LONG * vol = new LONG;
	////LONG *vol = DSBVOLUME_MAX;
	////vol = DSBVOLUME_MAX;
	//HRESULT hr = l_pSoundDataBS[a_ID]->GetVolume(vol);
	//if(FAILED(hr))
	//{
	//	MessageBox(NULL,TEXT("���݂̉��ʂ��擾�ł��܂���"),NULL,MB_OK);
	//	return;
	//}
	//a_vol +=(*vol);	//���ʂ��グ��or������
	//delete vol;	//�폜
//	HRESULT hr = l_pSoundDataBS[a_ID]->SetVolume(a_vol);	//�グ����̉��ʂ��Z�b�g����
	if(l_pDPrimaryBS){
		l_pDPrimaryBS->GetVolume(vol);
	//	l_pSoundDataBS[a_ID]=l_pDPrimaryBS;
		hr = l_pDPrimaryBS->SetVolume(a_vol);	//�グ����̉��ʂ��Z�b�g����
	}
	if(hr == DSERR_BUFFERLOST)
	{
		//l_pSoundDataBS[a_ID]->Release();	//�Ċm��
		l_pDPrimaryBS->Release();	//�Ċm��

	}
}

void SoundStop(bool a_reset,long a_ID)
{
	if(l_pSoundDataBS[a_ID])	//�T�E���h�Đ����ł����
	{
		l_pSoundDataBS[a_ID]->Stop();	//�T�E���h��~
		if(a_reset)
		{
			l_pSoundDataBS[a_ID]->SetCurrentPosition(NULL);		//���y�����Z�b�g����B
		}
	}
}

void SoundRelease(long a_ID)
{
	SoundStop(true,a_ID);	//�Đ�����Ă���T�E���h���~�߂�
	SAFE_RELEASE(l_pSoundDataBS[a_ID]);	//�o�b�t�@���
}

void ReleaseDsound(void)
{
	for(long i=0;i<MAX_SOUND;i++)
	{
		SoundStop(true,i);	//�Đ�����Ă���T�E���h�����ׂăX�g�b�v
		SAFE_RELEASE(l_pSoundDataBS[i]);	//�o�b�t�@���
	}
	//DirectSound�I�u�W�F�N�g���
	SAFE_RELEASE(l_pDPrimaryBS);
	SAFE_RELEASE(l_pDSoundBS);
}
