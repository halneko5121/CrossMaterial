/*-------------------------------------------------

		�}�N���̊Ǘ�
		�����@�FMacro�̃w�b�_�[
		�쐬�ҁF����
		�쐬���F10��22��
		�X�V���F10��22��

---------------------------------------------------*/
#ifndef _MACRO_H_
#define _MACRO_H_

//�������̉���iNULL �𔻒肵�āA�J������Ă��Ȃ� Object Class �Ȃǂ��J�����܂��j
#define SAFE_DELETE(p) {if(p){delete(p); (p) = NULL;}}
//�Q�ƃJ�E���^�̃f�N�������g
#define SAFE_RELEASE(p) {if(p){(p)->Release();(p) = NULL;}}

//�f���[�g�}�N��
#define SAFE_DELETE_ARRYY(x) {if(x){delete[](x);(x) = NULL;}}

#endif	//_MACRO_H_