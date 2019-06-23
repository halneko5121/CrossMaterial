#include "FileControl.h"

/************************************************************************************
 *																					*
 *	�����F�t�@�C���̓ǂݍ��݂����܂�												*
 *																					*
 *	�����F�e�L�X�g�t�@�C�����當����l��ǂݍ��݃Z�b�g���܂�						*
 *																					*
 *	�쐬���F2009�N 2 ��15��															*
 *																					*
 *	�X�V���F�N �� ��																*
 *													by	�O��@�j					*
 *																					*
 ************************************************************************************/

C_FileControl::C_FileControl(void)
{
}

C_FileControl::~C_FileControl(void)
{
}

void C_FileControl::Init()
{
	for(int i = 0;i < MAX_FOLDER;i++) string_section[i] = 0;
}

void C_FileControl::Init(int folder_num)
{
	string_section[folder_num] = 0;
}

/************************************************************************************
 *	����	�F�e�L�X�g�ǂݍ���														*
 *	����	�Fchar*  filefolder		�t�@�C���̃t�H���_���ւ̃|�C���^				*
 *		    �Fchar*  filename		�t�@�C�����ւ̃|�C���^							*
 *			�Fchar** file_string	�t�@�C�����̕��͂ւ̃|�C���^					*
 *			�Fint	 kind_folder 	�t�H���_�̎��(����	0:CG 1:SD 2:Script 3:Rect)  *
 *	�߂�l	�Fchar** file_string	�t�@�C���{�����i�[���ꂽchar�|�C���^�ւ̃|�C���^*
 *													by	�O��@�j					*
 ************************************************************************************/
char** C_FileControl::SetText(char* filefolder,char* filename, char** file_string, int kind_folder)
{
	memset(text_buffer,'\0', sizeof(char)	* MAX_STRING);
	memset(l_talk_no,  '\0', sizeof(char)	* MAX_STRING);

	sprintf_s(l_talk_no,"%s%s.txt",filefolder,filename);		//�ǂݍ��ރt�H���_���w��

	err = fopen_s(&fp,l_talk_no,"r");							//�t�@�C����ǂݍ���

	if(err != NULL)	perror("�t�@�C���I�[�v���G���[");

	while(fscanf(fp,"%s",text_buffer) != EOF){					//�t�@�C���̏I�[�łȂ����
		string_section[kind_folder]++;							//�s�����J�E���g����B
		memset(text_buffer,'\0', sizeof(char) * MAX_STRING);
	}

	fseek(fp,0L,SEEK_SET);										//�t�@�C���̐擪�ɃA�h���X��߂�

	file_string = new char * [string_section[kind_folder]];//���̐��������������m�ۂ���B

	for(int i = 0;i < string_section[kind_folder];i++){
		file_string[i] = new char[MAX_STRING];			//1�s���̃��������m�ۂ���B
	}
	for(int i = 0;i < string_section[kind_folder];i++){
		fscanf(fp,"%s",file_string[i]);
	}

	fclose(fp);	  //�t�@�C�������B

	return file_string;
}