/*--------------------------------------------

		DirectSoundライブラリ(fmt,bext形式)
		説明　：DirectSoundのライブラリ
		作成者：兼武
		作成日：2008年10月6日
		更新日：2008年11月05日

---------------------------------------------*/

#include "DirectSound.h"

//グローバル変数
LPDIRECTSOUND8 l_pDSoundBS;
LPDIRECTSOUNDBUFFER l_pDPrimaryBS;
LPDIRECTSOUNDBUFFER l_pSoundDataBS[MAX_SOUND];
//HRESULT hr;

HRESULT InitDSound(HWND a_hWnd)
{
	//初期化
	l_pDSoundBS=NULL;
	l_pDPrimaryBS=NULL;

	for(long i=0;i<MAX_SOUND;i++)
	{
		l_pSoundDataBS[MAX_SOUND];
	}

	//インターフェースの取得
	HRESULT hr = DirectSoundCreate8(NULL,&l_pDSoundBS,NULL);
	if(FAILED(hr))
	{
		MessageBox(NULL,TEXT("インターフェースの取得に失敗しました"),NULL,MB_OK);
		return E_FAIL;
	}

	//協調レベル
	hr = l_pDSoundBS->SetCooperativeLevel(a_hWnd,DSSCL_PRIORITY);
	if(FAILED(hr))
	{
		MessageBox(NULL,TEXT("協調レベの設定に失敗しました"),NULL,MB_OK);
		return E_FAIL;
	}

	//DSBUFFERDESC構造体の設定
	DSBUFFERDESC BufferDesc;
	ZeroMemory(&BufferDesc,sizeof(DSBUFFERDESC));
	//プライマリバッファの指定
	BufferDesc.dwSize = sizeof(DSBUFFERDESC);
	BufferDesc.dwFlags = DSBCAPS_CTRLVOLUME | DSBCAPS_CTRLPAN | DSBCAPS_PRIMARYBUFFER;
	BufferDesc.dwBufferBytes = NULL;
	BufferDesc.lpwfxFormat = NULL;

	//プライマリバッファ作成
	hr = l_pDSoundBS->CreateSoundBuffer(&BufferDesc,&l_pDPrimaryBS,NULL);
	if(FAILED(hr))
	{
		MessageBox(NULL,TEXT("プライマリバッファの作成にに失敗しました"),NULL,MB_OK);
		return E_FAIL;
	}

	WAVEFORMATEX PbWFormatBS;
	ZeroMemory(&PbWFormatBS,sizeof(WAVEFORMATEX));
	//形式(PCM)
	PbWFormatBS.wFormatTag = WAVE_FORMAT_PCM;
	//ステレオ
	PbWFormatBS.nChannels = WAV_CHANNNEL;
	//サンプリングレート44.1kHz
	PbWFormatBS.nSamplesPerSec = WAV_SAMPLESPERSEC;
	//16ビット
	PbWFormatBS.wBitsPerSample = WAV_BITSPERSAMPLE;
	//nSamplesPerSecとwBitsPerSampleの積を8で割った値
	PbWFormatBS.nBlockAlign = (PbWFormatBS.nChannels * PbWFormatBS.wBitsPerSample) / 8;
	//nSamplesPerSecとnBlockAlignの積を等しくする
	PbWFormatBS.nAvgBytesPerSec = PbWFormatBS.nSamplesPerSec * PbWFormatBS.nBlockAlign;
	
	hr = l_pDPrimaryBS->SetFormat(&PbWFormatBS);
	if (FAILED(hr))
	{
		//もしプライマリバッファのフォーマット設定が失敗したらメッセージが帰ってくる
		MessageBox(NULL,TEXT("プライマリバッファのフォーマット設定に失敗しました"),NULL,MB_OK);
		return E_FAIL;	//メッセージを返す
	}

	return S_OK;
}

void LoadSound(char* a_FileName,long a_ID)
{
	DSBUFFERDESC BufDesc = {sizeof(DSBUFFERDESC)};
	LPDIRECTSOUNDBUFFER lpTempBuf;
	LPBYTE lpData = NULL;
	WAVEFORMATEX wfMat;

	//Waveファイルフォーマット情報とデータ取得
	DWORD dataSize = GetWavData(a_FileName,&lpData,&wfMat);
	//もしWaveファイルフォーマット情報とデータ取得失敗したらメッセージを表示
	if(dataSize == 0)
	{
		MessageBox(NULL,TEXT("Waveファイルフォーマット情報とデータ取得に失敗しました"),NULL,MB_OK);
		if(lpData != NULL)
		{
			SAFE_DELETE_ARRYY(lpData);
		}
	}

	//DirectSoundBuffer設定	
	BufDesc.dwFlags		 = DSBCAPS_LOCSOFTWARE;
	BufDesc.dwBufferBytes   = dataSize;
	BufDesc.lpwfxFormat	 = &wfMat;

	//DirectSoundBuffer生成
	HRESULT hr = l_pDSoundBS->CreateSoundBuffer(&BufDesc,&lpTempBuf,NULL);
	//もしDirectSoundBuffer生成が失敗したらメッセージを表示
	if(FAILED(hr))
	{
		MessageBox(NULL,TEXT("DirectSoundBuffer生成に失敗しました"),NULL,MB_OK);
		if(lpData != NULL)
		{
			SAFE_DELETE_ARRYY(lpData);
		}
	}

	//DirectSoundBuffer取得
	hr = lpTempBuf->QueryInterface(IID_IDirectSoundBuffer8,(void**)&l_pSoundDataBS[a_ID]);
	lpTempBuf->Release();
	if(FAILED(hr))
	{
		MessageBox(NULL,TEXT("DirectSoundBuffer取得に失敗しました"),NULL,MB_OK);
		if(lpData != NULL)
		{
			SAFE_DELETE_ARRYY(lpData);
		}
	}
	
	//バッファロック
	//グローバル変数
	LPVOID lpSoundData1,lpSoundData2;	
	//lpSoundData1はバッファの最初にロックされた部分へのポインタを受け取る変数のアドレス
	//lpSoundData2はキャプチャ バッファの 2 番目にロックされた部分へのポインタを受け取る変数のアドレス
	//NULL が返された場合、lpSoundData1 パラメータはキャプチャ バッファのロックされた部分全体を指す
	DWORD size1,size2;
	//size1(lpSoundData1 のブロックのバイト数を受け取る変数のアドレスこの値が dwBytes より小さい場合、ロックはラップされ、
	//lpSoundData2 はバッファの先頭にある第 2 のデータ ブロックを指す)
	//size2(lpSoundData2 のブロックのバイト数を受け取る変数のアドレス。lpSoundData2 が NULL の場合、値は 0 である)
	hr = l_pSoundDataBS[a_ID]->Lock(0,dataSize,&lpSoundData1,&size1,&lpSoundData2,&size2,DSBLOCK_ENTIREBUFFER);
	//DSBLOCK_ENTIREBUFFERはバッファ全体をロックする。dwBytes パラメータは無視される
	//バッファロックが失敗したらメッセージを表示
	if(FAILED(hr))
	{
		MessageBox(NULL,TEXT("バッファロックに失敗しました"),NULL,MB_OK);
		if(lpData != NULL)
		{
			SAFE_DELETE_ARRYY(lpData);
		}
	}

	memcpy(lpSoundData1,lpData,dataSize);	//サウンドデータの読み込み
	l_pSoundDataBS[a_ID]->Unlock(lpSoundData1,size1,lpSoundData2,size2);	//ロック解除
	if(lpData != NULL)
	{
		SAFE_DELETE_ARRYY(lpData);
	}
}

DWORD GetWavData(char* a_pFile , LPBYTE *a_lpData , WAVEFORMATEX *a_lpwf)
{
	FILE *fp = NULL;
	DWORD result = 0;	//戻り値
	long riffDataSize;	//音声データを１つのファイルに格納するための共通フォーマットサイズ
	long fMatDataSize;	//フォーマットデータサイズ
	long dataSize;		//データサイズ
	long formatSize;	//フォーマットサイズ
	char chunk[5] = "";	//チャンク
	char TempBuff[1024];

	*a_lpData = NULL;

	fp = fopen(a_pFile,"rb");		//ファイルオープン
	if(fp == NULL)
	{
		//ファイルがないかまたはパスが違う
		if(fp !=NULL)
		{
			fclose(fp);
		}
		return 0;
	}
	fread(chunk,sizeof(char),4,fp);//RIFFの文字列
	if(strcmp("RIFF",chunk))
	{
		//RIFFよりも小さくはならない
		if(fp !=NULL)
		{
			fclose(fp);
		}
		return 0;
	}
	fread(&riffDataSize,sizeof(long),1,fp);	//RILFデータサイズ
	fread(chunk,sizeof(char),4,fp);			//WAVEの文字列
	if(strcmp("WAVE",chunk))
	{
		//WAVEよりも小さくはならない
		if(fp !=NULL)
		{
			fclose(fp);
		}
		return 0;
	}

//bext形式のwaveファイル
	fread(chunk,sizeof(char),4,fp);	//bext または、fmtの文字列
	if(!strcmp("bext",chunk))
	{
		fread(&fMatDataSize,sizeof(long),1,fp);	//bextデータサイズ
		fread(TempBuff,fMatDataSize,1,fp);
		fread(chunk,sizeof(char),4,fp);	//fmtの文字列
	}

//fmt形式のwaveファイル
	if(strcmp("fmt ",chunk))
	{
		//fmtよりも小さくはならない
		if(fp != NULL)
		{
			fclose(fp);
		}
		return 0;
	}
	fread(&fMatDataSize,sizeof(long),1,fp);	//fmtデータサイズ
	formatSize = sizeof(WAVEFORMATEX);		//フォーマット情報取得
	fread(a_lpwf,formatSize,1,fp);

	//PCMの時
	if(a_lpwf->wFormatTag == 1)
	{
		//追加データなし
		a_lpwf->cbSize = 0;
	}
	fseek(fp,fMatDataSize-sizeof(WAVEFORMATEX),SEEK_CUR);

	//Dataチャンク検索
	while(true)
	{
		fread(chunk,sizeof(char),4,fp);
		if(feof(fp))
		{
			//EOFが発見されたらおかしい
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
	fread(&dataSize,sizeof(long),1,fp);//データサイズ
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
		//もし再生したいサウンドデータが無い時
		MessageBox(NULL,TEXT("再生しようとしているサウンドデータがありません"),NULL,MB_OK);
		return;
	}
	if(SoundCheck(a_ID))
	{
		MessageBox(NULL,TEXT("再生されています"),NULL,MB_OK);
		return;
	}
	HRESULT hr = l_pSoundDataBS[a_ID]->Play(NULL,NULL,DSBPLAY_LOOPING & a_loop);
	if(FAILED(hr))
	{
		//ループしなかったら
		l_pSoundDataBS[a_ID]->Release();	//再び確保
	}
}

bool SoundCheck(long a_ID)
{
	DWORD state;
	l_pSoundDataBS[a_ID]->GetStatus(&state);	//今の状態を取得
	if(state == DSBSTATUS_PLAYING)	//再生されていたら
	{
		return true;
	}
	return false;
}

//まだボリュームが未完成（サウンドIDでの引数の部分がボリュームチェンジができない）
void VolumeChange(LONG a_vol/* , long a_ID*/)
{
	HRESULT hr;
	//if(!l_pSoundDataBS[a_ID])
	//{
	//	//再生しようとしているサウンドデータがない時
	//	MessageBox(NULL,TEXT("再生しようとしているサウンドデータがありません"),NULL,MB_OK);
	//	return;
	//}
	LONG * vol = new LONG;
	////LONG *vol = DSBVOLUME_MAX;
	////vol = DSBVOLUME_MAX;
	//HRESULT hr = l_pSoundDataBS[a_ID]->GetVolume(vol);
	//if(FAILED(hr))
	//{
	//	MessageBox(NULL,TEXT("現在の音量を取得できません"),NULL,MB_OK);
	//	return;
	//}
	//a_vol +=(*vol);	//音量を上げるor下げる
	//delete vol;	//削除
//	HRESULT hr = l_pSoundDataBS[a_ID]->SetVolume(a_vol);	//上げた後の音量をセットする
	if(l_pDPrimaryBS){
		l_pDPrimaryBS->GetVolume(vol);
	//	l_pSoundDataBS[a_ID]=l_pDPrimaryBS;
		hr = l_pDPrimaryBS->SetVolume(a_vol);	//上げた後の音量をセットする
	}
	if(hr == DSERR_BUFFERLOST)
	{
		//l_pSoundDataBS[a_ID]->Release();	//再確保
		l_pDPrimaryBS->Release();	//再確保

	}
}

void SoundStop(bool a_reset,long a_ID)
{
	if(l_pSoundDataBS[a_ID])	//サウンド再生中であれば
	{
		l_pSoundDataBS[a_ID]->Stop();	//サウンド停止
		if(a_reset)
		{
			l_pSoundDataBS[a_ID]->SetCurrentPosition(NULL);		//音楽をリセットする。
		}
	}
}

void SoundRelease(long a_ID)
{
	SoundStop(true,a_ID);	//再生されているサウンドを止める
	SAFE_RELEASE(l_pSoundDataBS[a_ID]);	//バッファ解放
}

void ReleaseDsound(void)
{
	for(long i=0;i<MAX_SOUND;i++)
	{
		SoundStop(true,i);	//再生されているサウンドをすべてストップ
		SAFE_RELEASE(l_pSoundDataBS[i]);	//バッファ解放
	}
	//DirectSoundオブジェクト解放
	SAFE_RELEASE(l_pDPrimaryBS);
	SAFE_RELEASE(l_pDSoundBS);
}
