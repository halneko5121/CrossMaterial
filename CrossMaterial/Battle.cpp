#include "Battle.h"

//������A�g�b�v�Ń{�g���Ń��t�g�Ń��C�g�B
F_RECT rect_battle[] =			//�e�R�}���h�̋�`
{
	{0.f,600.f,0.f,800.f},		//�X�e�[�^�X		0
	{20.f,49.f,0.f,59.f},		//����������		1
	{0.f,19.f,400.f,439.f},		//�HP�����			2
	{0.f,19.f,440.f,479.f},		//�AP�����			3
	{0.f,19.f,240.f,279.f},		//�MG�����			4
	{0.f,19.f,0.f,59.f},		//�ATK�����			5
	{0.f,19.f,60.f,119.f},		//�DEF�����			6
	{0.f,19.f,340.f,399.f},		//�DEX�����			7
	{0.f,19.f,280.f,339.f},		//�AGL�����			8
	{20.f,49.f,60.f,209.f},		//��}�g���N�X�����	9
	{20.f,49.f,210.f,359.f},	//��}�e���A�������	10
	{20.f,49.f,480.f,569.f},	//����꣕���		11
	{0.f,20.f,480.f,559.f},		//�AP_P�����		12
	{0.f,19.f,120.f,179.f},		//�MAG�����			13
	{0.f,19.f,180.f,239.f},		//�RES�����			14
	{0.f,19.f,560.f,619.f},		//�MOV�����			15
	{0.f,19.f,620.f,679.f},		//�LUK�����			16
	{20.f,49.f,0.f,59.f},		//����������		17
	{21.f,50.f,361.f,480.f},	//�����AP�����		18
	{21.f,50.f,361.f,480.f},	//�����AP�����		19
	{380.f,409.f,300.f,329.f},	//��^��̕���		20
	{380.f,409.f,300.f,329.f},	//��^��̕���		21
	{380.f,409.f,300.f,329.f},	//��^��̕���		22
	{380.f,409.f,0.f,29.f},		//�����̕S��		23
	{380.f,409.f,0.f,29.f},		//�����\��			24
	{380.f,409.f,0.f,29.f},		//�����̈ꌅ		25
	{50.f,79.f,30.f,59.f},		//�����鑮��1		26
	{50.f,79.f,30.f,59.f},		//�����鑮��2		27
	{80.f,109.f,0.f,119.f},		//�}�g���N�X��		28
	{411.f,439.f,3.f,126.f},	//�}�e���A����		29�@��

	{111.f,140.f,644.f,855.f},	//�����ٴ��ޣ		30
	{111.f,140.f,460.f,619.f},	//��������			31
	{111.f,140.f, 13.f,197.f},	//�˰ٳ���ޣ		32
	{111.f,140.f,225.f,435.f},	//��װ�ޭ���ޣ		33
	{171.f,200.f,  2.f, 88.f},	//��������			34
	{171.f,200.f, 93.f,177.f},	//��������			35
	{171.f,200.f,183.f,268.f},	//��n�Ӑo�			36
	{171.f,200.f,272.f,357.f},	//��|�����			37
	{201.f,230.f,465.f,675.f},	//���ڲ����گģ		40
	{201.f,230.f,695.f,804.f},	//��ް�ģ			39
	{201.f,230.f,198.f,431.f},	//��۰�����گģ		38
	{201.f,230.f,  9.f,170.f},	//��������			41

	{261.f,290.f,217.f,353.f},	//�����ٴ��ޣ�ڍ�	42
	{261.f,290.f,  3.f, 88.f},	//�����˰٣�ڍ�		43
	{261.f,290.f, 98.f,202.f},	//��װ���ޣ�ڍ�		44

	{291.f,320.f,  1.f,239.f},	//���������ڍ�		45
	{291.f,320.f,253.f,557.f},	//���������ڍ�		46
	{291.f,320.f,581.f,769.f},	//��n�Ӑo��ڍ�		47
	{321.f,350.f, 15.f,315.f},	//��|������ڍ�		48
	{351.f,380.f,337.f,473.f},	//���ڲ����گģ�ڍ�	49@
	{351.f,380.f,496.f,703.f},	//��ް�ģ�ڍ�		50@
	{351.f,380.f, 21.f,308.f},	//��۰�����گģ�ڍ�	51@
	{0.f,30.f,0.f,299.f},		//���ׂ���Ȱѣ		52
	{0.f,512.f,0.f,349.f},		//��V�I���̂b�f�	53
	{0.f,512.f,0.f,349.f},		//����@���̂b�f�	54
	{0.f,512.f,0.f,349.f},		//����I�̂b�f�		55
	//�o�g��
	{  0.f,600.f,  0.f,800.f},		//�o�g�����̔w�i
	{  0.f,600.f,  0.f,800.f},		//���������\�����̔w�i
	{160.f,219.f,  0.f,295.f},		//"��������"
	{160.f,219.f,330.f,590.f},		//"�s�k����"
	{ 42.f, 79.f,  0.f,200.f},		//���������@
	{ 42.f, 79.f,205.f,475.f},		//���������A
	{ 42.f, 79.f,475.f,610.f},		//�s�k�����@
	{ 80.f,159.f,  0.f,399.f},		//���t�F�C�Y
	{ 80.f,159.f,400.f,799.f},		//�G�t�F�C�Y
	{  0.f, 41.f,  0.f,121.f},		//�ړ�
	{  0.f, 41.f,121.f,242.f},		//�U��
	{  0.f, 41.f,363.f,484.f},		//���`
	{  0.f, 41.f,242.f,363.f},		//����
	{  0.f, 41.f,484.f,605.f},		//�X�e�[�^�X
	{  0.f, 41.f,605.f,726.f},		//�ҋ@

//�X�e�[�W
	{  0.0f, 99.0f,  0.0f, 99.0f},  //�T�{�e��1		//������4�͏�Q����
	{  0.0f, 99.0f,100.0f,199.0f},  //�T�{�e��2
	{  0.0f, 99.0f,200.0f,299.0f},  //��1
	{  0.0f, 99.0f,300.0f,399.0f},  //��2

	{100.0f,199.0f,  0.0f, 99.0f},  //�r��1			//���������Q������Ȃ���
	{100.0f,199.0f,100.0f,199.0f},  //�r��2
	{100.0f,199.0f,200.0f,299.0f},  //�r��3
	{100.0f,199.0f,300.0f,399.0f},  //�r��4

	{200.0f,299.0f,  0.0f, 99.0f},  //���n1
	{200.0f,299.0f,100.0f,199.0f},  //���n2
	{200.0f,299.0f,200.0f,299.0f},  //���n3
	{200.0f,299.0f,300.0f,399.0f},  //���n4

	{300.f,424.f,  0.f, 99.f},		//�J�[�\��
	{300.f,424.f,100.f,199.f},		//�ړ��\�G���A

	//�L�����N�^�[
	{  0.f,124.f,  0.f, 99.f},		//�L�����ҋ@
	{  0.f,124.f,100.f,199.f},
	{  0.f,124.f,200.f,299.f},
	{  0.f,124.f,300.f,399.f},

	{125.f,249.f,  0.f, 99.f},		//�L�����U��(���O)
	{125.f,249.f,100.f,199.f},
	{125.f,249.f,200.f,299.f},
	{125.f,249.f,300.f,399.f},
	{250.f,374.f,  0.f, 99.f},		//�L�����U��(����)
	{250.f,374.f,100.f,199.f},
	{250.f,374.f,200.f,299.f},
	{250.f,374.f,300.f,399.f},
	{375.f,499.f,  0.f, 99.f},		//�L�����U��(�E�O)
	{375.f,499.f,100.f,199.f},
	{375.f,499.f,200.f,299.f},
	{375.f,499.f,300.f,399.f},
	{500.f,624.f,  0.f, 99.f},		//�L�����U��(�E��)
	{500.f,624.f,100.f,199.f},
	{500.f,624.f,200.f,299.f},
	{500.f,624.f,300.f,399.f},

	{125.f,274.f,  0.f, 99.f},		//�V�I���U��(���O)
	{125.f,274.f,100.f,199.f},
	{125.f,274.f,200.f,299.f},
	{125.f,274.f,300.f,399.f},
	{425.f,574.f,  0.f, 99.f},		//�V�I���U��(�E�O)
	{425.f,574.f,100.f,199.f},
	{425.f,574.f,200.f,299.f},
	{425.f,574.f,300.f,399.f},

	{ 90.f,139,  0.f,450.f},			//�Q�[���I�[�o�[
	{  0.f, 39,  0.f,119.f},			//�V�I�����O
	{  0.f, 39,120.f,243.f},			//���@�����O
	{  0.f, 39,760.f,839.f},			//���I���O
	{381.f,410.f,330.f,369.f},			//�A�C�R��
	{411.f,438.f,203.f,278.f},	//�}�e���A����	��	
	{411.f,439.f,384.f,447.f},	//�}�e���A����	��	
	{411.f,440.f,529.f,583.f},	//�}�e���A����	�y

	{  0.f,169.f,741.f,910.f},	//�ȈՃX�e�[�^�X�n�`�w�i
	{51.f,80.f,0.f,29.f},		//�n�`���ʁu�E�v
	{226.f,392.f,1.f,322.f},	//�ȈՃX�e�[�^�X�L�����w�i
	{450.f,469.f,0.f,19.f},		//�����̕S��(�ȈՃX�e�[�^�X�p�̐���)
	{450.f,469.f,0.f,19.f},		//�����\��(�ȈՃX�e�[�^�X�p�̐���)		
	{450.f,469.f,0.f,19.f},		//�����̈ꌅ(�ȈՃX�e�[�^�X�p�̐���)		

	{450.f,469.f,200.f,219.f},	//��^��̕���(�ȈՃX�e�[�^�X�p)	
	{145.f,175.f,0.f,59.f},		//���ׂ���Ȱѣ(�ȈՃX�e�[�^�X�p,�T�C�Y��ύX�p)
	{396.f,425.f,0.f,29.f}, 	//��������

	{  0.f,124.f,  0.f, 99.f},		//�V�I���ҋ@(���O�j
	{  0.f,124.f,100.f,199.f},		//(����)
	{  0.f,124.f,200.f,299.f},		//(�E�O�j
	{  0.f,124.f,300.f,399.f},		//(�E��)
	{125.f,274.f,  0.f, 99.f},		//�V�I���U��(���O)
	{125.f,274.f,100.f,199.f},
	{125.f,274.f,200.f,299.f},
	{125.f,274.f,300.f,399.f},
	{275.f,424.f,  0.f, 99.f},		//�V�I���U��(����)
	{275.f,424.f,100.f,199.f},
	{275.f,424.f,200.f,299.f},
	{275.f,424.f,300.f,399.f},
	{425.f,574.f,  0.f, 99.f},		//�V�I���U��(�E�O)
	{425.f,574.f,100.f,199.f},
	{425.f,574.f,200.f,299.f},
	{425.f,574.f,300.f,399.f},
	{575.f,724.f,  0.f, 99.f},		//�V�I���U��(�E��)
	{575.f,724.f,100.f,199.f},
	{575.f,724.f,200.f,299.f},
	{575.f,724.f,300.f,399.f},
	{  0.f,124.f,  0.f, 99.f},		//���@���ҋ@
	{  0.f,124.f,100.f,199.f},
	{  0.f,124.f,200.f,299.f},
	{  0.f,124.f,300.f,399.f},
	{125.f,274.f,  0.f,149.f},		//���@���U��(���O)
	{125.f,274.f,150.f,299.f},
	{125.f,274.f,300.f,449.f},
	{125.f,274.f,450.f,599.f},
	{275.f,424.f,  0.f,149.f},		//���@���U��(����)
	{275.f,424.f,150.f,299.f},
	{275.f,424.f,300.f,449.f},
	{275.f,424.f,450.f,599.f},
	{425.f,574.f,  0.f,149.f},		//���@���U��(�E�O)
	{425.f,574.f,150.f,299.f},
	{425.f,574.f,300.f,449.f},
	{425.f,574.f,450.f,599.f},
	{575.f,724.f,  0.f,149.f},		//���@���U��(�E��)
	{575.f,724.f,150.f,299.f},
	{575.f,724.f,300.f,449.f},
	{575.f,724.f,450.f,599.f},
	{  0.f,124.f,  0.f, 99.f},		//���I�ҋ@
	{  0.f,124.f,100.f,199.f},
	{  0.f,124.f,200.f,299.f},
	{  0.f,124.f,300.f,399.f},
	{125.f,249.f,  0.f, 99.f},		//���I�U��(���O)
	{125.f,249.f,100.f,199.f},
	{125.f,249.f,200.f,299.f},
	{125.f,249.f,300.f,399.f},
	{250.f,374.f,  0.f, 99.f},		//���I�U��(����)
	{250.f,374.f,100.f,199.f},
	{250.f,374.f,200.f,299.f},
	{250.f,374.f,300.f,399.f},
	{375.f,499.f,  0.f, 99.f},		//���I�U��(�E�O)
	{375.f,499.f,100.f,199.f},
	{375.f,499.f,200.f,299.f},
	{375.f,499.f,300.f,399.f},
	{500.f,624.f,  0.f, 99.f},		//���I�U��(�E��)
	{500.f,624.f,100.f,199.f},
	{500.f,624.f,200.f,299.f},
	{500.f,624.f,300.f,399.f},
	{  0.f,124.f,  0.f, 99.f},		//�T�n�M��1�ҋ@
	{  0.f,124.f,100.f,199.f},
	{  0.f,124.f,200.f,299.f},
	{  0.f,124.f,300.f,399.f},
	{  0.f,124.f,  0.f, 99.f},		//�T�n�M��2�ҋ@
	{  0.f,124.f,100.f,199.f},
	{  0.f,124.f,200.f,299.f},
	{  0.f,124.f,300.f,399.f},
	{  0.f,124.f,  0.f, 99.f},		//���U�[�h�}��1�ҋ@
	{  0.f,124.f,100.f,199.f},
	{  0.f,124.f,200.f,299.f},
	{  0.f,124.f,300.f,399.f},
	{  0.f,124.f,  0.f, 99.f},		//���U�[�h�}��2�ҋ@
	{  0.f,124.f,100.f,199.f},
	{  0.f,124.f,200.f,299.f},
	{  0.f,124.f,300.f,399.f},
	{  0.f,124.f,  0.f, 99.f},		//���U�[�h�}��3�ҋ@
	{  0.f,124.f,100.f,199.f},
	{  0.f,124.f,200.f,299.f},
	{  0.f,124.f,300.f,399.f},
	{  0.f,124.f,  0.f, 99.f},		//�t�[�h�̒j�ҋ@
	{  0.f,124.f,100.f,199.f},
	{  0.f,124.f,200.f,299.f},
	{  0.f,124.f,300.f,399.f},
	//�G�t�F�N�g
	{  0.f,124.f,  0.f, 99.f},		//��up
	{  0.f,124.f,100.f,199.f},
	{  0.f,124.f,200.f,299.f},
	{  0.f,124.f,300.f,399.f},
	{250.f,374.f,  0.f, 99.f},		//�yup
	{250.f,374.f,100.f,199.f},
	{250.f,374.f,200.f,299.f},
	{250.f,374.f,300.f,399.f},
	{375.f,499.f,  0.f, 99.f},		//��up
	{375.f,499.f,100.f,199.f},
	{375.f,499.f,200.f,299.f},
	{375.f,499.f,300.f,399.f},
	{125.f,249.f,  0.f, 99.f},		//��up
	{125.f,249.f,100.f,199.f},
	{125.f,249.f,200.f,299.f},
	{125.f,249.f,300.f,399.f},
	//�U���G�t�F�N�g
	//{  0.f,124.f,  0.f, 99.f},		//��
	//{  0.f,124.f,100.f,199.f},
	//{  0.f,124.f,200.f,299.f},
	//{  0.f,124.f,300.f,399.f},
	{  0.f,300.f,400.f,700.f},		//��
	{  0.f,300.f,700.f,1000.f},
	{300.f,600.f,700.f,1000.f},
	{600.f,900.f,700.f,1000.f},
	{125.f,249.f,  0.f, 99.f},		//����
	{125.f,249.f,100.f,199.f},
	{125.f,249.f,200.f,299.f},
	{125.f,249.f,300.f,399.f},
	{250.f,374.f,  0.f, 99.f},		//��e
	{250.f,374.f,100.f,199.f},
	{250.f,374.f,200.f,299.f},
	{250.f,374.f,300.f,399.f},
	{375.f,499.f,  0.f, 99.f},		//�}�O�}(�Ή�)
	{375.f,499.f,100.f,199.f},
	{375.f,499.f,200.f,299.f},
	{375.f,499.f,300.f,399.f},
	{500.f,624.f,  0.f, 99.f},		//�X(���I)
	{500.f,624.f,100.f,199.f},
	{500.f,624.f,200.f,299.f},
	{500.f,624.f,300.f,399.f},
	{625.f,749.f,  0.f, 99.f},		//���ݕt��
	{625.f,749.f,100.f,199.f},
	{625.f,749.f,200.f,299.f},
	{625.f,749.f,300.f,399.f},
	{750.f,874.f,  0.f, 99.f},		//�A�C�V�N���G�b�W
	{750.f,874.f,100.f,199.f},
	{750.f,874.f,200.f,299.f},
	{750.f,874.f,300.f,399.f},
	{125.f,274.f,400.f,499.f},		//�V�I���A�C�V�N��(���O)
	{125.f,274.f,500.f,599.f},
	{125.f,274.f,600.f,699.f},
	{125.f,274.f,700.f,799.f},
	{275.f,424.f,400.f,499.f},		//�V�I���A�C�V�N��(����)
	{275.f,424.f,500.f,599.f},
	{275.f,424.f,600.f,699.f},
	{275.f,424.f,700.f,799.f},
	{425.f,574.f,400.f,499.f},		//�V�I���A�C�V�N��(�E�O)
	{425.f,574.f,500.f,599.f},
	{425.f,574.f,600.f,699.f},
	{425.f,574.f,700.f,799.f},
	{575.f,724.f,400.f,499.f},		//�V�I���A�C�V�N��(�E��)
	{575.f,724.f,500.f,599.f},
	{575.f,724.f,600.f,699.f},
	{575.f,724.f,700.f,799.f},
	{  0.f,600.f,  0.f,800.f},		//�V�I��	�A�u�\�����[�g�G���h(�w�i)
	{  0.f,600.f,  0.f,800.f},		//���@��	������V��(�w�i)
	{  0.f,600.f,  0.f,800.f},		//���I		���IDE�J�[�j�o��(�w�i)
	{141.f,169.f,  8.f,319.f},		//�V�I��	�A�u�\�����[�g�G���h(���O)
	{169.f,199.f,362.f,510.f},		//���@��	������V��(���O)
	{200.f,230.f,668.f,920.f},		//���I		���IDE�J�[�j�o��(���O)
	{370.f,390.f,  0.f, 22.f},
	{  0.f, 64.f,  0.f,1024.f},
	{  0.f, 64.f,  0.f,1024.f},
	{412.f,439.f,  3.f,126.f},	//�}�e���A����	��
	{411.f,439.f,203.f,278.f},	//�}�e���A����	��	
	{411.f,439.f,384.f,447.f},	//�}�e���A����	��	
	{411.f,439.f,529.f,583.f},	//�}�e���A����	�y
	{  0.f,600.f,  0.f,800.f},
	{  0.f,600.f,  0.f,800.f},
	{  0.f,600.f,  0.f,800.f},
	//���`���G�t�F�N�g
	{  0.f, 99.f,  0.f, 99.f},		//����1
	{  0.f, 99.f,100.f,199.f},		//����2
	{  0.f, 99.f,200.f,299.f},		//����3
	{  0.f, 99.f,300.f,399.f},		//����4
	{100.f,224.f,  0.f, 99.f},		//�a��1
	{100.f,224.f,200.f,299.f},		//�a��3
	{100.f,224.f,100.f,199.f},		//�a��2
	{100.f,224.f,300.f,399.f},		//�a��4
	{100.f,224.f,  0.f,124.f},		//�a��_1�V�I���E��
	{100.f,224.f,125.f,249.f},		//�a��_2�V�I��
	{224.f,100.f,124.f,  0.f},		//�a��_1�V�I������
	{224.f,100.f,249.f,125.f},		//�a��_2�V�I��
	{100.f,224.f,250.f,375.f},		//�a��_1�V�I���E��
	{100.f,224.f,250.f,375.f},		//�a��_2�V�I��
	{224.f,100.f,375.f,250.f},		//�a��_1�V�I������
	{224.f,100.f,375.f,250.f},		//�a��_2�V�I��
	{225.f,349.f,  0.f,124.f},		//�a��_1���@��
	{225.f,349.f,125.f,249.f},		//�a��_2���@��
	{225.f,349.f,124.f,  0.f},		//�a��_1���@��
	{225.f,349.f,249.f,125.f},		//�a��_2���@��
	{  0.f,600.f,  0.f,800.f},
	{236.f,314.f,  0.f,800.f},		//�t�F�C�Y�`���BG
	{375.f,499.f,  0.f, 99.f},		//�}�O�}(�Ή�)
	{375.f,499.f,100.f,199.f},
	{375.f,499.f,200.f,299.f},
	{375.f,499.f,300.f,399.f},
	{375.f,499.f,400.f,499.f},

	{300.f,424.f,201.f,311.f},		//�J�[�\��(����)
	{300.f,424.f,311.f,422.f},		//�J�[�\��(�G)

	{726.f,850.f,  0.f, 99.f},		//�V�I���E���@���ҋ@(���O)
	{726.f,850.f,100.f,199.f},
	{726.f,850.f,200.f,299.f},
	{726.f,850.f,300.f,399.f},
	{851.f,975.f,  0.f, 99.f},		//�V�I���E���@���ҋ@(����)
	{851.f,975.f,100.f,199.f},
	{851.f,975.f,200.f,299.f},
	{851.f,975.f,300.f,399.f},
	{726.f,850.f,400.f,499.f},		//�V�I���E���@���ҋ@(�E�O)
	{726.f,850.f,500.f,599.f},
	{726.f,850.f,600.f,699.f},
	{726.f,850.f,700.f,799.f},
	{851.f,975.f,400.f,499.f},		//�V�I���E���@���ҋ@(�E��)
	{851.f,975.f,500.f,599.f},
	{851.f,975.f,600.f,699.f},
	{851.f,975.f,700.f,799.f},

	{626.f,750.f,  0.f, 99.f},		//���I�E�t�[�h�̒j�ȊO�̓G�ҋ@(���O)
	{626.f,750.f,100.f,199.f},
	{626.f,750.f,200.f,299.f},
	{626.f,750.f,300.f,399.f},
	{751.f,875.f,  0.f, 99.f},		//���I�E�t�[�h�̒j�ȊO�̓G�ҋ@(����)
	{751.f,875.f,100.f,199.f},
	{751.f,875.f,200.f,299.f},
	{751.f,875.f,300.f,399.f},
	{626.f,750.f,400.f,499.f},		//���I�E�t�[�h�̒j�ȊO�̓G�ҋ@(�E�O)
	{626.f,750.f,500.f,599.f},
	{626.f,750.f,600.f,699.f},
	{626.f,750.f,700.f,799.f},
	{751.f,875.f,400.f,499.f},		//���I�E�t�[�h�̒j�ȊO�̓G�ҋ@(�E��)
	{751.f,875.f,500.f,599.f},
	{751.f,875.f,600.f,699.f},
	{751.f,875.f,700.f,799.f},

	{126.f,250.f,  0.f, 99.f},		//�t�[�h�̒j�ҋ@(���O)
	{126.f,250.f,100.f,199.f},
	{126.f,250.f,200.f,299.f},
	{126.f,250.f,300.f,399.f},

	{161.f,220.f,606.f,885.f},		//�}�e���A���Z�b�g

	{250.f,310.f,760.f,860.f},		//�ҋ@�������I��
	{250.f,310.f,660.f,760.f},
	{250.f,310.f,860.f,960.f},
	{250.f,310.f,560.f,660.f},
	//�L�����G(��)
	{  0.f,100.f,  0.f,100.f},		//�ȈՃX�e�[�^�X�g�p(�V�I��)
	{  0.f,100.f,100.f,200.f},		//�ȈՃX�e�[�^�X�g�p(���@��)
	{  0.f,100.f,200.f,300.f},		//�ȈՃX�e�[�^�X�g�p(���I)
	{  0.f,100.f,300.f,400.f},		//�ȈՃX�e�[�^�X�g�p(�t�[�h�̒j)
	{101.f,200.f,  0.f,100.f},		//�ȈՃX�e�[�^�X�g�p(�T�n�M���P)
	{101.f,200.f,100.f,200.f},		//�ȈՃX�e�[�^�X�g�p(�T�n�M���Q)
	{101.f,200.f,200.f,300.f},		//�ȈՃX�e�[�^�X�g�p(���U�[�h�}���P)
	{101.f,200.f,300.f,400.f},		//�ȈՃX�e�[�^�X�g�p(���U�[�h�}���Q)
	//�L�������O
	{317.f,345.f,  0.f, 76.f},		//�ȈՃX�e�[�^�X�g�p(�V�I��)
	{346.f,376.f,  0.f, 76.f},		//�ȈՃX�e�[�^�X�g�p(���@��)
	{377.f,405.f,  0.f, 52.f},		//�ȈՃX�e�[�^�X�g�p(���I)
	{436.f,465.f,  0.f,100.f},		//�ȈՃX�e�[�^�X�g�p(�T�n�M���P)
	{465.f,495.f,  0.f,195.f},		//�ȈՃX�e�[�^�X�g�p(�T�n�M���Q)
	{317.f,345.f, 90.f,238.f},		//�ȈՃX�e�[�^�X�g�p(���U�[�h�}���P)
	{346.f,376.f, 90.f,287.f},		//�ȈՃX�e�[�^�X�g�p(���U�[�h�}���Q)
	{406.f,435.f,  0.f, 65.f},		//�ȈՃX�e�[�^�X�g�p(�t�[�h�̒j)
	//�g
	{  0.f,170.f,  0.f,367.f},		//�ȈՃX�e�[�^�X�v���C���[
	{  0.f,170.f,367.f,735.f},		//�ȈՃX�e�[�^�X�G�l�~�[
	{202.f,225.f,  2.f, 26.f},		//�ȈՃX�e�[�^�XHP
	{225.f,247.f,  2.f, 26.f},		//�ȈՃX�e�[�^�XAP
	{247.f,269.f,  2.f, 26.f},		//�ȈՃX�e�[�^�XMG
	{269.f,292.f,  2.f, 35.f},		//�ȈՃX�e�[�^�XMOV
	{450.f,467.f,203.f,214.f},		//�ȈՃX�e�[�^�X/(�X���b�V��)
	{185.f,202.f,  0.f,182.f},		//�ȈՃX�e�[�^�X�Q�[�W�g
	{171.f,185.f,  0.f,180.f},		//�ȈՃX�e�[�^�X�Q�[�WHP
	{171.f,185.f,  0.f,180.f},		//�ȈՃX�e�[�^�X�Q�[�WAP
	{171.f,185.f,  0.f,180.f},		//�ȈՃX�e�[�^�X�Q�[�WMG
	{171.f,185.f,  0.f,180.f},		//�ȈՃX�e�[�^�X�Q�[�WHP_MAX
	{171.f,185.f,  0.f,180.f},		//�ȈՃX�e�[�^�X�Q�[�WAP_MAX
	{171.f,185.f,  0.f,180.f},		//�ȈՃX�e�[�^�X�Q�[�WMG_MAX
	
	{  0.0f, 30.0f,  0.0f,200.0f},	//LOADING

	{  0.f,600.f,  0.f,800.f},
};

char* LoadBattleFile[] =		  //�g���G��ǂݍ���ł���
{
	//�X�e�[�^�X�`��p
	{"Graphic\\BG\\T_Intro.png"},
	{"Graphic\\Font�EConsor\\T_status.png"},
	{"Graphic\\Font�EConsor\\T_Chara_Name.png"},
	{"Graphic\\CHARACTER\\ADV\\T_ADV_Zion_1.png"},
	{"Graphic\\CHARACTER\\ADV\\T_ADV_Van.png"},
	{"Graphic\\CHARACTER\\ADV\\T_ADV_Rio_1.png"},
	{"Graphic\\CHARACTER\\BATTLE\\B_face.png"},

	{"Graphic\\BG\\T_Battle.png"},
	{"Graphic\\BG\\T_win_or_defeat.png"},		
	{"Graphic\\Font�EConsor\\T_Battle_Font_Consor.png"},
	//�X�e�[�W�֘A
	{"Graphic\\MAPTIP\\T_Maptip.png"},
	
	//�L�����N�^�[�E�G�t�F�N�g
	{"Graphic\\CHARACTER\\BATTLE\\T_Battle_Zion.png"},
	{"Graphic\\CHARACTER\\BATTLE\\T_Battle_Van.png"},
	{"Graphic\\CHARACTER\\BATTLE\\T_Battle_Rio.png"},
	{"Graphic\\CHARACTER\\BATTLE\\T_Sahagin1.png"},
	{"Graphic\\CHARACTER\\BATTLE\\T_Sahagin2.png"},
	{"Graphic\\CHARACTER\\BATTLE\\T_Lizardman1.png"},
	{"Graphic\\CHARACTER\\BATTLE\\T_Lizardman2.png"},
	{"Graphic\\CHARACTER\\BATTLE\\T_Battle_robe.png"},
	{"Graphic\\Font�EConsor\\T_Adv_Font_Consor.png"},
	{"Graphic\\EFFECT\\E_up.png"},
	{"Graphic\\EFFECT\\E_atc.png"},
	{"Graphic\\BG\\cutin_bg_xion.png"},
	{"Graphic\\BG\\cutin_bg_van.png"},
	{"Graphic\\BG\\cutin_bg_rio.png"},
	{"Graphic\\Font�EConsor\\Inline.png"},
	{"Graphic\\BG\\T_Black.png"},
	{"Graphic\\EFFECT\\Zion_ex.png"},
	{"Graphic\\EFFECT\\explosion.png"},
	{"Graphic\\EFFECT\\B_atc.png"},
	{"Graphic\\EFFECT\\B_atc_2.png"},
	{"Graphic\\EFFECT\\zion_ex_slash.png"},

	{"Graphic\\NowLoading.png"},

	{"Graphic\\BG\\�s���I��.png"},

	{"Graphic\\Font�EConsor\\T_Battle_Font01.png"},

	{"\0"},
};

char* LoadSoundBattle[] = //�g������ǂݍ���ł���
{
	{"Sound\\Battle\\BGM\\Battle_BGM01.wav"},
	{"Sound\\Battle\\BGM\\d17.wav"},  

	{"Sound\\Battle\\VOICE\\�V�I��\\�~���[�W���G�b�W.wav"},
	{"Sound\\Battle\\VOICE\\�V�I��\\�q�[���E�B���h.wav"},
	{"Sound\\Battle\\VOICE\\�V�I��\\�A�C�V�N���G�b�W.wav"},
	{"Sound\\Battle\\VOICE\\�V�I��\\�A�N�A�L���A.wav"},
	{"Sound\\Battle\\VOICE\\���@��\\������.wav"},
	{"Sound\\Battle\\VOICE\\���@��\\������.wav"},
	{"Sound\\Battle\\VOICE\\���@��\\�n�Ӑw.wav"},
	{"Sound\\Battle\\VOICE\\���@��\\�|����.wav"},
	{"Sound\\Battle\\VOICE\\���I\\�u���C�Y�o���b�g.wav"},
	{"Sound\\Battle\\VOICE\\���I\\�o�[�X�g.wav"},
	{"Sound\\Battle\\VOICE\\���I\\�t���[�Y���o���b�g.wav"},
	{"Sound\\Battle\\VOICE\\���I\\�A�N�A�L���A.wav"},

	{"Sound\\Battle\\VOICE\\�V�I��\\�ʏ�1.wav"},
	{"Sound\\Battle\\VOICE\\�V�I��\\�ʏ�2.wav"},
	{"Sound\\Battle\\VOICE\\�V�I��\\�ʏ�3.wav"},
	{"Sound\\Battle\\VOICE\\���@��\\�ʏ�1.wav"},
	{"Sound\\Battle\\VOICE\\���@��\\�ʏ�2.wav"},
	{"Sound\\Battle\\VOICE\\���@��\\�ʏ�3.wav"},
	{"Sound\\Battle\\VOICE\\���@��\\�ʏ�4.wav"},
	{"Sound\\Battle\\VOICE\\���@��\\�ʏ�5.wav"},
	{"Sound\\Battle\\VOICE\\���I\\�ʏ�1.wav"},
	{"Sound\\Battle\\VOICE\\���I\\�ʏ�2.wav"},

	{"Sound\\Battle\\VOICE\\�V�I��\\�A�u�\�����[�g�G���h.wav"},
	//{"Sound\\Battle\\VOICE\\�V�I��\\�A�u�\�����[�g�G���h2.wav"},
	{"Sound\\Battle\\VOICE\\���@��\\������|��.wav"},
	//�U��
	{"Sound\\Battle\\SE\\�V�I��\\SwordSwing01.WAV"},
	{"Sound\\Battle\\SE\\���@��\\SWORD3.WAV"},
	{"Sound\\Battle\\SE\\���I\\38revolv01.wav"},
	//����
	{"Sound\\Battle\\SE\\���@��\\AI_FIRE2.WAV"},			//������
	{"Sound\\Battle\\SE\\�V�I��\\ICICLE_EDGE.wav"},			//�A�C�V�N���G�b�W
	{"Sound\\Battle\\SE\\�V�I��\\AQUACURE.wav"},			//�A�N�A�L���A
	{"Sound\\Battle\\SE\\�V�I��\\�~���[�W���G�b�W.wav"},	//�~���[�W���G�b�W
	{"Sound\\Battle\\SE\\�V�I��\\HEELWIND.wav"},			//�q�[���E�B���h
	{"Sound\\Battle\\SE\\���@��\\GOUSYORAI.WAV"},			//������
	{"Sound\\Battle\\SE\\���@��\\TISAIJIN.wav"},			//�n�Ӑo
	{"Sound\\Battle\\SE\\���@��\\KOUSYORAI.wav"},			//�|����
	{"Sound\\Battle\\SE\\���I\\BLAZEBULLET.wav"},			//�u���C�Y�o���b�g
	{"Sound\\Battle\\SE\\���I\\BURST.wav"},					//�o�[�X�g

	{"Sound\\Battle\\SE\\���I\\FROZENBULLET.wav"},				//�t���[�Y���o���b�g(����)
	{"Sound\\Battle\\SE\\���I\\FROZENBULLET2.wav"},				//�t���[�Y���o���b�g(���s)

	{"Sound\\Battle\\SE\\���I\\AQUACURE.wav"},				//�A�N�A�L���A
	//���`
	{"Sound\\Battle\\SE\\�V�I��\\SwordShwing.wav"},
	{"Sound\\Battle\\SE\\���@��\\hellfire.wav"},
	{"Sound\\Battle\\SE\\���I\\44mag.wav"},
	//���`(���鎞)
	{"Sound\\Battle\\SE\\OUGI_IN.wav"},
	//�J�[�\��
	{"Sound\\Battle\\SE\\CURSOR_MOVE.wav"},

	//�A�i�E���X
	{"Sound\\Battle\\VOICE\\victory-man.wav"},
	{"Sound\\Battle\\VOICE\\majyutusi-man.wav"},
	{"Sound\\Battle\\VOICE\\lose-man.wav"},
	{"Sound\\Battle\\VOICE\\enemy-man.wav"},
	{"Sound\\Battle\\VOICE\\die sion-man.wav"},

	{"Sound\\Battle\\VOICE\\victory-girl.wav"},
	{"Sound\\Battle\\VOICE\\majyutusi-girl.wav"},
	{"Sound\\Battle\\VOICE\\lose-girl.wav"},
	{"Sound\\Battle\\VOICE\\enemy-girl.wav"},
	{"Sound\\Battle\\VOICE\\die sion-girl.wav"},

	{"Sound\\Battle\\VOICE\\material-man.wav"},
	{"Sound\\Battle\\VOICE\\material-girl.wav"},
	//�R�}���h
	//{"Sound\\Battle\\SE\\���I\\44mag.wav"},
	{"Sound\\Battle\\SE\\AP_error.wav"},
};

const int  C_Battle::deray[8][4] = {
	{9,9,3,9},	//�V�I��
	{9,12,3,9},	//���@��
	{9,9,3,9},	//���I
	{4,4,4,4},	//�T�n�M���P
	{4,4,4,4},	//�T�n�M���Q
	{5,5,5,4},	//���U�[�h�}���P
	{5,5,5,4},	//���U�[�h�}���Q
	{4,4,4,4},	//�{�X(��)
};			//�U���̃f�B���C

const int C_Battle::deray_skill[4] = {
	12,12,9,40
};

const int C_Battle::deray_wait[8][4] = {
	{15,15,15,15},	//�V�I��
	{15,15,15,15},	//���@��
	{15,15,15,15},	//���I
	{15,10,15,15},	//�T�n�M��1
	{10,15,15,15},	//�T�n�M��2
	{20,20,20,20},	//���U�[�h�}��1
	{18,18,18,18},	//���U�[�h�}��2
	{25,25,25,25},	//�{�X
};

C_Battle::~C_Battle()
{
}

C_Battle::C_Battle(C_DGraphics* in_m_graphics)
{
	stage = new C_Stage;

	zion = new C_CharaData_Zion;
	van = new C_CharaData_Van;
	rio = new C_CharaData_Rio;
	enemy1 = new C_CharaData_Enemy1;
	enemy2 = new C_CharaData_Enemy2;
	enemy3 = new C_CharaData_Enemy3;
	enemy4 = new C_CharaData_Enemy4;
	boss = new C_CharaData_Boss;

	m_scene_flag = BATTLE_SCENE;	//SceneManage�N���X��BATTLE�t���O��Ԃ��B

	m_graphics = in_m_graphics;

	m_scene_number = new int;

	use_texture = 0;
	m_key_cnt=0;

	for(int i = 0; LoadBattleFile[i] != "\0"; i++)	//�g���G�̖�����m�点��
	{
		use_texture++;	
	}

	m_graphics->SetTextureNum(use_texture);	//�e�N�X�`���̖������Z�b�g����B

	m_graphics->InitData(MAX_BATTLE_DATA);	//��`�̐��������������m�ۂ���B

	m_pTexture = new LPDIRECT3DTEXTURE9[use_texture];

	for(int i = 0; i < use_texture; i++)	//�e�N�X�`���̓ǂݍ���
	{
		m_graphics->LoadTexture(LoadBattleFile[i],m_pTexture[i]);
	}

	for(int i = 0;i < MAX_BATTLE_DATA;i++)
	{
		m_graphics->SetPostion(rect_battle[i],i);		//��`�����Z�b�g����B
	}

	for(int i = 0;i < MAX_S_BATTLE;i++){
		LoadSound(LoadSoundBattle[i],i);	//�o�g����ʂ�BGM
	}

	flag_sp_draw_off = false;
	x_temporarily = 0;
	y_temporarily = 0;
	time_cnt = 0;
	flag_turn = PLAYER_TURN;
	flag_turn_enemy = 0;
	flag_any_end = 0;
	flag_char_commando = 0;
	locate_cursor_commando = 0;
	fade = 0.f;
	flag_change_keep = 0;
	phase_shift = R_PLAYER_PHASE;

	locate_cursor_field.x = 0;
	locate_cursor_field.y = 0;
	keep_posi.x = 0;
	keep_posi.y = 0;

	area_shift = D3DCOLOR_ARGB(0,0,0,0);

	charaAttackEfCnt = 0;

	//�ǉ�
	keep_char_select = BLANK_ID;
	flag_turn_player = ZION_ID;
	keep_id = 0;
	deleat_posi.x = 0;
	deleat_posi.y = 0;
	//flag_atk = 0;
	//atk_draw = 0;
	font_increase_y = 0;	//�Œ�t�H���g�̑�����
	font_standard= 0;		//�Œ�t�H���g�̍��̊
	font_center_x=0;		//�Œ�t�H���g��X�̒��S
	font_center_y=0;		//�Œ�t�H���g�̂x����Ƃ������S
	add_font_canter_y=0;	//�Œ�t�H���g�̍��v
	num_center_x=0;			//�����̂w�̒��S
	add_num_canter_y=0;		//�����̍��v�����x�̒��S
	num_center_y=0;			//�����̂x����������S
	num_increase_y=0;
	num_standard=0;
	mrx_increase_left=0;
	mrx_increase_right=0;
	mrx_center_x=0;
	set_material=0;
	mrl_magic_1=0;	//�}�e���A���Z���P
	magic1_center_x=0;//�Z��x���S���W
	mrl_detail_1=0;	//�}�e���A���Z�P�̏ڍ�
	mrl_detail1_center_x=0;	//�}�e���A���ڍ׋Z1�̒��S���W
	mrl_magic_2=0;	//�}�e���A���Z���Q
	magic2_center_x=0;//�Z��x���S���W
	mrl_detail_2=0;	//�}�e���A���Z�Q�̏ڍ�
	mrl_detail2_center_x=0;
	fade2 = 255.0;
	fade3 = 0;
	battle_change = BATTLE_STATUS_MAKE;
	cursor_locate_x = 0;
	cursor_locate_y = 0.0;
	direction = 0;
	draw_direction = 0;
	flag_simple_chara=0;
	landform=0;
//topography_effect=0;	//��������
	chara_id=0;				//�L�����N�^�[��id
	simple_num_x=0;
	simple_num_y=0;
	sim_num_standard=0;
	simple_chara_name=0;	//�L�����N�^�[�̋�`���
	flag_atk = 0;	//2/12�ǉ�(nisii)

	damegeCulc = new C_Calculate;
	battleDrawEnd = false;
	hitInit = true;

	charaAttack = false;
	charaAttackCnt = 0;
	AtkEfStart = false;

	flag_battle_status_draw = false;

	sound_in = 0;

	//�L�����ҋ@���[�V����
	charaWaitZion		= 189;
	charaWaitVan		= 169;
	charaWaitRio		= 165;
	charaWaitSahagin1	= 250;	
	charaWaitSahagin2	= 250;	
	charaWaitLizardman1	= 250;
	charaWaitLizardman2	= 250;
	charaWaitBoss		= 266;

	atkDeray = 0;
	locate_cursor_skill = 0;
	flag_skill = 0;
	charaSkillatk = false;
	attribute_advantage = 0;
	recovery_point = 0;
	cut_out = stage->GetCharMaxData();
	charaRecoveryCnt = 0;
	charaSkillCnt =0;
	SkillEfStart = false;
	cnt_turn = 0;
	for(int i = 0;i < 3;i++){
		flag_use_skill[i] = false;
		flag_skill_ef[i] = 0;
		keep_skill_ef_id[i] = 0;
		flag_char_selected[i] = 0;
		flag_material_seted[i] = 4;
	}
	telop = 1312.f;
	telop2 = 2324.f;
	flag_sp_extra = 0;
	flag_sp_extra_draw = false;
	fade_color = 0;
	fade_end = true;
	sp_end_extra = false;

	flag_zion_num_end = false;

	fade_in_out = 0;
	cursor_color = 0;

	flag_field_show = 0;

	//���`
	cnt_ex_alltime = 0;
	fade_black = 255;
	fade_out_black = 255;
	flag_black = false;

	InitBattleData();
	//AI�p
	selectionId = 0;
	flag_enemy_atk = 0;
	enemyAttackCnt = 0;
	//�{�C�X�p
	flag_voice = false;
	voice_change = 0;
	flag_voice_attack = false;
	voice_change_attack = 0;
	flag_sound_ef = false;
	sound_ef_change_attack = 0;
	flag_voice_ex = false;
	voice_change_ex = 0;
	flag_sound_ex = false;
	sound_ef_change_ex = 0;
	flag_sound_sp = false;
	sound_ef_change_sp = 0;
	flag_sound_in = false;
	flag_sound_cursor = false;
	flag_voice_setumei = false;
	voice_change_setumei = 0;
}

void C_Battle::Init()
{
	m_alpha_load = m_count_fade = 0;
	m_flag_fade  = false;
#ifdef _DEBUG
	::_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
#endif
}

void C_Battle::Control(int* key)
{
#ifdef _DEBUG
	if(key[S_PUSH-1] == S_PUSH) battle_change = BATTLE_CLEAR;
#endif

	if(battle_change == BATTLE_STATUS_MAKE)			BattleStatusMake();
	else if(battle_change == BATTLE_CONDITION)		BattleCondition(key);
	else if(battle_change == BATTLE_MATERIAL_SET)	BattleMaterial(key);
	else if(battle_change == BATTLE_COMBAT)			BattleCombat(key);
	else if(battle_change == BATTLE_CLEAR)			BattleClear(key);
}

void C_Battle::Draw()
{
	if(battle_change == BATTLE_CONDITION)			BattleConditionDraw();	//���������E�s�k�����\��
	else if(battle_change == BATTLE_MATERIAL_SET)	BattleMaterialDraw();	//�퓬�O�}�e���A���ݒ�
	else if(battle_change == BATTLE_COMBAT)			BattleCombatDraw();		//�퓬��
	else if(battle_change == BATTLE_CLEAR)			BattleClearDraw();		//�N���A���
	if(!fade_end){
		m_graphics->SetColor(D3DCOLOR_ARGB(fade_color,255,255,255),R_FADE);
		m_graphics->DrawCC(400.f,300.f,m_pTexture[T_FADE],T_FADE,R_FADE);
	}
}

void C_Battle::BattleStatusMake()
{
	status = new CharaData_status[stage->GetCharMaxData()];
	status_battle = new CharaData_battle[stage->GetCharMaxData()];
//	status_battle = new CharaData_battle[16];
	InitStatus();
	SetStatus();
	battle_change = BATTLE_CONDITION;
}

void C_Battle::BattleMaterial(int* key)
{
	int check_cnt = 0;
	telop -= 3.f;
	telop2 -= 3.f;
	if(telop < -700.f) telop = 1312.f;
	if(telop2 < -700.f) telop2 = 1312.f;
	if(flag_any_end == 0)
	{
		CursorControl(key,3);
		cursor_locate_y = locate_cursor_commando;
		if(key[Z_PUSH-1] == Z_PUSH)
		{
			cursor_locate_x = 1;
			keep_id = locate_cursor_commando;
			locate_cursor_commando = 0;
			flag_any_end = 1;
			key[Z_PUSH-1] = 0;
		}
		if(key[X_PUSH-1] == X_PUSH)
		{
			for(int i = 0;i < 3;i++){
				if(material_set[i] == 1){
					check_cnt++;
				}
			}
			if(check_cnt == 3){
				battle_change = BATTLE_COMBAT;
				keep_id = 0;
				locate_cursor_commando = 0;
			}
		}
#ifdef _DEBUG
		//�f�o�b�O�L�[�Ȃǎg�p
		if(key[A_PUSH - 1] == A_PUSH)
		{
			status[StatusSeachId(10)].m_attribute = SYLPH;
			status[StatusSeachId(10)].m_skill_range1 = RANGE_MIRAGE_EDGE;
			status[StatusSeachId(10)].m_skill_range2 = RANGE_HEEL_WIND;
			status[StatusSeachId(20)].m_attribute = SALAMANDER;
			status[StatusSeachId(20)].m_skill_range1 = RANGE_BAKUENKEN;
			status[StatusSeachId(20)].m_skill_range2 = RANGE_GOUSYORAI;
			status[StatusSeachId(30)].m_attribute = SALAMANDER;
			status[StatusSeachId(30)].m_skill_range1 = RANGE_BLAZE_BULLET;
			status[StatusSeachId(30)].m_skill_range2 = RANGE_BURST;
			battle_change = BATTLE_COMBAT;
			keep_id = 0;
			locate_cursor_commando = 0;
		}
		if(key[C_PUSH-1] == C_PUSH)
		{
			status[StatusSeachId(10)].m_attribute = UNDINE;
			status[StatusSeachId(10)].m_skill_range1 = RANGE_ICICLE_EDGE;
			status[StatusSeachId(10)].m_skill_range2 = RANGE_AQUA_CURE_Z;
			status[StatusSeachId(20)].m_attribute = GNOME;
			status[StatusSeachId(20)].m_skill_range1 = RANGE_TISAIJIN;
			status[StatusSeachId(20)].m_skill_range2 = RANGE_KOUSYORAI;
			status[StatusSeachId(30)].m_attribute = UNDINE;
			status[StatusSeachId(30)].m_skill_range1 = RANGE_FROZEN_BULLET;
			status[StatusSeachId(30)].m_skill_range2 = RANGE_AQUA_CURE_R;
			battle_change = BATTLE_COMBAT;
			keep_id = 0;
			locate_cursor_commando = 0;
		}
		//�����܂�
#endif
	}
	if(flag_any_end == 1)
	{
		CursorControl(key,2);
		cursor_locate_y = locate_cursor_commando + 0.5;
		if(key[Z_PUSH-1] == Z_PUSH)
		{
			flag_any_end = 2;
			key[Z_PUSH-1] = 0;
		}
		if(key[X_PUSH-1] == X_PUSH)
		{
			flag_any_end = 0;
			cursor_locate_x = 0;
			cursor_locate_y = 0.0;
			locate_cursor_commando = 0;
			key[X_PUSH-1] = 0;
		}
	}
	if(flag_any_end == 2)
	{
		if(key[Z_PUSH-1] == Z_PUSH)
		{
			if(keep_id == 0){	//�V�I���̎�
				if(locate_cursor_commando == 0){
					status[StatusSeachId(U_ZION)].m_attribute = locate_cursor_commando + 2;
					status[StatusSeachId(U_ZION)].m_skill_range1 = RANGE_MIRAGE_EDGE;
					status[StatusSeachId(U_ZION)].m_skill_range2 = RANGE_HEEL_WIND;
					flag_material_seted[0] = status[StatusSeachId(U_ZION)].m_attribute;
				}
				else if(locate_cursor_commando == 1){
					status[StatusSeachId(U_ZION)].m_attribute = locate_cursor_commando;
					status[StatusSeachId(U_ZION)].m_skill_range1 = RANGE_ICICLE_EDGE;
					status[StatusSeachId(U_ZION)].m_skill_range2 = RANGE_AQUA_CURE_Z;
					flag_material_seted[0] = status[StatusSeachId(U_ZION)].m_attribute;
				}
			}
			if(keep_id == 1){	//���@���̎�
				if(locate_cursor_commando == 0){
					status[StatusSeachId(20)].m_attribute = locate_cursor_commando;
					status[StatusSeachId(20)].m_skill_range1 = RANGE_BAKUENKEN;
					status[StatusSeachId(20)].m_skill_range2 = RANGE_GOUSYORAI;
					flag_material_seted[1] = status[StatusSeachId(U_VAN)].m_attribute;
				}
				else if(locate_cursor_commando == 1){
					status[StatusSeachId(20)].m_attribute = locate_cursor_commando + 2;
					status[StatusSeachId(20)].m_skill_range1 = RANGE_TISAIJIN;
					status[StatusSeachId(20)].m_skill_range2 = RANGE_KOUSYORAI;
					flag_material_seted[1] = status[StatusSeachId(U_VAN)].m_attribute;
				}
			}
			if(keep_id == 2){
				if(locate_cursor_commando == 0){
					status[StatusSeachId(30)].m_skill_range1 = RANGE_BLAZE_BULLET;
					status[StatusSeachId(30)].m_skill_range2 = RANGE_BURST;
				}
				else{
					status[StatusSeachId(30)].m_skill_range1 = RANGE_BLAZE_BULLET;
					status[StatusSeachId(30)].m_skill_range2 = RANGE_AQUA_CURE_R;
				}
				status[StatusSeachId(30)].m_attribute = locate_cursor_commando;
				flag_material_seted[2] = status[StatusSeachId(U_RIO)].m_attribute;
			}

			flag_any_end = 0;
			cursor_locate_x = 0;
			cursor_locate_y = 0.0;
			locate_cursor_commando = 0;
			material_set[keep_id] = 1;
			key[Z_PUSH-1] = 0;
		}
		if(key[X_PUSH-1] == X_PUSH)
		{
			flag_any_end = 1;
			key[X_PUSH-1] = 0;
		}
	}
}

void C_Battle::BattleCondition(int* key)
{
	static int cnt = 0;
	static int cnt2 = 0;
	if(cnt != 0){
		if(!SoundCheck(S_WIN_MAN + cnt - 1)){
			if(cnt2++ > 120){
				if(cnt != 5){
					flag_voice_setumei = true;
					voice_change_setumei = cnt;
					cnt++;
					cnt2 = 0;
				}
				else{
					cnt = 0;
				}
			}
		}
	}
	else{
		if(cnt2++ > 120){
			flag_voice_setumei = true;
			voice_change_setumei = cnt;
			cnt = 1;
			cnt2 = 0;
		}
	}
	if(key[Z_PUSH-1] == Z_PUSH)
	{
		time_cnt = 0;
		battle_change = BATTLE_MATERIAL_SET;
	}
	time_cnt++;
}

void C_Battle::BattleCombat(int* key)
{
	static bool color_in_out = false;
	static int cnt_wait = 0;
	static int cnt_wait_e = 0;

	if((cnt_wait_e++)%deray_wait[3][charaWaitSahagin1 - 250] >= deray_wait[3][charaWaitSahagin1 - 250] - 1){
		charaWaitSahagin1++;
		if(charaWaitSahagin1 == 254){
			charaWaitSahagin1 = 250;
		}
	}
	if((cnt_wait_e)%deray_wait[4][charaWaitSahagin2 - 250] >= deray_wait[4][charaWaitSahagin2 - 250] - 1){
		charaWaitSahagin2++;
		if(charaWaitSahagin2 == 254){
			charaWaitSahagin2 = 250;
		}
	}
	if((cnt_wait_e)%deray_wait[5][charaWaitLizardman1 - 250] >= deray_wait[5][charaWaitLizardman1 - 250] - 1){
		charaWaitLizardman1++;
		if(charaWaitLizardman1 == 254){
			charaWaitLizardman1 = 250;
		}
	}
	if((cnt_wait_e)%deray_wait[6][charaWaitLizardman2 - 250] >= deray_wait[6][charaWaitLizardman2 - 250] - 1){
		charaWaitLizardman2++;
		if(charaWaitLizardman2 == 254){
			charaWaitLizardman2 = 250;
		}
	}
	if((cnt_wait_e)%deray_wait[7][charaWaitBoss - 266] >= deray_wait[7][charaWaitBoss - 266] - 1){
		charaWaitBoss++;
		if(charaWaitBoss == 270){
			charaWaitBoss = 266;
		}
	}
	if((cnt_wait++)%deray_wait[0][charaWaitZion - 189] >= deray_wait[0][charaWaitZion - 189] - 1){
		charaWaitZion++;
		if(charaWaitZion == 193){
			charaWaitZion = 189;
		}
	}
	if((cnt_wait)%deray_wait[0][charaWaitVan - 169] >= deray_wait[0][charaWaitVan - 169] - 1){
		charaWaitVan++;
		if(charaWaitVan == 173){
			charaWaitVan = 169;
		}
	}
	if((cnt_wait)%deray_wait[0][charaWaitRio - 165] >= deray_wait[0][charaWaitRio - 165] - 1){
		charaWaitRio++;
		if(charaWaitRio == 169){
			charaWaitRio = 165;
		}
	}

	static int cnt_deray = 0;
	static int cnt_deray2 = 0;

	if(flag_field_show == 0){
		locate_cursor_field.x = 3;
		locate_cursor_field.y = 15;
		flag_field_show = 1;
		stage->FieldControl(locate_cursor_field.x,locate_cursor_field.y);
	}
	else if(flag_field_show == 1){
		if(cnt_deray++ == 4){
			locate_cursor_field.y -= 1;
			cnt_deray = 0;
		}
		if(locate_cursor_field.y == 3){
			cnt_deray = 5;
			if(cnt_deray2++ == 5){
				flag_field_show = 2;
				cnt_deray = 0;
				cnt_deray2 = 0;
			}
		}
		stage->FieldControl(locate_cursor_field.x,locate_cursor_field.y);
	}
	else if(flag_field_show == 2){
		if(cnt_deray++ == 4){
			locate_cursor_field.x += 1;
			cnt_deray = 0;
		}
		if(locate_cursor_field.x == 11){
			cnt_deray = 5;
			if(cnt_deray2++ == 5){
				flag_field_show = 3;
				cnt_deray = 0;
				cnt_deray2 = 0;
			}
		}
		stage->FieldControl(locate_cursor_field.x,locate_cursor_field.y);
	}
	else if(flag_field_show == 3){
		if(cnt_deray++ == 4){
			locate_cursor_field.y += 1;
			cnt_deray = 0;
		}
		if(locate_cursor_field.y == 15){
			cnt_deray = 5;
			if(cnt_deray2++ == 5){
				flag_field_show = 4;
				cnt_deray = 0;
				cnt_deray2 = 0;
			}
		}
		stage->FieldControl(locate_cursor_field.x,locate_cursor_field.y);
	}
	else if(flag_field_show == 4){
		if(cnt_deray++ == 4){
			locate_cursor_field.x -= 1;
			cnt_deray = 0;
		}
		if(locate_cursor_field.x == 7){
			flag_field_show = 5;
		}
		stage->FieldControl(locate_cursor_field.x,locate_cursor_field.y);
	}
	else{
		if(color_in_out == false){
			cursor_color += 4;
			if(cursor_color > 255){
				cursor_color = 255;
				color_in_out = true;
			}
		}
		else{
			cursor_color -= 4;
			if(cursor_color < 0){
				cursor_color = 0;
				color_in_out = false;
			}
		}
		if(flag_turn == PLAYER_TURN)	PlayerTurn(key);
		else if(flag_turn == ENEMY_TURN)		EnemyTurn(key);
	}
}

void C_Battle::BattleCombatSystem(int* key)
{
	static int cnt = 0;
	CursorControlField(key);
	if(stage->GameStateSeach() == 0)
	{
		//�^�[���`�掞����(�X���C�h�C��)
		if(flag_any_end == 0)
		{
			if(time_cnt <= 31)
			{
				fade_in_out += 12;
				if(fade_in_out > 255){
					fade_in_out = 255;
					if(fade < 600.f)	fade += 60.f;
					if(fade >= 600.f)	fade = 600.f;
				}
				time_cnt++;
			}
			else if(time_cnt <= 70) { time_cnt++; }
			else if(time_cnt <= 101)
			{
				time_cnt++;
				if(fade < 1200.f)	fade += 60.f;
				if(fade >= 1200.f)	fade = 1200.f;
				if(time_cnt >= 150){
					fade_in_out -= 12;
					if(fade_in_out < 0){
						fade_in_out = 0;
					}
				}
			}
			else
			{
				fade = 0.f;
				flag_any_end = 1;
				time_cnt = 0;
			}
		}
		else if(flag_any_end == 1 && flag_turn == PLAYER_TURN)	//�J�[�\������
		{
			CursorSelectChara(key);
			deleat_posi = keep_posi = locate_cursor_field;
			if(StatusSeachPosi(locate_cursor_field) != stage->GetCharMaxData()){
				keep_direction = status_battle[StatusSeachPosi(locate_cursor_field)].m_direction;
			}
			direction = keep_direction;
		}
		else if(flag_any_end == 2 && flag_turn == PLAYER_TURN)	//�R�}���h����
		{
			CursorControl(key,COMMANDO_MAX);
			switch(locate_cursor_commando)
			{
			case CHAR_MOVE:		//�L�����ړ�
				if(flag_char_selected[CHAR_MOVE] != 1)
				{
					if(flag_char_commando == 0)		//�ړ��͈͂��\�������O
					{
						if(StatusSeachPosi(locate_cursor_field) != stage->GetCharMaxData()){
							keep_direction = status_battle[StatusSeachPosi(locate_cursor_field)].m_direction;
						}
						locate_cursor_field = keep_posi;
						if(key[Z_PUSH-1] == Z_PUSH){	//�y�L�[�������ꂽ��
							if(status[StatusSeachPosi(locate_cursor_field)].m_ap<UseMoveAP())
							{
								//MessageBox(NULL,TEXT("AP������܂���"),TEXT("AP�x��"),MB_OK);
								SoundPlay(false,59);
								flag_char_commando = 0;
							}
							else{
							stage->AreaSeach(locate_cursor_field.x,locate_cursor_field.y,keep_char_select,status[StatusSeachPosi(locate_cursor_field)].m_mov,CHAR_MOVE);
							area_shift = D3DCOLOR_ARGB(70,0,0,200);
							flag_char_commando = 3;
							}
						}
						if(key[X_PUSH-1] == X_PUSH) { if(!SelectedCommando()){ flag_any_end = 1; } }	//X�L�[�������ꂽ��J�[�\���ړ��ɖ߂�
					}
					else if(flag_char_commando == 3)	//�ړ��͈͂��\�����ꂽ��
					{
						if(stage->GetAreaInfoData(locate_cursor_field.x,locate_cursor_field.y) >= 1){
							if(stage->GetAreaInfoData(locate_cursor_field.x,locate_cursor_field.y) != 5){
								stage->SetFieldCharacterData(deleat_posi,U_BLANK_AREA);
								stage->SetFieldCharacterData(locate_cursor_field,keep_field_id[keep_char_select]);
								deleat_posi = locate_cursor_field;
							}
							if(StatusSeachPosi(locate_cursor_field) != stage->GetCharMaxData()){
								status_battle[StatusSeachPosi(locate_cursor_field)].m_direction = direction;
							}
							if(stage->GetAreaInfoData(locate_cursor_field.x,locate_cursor_field.y) == 1)
							{
								if(key[Z_PUSH-1] == Z_PUSH){	//�y�L�[�������ꂽ��
									flag_char_commando = 5;
									/*keep_posi = locate_cursor_field;
									flag_char_selected[CHAR_MOVE] = 1;
									flag_char_commando = 0;
									status[StatusSeachPosi(locate_cursor_field)].m_ap-=UseMoveAP();
									stage->AreaDeleat();*/
								}
							}
							if(key[X_PUSH-1] == X_PUSH){	//�]�L�[�������ꂽ��
								if(stage->GetAreaInfoData(locate_cursor_field.x,locate_cursor_field.y) != 5){
									area_shift = D3DCOLOR_ARGB(0,0,0,0);
									flag_char_commando = 0;
									key[X_PUSH - 1] = 0;
									stage->SetFieldCharacterData(locate_cursor_field,U_BLANK_AREA);
									stage->SetFieldCharacterData(keep_posi,keep_field_id[keep_char_select]);
								}
							}
						}	
					}
					else if(flag_char_commando == 5){
						if(key[Z_PUSH-1] == Z_PUSH){	//�y�L�[�������ꂽ��
							keep_posi = locate_cursor_field;
							flag_char_selected[CHAR_MOVE] = 1;
							flag_char_commando = 0;
							status[StatusSeachPosi(locate_cursor_field)].m_ap-=UseMoveAP();
							stage->AreaDeleat();
						}
						if(key[X_PUSH-1] == X_PUSH){	//�]�L�[�������ꂽ��
							flag_char_commando = 3;
						}
					}
				}
				break;
			case CHAR_ATTACK:	//�L�����U��
				if(flag_char_selected[CHAR_ATTACK] != 1)
				{
					if(flag_char_commando == 0)
					{
						if(StatusSeachPosi(locate_cursor_field) != stage->GetCharMaxData()){
							keep_direction = status_battle[StatusSeachPosi(locate_cursor_field)].m_direction;
						}
						if(key[Z_PUSH-1] == Z_PUSH)	//�y�L�[�������ꂽ��U���ł���G���A��T���Ă��̃G���A�̐F��Ԃɂ���
						{	
							if(status[StatusSeachPosi(locate_cursor_field)].m_ap<UseNormalAttackAP())
							{
							//	MessageBox(NULL,TEXT("AP������܂���"),TEXT("AP�x��"),MB_OK);
								SoundPlay(false,59);							
								flag_char_commando = 0;
							}
							else{
							stage->AreaSeach(locate_cursor_field.x,locate_cursor_field.y,keep_char_select,status[StatusSeachPosi(locate_cursor_field)].m_atkrange,CHAR_ATTACK);
							area_shift = D3DCOLOR_ARGB(70,170,20,20);
							flag_char_commando = 3;
							}
						}
						if(key[X_PUSH-1] == X_PUSH) { if(!SelectedCommando()){ flag_any_end = 1; } }	//X�L�[�������ꂽ��J�[�\���ړ��ɖ߂�
					}
					else if(flag_char_commando == 3)
					{
						status_battle[StatusSeachId(keep_field_id[keep_char_select])].m_direction = direction;
						if(key[Z_PUSH-1] == Z_PUSH)
						{
							if(stage->IdSeach(locate_cursor_field.x,locate_cursor_field.y) >= U_SAHAGIN1 && 
								stage->IdSeach(locate_cursor_field.x,locate_cursor_field.y) <= U_LIZARDMAN3)
							{
								if(stage->GetAreaInfoData(locate_cursor_field.x,locate_cursor_field.y) == 1){
									flag_char_commando = 5;
								}
							}
						}
						if(key[X_PUSH-1] == X_PUSH){	//�w�L�[�������ꂽ��U���͈̓G���A�������ăR�}���h�ɖ߂�
							flag_char_commando = 0;
							area_shift = D3DCOLOR_ARGB(0,0,0,0);
							locate_cursor_field = keep_posi;
						}
					}
					else if(flag_char_commando == 5){
						if(key[Z_PUSH-1] == Z_PUSH){
							flag_atk = 1;
							flag_char_commando = 2;
						}
						if(key[X_PUSH-1] == X_PUSH){	//�w�L�[�������ꂽ��U���͈̓G���A�������ăR�}���h�ɖ߂�
							flag_char_commando = 3;
						}
					}
					BattleProcess();	//�ǉ�2/12(nisii)
				}
				break;
			case CHAR_SPECIAL:	//�L��������
				if(flag_char_selected[CHAR_SPECIAL] != 2)
				{
					if(flag_char_commando == 0){
						if(StatusSeachPosi(locate_cursor_field) != stage->GetCharMaxData()){
							keep_direction = status_battle[StatusSeachPosi(locate_cursor_field)].m_direction;
						}
						if(key[Z_PUSH-1] == Z_PUSH){
							flag_char_commando = 4;
							key[Z_PUSH-1] = 0;
						}
						if(key[X_PUSH-1] == X_PUSH) { if(!SelectedCommando()){ flag_any_end = 1; } }	//X�L�[�������ꂽ��J�[�\���ړ��ɖ߂�
					}
					else if(flag_char_commando == 4)
					{
						if(key[Z_PUSH-1] == Z_PUSH)
						{
							if(locate_cursor_skill == 0){
								if(status[StatusSeachPosi(keep_posi)].m_ap<UseSpecialAP1())
								{
									//MessageBox(NULL,TEXT("AP������܂���"),TEXT("AP�x��"),MB_OK);
									SoundPlay(false,59);
									flag_char_commando=0;
								}
								else{
									stage->AreaSeach(locate_cursor_field.x,locate_cursor_field.y,keep_char_select,status[StatusSeachPosi(locate_cursor_field)].m_skill_range1,CHAR_SPECIAL);
									area_shift = D3DCOLOR_ARGB(70,170,20,170);
									flag_char_commando = 3;
									key[Z_PUSH-1] = 0;
								}
							}
							else{
								if(status[StatusSeachPosi(locate_cursor_field)].m_ap<UseSpecialAP2())
								{
									//MessageBox(NULL,TEXT("AP������܂���"),TEXT("AP�x��"),MB_OK);
									SoundPlay(false,59);
									flag_char_commando=0;
								}
								else{
									stage->AreaSeach(locate_cursor_field.x,locate_cursor_field.y,keep_char_select,status[StatusSeachPosi(locate_cursor_field)].m_skill_range2,CHAR_SPECIAL);
									area_shift = D3DCOLOR_ARGB(70,170,20,170);
									flag_char_commando = 3;
									key[Z_PUSH-1] = 0;
								}
							}
						}
						if(key[X_PUSH-1] == X_PUSH){
							flag_char_commando = 0;
						}
					}
					BattleSkill(key);
					SkillProcess();
				}
				break;
			case CHAR_SP_EXTRA:
				if(flag_char_commando == 0){
					keep_direction = status_battle[StatusSeachPosi(locate_cursor_field)].m_direction;
					if(key[Z_PUSH-1] == Z_PUSH){
						if(status[StatusSeachPosi(locate_cursor_field)].m_mg == 100){
							stage->AreaSeach(locate_cursor_field.x,locate_cursor_field.y,keep_char_select,status[StatusSeachPosi(locate_cursor_field)].m_atkrange,CHAR_SP_EXTRA);
							area_shift = D3DCOLOR_ARGB(70,170,170,20);
							flag_char_commando = 3;
						}
					}
					if(key[X_PUSH-1] == X_PUSH) { if(!SelectedCommando()){ flag_any_end = 1; } }	//X�L�[�������ꂽ��J�[�\���ړ��ɖ߂�
				}
				else if(flag_char_commando == 3){
					status_battle[StatusSeachId(keep_field_id[keep_char_select])].m_direction = direction;
					if(key[Z_PUSH-1] == Z_PUSH){
						if(stage->IdSeach(locate_cursor_field.x,locate_cursor_field.y) >= U_SAHAGIN1 &&
							stage->IdSeach(locate_cursor_field.x,locate_cursor_field.y) <= U_LIZARDMAN3)
						{
							if(stage->GetAreaInfoData(locate_cursor_field.x,locate_cursor_field.y) == 1){
								flag_char_commando = 5;
							}
						}
					}
					if(key[X_PUSH-1] == X_PUSH){
						flag_char_commando = 0;
						area_shift = D3DCOLOR_ARGB(0,0,0,0);
						locate_cursor_field = keep_posi;
					}
				}
				else if(flag_char_commando == 5){
					if(key[Z_PUSH-1] == Z_PUSH){
						flag_char_commando = 2;
						flag_sound_in = true;
						flag_sp_extra = stage->IdSeach(keep_posi.x,keep_posi.y);
					}
					if(key[X_PUSH-1] == X_PUSH){
						flag_char_commando = 3;
					}
				}
				BattleSpExtra();
				break;
			case CHAR_STATE:	//�L�����X�e�[�^�X
				if(flag_char_commando == 0){
					if(key[Z_PUSH-1] == Z_PUSH){	//�y�L�[�������ꂽ��
						flag_char_commando = 1;
						flag_status_draw = 1;
					}
					if(key[X_PUSH-1] == X_PUSH) { if(!SelectedCommando()){ flag_any_end = 1; } }	//X�L�[�������ꂽ��J�[�\���ړ��ɖ߂�
				}
				if(flag_char_commando == 1){
					if(key[X_PUSH-1] == X_PUSH){
						flag_char_commando = 0;
						flag_status_draw = 0;
					}
				}
				break;
			case CHAR_WAIT:		//�L�����ҋ@
				if(flag_char_commando == 2){
					status_battle[StatusSeachPosi(locate_cursor_field)].m_direction = direction;
					if(key[Z_PUSH-1] == Z_PUSH){
						status_battle[StatusSeachPosi(locate_cursor_field)].m_action_end = true;
						flag_any_end = 1;
						flag_char_commando = 0;
						locate_cursor_commando = 0;
						deleat_posi.x = deleat_posi.y = 0;
						for(int i = 0;i < 3;i++){
							flag_char_selected[i] = 0;
						}
					}
					if(key[X_PUSH-1] == X_PUSH){
						status_battle[StatusSeachPosi(locate_cursor_field)].m_direction = keep_direction;
						flag_char_commando = 0;
						key[X_PUSH-1] = 0;
					}
				}
				else if(key[Z_PUSH-1] == Z_PUSH)	//�y�L�[�������ꂽ��
				{
					flag_char_commando = 2;
					key[Z_PUSH-1] = 0;
				}
				if(key[X_PUSH-1] == X_PUSH) { if(!SelectedCommando()){ 
					flag_any_end = 1;
					locate_cursor_commando = 0;
				} }	//X�L�[�������ꂽ��J�[�\���ړ��ɖ߂�
				break;
			}
			status_battle[StatusSeachPosi(locate_cursor_field)].m_pos_chara_x = locate_cursor_field.x;
			status_battle[StatusSeachPosi(locate_cursor_field)].m_pos_chara_y = locate_cursor_field.y;
		}
	}
	else if(stage->GameStateSeach() == STATE_CLEAR || stage->GameStateSeach() == STATE_GAMEOVER)	//�Q�[���I�[�o�[�������̓Q�[���N���A�Ȃ�
	{
		if(cnt++ <= 53){
			fade2 -= 1.28;
			for(int i = 0;i < MAX_BATTLE_DATA - R_BATTLE_FIELD1;i++){
				m_graphics->SetColor(D3DCOLOR_ARGB((int)fade2,255,255,255),R_BATTLE_FIELD1 + i);
			}
		}
		if(cnt >= 54){
			if(stage->GameStateSeach() == STATE_CLEAR){
				battle_change = BATTLE_CLEAR;	//�Q�[���N���A��������
			}
			else if(stage->GameStateSeach() == STATE_GAMEOVER){	//�Q�[���I�[�o�[��������
				if(cnt < 113){
					flag_geme_end = 1;
					m_graphics->SetColor(D3DCOLOR_ARGB(fade3,255,255,255),R_ENEMY_PHASE);
					fade3 += 4;
				}
				if(cnt > 113){
					fade2 -= 12.8;
					if(fade2 < 0){
						//�^�C�g����
						m_scene_flag = TITLE;
					}
					else{
						for(int i = 0;i < MAX_BATTLE_DATA - R_BATTLE_FIELD1;i++){
							m_graphics->SetColor(D3DCOLOR_ARGB((int)fade2,255,255,255),R_BATTLE_FIELD1 + i);
						}
					}
				}
			}
		}
	}
	stage->FieldControl(locate_cursor_field.x,locate_cursor_field.y);
}

//�ǉ�2/12(nisii)
void C_Battle::BattleProcess(void)			//�o�g�����̏����i�퓬�Ȃǁj
{
	static int cnt_in = 0;
	if(!flag_atk)	return ; //�A�^�b�N���Ă��Ȃ����͖���

	if(hitInit){
		//�f�[�^�Z�b�g
		BattleDataSet();

		if(! damegeCulc->HitResult( getPlData.status.m_dex, getEnemyData.status.m_agl ) ){	return ; }	//�q�b�g���Ă��Ȃ������珈�����I����
		//�������瓖�������ꍇ�̏���
		hitDamage = (double)damegeCulc->NormalAttackDamage( getPlData.status.m_atk, getEnemyData.status.m_def );
		
		if(hitDamage > 0){		//�_���[�W��1�ȏ゠���
			//�G�̌�������낾������
			if(getEnemyData.direction == getPlData.direction)	hitDamage *= 2.0;
			//�N���e�B�J���v�Z
			hitDamage *= damegeCulc->Critical(getPlData.status.m_luk);
		}else hitDamage = 0;	//�|�_���[�W��0�ɂ���

		charaAttack = true;	//�L�������U����Ԃɂ���B
		charaAttackCnt = (getPlData.direction + 1 ) * 4;	//�L�����̍U���J�E���g�p
		keepAttackCnt = charaAttackCnt;
		charaAttackEfCnt = 0;
		AtkEfStart = false;
		cnt_in = 0;
		/*flag_sound_ef = true;
		sound_ef_change_attack = 3;*/
	}
	switch(getPlData.status.m_id){
		case U_ZION:
			if(charaAttackEfCnt == 2){
				cnt_in++;
				if(cnt_in <= 1){
					flag_sound_ef = true;
					sound_ef_change_attack = 0;
					flag_voice_attack = true;
					voice_change_attack = rand()%3;
				}
			}
			break;
		case U_VAN:
			if(charaAttackEfCnt == 2){
				cnt_in++;
				if(cnt_in <= 1){
					flag_sound_ef = true;
					sound_ef_change_attack = 1;
					flag_voice_attack = true;
					voice_change_attack = rand()%5+3;
				}
			}
			break;
		case U_RIO:
			if(charaAttackEfCnt == 2){
				cnt_in++;
				if(cnt_in <= 1){
					flag_sound_ef = true;
					sound_ef_change_attack = 2;
					flag_voice_attack = true;
					if(getPlData.status.m_ap >= 4){
						voice_change_attack = 8;
					}
					else{
						voice_change_attack = 9;
					}
				}
			}
			break;
	}

	if(charaAttack){
		if(getPlData.status.m_id < U_SAHAGIN1){
			if(deray[ keep_field_id[keep_char_select] / 10 - 1 ][ charaAttackCnt - keepAttackCnt ] <= atkDeray++){
				charaAttackCnt++;
				if(flag_skill > 0){
				}
				else{
					if(getPlData.status.m_id == U_ZION || getPlData.status.m_id == U_VAN){
						charaAttackEfCnt++;
					}
				}
				atkDeray = 0;
			}
			if(charaAttackCnt - keepAttackCnt >= 4){
				charaAttack = !charaAttack;
				AtkEfStart = true;
				atkDeray = 0;
				/*charaAttackEfCnt = 0;*/
			}
			return;
		}
	}
	if(AtkEfStart){
		if(4 <= atkDeray++){
			charaAttackEfCnt++;
			atkDeray = 0;
		}
		if(charaAttackEfCnt >= 4){
			AtkEfStart = false;
			charaAttackEfCnt = 0;
		}
	}

	if(battleDrawEnd){
		//�U�������Ώۂ�HP�����炷
		SetDamage( StatusSeachId(stage->GetFieldCharacterData(locate_cursor_field.x,locate_cursor_field.y)), (int)hitDamage );

		//�o�g���I������
		BattleEndProcess();
		battleDrawEnd = false;
		hitInit = true;
	}
}

void C_Battle::AttackEffectDraw(int i,int j)
{
	if(getPlData.status.m_id == U_ZION || getPlData.status.m_id == U_VAN) { if(!charaAttack) return ; }
	else if(!AtkEfStart) return ;
	if(flag_skill > 0) return ;
	static int cnt = 0;
	static int cnt2 = 0;
	static int change = 0;
	static float down = 0;
	if(locate_cursor_field.x == i && locate_cursor_field.y == j){
		if(getPlData.status.m_id == U_ZION){
			//�����ߓx���e�_�ł������Ďa����\�����悤�Ƃ������@�[�W����
			/*if(charaAttackCnt == 0){
				m_graphics->SetColor2(0x00FFFFFF,0);
				m_graphics->SetColor2(0x00FFFFFF,1);
				m_graphics->SetColor2(0xFFFFFFFF,2);
				m_graphics->SetColor2(0xFFFFFFFF,3);
			}
			if(charaAttackCnt == 1){
				m_graphics->SetColor2(0x55FFFFFF,0);
				m_graphics->SetColor2(0x55FFFFFF,1);
				m_graphics->SetColor2(0xAAFFFFFF,2);
				m_graphics->SetColor2(0xAAFFFFFF,3);
			}
			if(charaAttackCnt == 2){
				m_graphics->SetColor2(0xAAFFFFFF,0);
				m_graphics->SetColor2(0xAAFFFFFF,1);
				m_graphics->SetColor2(0x55FFFFFF,2);
				m_graphics->SetColor2(0x55FFFFFF,3);
			}
			if(charaAttackCnt >= 3){
				m_graphics->SetColor2(0xFFFFFFFF,0);
				m_graphics->SetColor2(0xFFFFFFFF,1);
				m_graphics->SetColor2(0x00FFFFFF,2);
				m_graphics->SetColor2(0x00FFFFFF,3);
			}*/
			//���G�t�F�N�g�����S�Ɍ������Ԃɂ������@�[�W����
			//m_graphics->DrawCC2(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y - 40.0f,m_pTexture[T_ATK_SP_EF],T_ATK_SP_EF,R_CUT_EF1+getPlData.direction);
			//���G�t�F�N�g���n�ʂɂ��߂��܂�Ă��܂��Ă��郔�@�[�W����
			//m_graphics->DrawCC2(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y - 25.f,m_pTexture[T_ATK_SP_EF],T_ATK_SP_EF,R_CUT_EF1+getPlData.direction);
			if(charaAttackEfCnt >= 3){
				if(cnt2++ == 5){
					charaAttackEfCnt++;
				}
				switch(getPlData.direction)
				{
				case 0:
					change = 2;
					down = 0.f;
					break;
				case 1:
					change = 6;
					down = 35.f;
					break;
				case 2:
					change = 4;
					down = 0.f;
					break;
				case 3:
					change = 0;
					down = 0.f;
					break;
				}
				m_graphics->DrawCC(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y - 25.f + down,m_pTexture[T_ATK_SP_EF2],T_ATK_SP_EF2,R_CUT_EF01 + charaAttackEfCnt - 3 + change);
			}
			//�������܂�
			//����`�ʒu�Ŏa����\��
			/*m_graphics->SetPostion(225.f - 3.90625f * (cnt),0.f + 99.f * getPlData.direction,225.f - 3.90625f * (cnt++),100.f + 99.f * getPlData.direction,R_CUT_EF1 + getPlData.direction);
			m_graphics->Draw(stage->GetFieldPositionData(i,j).x - 50.f,stage->GetFieldPositionData(i,j).y - 62.5f + (125.f - 3.90625f * cnt),m_pTexture[T_ATK_SP_EF],T_ATK_SP_EF,R_CUT_EF1+getPlData.direction);*/
			//��(*�L�t`;)�c�v
			//�������Ƃɒ��߂��Ă݂�
			/*m_graphics->SetPostion(193.75f - 31.25f * charaAttackEfCnt,0.f + 99.f * getPlData.direction,225.f - 31.25f * charaAttackEfCnt,100.f + 99.f * getPlData.direction,R_CUT_EF1 + getPlData.direction);
			m_graphics->Draw(stage->GetFieldPositionData(i,j).x - 50.f,stage->GetFieldPositionData(i,j).y - 62.5f + (125.f - 31.25f * (charaAttackEfCnt+1)),m_pTexture[T_ATK_SP_EF],T_ATK_SP_EF,R_CUT_EF1+getPlData.direction);*/
			//���_���������B
		}
		else if(getPlData.status.m_id == U_VAN){
			/*if(charaAttackEfCnt == 0){
				m_graphics->SetColor2(0xFFFFFFFF,0);
				m_graphics->SetColor2(0xFFFFFFFF,1);
				m_graphics->SetColor2(0x00FFFFFF,2);
				m_graphics->SetColor2(0x00FFFFFF,3);
			}
			if(charaAttackEfCnt == 1){
				m_graphics->SetColor2(0xAAFFFFFF,0);
				m_graphics->SetColor2(0xAAFFFFFF,1);
				m_graphics->SetColor2(0x55FFFFFF,2);
				m_graphics->SetColor2(0x55FFFFFF,3);
			}
			if(charaAttackEfCnt == 2){
				m_graphics->SetColor2(0x55FFFFFF,0);
				m_graphics->SetColor2(0x55FFFFFF,1);
				m_graphics->SetColor2(0xAAFFFFFF,2);
				m_graphics->SetColor2(0xAAFFFFFF,3);
			}
			if(charaAttackEfCnt >= 3){
				m_graphics->SetColor2(0x00FFFFFF,0);
				m_graphics->SetColor2(0x00FFFFFF,1);
				m_graphics->SetColor2(0xFFFFFFFF,2);
				m_graphics->SetColor2(0xFFFFFFFF,3);
			}*/
			if(charaAttackEfCnt >= 3){
				if(cnt2++ == 5){
					charaAttackEfCnt++;
				}
				switch(getPlData.direction)
				{
				case 0:
					change = 2;
					down = 0.f;
					break;
				case 1:
					change = 2;
					down = 0.f;
					break;
				case 2:
					change = 0;
					down = 0.f;
					break;
				case 3:
					change = 0;
					down = 0.f;
					break;
				}
				m_graphics->DrawCC(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y - 25.f,m_pTexture[T_ATK_SP_EF2],T_ATK_SP_EF2,R_CUT_EF_VAN01 + charaAttackEfCnt - 3 + change);
			}
			//m_graphics->DrawCC2(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y - 35.0f,m_pTexture[T_ATK_SP_EF],T_ATK_SP_EF,R_CUT_EF1+getPlData.direction);
		}
		else{
			m_graphics->DrawCC(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y - 13.5f,m_pTexture[T_ATK_EF],T_ATK_EF,R_RIO_JUGEKI1 + charaAttackEfCnt);
		}
	}
}

void C_Battle::BattleDataSet(void)			//��풆�̓G�ƃv���C���[�̃f�[�^���Z�b�g
{
	//�X�e�[�^�X
	getEnemyData.status	= status[StatusSeachPosi (locate_cursor_field.x,locate_cursor_field.y)];
	getPlData.status	= status[StatusSeachId( keep_field_id[keep_char_select] ) ];

	//�o�g���f�[�^
	getEnemyData.direction = status_battle[StatusSeachPosi(locate_cursor_field.x,locate_cursor_field.y)].m_direction;
	getPlData.direction	= status_battle[StatusSeachId( keep_field_id[keep_char_select] ) ].m_direction;

	memset(drawBattleData, 0, sizeof(DrawBattleData) * 3);

}

void C_Battle::BattleEndProcess(void)		//�o�g���I������
{
	//���񂾂��ǂ����H
	if(flag_turn == PLAYER_TURN){
		if( DeathCheck( StatusSeachId(getEnemyData.status.m_id) ) ) {
			status_battle[StatusSeachId(getEnemyData.status.m_id)].m_battle_impossible = true;
			stage->SetFieldCharacterData( locate_cursor_field, U_BLANK_AREA );
		}
	}
	else{
		if( DeathCheck( StatusSeachId(getPlData.status.m_id) ) ) {
			status_battle[StatusSeachId(getEnemyData.status.m_id)].m_battle_impossible = true;
			stage->SetFieldCharacterData( locate_cursor_field, U_BLANK_AREA );
		}
	}

	//���ݑI�΂�Ă���L�����̍s�����I��
	//status_battle[StatusSeachId(keep_field_id[keep_char_select])].m_action_end = true;

	if(flag_atk){
		flag_char_selected[CHAR_ATTACK] = 1;	//�U���R�}���h��I���I��
		status[StatusSeachId(getPlData.status.m_id)].m_ap -= UseNormalAttackAP();
		status_battle[StatusSeachPosi(keep_posi)].m_action_end = true;
		flag_any_end = 1;
		flag_char_commando = 0;
		locate_cursor_commando = 0;
		deleat_posi.x = deleat_posi.y = 0;
		for(int i = 0;i < 3;i++){
			flag_char_selected[i] = 0;
		}
	}
	if(flag_enemy_atk > 0) { flag_char_selected[CHAR_ATTACK] = 1; }
	if(flag_skill > 0){
		flag_char_selected[CHAR_SPECIAL] = 1;	//����R�}���h��I���I��(��)
		if(flag_skill <= RIO_SKILL_ATK){
			status[StatusSeachId(getPlData.status.m_id)].m_ap -= UseSpecialAP1();
			status_battle[StatusSeachPosi(keep_posi)].m_action_end = true;
			flag_any_end = 1;
			flag_char_commando = 0;
			locate_cursor_commando = 0;
			deleat_posi.x = deleat_posi.y = 0;
			for(int i = 0;i < 3;i++){
				flag_char_selected[i] = 0;
			}
		}
		if(flag_skill > RIO_SKILL_ATK){
			status[StatusSeachId(getPlData.status.m_id)].m_ap -= UseSpecialAP2();
		}
	}

	flag_atk = 0;							//�U�����Ă��Ȃ���Ԃɖ߂�
	flag_enemy_atk = 0;
	flag_skill = 0;							//����U�����Ă��Ȃ���Ԃɖ߂�
	area_shift = D3DCOLOR_ARGB(0,0,0,0);	//�}�X�̐F������
	locate_cursor_field = keep_posi;
	flag_char_commando = 0;
	if(flag_turn == PLAYER_TURN){
		status[StatusSeachId(getPlData.status.m_id)].m_mg += damegeCulc->MGPlus(getEnemyData.status.m_id);
		if(status[StatusSeachId(getPlData.status.m_id)].m_mg >= status[StatusSeachId(getPlData.status.m_id)].m_maxmg) { status[StatusSeachId(getPlData.status.m_id)].m_mg = status[StatusSeachId(getPlData.status.m_id)].m_maxmg;}
	}
}

void C_Battle::BattleProcessDraw(void)		//�o�g�����̕`��
{
	if(!flag_atk && flag_enemy_atk == 0)	return ;	//�U����Ԃ���Ȃ���Ώ������Ȃ�

	if(hitInit){
		for(int i = 0, num = (int)hitDamage; i < 3; i++, num /= 10){
			drawBattleData[2 - i].damage = num % 10;
			drawBattleData[2 - i].move = 20;
			drawBattleData[2 - i].act = false;
			drawBattleData[2 - i].posX = stage->GetFieldPositionData(locate_cursor_field.x,locate_cursor_field.y).x + (2 - i) * 30.f - 50.f;
			drawBattleData[2 - i].posY = stage->GetFieldPositionData(locate_cursor_field.x,locate_cursor_field.y).y - 60.f;

			if(num == 0) break;
		}
		drawBattleData[2 - (int)log10(hitDamage)].act = true;
		hitInit = false;
	}

	if(charaAttack == true || AtkEfStart == true)	return; //�L�������[�V�������͉��̏����͂��Ȃ�

	int num = (int)hitDamage;
	int loop = 0;
	static int cnt = 0;

	m_graphics->SetColor(D3DCOLOR_ARGB(255,255,255,255),R_STATUS_NUM100);
	do{
		m_graphics->SetPostion(rect_battle[R_STATUS_NUM100].top,rect_battle[R_STATUS_NUM100].left + 30.f * drawBattleData[2 - loop].damage ,rect_battle[R_STATUS_NUM100].bottom,rect_battle[R_STATUS_NUM100].right + 30.f * (num % 10),R_STATUS_NUM100);
		m_graphics->DrawCC(drawBattleData[2 - loop].posX,drawBattleData[2 - loop].posY - drawBattleData[2 - loop].move,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_NUM100);
		if(drawBattleData[2 - loop].move > 0 && drawBattleData[2 - loop].act) drawBattleData[2 - loop].move -= 5;
		else if(drawBattleData[loop].move <= 0 && loop <= 2) drawBattleData[loop+1].act = true;

		if(drawBattleData[2].move <= 0){
			if(cnt++ == 60){
				cnt = 0;
				battleDrawEnd = true;
			}
		}
		num /= 10;
		loop++;
	}while(num > 0);
}

float C_Battle::BattleDrawConvert(int id, bool x)		//�o�g�����̕`��ʒu�C��
{
	if(!charaAttack)	return 0.f;

	if(id == U_ZION && id == keep_field_id[keep_char_select])	return -12.5f;
	if(id == U_VAN && id == keep_field_id[keep_char_select]){
		if(status_battle[StatusSeachId(U_VAN)].m_direction == LEFT_BACK || status_battle[StatusSeachId(U_VAN)].m_direction == LEFT_FLONT){
			if(x == true){
				return -25.f;
			}
		}
		return (x ? 25.0f : -12.5f);
	}
	return 0.f;
}

//�ǉ������܂�

void C_Battle::BattleSkill(int* key)	//�X�L���I����ʂł̃R���g���[��
{
	static int keep_flag_skill = 0;
	if(flag_char_commando == 3)
	{
		status_battle[StatusSeachId(keep_field_id[keep_char_select])].m_direction = direction;
		if(key[Z_PUSH-1] == Z_PUSH)
		{
			if(keep_char_select == ZION_ID){		//�V�I��
				if(locate_cursor_skill == 0){
					if(stage->IdSeach(locate_cursor_field.x,locate_cursor_field.y) >= U_SAHAGIN1)		//�G�Ȃ�
					{
						if(stage->GetAreaInfoData(locate_cursor_field.x,locate_cursor_field.y) == 1)
						{
							keep_flag_skill = ZION_SKILL_ATK;
							flag_char_commando = 5;
						}
					}
				}
				else{
					if(stage->IdSeach(locate_cursor_field.x,locate_cursor_field.y) != U_BLANK_AREA &&	//�����Ȃ�
						stage->IdSeach(locate_cursor_field.x,locate_cursor_field.y) < U_SAHAGIN1){
							if(stage->GetAreaInfoData(locate_cursor_field.x,locate_cursor_field.y) >= 1)
							{
								keep_flag_skill = ZION_SKILL_EFFECT;
								flag_char_commando = 5;
							}
					}
				}
			}
			else if(keep_char_select == VAN_ID){	//���@��
				if(locate_cursor_skill == 0){
					if(stage->IdSeach(locate_cursor_field.x,locate_cursor_field.y) >= U_SAHAGIN1)		//�G�Ȃ�
					{
						if(stage->GetAreaInfoData(locate_cursor_field.x,locate_cursor_field.y) == 1)
						{
							keep_flag_skill = VAN_SKILL_ATK;
							flag_char_commando = 5;
						}
					}
				}
				else{
					if(stage->IdSeach(locate_cursor_field.x,locate_cursor_field.y) != U_BLANK_AREA &&	//�����Ȃ�
						stage->IdSeach(locate_cursor_field.x,locate_cursor_field.y) < U_SAHAGIN1){
							if(stage->GetAreaInfoData(locate_cursor_field.x,locate_cursor_field.y) >= 1)
							{
								keep_flag_skill = VAN_SKILL_EFFECT;
								flag_char_commando = 5;
							}
					}
				}
			}
			else{									//���I
				if(locate_cursor_skill == 0){
					if(stage->IdSeach(locate_cursor_field.x,locate_cursor_field.y) >= U_SAHAGIN1)		//�G�Ȃ�
					{
						if(stage->GetAreaInfoData(locate_cursor_field.x,locate_cursor_field.y) == 1)
						{
							keep_flag_skill = RIO_SKILL_ATK;
							flag_char_commando = 5;
						}
					}
				}
				else{
					if(stage->IdSeach(locate_cursor_field.x,locate_cursor_field.y) != U_BLANK_AREA &&	//�����Ȃ�
						stage->IdSeach(locate_cursor_field.x,locate_cursor_field.y) < U_SAHAGIN1){
							if(stage->GetAreaInfoData(locate_cursor_field.x,locate_cursor_field.y) >= 1)
							{
								keep_flag_skill = RIO_SKILL_EFFECT;
								flag_char_commando = 5;
							}
					}
				}
			}
		}
		if(key[X_PUSH-1] == X_PUSH){	//�w�L�[�������ꂽ��U���͈̓G���A�������ăR�}���h�ɖ߂�
			flag_char_commando = 4;
			area_shift = D3DCOLOR_ARGB(0,0,0,0);
			locate_cursor_field = keep_posi;
		}
	}
	else if(flag_char_commando == 5){
		if(key[Z_PUSH-1] == Z_PUSH){
			flag_char_commando = 2;
			flag_skill = keep_flag_skill;
			keep_flag_skill = 0;
		}
		if(key[X_PUSH-1] == X_PUSH){
			flag_char_commando = 3;
			keep_flag_skill = 0;
		}
	}
}

void C_Battle::SkillProcess()
{
	if(!flag_skill)	return ;	//������g��Ȃ����菈�����Ȃ�

	if(hitInit){
		if(flag_skill != VAN_SKILL_ATK){
			if(status[StatusSeachId( keep_field_id[keep_char_select] ) ].m_attribute == SYLPH && flag_skill == ZION_SKILL_ATK){
				BattleDataSetVan();	//�f�[�^�Z�b�g
				flag_voice = true;
				voice_change = 0;
			}
			else { 
				BattleDataSet();
				flag_voice = true;
				switch(getPlData.status.m_attribute)
				{
				case SALAMANDER:
					if(flag_skill == RIO_SKILL_ATK){voice_change = 8;}
					else if(flag_skill == RIO_SKILL_EFFECT){voice_change = 9;}
					else {voice_change = 5;}
					break;
				case UNDINE:
					if(flag_skill == ZION_SKILL_ATK){voice_change = 2;}
					else if(flag_skill == ZION_SKILL_EFFECT){voice_change = 3;}
					else if(flag_skill == RIO_SKILL_ATK){voice_change = 10;}
					else {voice_change = 11;}
					break;
				case SYLPH:
					voice_change = 1;
					break;
				case GNOME:
					voice_change = 7;
					break;
				}
			}
		}
		else{
			BattleDataSetVan();
			flag_voice = true;
			if(getPlData.status.m_attribute == GNOME){voice_change = 6;}
			else{voice_change = 4;}
		}
		switch(flag_skill)
		{
		case 0:
			break;
		case ZION_SKILL_ATK:case RIO_SKILL_ATK:
			if(flag_skill == RIO_SKILL_ATK && getPlData.status.m_attribute == UNDINE){
				charaSkillatk = true;		//�L�������X�L���U����Ԃɂ���B
				charaAttackCnt = (getPlData.direction + 1 ) * 4;	//�L�����̍U���J�E���g�p
				keepAttackCnt = charaAttackCnt;
			}
			if(flag_skill == ZION_SKILL_ATK && getPlData.status.m_attribute == SYLPH){
				for(int i = 0;i < 2;i++){
					if(! damegeCulc->HitResult( getPlData.status.m_dex,getEnemydatavan[i].status.m_agl)){continue;}//�q�b�g���ĂȂ������玟�̏����ɍs��
					getEnemydatavan[i].hitDamagevan = (double)damegeCulc->NormalAttackDamage( getPlData.status.m_atk,getEnemydatavan[i].status.m_def);
					if(getEnemydatavan[i].hitDamagevan > 0){
						if(getEnemydatavan[i].direction == getPlData.direction)	getEnemydatavan[i].hitDamagevan *= 2.0;
						getEnemydatavan[i].hitDamagevan *= damegeCulc->Critical(getPlData.status.m_luk);
					}else getEnemydatavan[i].hitDamagevan = 0;	//�[�_���[�W���O�ɂ���
				}
				charaSkillatk = true;
				charaAttackCnt = (getPlData.direction + 1 ) * 4;	//�L�����̍U���J�E���g�p
				keepAttackCnt = charaAttackCnt;
			}
			else{
				if(! damegeCulc->HitResult( getPlData.status.m_dex, getEnemyData.status.m_agl)){ return ; }	//�q�b�g���ĂȂ������珈�����I����
				hitDamage = damegeCulc->SpecialAttackDamage( getPlData.status.m_atk,getPlData.status.m_mag,TopographyEffect(),damegeCulc->AttributeAffinity(getPlData.status.m_attribute,getEnemyData.status.m_attribute),getEnemyData.status.m_def,getEnemyData.status.m_res,getPlData.status.m_id);
				if(hitDamage > 0){
					if(getEnemyData.direction == getPlData.direction)	hitDamage *= 2.0;
					hitDamage *= damegeCulc->Critical(getPlData.status.m_luk);
				}else hitDamage = 0;	//�[�_���[�W�͂O�ɂ���
				charaSkillatk = true;		//�L�������X�L���U����Ԃɂ���B
				if(flag_skill == ZION_SKILL_ATK && getPlData.status.m_attribute == UNDINE){
					charaAttackCnt = 124 + ((getPlData.direction + 1 ) * 4);	//�L�����̍U���J�E���g�p
					keepAttackCnt = charaAttackCnt;
				}
				else{
					charaAttackCnt = (getPlData.direction + 1 ) * 4;	//�L�����̍U���J�E���g�p
					keepAttackCnt = charaAttackCnt;
				}
			}
			break;
		case VAN_SKILL_ATK:
			if(getPlData.status.m_attribute == SALAMANDER){
				for(int i = 0;i < 3;i++){
					if(getEnemydatavan[i].direction == 4)	{continue;}
					if(! damegeCulc->HitResult( getPlData.status.m_dex,getEnemydatavan[i].status.m_agl)){continue;}//�q�b�g���ĂȂ������玟�̏����ɍs��
					getEnemydatavan[i].hitDamagevan = (double)damegeCulc->SpecialAttackDamage( getPlData.status.m_atk,getPlData.status.m_mag,TopographyEffect(),damegeCulc->AttributeAffinity(getPlData.status.m_attribute,getEnemydatavan[i].status.m_attribute),getEnemydatavan[i].status.m_def,getEnemydatavan[i].status.m_res,getPlData.status.m_id);
					if(getEnemydatavan[i].hitDamagevan > 0){
						if(getEnemydatavan[i].direction == getPlData.direction)	getEnemydatavan[i].hitDamagevan *= 2.0;
						getEnemydatavan[i].hitDamagevan *= damegeCulc->Critical(getPlData.status.m_luk);
					}else getEnemydatavan[i].hitDamagevan = 0;	//�[�_���[�W���O�ɂ���
				}
				charaSkillatk = true;
				charaAttackCnt = (getPlData.direction + 1 ) * 4;	//�L�����̍U���J�E���g�p
				keepAttackCnt = charaAttackCnt;
			}
			if(getPlData.status.m_attribute == GNOME){
				for(int i = 0;i < 12;i++){
					if(getEnemydatavan[i].direction == 4)	{continue;}
					if(! damegeCulc->HitResult( getPlData.status.m_dex,getEnemydatavan[i].status.m_agl)){continue;}//�q�b�g���ĂȂ������玟�̏����ɍs��
					getEnemydatavan[i].hitDamagevan = (double)damegeCulc->SpecialAttackDamage( getPlData.status.m_atk,getPlData.status.m_mag,TopographyEffect(),damegeCulc->AttributeAffinity(getPlData.status.m_attribute,getEnemydatavan[i].status.m_attribute),getEnemydatavan[i].status.m_def,getEnemydatavan[i].status.m_res,getPlData.status.m_id);
					if(getEnemydatavan[i].hitDamagevan > 0){
						getEnemydatavan[i].hitDamagevan *= damegeCulc->Critical(getPlData.status.m_luk);
					}else getEnemydatavan[i].hitDamagevan = 0;	//�[�_���[�W���O�ɂ���
				}
				charaSkillatk = true;
				charaAttackCnt = (getPlData.direction + 1 ) * 4;	//�L�����̍U���J�E���g�p
				keepAttackCnt = charaAttackCnt;
			}
			break;
		case ZION_SKILL_EFFECT:case RIO_SKILL_EFFECT:
			if(flag_skill == RIO_SKILL_EFFECT && getPlData.status.m_attribute == SALAMANDER)
			{
				keep_skill_ef_id[2] = StatusSeachId(stage->GetFieldCharacterData(locate_cursor_field.x,locate_cursor_field.y));
				flag_skill_ef[2] = (int)(status[StatusSeachId(stage->GetFieldCharacterData(locate_cursor_field.x,locate_cursor_field.y))].m_atk * BURST_EF_SIZE);
				flag_use_skill[2] = true;
				charaSkillatk = true;
			}
			else{
				recovery_point = damegeCulc->SpecialRecovery(getPlData.status.m_maxhp);
				charaSkillatk = true;	//�L�������X�L���񕜏�Ԃɂ���
			}
			break;
		case VAN_SKILL_EFFECT:
			if(getPlData.status.m_attribute == SALAMANDER){
				keep_skill_ef_id[0] = StatusSeachId(stage->GetFieldCharacterData(locate_cursor_field.x,locate_cursor_field.y));
				flag_skill_ef[0] = (int)(status[StatusSeachId(stage->GetFieldCharacterData(locate_cursor_field.x,locate_cursor_field.y))].m_atk * GOUSYOURAI_EF_SIZE);
				flag_use_skill[0] = true;
				charaSkillatk = true;
			}
			else if(getPlData.status.m_attribute == GNOME){
				keep_skill_ef_id[1] = StatusSeachId(stage->GetFieldCharacterData(locate_cursor_field.x,locate_cursor_field.y));
				flag_skill_ef[1] = (int)(status[StatusSeachId(stage->GetFieldCharacterData(locate_cursor_field.x,locate_cursor_field.y))].m_def * KOUSYOURAI_EF_SIZE);
				flag_use_skill[1] = true;
				charaSkillatk = true;
			}
			break;
		}
	}
	static int zion_attack_cnt = 0;

	if(charaSkillatk){
		if(flag_skill < ZION_SKILL_EFFECT){
			charaAttack = true;
			if(deray[ keep_field_id[keep_char_select] / 10 - 1 ][ charaAttackCnt - keepAttackCnt ] <= atkDeray++){
				charaAttackCnt++; 
				atkDeray = 0;
				if(flag_skill == ZION_SKILL_ATK && getPlData.status.m_attribute == UNDINE){
					if(sound_in++ == 1){
						flag_sound_sp = true;
						sound_ef_change_sp = 1;
					}
				}
				if(flag_skill == ZION_SKILL_ATK && getPlData.status.m_attribute == SYLPH){
					charaSkillCnt = charaAttackCnt - 1;
					SkillEfStart = true;
				}
			}
			if(charaAttackCnt - keepAttackCnt >= 4){
				if(flag_skill == ZION_SKILL_ATK && getPlData.status.m_attribute == SYLPH){
					charaSkillatk = !charaSkillatk;
					SkillEfStart = false;
				}
				else{
					charaAttackCnt -= 1;
					charaSkillatk = !charaSkillatk;
					SkillEfStart = true;
				}
			}
		}
		else{
			charaSkillatk = !charaSkillatk;
			SkillEfStart = true;
		}
		return;
	}
	if(SkillEfStart){
		if(flag_skill < ZION_SKILL_EFFECT){
			charaAttack = false;
			if(flag_skill == ZION_SKILL_ATK && getPlData.status.m_attribute == SYLPH){
			}
			else{
				if(flag_skill == VAN_SKILL_ATK && getPlData.status.m_attribute == GNOME){
					if(charaSkillCnt < 3){
						if(deray_skill[charaSkillCnt] <= atkDeray++){
							charaSkillCnt++;
							atkDeray = 0;
						}
					}
				}
				else{
					if(8 <= atkDeray++){
						charaSkillCnt++;
						atkDeray = 0;
					}
					if(flag_skill == VAN_SKILL_ATK && getPlData.status.m_attribute == SALAMANDER){
						if(charaSkillCnt >= 4){
							charaSkillCnt = 0;
							SkillEfStart = false;
						}
					}
					else{
						if(charaSkillCnt >= 4){
							charaSkillCnt = 0;
							SkillEfStart = false;
						}
					}
				}
			}
		}
		else{
			if(8 <= atkDeray++){
				charaRecoveryCnt++;
				atkDeray = 0;
			}
			if(charaRecoveryCnt >= 4){
				charaRecoveryCnt = 0;
				SkillEfStart = false;
			}
		}
	}

	if(battleDrawEnd)
	{
		//����U�������Ώۂ�HP�����炷
		if(flag_skill == RIO_SKILL_ATK && getPlData.status.m_attribute == UNDINE){
			if(damegeCulc->Critical(60) > 1){
				cut_out = StatusSeachId(stage->GetFieldCharacterData(locate_cursor_field.x,locate_cursor_field.y));
			}
		}
		else if(flag_skill == VAN_SKILL_ATK || flag_skill == ZION_SKILL_ATK && getPlData.status.m_attribute == SYLPH){
			SetDamageVan();
		}
		else if(flag_skill == RIO_SKILL_EFFECT || flag_skill == ZION_SKILL_EFFECT || flag_skill == VAN_SKILL_EFFECT){
			//����񕜂����Ώۂ�HP���񕜂���
			if(recovery_point != 0){
				SetRecovery( StatusSeachId(stage->GetFieldCharacterData(locate_cursor_field.x,locate_cursor_field.y)),(int)recovery_point);
			}
			if(flag_use_skill[0] == true){
				status[keep_skill_ef_id[0]].m_atk += flag_skill_ef[0];
				flag_use_skill[0] = false;
			}
			if(flag_use_skill[1] == true){
				status[keep_skill_ef_id[1]].m_def += flag_skill_ef[1];
				flag_use_skill[1] = false;
			}
			if(flag_use_skill[2] == true){
				status[keep_skill_ef_id[2]].m_atk += flag_skill_ef[2];
				flag_use_skill[2] = false;
			}
		}
		else{ SetDamage( StatusSeachId(stage->GetFieldCharacterData(locate_cursor_field.x,locate_cursor_field.y)),(int)hitDamage); }
		//����U���I������
		if(flag_skill == VAN_SKILL_ATK || flag_skill == ZION_SKILL_ATK && getPlData.status.m_attribute == SYLPH)
			BattleEndProcessVan();
		else BattleEndProcess();
		hitInit = true;
		battleDrawEnd = false;
		charaAttackEfCnt = 0;
		charaAttackCnt = 0;
		sound_in = 0;
		charaSkillCnt = 0;
	}
}

void C_Battle::BattleSkillDraw()
{
	int skill_ef_area = 0;
	SkillDetailDraw();
	if(!flag_skill)	return ;	//�U����Ԃ���Ȃ���Ώ������Ȃ�

	double hitnum = 0;

	if(hitInit){
		if(flag_skill == VAN_SKILL_ATK || flag_skill == ZION_SKILL_ATK && getPlData.status.m_attribute == SYLPH){
			if(getPlData.status.m_attribute == GNOME) { skill_ef_area = 12; }
			else if(getPlData.status.m_attribute == SALAMANDER) { skill_ef_area = 3; }
			else { skill_ef_area = 2; }
			for(int i = 0;i < skill_ef_area;i++){
				if(getEnemydatavan[i].status.m_id != 0){
					for(int j = 0, num = (int)getEnemydatavan[i].hitDamagevan;j < 3;j++,num /= 10)
					{
						drawBattleVanData[i][2-j].damage = num % 10;
						drawBattleVanData[i][2-j].move = 20;
						drawBattleVanData[i][2-j].act = false;
						drawBattleVanData[i][2-j].posX = stage->GetFieldPositionData(keep_skillarea[i].x,keep_skillarea[i].y).x + (2 - j) * 30.f - 50.f;
						drawBattleVanData[i][2-j].posY = stage->GetFieldPositionData(keep_skillarea[i].x,keep_skillarea[i].y).y - 60.f;

						if(num == 0) continue;
					}
					drawBattleVanData[i][2 - (int)log10(getEnemydatavan[i].hitDamagevan)].act = true;
				}
			}
		}
		else{
			if(flag_skill == ZION_SKILL_EFFECT || flag_skill == RIO_SKILL_EFFECT && getPlData.status.m_attribute == UNDINE){
				hitnum = recovery_point;
			}
			else if(flag_skill == RIO_SKILL_EFFECT && getPlData.status.m_attribute == SALAMANDER || flag_skill == VAN_SKILL_EFFECT){
				for(int i = 0;i < 3;i++){
					if(flag_use_skill[i] == true){
						hitnum = flag_skill_ef[i];
						break;
					}
				}
			}
			else {
				hitnum = hitDamage;}
			for(int i = 0, num = (int)hitnum; i < 3; i++, num /= 10){
				drawBattleData[2 - i].damage = num % 10;
				drawBattleData[2 - i].move = 20;
				drawBattleData[2 - i].act = false;
				drawBattleData[2 - i].posX = stage->GetFieldPositionData(locate_cursor_field.x,locate_cursor_field.y).x + (2 - i) * 30.f - 50.f;
				drawBattleData[2 - i].posY = stage->GetFieldPositionData(locate_cursor_field.x,locate_cursor_field.y).y - 60.f;

				if(num == 0) break;
			}
			drawBattleData[2 - (int)log10(hitnum)].act = true;
		}
		hitInit = false;
	}

	if(charaSkillatk)	return;
	if(SkillEfStart)	return; //�L�������[�V�������͉��̏����͂��Ȃ�
	if(flag_skill == RIO_SKILL_ATK && getPlData.status.m_attribute == UNDINE){
		battleDrawEnd = true;
		return ;
	}

	int num = 0;
	int loop = 0;
	static int cnt = 0;
	static int cnt2 = 0;
	static int limit = 0;

	if(flag_skill == RIO_SKILL_ATK || flag_skill == ZION_SKILL_ATK && getPlData.status.m_attribute != SYLPH || flag_skill == ZION_SKILL_EFFECT || flag_skill == VAN_SKILL_EFFECT||flag_skill == RIO_SKILL_EFFECT){
		if(flag_skill == ZION_SKILL_EFFECT || flag_skill == RIO_SKILL_EFFECT && getPlData.status.m_attribute == UNDINE){
			num = (int)recovery_point;
			m_graphics->SetColor(D3DCOLOR_ARGB(255,0,255,0),R_STATUS_NUM100);
		}
		else if(flag_skill == RIO_SKILL_EFFECT && getPlData.status.m_attribute == SALAMANDER || flag_skill == VAN_SKILL_EFFECT){
			for(int i = 0;i < 3;i++){
				if(flag_use_skill[i] == true){
					num = (int)flag_skill_ef[i];
					if(i == 1){ m_graphics->SetColor(D3DCOLOR_ARGB(255,145,76,53),R_STATUS_NUM100); }
					else { m_graphics->SetColor(D3DCOLOR_ARGB(255,255,0,0),R_STATUS_NUM100); }
				}
			}
		}
		else {
			num = (int)hitDamage;
			m_graphics->SetColor(D3DCOLOR_ARGB(255,255,255,255),R_STATUS_NUM100);
		}
		do{
			m_graphics->SetPostion(rect_battle[R_STATUS_NUM100].top,rect_battle[R_STATUS_NUM100].left + 30.f * drawBattleData[2 - loop].damage ,rect_battle[R_STATUS_NUM100].bottom,rect_battle[R_STATUS_NUM100].right + 30.f * (num % 10),R_STATUS_NUM100);
			m_graphics->DrawCC(drawBattleData[2 - loop].posX,drawBattleData[2 - loop].posY - drawBattleData[2 - loop].move,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_NUM100);
			if(drawBattleData[2 - loop].move > 0 && drawBattleData[2 - loop].act) drawBattleData[2 - loop].move -= 5;
			else if(drawBattleData[loop].move <= 0 && loop <= 2) drawBattleData[loop+1].act = true;

			if(drawBattleData[2].move <= 0){
				if(cnt2++ == 60){
					cnt2 = 0;
					battleDrawEnd = true;
				}
			}
			num /= 10;
			loop++;
		}while(num > 0);
	}
	else{
		m_graphics->SetColor(D3DCOLOR_ARGB(255,255,255,255),R_STATUS_NUM100);
		num = (int)getEnemydatavan[cnt].hitDamagevan;
		if(cnt < limit){
			if(getEnemydatavan[cnt].status.m_id != 0){
				do{
					m_graphics->SetPostion(rect_battle[R_STATUS_NUM100].top,rect_battle[R_STATUS_NUM100].left + 30.f * drawBattleVanData[cnt][2 - loop].damage ,rect_battle[R_STATUS_NUM100].bottom,rect_battle[R_STATUS_NUM100].right + 30.f * (num % 10),R_STATUS_NUM100);
					if(drawBattleVanData[cnt][2-loop].posY > 0.f){
						m_graphics->DrawCC(drawBattleVanData[cnt][2 - loop].posX,drawBattleVanData[cnt][2 - loop].posY - drawBattleVanData[cnt][2 - loop].move,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_NUM100);
					}
					if(drawBattleVanData[cnt][2 - loop].move > 0 && drawBattleVanData[cnt][2 - loop].act) drawBattleVanData[cnt][2 - loop].move -= 5;
					else if(drawBattleVanData[cnt][loop].move <= 0 && loop <= 2) drawBattleVanData[cnt][loop+1].act = true;

					if(drawBattleVanData[cnt][2].move <= 0){
						if(cnt2++ == 60){
							cnt++;
							cnt2 = 0;
						}
					}
					num /= 10;
					loop++;
				}while(num > 0);
			}
			else{cnt++;}
		}
		if(getPlData.status.m_attribute == SALAMANDER) { limit = 3; }
		else if(getPlData.status.m_attribute == GNOME) { limit = 12; }
		else { limit = 2; }
		if(cnt == limit){
			battleDrawEnd = true;
			cnt = 0;
		}
	}
}

void C_Battle::CharaSkillDraw(int i,int j)
{
	if(!SkillEfStart)	return;

	static float vibration = 0.f;
	static int vibration_cnt = 0;
	static float fade_out = 0.f;
	static FIELD_POS mirage = {0.f};

	switch(flag_skill)
	{
	case ZION_SKILL_ATK:
		charaAttackEfCnt++;
			if(getPlData.status.m_attribute == SYLPH) {
				if(keep_posi.x == i && keep_posi.y == j){
					if(getPlData.direction == LEFT_FLONT){
						mirage.x = 10.f;
						mirage.y = 10.f;
					}
					else if(getPlData.direction == LEFT_BACK){
						mirage.x = -10.f;
						mirage.y = 10.f;
					}
					else if(getPlData.direction == RIGHT_FLONT){
						mirage.x = 10.f;
						mirage.y = -10.f;
					}
					else{
						mirage.x = -10.f;
						mirage.y = -10.f;
					}
					m_graphics->SetColor(0x55FFFFFF,R_ZION_WAIT_LEFTFRONT + charaSkillCnt);
					m_graphics->DrawCC(stage->GetFieldPositionData(keep_posi).x + mirage.x,stage->GetFieldPositionData(keep_posi).y - 25.f + mirage.y,m_pTexture[T_CHAR_ZION],T_CHAR_ZION,R_ZION_WAIT_LEFTFRONT + charaSkillCnt);
					if(sound_in++ == 1){
						flag_sound_sp = true;
						sound_ef_change_sp = 3;
					}
				}
			}
			else {
				if(locate_cursor_field.x == i && locate_cursor_field.y == j){
					m_graphics->SetColor(0x55FFFFFF,R_ICICLE_EDGE1 + charaSkillCnt);
					m_graphics->DrawCC(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y - 13.5f,m_pTexture[T_ATK_EF],T_ATK_EF,R_ICICLE_EDGE1+charaSkillCnt);
				}
			}
		break;
	case VAN_SKILL_ATK:
		charaAttackEfCnt++;
		for(int k = 0;k < 12;k++){
			if(getPlData.status.m_attribute == SALAMANDER) {
				if(k == 3) { break; }
				if(keep_skillarea[k].x == i && keep_skillarea[k].y == j){
					m_graphics->DrawCC(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y - 13.5f,m_pTexture[T_ATK_EF],T_ATK_EF,R_MAGUMA1+charaSkillCnt);
					if(sound_in++ == 1){
						flag_sound_sp = true;
						sound_ef_change_sp = 0;
					}
				}
			}
			else {
				if(keep_skillarea[7].x == i && keep_skillarea[7].y == j){
					if(sound_in++ == 1){
						flag_sound_sp = true;
						sound_ef_change_sp = 6;
					}
					static int cnt = 0;
					if((vibration_cnt++)%4 == 1){
						vibration += 2.f;
					}
					else if(vibration_cnt%4 == 3){
						vibration -= 2.f;
					}
					if(charaSkillCnt == 0){
						m_graphics->SetPostion(600.f,700.f,900.f,1000.f,R_TISAIJIN4);
					}
					if(charaSkillCnt == 3){
						if(cnt++ >= deray_skill[3]){
							if(vibration_cnt%10 == 9){
								fade_out += 300.f;
								//m_graphics->SetPostion(600.f,700.f,900.f - fade_out,1000.f,R_TISAIJIN4);
							}
						}
					}
					m_graphics->DrawCC(stage->GetFieldPositionData(keep_posi).x + vibration,stage->GetFieldPositionData(keep_posi).y - 13.5f /*+ (fade_out / 6.f)*/,m_pTexture[T_ATK_EF],T_ATK_EF,R_TISAIJIN1+charaSkillCnt);
					if(fade_out == 300.f){
						SkillEfStart = false;
						fade_out = 0.f;
						charaSkillCnt = 0;
						vibration_cnt = 0;
						vibration = 0.f;
						cnt = 0;
					}
				}
				break;
			}
		}
		break;
	case RIO_SKILL_ATK:
		charaAttackEfCnt++;
		if(locate_cursor_field.x == i && locate_cursor_field.y == j){
			if(getPlData.status.m_attribute == SALAMANDER) {
				if(sound_in++ == 1){
					flag_sound_sp = true;
					sound_ef_change_sp = 8;
				}
				m_graphics->DrawCC(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y - 13.5f,m_pTexture[T_ATK_EF],T_ATK_EF,R_BAKUEN1+charaSkillCnt);
			}
			else {
				if(sound_in++ == 1){
					flag_sound_sp = true;
					sound_ef_change_sp = 10;
				}
				m_graphics->DrawCC(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y - 13.5f,m_pTexture[T_ATK_EF],T_ATK_EF,R_FROZEN_BULLET1+charaSkillCnt);
			}
		}
		break;
	case ZION_SKILL_EFFECT:
		if(locate_cursor_field.x == i && locate_cursor_field.y == j){
			if(getPlData.status.m_attribute == SYLPH) {
				if(sound_in++ == 1){
					flag_sound_sp = true;
					sound_ef_change_sp = 4;
				}
				m_graphics->DrawCC(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y - 13.5f,m_pTexture[T_UP_EF],T_UP_EF,R_HEELWIND1+charaRecoveryCnt);
			}
			else {
				if(sound_in++ == 1){
					flag_sound_sp = true;
					sound_ef_change_sp = 2;
				}
				m_graphics->DrawCC(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y - 13.5f,m_pTexture[T_UP_EF],T_UP_EF,R_AQUA_CURE1+charaRecoveryCnt);
			}
		}
		break;
	case VAN_SKILL_EFFECT:
		if(locate_cursor_field.x == i && locate_cursor_field.y == j){
			if(getPlData.status.m_attribute == SALAMANDER) {
				if(sound_in++ == 1){
					flag_sound_sp = true;
					sound_ef_change_sp = 5;
				}
				m_graphics->DrawCC(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y - 13.5f,m_pTexture[T_UP_EF],T_UP_EF,R_SALAMANDER1+charaRecoveryCnt);
			}
			else {
				if(sound_in++ == 1){
					flag_sound_sp = true;
					sound_ef_change_sp = 7;
				}
				m_graphics->DrawCC(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y - 13.5f,m_pTexture[T_UP_EF],T_UP_EF,R_KOUSYORAI1+charaRecoveryCnt);
			}
		}
		break;
	case RIO_SKILL_EFFECT:
		if(locate_cursor_field.x == i && locate_cursor_field.y == j){
			if(getPlData.status.m_attribute == SALAMANDER) {
				if(sound_in++ == 1){
					flag_sound_sp = true;
					sound_ef_change_sp = 9;
				}
				m_graphics->DrawCC(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y - 13.5f,m_pTexture[T_UP_EF],T_UP_EF,R_SALAMANDER1+charaRecoveryCnt);
			}
			else {
				if(sound_in++ == 1){
					flag_sound_sp = true;
					sound_ef_change_sp = 11;
				}
				m_graphics->DrawCC(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y - 13.5f,m_pTexture[T_UP_EF],T_UP_EF,R_AQUA_CURE1+charaRecoveryCnt);
			}
		}
		break;
	}
}

void C_Battle::SkillDetailDraw()
{
	if(flag_char_commando == 4){
		m_graphics->SetSize(1.75f,1.0f,R_SIMPLE_CHARA_BG);
		m_graphics->DrawCC(300.f,500.f,m_pTexture[T_BATTLE_FONT],T_BATTLE_FONT,R_SIMPLE_CHARA_BG);
		//if(locate_cursor_skill != 2){
			m_graphics->Draw(30.f,435.f+70*locate_cursor_skill,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_BATTLE_ICON);
			if(keep_char_select == ZION_ID){
				if(status[StatusSeachId(stage->GetFieldCharacterData(locate_cursor_field.x,locate_cursor_field.y))].m_attribute == SYLPH){
					m_graphics->Draw( 70.f,433.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_Z_SYLPH2);
					m_graphics->Draw(105.f,465.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_Z_SY_DATAIL1);
					F_RECT num = rect_battle[R_STATUS_NUM1];
					num.left = 30*AP_MIRAGE_EDGE;					//�~���[�W���G�b�W
					num.right = 30*(AP_MIRAGE_EDGE+1);
					m_graphics->SetPostion(num,R_STATUS_NUM1);
					m_graphics->Draw(530.f,449.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_NUM1);

					m_graphics->Draw( 70.f,505.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_Z_SYLPH1);
					m_graphics->Draw(105.f,537.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_RECOVERY_DATAIL);
					num = rect_battle[R_STATUS_NUM1];
					num.left = 30*AP_HEEL_WIND;						//�q�[���E�B���h
					num.right = 30*(AP_HEEL_WIND+1);
					m_graphics->SetPostion(num,R_STATUS_NUM1);
					m_graphics->Draw(530.f,521.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_NUM1);
				}
				else{
					m_graphics->Draw( 70.f,433.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_Z_UNDINE1);
					m_graphics->Draw(105.f,465.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_Z_UN_DATAIL1);
					F_RECT num = rect_battle[R_STATUS_NUM1];
					num.left = 30*AP_ICICLE_EDGE;					//�A�C�V�N���G�b�W
					num.right = 30*(AP_ICICLE_EDGE+1);
					m_graphics->SetPostion(num,R_STATUS_NUM1);
					m_graphics->Draw(530.f,449.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_NUM1);

					m_graphics->Draw( 70.f,505.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_Z_UNDINE2);
					m_graphics->Draw(105.f,537.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_RECOVERY_DATAIL);
					num = rect_battle[R_STATUS_NUM1];
					num.left = 30*AP_AQUA_CURE_Z;					//�A�N�A�L���A
					num.right = 30*(AP_AQUA_CURE_Z+1);
					m_graphics->SetPostion(num,R_STATUS_NUM1);
					m_graphics->Draw(530.f,521.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_NUM1);
				}
			}
			else if(keep_char_select == VAN_ID){
				if(status[StatusSeachId(stage->GetFieldCharacterData(locate_cursor_field.x,locate_cursor_field.y))].m_attribute == SALAMANDER){
					m_graphics->Draw( 70.f,433.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_V_SALAMANDER1);
					m_graphics->Draw(105.f,465.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_V_SA_DATAIL1);
					F_RECT num = rect_battle[R_STATUS_NUM1];
					num.left = 30*AP_BAKUENKEN;						//������
					num.right = 30*(AP_BAKUENKEN+1);
					m_graphics->SetPostion(num,R_STATUS_NUM1);
					m_graphics->Draw(530.f,449.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_NUM1);

					m_graphics->Draw( 70.f,505.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_V_SALAMANDER2);
					m_graphics->Draw(105.f,537.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_V_SA_DATAIL2);
					num = rect_battle[R_STATUS_NUM1];
					num.left = 30*AP_GOUSYORAI;						//������
					num.right = 30*(AP_GOUSYORAI+1);
					m_graphics->SetPostion(num,R_STATUS_NUM1);
					m_graphics->Draw(530.f,521.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_NUM1);
				}
				else{
					m_graphics->Draw( 70.f,433.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_V_GNOME1);
					m_graphics->Draw(105.f,465.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_V_GN_DATAIL1);
					F_RECT num = rect_battle[R_STATUS_NUM1];
					num.left = 30*AP_TISAIJIN;						//�n�Ӑo
					num.right = 30*(AP_TISAIJIN+1);
					m_graphics->SetPostion(num,R_STATUS_NUM1);
					m_graphics->Draw(530.f,449.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_NUM1);

					m_graphics->Draw( 70.f,505.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_V_GNOME2);
					m_graphics->Draw(105.f,537.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_V_GN_DATAIL2);
					num = rect_battle[R_STATUS_NUM1];
					num.left = 30*AP_KOUSYORAI;						//�|����
					num.right = 30*(AP_KOUSYORAI+1);
					m_graphics->SetPostion(num,R_STATUS_NUM1);
					m_graphics->Draw(530.f,521.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_NUM1);
				}
			}
			else{
				if(status[StatusSeachId(stage->GetFieldCharacterData(locate_cursor_field.x,locate_cursor_field.y))].m_attribute == SALAMANDER){
					m_graphics->Draw( 70.f,433.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_R_SALAMANDER1);
					m_graphics->Draw(105.f,465.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_R_SA_DATAIL1);
					F_RECT num = rect_battle[R_STATUS_NUM1];
					num.left = 30*AP_BLAZE_BULLET;					//�u���C�Y�o���b�g
					num.right = 30*(AP_BLAZE_BULLET+1);
					m_graphics->SetPostion(num,R_STATUS_NUM1);
					m_graphics->Draw(530.f,449.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_NUM1);

					m_graphics->Draw( 70.f,505.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_R_SALAMANDER2);
					m_graphics->Draw(105.f,537.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_R_SA_DATAIL2);
					num = rect_battle[R_STATUS_NUM1];
					num.left = 30*AP_BURST;							//�o�[�X�g
					num.right = 30*(AP_BURST+1);
					m_graphics->SetPostion(num,R_STATUS_NUM1);
					m_graphics->Draw(530.f,521.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_NUM1);
				}
				else{
					m_graphics->Draw( 70.f,433.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_R_UNDINE1);
					m_graphics->Draw(105.f,465.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_R_UN_DATAIL1);
					F_RECT num = rect_battle[R_STATUS_NUM1];
					num.left = 30*AP_FROZEN_BULLET;					//�t���[�Y���o���b�g
					num.right = 30*(AP_FROZEN_BULLET+1);
					m_graphics->SetPostion(num,R_STATUS_NUM1);
					m_graphics->Draw(530.f,449.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_NUM1);

					m_graphics->Draw( 70.f,505.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_R_UNDINE2);
					m_graphics->Draw(105.f,537.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_RECOVERY_DATAIL);
					num = rect_battle[R_STATUS_NUM1];
					num.left = 30*AP_AQUA_CURE_R;					//�A�N�A�L���A
					num.right = 30*(AP_AQUA_CURE_R+1);
					m_graphics->SetPostion(num,R_STATUS_NUM1);
					m_graphics->Draw(530.f,521.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_NUM1);
				}
			}
			m_graphics->Draw(400.f,449.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_USE_AP1);
			m_graphics->Draw(400.f,521.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_USE_AP1);
			//if(status[StatusSeachPosi(locate_cursor_field)].m_mg == 100){
			//	static int alph = 50;
			//	static int change = 0;
			//	if(alph < 55) change = 1;
			//	if(alph > 250) change = -1;
			//	alph += 6 * change;
			//	m_graphics->SetColor(D3DCOLOR_ARGB(alph,255,255,255),R_TRIAN);
			//	m_graphics->Draw(400.f,570.f,m_pTexture[T_CHAR_NAME1],T_CHAR_NAME1,R_TRIAN);
			//}
			//status[StatusSeachPosi(locate_cursor_field)].m_mg = 100;	//��
		/*}
		else{
			if(status[StatusSeachPosi(locate_cursor_field)].m_id == U_ZION) { m_graphics->DrawCC(400.f,500.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_SP_ZION_NAME); }
			else if(status[StatusSeachPosi(locate_cursor_field)].m_id == U_VAN) { m_graphics->DrawCC(400.f,500.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_SP_VAN_NAME); }
			else { m_graphics->DrawCC(400.f,500.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_SP_RIO_NAME); }
		}*/
	}
}

void C_Battle::InitBattleData()
{
	for(int i = 0;i < 12;i++)
	{
		getEnemydatavan[i].direction = 0;
		getEnemydatavan[i].hitDamagevan = 0;
		getEnemydatavan[i].status.m_attribute=4;
	}
}

void C_Battle::BattleDataSetVan()
{
	COORDINATE range_ef;
	//�v���C���[�̃X�e�[�^�X�E�o�g���f�[�^
	getPlData.status	= status[StatusSeachId( keep_field_id[keep_char_select] ) ];
	getPlData.direction	= status_battle[StatusSeachId( keep_field_id[keep_char_select] ) ].m_direction;

	memset(drawBattleVanData, 0, sizeof(DrawBattleData) * 3 * 12);

	if(getPlData.status.m_attribute == SYLPH){
		for(int i = 0;i < 2;i++){
			getEnemydatavan[i].status = status[StatusSeachId(stage->GetFieldCharacterData(locate_cursor_field.x,locate_cursor_field.y))];
			getEnemydatavan[i].direction = status_battle[StatusSeachId(stage->GetFieldCharacterData(locate_cursor_field.x,locate_cursor_field.y))].m_direction;
			keep_skillarea[i] = locate_cursor_field;
		}
	}
	//�G�l�~�[�̃X�e�[�^�X�E�o�g���f�[�^
	else if(getPlData.status.m_attribute == SALAMANDER)
	{
		for(int i = 0;i < 3;i++){
			if(getPlData.direction == LEFT_FLONT) {		//����������
				range_ef.x = 0;
				range_ef.y = i+1;
			}
			if(getPlData.direction == LEFT_BACK) {		//����������
				range_ef.x = -1*(i+1);
				range_ef.y = 0;
			}
			if(getPlData.direction == RIGHT_FLONT) {	//�������E��
				range_ef.x = i+1;
				range_ef.y = 0;
			}
			if(getPlData.direction == RIGHT_BACK) {		//�������E��
				range_ef.x = 0;
				range_ef.y = -1*(i+1);
			}
			if(stage->GetFieldCharacterData(keep_posi.x+range_ef.x,keep_posi.y+range_ef.y) >= U_SAHAGIN1){
				getEnemydatavan[i].status	 = status[StatusSeachId( stage->GetFieldCharacterData(keep_posi.x+range_ef.x,keep_posi.y+range_ef.y) )];
				getEnemydatavan[i].direction = status_battle[StatusSeachId( stage->GetFieldCharacterData(keep_posi.x+range_ef.x,keep_posi.y+range_ef.y) )].m_direction;
				keep_skillarea[i].x = keep_posi.x + range_ef.x;
				keep_skillarea[i].y = keep_posi.y + range_ef.y;
			}
			else{
				getEnemydatavan[i].direction = 4;
				getEnemydatavan[i].status.m_id = 0;
				keep_skillarea[i].x = keep_posi.x + range_ef.x;
				keep_skillarea[i].y = keep_posi.y + range_ef.y;
			}
		}
	}
	else if(getPlData.status.m_attribute == GNOME)
	{
		int cnt = 0;
		//
		for(int i = -getPlData.status.m_skill_range1;i <= getPlData.status.m_skill_range1;i++){	//�|�ړ��͂���ړ��͂܂ŉ�(X����)
			for(int j = -getPlData.status.m_skill_range1;j <= getPlData.status.m_skill_range1;j++){	//��ɓ���(Y����)
				if(i != 0 || j != 0){	//������������ʒu����Ȃ������火��
					if(stage->GetAreaInfoData(keep_posi.x+i,keep_posi.y+j) == 1){
						if(keep_posi.x + i >= 0 && keep_posi.x + i < MAX_MAPTIP_LENGTE){	//�z���[20]�ō�����ꍇ�O�`19�܂ł����Ȃ����ߗ\�h��
							if(keep_posi.y + j >= 0 && keep_posi.y + j < MAX_MAPTIP_WIDE){	//��ɓ���
								if(stage->GetFieldCharacterData(keep_posi.x+i,keep_posi.y+j) >= U_SAHAGIN1){
									getEnemydatavan[cnt].status = status[StatusSeachId( stage->GetFieldCharacterData(keep_posi.x+i,keep_posi.y+j) )];
									keep_skillarea[cnt].x = keep_posi.x + i;
									keep_skillarea[cnt].y = keep_posi.y + j;
									cnt++;
								}
								else{
									getEnemydatavan[cnt].direction = 4;
									getEnemydatavan[cnt].status.m_id = 0;
									keep_skillarea[cnt].x = keep_posi.x + i;
									keep_skillarea[cnt].y = keep_posi.y + j;
									cnt++;
								}
							}
							else{
								getEnemydatavan[cnt].direction = 4;
								getEnemydatavan[cnt].status.m_id = 0;
								keep_skillarea[cnt].x = keep_posi.x + i;
								keep_skillarea[cnt].y = keep_posi.y + j;
								cnt++;
							}
						}
						else{
							getEnemydatavan[cnt].direction = 4;
							getEnemydatavan[cnt].status.m_id = 0;
							keep_skillarea[cnt].x = keep_posi.x + i;
							keep_skillarea[cnt].y = keep_posi.y + j;
							cnt++;
						}
					}
				}
			}
		}
	}
}

void C_Battle::SetDamageVan()
{
	int skill_ef_area = 0;

	if(getPlData.status.m_attribute == GNOME){ skill_ef_area = 12; }
	else if(getPlData.status.m_attribute == SALAMANDER){ skill_ef_area = 3; }
	else { skill_ef_area = 2; }
	for(int i = 0;i < skill_ef_area;i++){
		if(getEnemydatavan[i].status.m_id != 0){
			SetDamage(StatusSeachId(stage->GetFieldCharacterData(keep_skillarea[i].x,keep_skillarea[i].y)),(int)getEnemydatavan[i].hitDamagevan);
		}
	}
}

void C_Battle::SetRecovery(int id, int recovery)
{ 
	status[id].m_hp += recovery;
	if(status[id].m_hp > status[id].m_maxhp){
		status[id].m_hp = status[id].m_maxhp;
	}
}

void C_Battle::BattleEndProcessVan(void)		//�o�g���I������
{
	int skill_ef_area = 0;
	int big_id = 0;

	if(getPlData.status.m_attribute == GNOME) { skill_ef_area = 12; }
	else if(getPlData.status.m_attribute == SALAMANDER) { skill_ef_area = 3; }
	else { skill_ef_area = 2;}
	for(int i = 0;i < skill_ef_area;i++){
		if(getEnemydatavan[i].status.m_id != 0){
			if( DeathCheck( StatusSeachId(stage->GetFieldCharacterData(keep_skillarea[i].x,keep_skillarea[i].y)) ) ) {
				status_battle[StatusSeachId(stage->GetFieldCharacterData(keep_skillarea[i].x,keep_skillarea[i].y))].m_battle_impossible = true;
				stage->SetFieldCharacterData(keep_skillarea[i].x,keep_skillarea[i].y, U_BLANK_AREA );
			}
			if(big_id < getEnemydatavan[skill_ef_area].status.m_id) { big_id = getEnemydatavan[skill_ef_area].status.m_id; }
		}
	}
	if(flag_skill <= RIO_SKILL_ATK){
		status[StatusSeachId(getPlData.status.m_id)].m_ap -= UseSpecialAP1();
		status_battle[StatusSeachPosi(keep_posi)].m_action_end = true;
		flag_any_end = 1;
		flag_char_commando = 0;
		locate_cursor_commando = 0;
		deleat_posi.x = deleat_posi.y = 0;
		for(int i = 0;i < 3;i++){
			flag_char_selected[i] = 0;
		}
	}
	if(flag_skill > RIO_SKILL_ATK){
		status[StatusSeachId(getPlData.status.m_id)].m_ap -= UseSpecialAP2();
	}
	flag_skill = 0;							//����U�����Ă��Ȃ���Ԃɖ߂�
	area_shift = D3DCOLOR_ARGB(0,0,0,0);	//�}�X�̐F������
	flag_char_selected[CHAR_SPECIAL] = 1;	//����U���I��
	locate_cursor_field = keep_posi;
	flag_char_commando = 0;
	status[StatusSeachId(getPlData.status.m_id)].m_mg += damegeCulc->MGPlus(big_id);
	if(status[StatusSeachId(getPlData.status.m_id)].m_mg >= status[StatusSeachId(getPlData.status.m_id)].m_maxmg) { status[StatusSeachId(getPlData.status.m_id)].m_mg = status[StatusSeachId(getPlData.status.m_id)].m_maxmg;}
}

void C_Battle::BattleClear(int* key)
{
	//�ǉ��@3/12 �O�に
	NowLoading();
	m_graphics->SetColor(D3DCOLOR_ARGB(m_alpha_load,255,255,255),R_NOWLOADING);

	if(m_count_fade > 3){
		delete stage;
		delete zion;
		delete van;
		delete rio;
		delete enemy1;
		delete enemy2;
		delete enemy3;
		delete enemy4;
		delete boss;

		delete[] status;
		delete damegeCulc;

		m_scene_flag		= ADV_SCENE;
		m_scene_number[0]	= TEXT_EPILOGUE;	
		SetSceneNum(m_scene_flag,m_scene_number);	//ADV�V�[���́w�G�s���[�O�x��
		m_count_fade = 0;
	}
	//�ǉ��@3/12 �O�な

}

void C_Battle::BattleMaterialDraw()
{
	m_graphics->DrawCC(400.f,300.f,m_pTexture[T_WIN_CONDITION_BG],T_WIN_CONDITION_BG,R_WIN_CONDITION_BG);	//�w�i
	m_graphics->DrawCC(telop,25.f,m_pTexture[T_TELOP],T_TELOP,R_TELOP);
	m_graphics->DrawCC(telop2,25.f,m_pTexture[T_TELOP],T_TELOP,R_TELOP2);
	m_graphics->DrawCC(400.f,125.f,m_pTexture[T_BATTLE_FONT],T_BATTLE_FONT,R_MATERIAL_SET);
	if(flag_any_end == 0 || keep_id == ZION_ID - 1)	m_graphics->DrawCC(150.f,200.f,m_pTexture[T_CHAR_NAME1],T_CHAR_NAME1,R_ZION_NAME);						//�V�I��
	if(flag_any_end == 0)	m_graphics->DrawCC(150.f,300.f,m_pTexture[T_CHAR_NAME1],T_CHAR_NAME1,R_VAN_NAME);						//���@��
	if(flag_any_end >= 1 && keep_id == VAN_ID - 1)	m_graphics->DrawCC(150.f,200.f,m_pTexture[T_CHAR_NAME1],T_CHAR_NAME1,R_VAN_NAME);					//���@��
	if(flag_any_end == 0)	m_graphics->DrawCC(150.f,400.f,m_pTexture[T_CHAR_NAME1],T_CHAR_NAME1,R_RIO_NAME);						//���I
	if(flag_any_end >= 1 && keep_id == RIO_ID - 1)	m_graphics->DrawCC(150.f,200.f,m_pTexture[T_CHAR_NAME1],T_CHAR_NAME1,R_RIO_NAME);						//���I
	if(flag_any_end == 0 || flag_any_end == 1)	m_graphics->DrawCC(60.f + 350.f * cursor_locate_x,200.f + 100.f * (float)cursor_locate_y,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_BATTLE_ICON);	//�J�[�\��
	if(flag_any_end == 0){
		if(flag_material_seted[0] != 4){
			m_graphics->DrawCC(350.f,200.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_MATERIALSALAMANDER + flag_material_seted[0]);
		}
		if(flag_material_seted[1] != 4){
			m_graphics->DrawCC(350.f,300.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_MATERIALSALAMANDER + flag_material_seted[1]);
		}
		if(flag_material_seted[2] != 4){
			m_graphics->DrawCC(350.f,400.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_MATERIALSALAMANDER + flag_material_seted[2]);
		}
	}
	if(flag_any_end == 1)
	{
		if(keep_id == VAN_ID - 1 || keep_id == RIO_ID - 1)		m_graphics->DrawCC(525.f,250.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_MATERIALNAME);			//�Α���
		if(keep_id == ZION_ID -1 || keep_id == RIO_ID - 1)		m_graphics->DrawCC(525.f,350.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_MATERIAL_UNDINE);				//������
		if(keep_id == ZION_ID -1)	m_graphics->DrawCC(525.f,250.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_MATERIAL_SYIPH);				//������
		if(keep_id == VAN_ID - 1)	m_graphics->DrawCC(525.f,350.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_MATERIAL_GNOM);				//�y����
	}
	if(flag_any_end == 2)
	{
		m_graphics->Draw(600.f,280.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_USE_AP1);	//����AP
		m_graphics->Draw(600.f,350.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_USE_AP1);	//����AP
		if(keep_id == ZION_ID -1 && (int)cursor_locate_y == 0)
		{
			m_graphics->Draw(125.f,265.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_Z_SYLPH2);		//�~���[�W���G�b�W
			m_graphics->Draw(225.f,295.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_Z_SY_DATAIL1);	//�~���[�W���G�b�W�ڍ�
			F_RECT num = rect_battle[R_STATUS_NUM1];
			num.left = 30*AP_MIRAGE_EDGE;
			num.right = 30*(AP_MIRAGE_EDGE+1);
			m_graphics->SetPostion(num,R_STATUS_NUM1);
			m_graphics->Draw(750.f,280.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_NUM1);	//�~���[�W���G�b�W����AP����

			m_graphics->Draw(125.f,335.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_Z_SYLPH1);		//�q�[���E�B���h
			m_graphics->Draw(225.f,365.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_RECOVERY_DATAIL);	//�q�[���E�B���h�ڍ�
			num = rect_battle[R_STATUS_NUM1];
			num.left = 30*AP_HEEL_WIND;
			num.right = 30*(AP_HEEL_WIND+1);
			m_graphics->SetPostion(num,R_STATUS_NUM1);
			m_graphics->Draw(750.f,350.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_NUM1);	//�q�[���E�B���h����AP����
		}
		if(keep_id == ZION_ID -1 && (int)cursor_locate_y == 1)
		{
			m_graphics->Draw(125.f,265.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_Z_UNDINE1);		//�A�C�V�N���G�b�W
			m_graphics->Draw(225.f,295.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_Z_UN_DATAIL1);	//�A�C�V�N���G�b�W�ڍ�
			F_RECT num = rect_battle[R_STATUS_NUM1];
			num.left = 30*AP_ICICLE_EDGE;
			num.right = 30*(AP_ICICLE_EDGE+1);
			m_graphics->SetPostion(num,R_STATUS_NUM1);
			m_graphics->Draw(750.f,280.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_NUM1);	//�A�C�V�N���G�b�W����AP����

			m_graphics->Draw(125.f,335.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_R_UNDINE2);		//�A�N�A�L���A
			m_graphics->Draw(225.f,365.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_RECOVERY_DATAIL);	//�A�N�A�L���A�ڍ�
			num = rect_battle[R_STATUS_NUM1];
			num.left = 30*AP_AQUA_CURE_Z;
			num.right = 30*(AP_AQUA_CURE_Z+1);
			m_graphics->SetPostion(num,R_STATUS_NUM1);
			m_graphics->Draw(750.f,350.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_NUM1);	//�A�N�A�L���A����AP����
		}
		if(keep_id == VAN_ID -1 && (int)cursor_locate_y == 0)
		{
			m_graphics->Draw(125.f,265.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_V_SALAMANDER1);		//������
			m_graphics->Draw(225.f,295.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_V_SA_DATAIL1);	//�������ڍ�
			F_RECT num = rect_battle[R_STATUS_NUM1];
			num.left = 30*AP_BAKUENKEN;
			num.right = 30*(AP_BAKUENKEN+1);
			m_graphics->SetPostion(num,R_STATUS_NUM1);
			m_graphics->Draw(750.f,280.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_NUM1);	//����������AP����

			m_graphics->Draw(125.f,335.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_V_SALAMANDER2);		//������
			m_graphics->Draw(225.f,365.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_V_SA_DATAIL2);	//�������ڍ�
			num = rect_battle[R_STATUS_NUM1];
			num.left = 30*AP_GOUSYORAI;
			num.right = 30*(AP_GOUSYORAI+1);
			m_graphics->SetPostion(num,R_STATUS_NUM1);
			m_graphics->Draw(750.f,350.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_NUM1);	//����������AP����
		}
		if(keep_id == VAN_ID -1 && (int)cursor_locate_y == 1)
		{
			m_graphics->Draw(125.f,265.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_V_GNOME1);		//�n�Ӑo
			m_graphics->Draw(225.f,295.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_V_GN_DATAIL1);	//�n�Ӑo�ڍ�
			F_RECT num = rect_battle[R_STATUS_NUM1];
			num.left = 30*AP_TISAIJIN;
			num.right = 30*(AP_TISAIJIN+1);
			m_graphics->SetPostion(num,R_STATUS_NUM1);
			m_graphics->Draw(750.f,280.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_NUM1);	//�n�Ӑo����AP����

			m_graphics->Draw(125.f,335.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_V_GNOME2);		//�|����
			m_graphics->Draw(225.f,365.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_V_GN_DATAIL2);	//�|�����ڍ�
			num = rect_battle[R_STATUS_NUM1];
			num.left = 30*AP_KOUSYORAI;
			num.right = 30*(AP_KOUSYORAI+1);
			m_graphics->SetPostion(num,R_STATUS_NUM1);
			m_graphics->Draw(750.f,350.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_NUM1);	//�|��������AP����
		}
		if(keep_id == RIO_ID -1 && (int)cursor_locate_y == 0)
		{
			m_graphics->Draw(125.f,265.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_R_SALAMANDER1);		//��ڲ����گ�
			m_graphics->Draw(225.f,295.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_R_SA_DATAIL1);	//��ڲ����گďڍ�
			F_RECT num = rect_battle[R_STATUS_NUM1];
			num.left = 30*AP_BLAZE_BULLET;
			num.right = 30*(AP_BLAZE_BULLET+1);
			m_graphics->SetPostion(num,R_STATUS_NUM1);
			m_graphics->Draw(750.f,280.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_NUM1);	//��ڲ����گď���AP����

			m_graphics->Draw(125.f,335.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_R_SALAMANDER2);		//�ް��
			m_graphics->Draw(225.f,365.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_R_SA_DATAIL2);	//�ް�ďڍ�
			num = rect_battle[R_STATUS_NUM1];
			num.left = 30*AP_BURST;
			num.right = 30*(AP_BURST+1);
			m_graphics->SetPostion(num,R_STATUS_NUM1);
			m_graphics->Draw(750.f,350.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_NUM1);	//�ް�ď���AP����
		}
		if(keep_id == RIO_ID -1 && (int)cursor_locate_y == 1)
		{
			m_graphics->Draw( 50.f,265.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_R_UNDINE1);		//�۰�����گ�
			m_graphics->Draw(100.f,295.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_R_UN_DATAIL1);	//�۰�����گďڍ�
			F_RECT num = rect_battle[R_STATUS_NUM1];
			num.left = 30*AP_FROZEN_BULLET;
			num.right = 30*(AP_FROZEN_BULLET+1);
			m_graphics->SetPostion(num,R_STATUS_NUM1);
			m_graphics->Draw(750.f,280.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_NUM1);	//�۰�����گď���AP����
			m_graphics->Draw( 50.f,335.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_R_UNDINE2);		//�A�N�A�L���A
			m_graphics->Draw(100.f,365.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_RECOVERY_DATAIL);	//�A�N�A�L���A�ڍ�
			num = rect_battle[R_STATUS_NUM1];
			num.left = 30*AP_AQUA_CURE_R;
			num.right = 30*(AP_AQUA_CURE_R+1);
			m_graphics->SetPostion(num,R_STATUS_NUM1);
			m_graphics->Draw(750.f,350.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_NUM1);	//�A�N�A�L���A����AP����
		}
	}
}

void C_Battle::BattleConditionDraw()
{
	m_graphics->DrawCC( 400.0f, 300.0f,m_pTexture[T_WIN_CONDITION_BG],T_WIN_CONDITION_BG,R_WIN_CONDITION_BG);	//�w�i�`��
	//m_graphics->DrawCC( 400.0f, 300.0f,m_pTexture[T_ATK_EF],T_ATK_EF,R_TISAIJIN4);	//�w�i�`��
	//m_graphics->DrawCC( 400.0f, 300.0f,m_pTexture[T_ATK_EF],T_ATK_EF,R_BAKUEN1);	//�w�i�`��
	if(time_cnt >= 60)
	{
		m_graphics->DrawCC( 400.0f, 210.0f,m_pTexture[T_BATTLE_FONT],T_BATTLE_FONT,R_WIN_CONDITION);	//"��������"
		m_graphics->DrawCC( 400.0f, 330.0f,m_pTexture[T_BATTLE_FONT],T_BATTLE_FONT,R_LOSS_CONDITION);	//"�s�k����"
		m_graphics->DrawCC( 400.0f, 260.0f,m_pTexture[T_BATTLE_FONT],T_BATTLE_FONT,R_WIN_ONE);	//���������@
		m_graphics->DrawCC( 400.0f, 390.0f,m_pTexture[T_BATTLE_FONT],T_BATTLE_FONT,R_WIN_TWO);	//���������A
		m_graphics->DrawCC( 400.0f, 430.0f,m_pTexture[T_BATTLE_FONT],T_BATTLE_FONT,R_LOSS_ONE);	//�s�k�����@
	}
}

void C_Battle::BattleCombatDraw()
{
	if(flag_sp_extra_draw) BattleSpExtradraw();
	if(flag_sp_extra_draw) return ;
	m_graphics->DrawCC( 400.f, 300.f,m_pTexture[T_BATTLE_FIELD1],T_BATTLE_FIELD1,R_BATTLE_FIELD1);	//�w�i�`��

	FieldDraw();		//�o�g���t�B�[���h��`��
	
	static FIELD_POS locate_wait[4] = {
		-30.f,-50.f,
		-30.f,-85.f,
		 40.f,-50.f,
		 40.f,-85.f,
	};

	if(flag_char_commando == 5){
		if(locate_cursor_commando == CHAR_MOVE){
			m_graphics->SetColor(0xFFFFFFFF,R_WAIT_LF + status_battle[StatusSeachPosi(locate_cursor_field)].m_direction);
			m_graphics->DrawCC(stage->GetFieldPositionData(locate_cursor_field).x + locate_wait[status_battle[StatusSeachPosi(locate_cursor_field)].m_direction].x,stage->GetFieldPositionData(locate_cursor_field).y + locate_wait[status_battle[StatusSeachPosi(locate_cursor_field)].m_direction].y,m_pTexture[T_BATTLE_FONT],T_BATTLE_FONT,R_WAIT_LF + status_battle[StatusSeachPosi(locate_cursor_field)].m_direction);
		}
		else{
			m_graphics->SetColor(0xFFFFFFFF,R_WAIT_LF + status_battle[StatusSeachPosi(keep_posi)].m_direction);
			m_graphics->DrawCC(stage->GetFieldPositionData(keep_posi).x + locate_wait[status_battle[StatusSeachPosi(keep_posi)].m_direction].x,stage->GetFieldPositionData(keep_posi).y + locate_wait[status_battle[StatusSeachPosi(keep_posi)].m_direction].y,m_pTexture[T_BATTLE_FONT],T_BATTLE_FONT,R_WAIT_LF + status_battle[StatusSeachPosi(keep_posi)].m_direction);
		}
	}

	if(locate_cursor_commando == CHAR_WAIT && flag_char_commando == 2){
		for(int i = 0;i < 4;i++){
			if(i == status_battle[StatusSeachPosi(locate_cursor_field)].m_direction){
				m_graphics->SetColor(0xFFFFFFFF,R_WAIT_LF + i);
			}else{
				m_graphics->SetColor(0x44FFFFFF,R_WAIT_LF + i);
			}
			m_graphics->DrawCC(stage->GetFieldPositionData(locate_cursor_field).x + locate_wait[i].x,stage->GetFieldPositionData(locate_cursor_field).y + locate_wait[i].y,m_pTexture[T_BATTLE_FONT],T_BATTLE_FONT,R_WAIT_LF + i);
		}
	}

	if(flag_any_end == 0)	//�t�F�C�Y�`��
	{
		m_graphics->SetColor(D3DCOLOR_ARGB(fade_in_out,255,255,255),R_PHASE_BG);
		m_graphics->DrawCC(400.f,300.f,m_pTexture[T_STATUS_NAME],T_STATUS_FC,R_PHASE_BG);
		m_graphics->DrawCC(-200.0f + fade,300.0f,m_pTexture[T_BATTLE_FONT],T_BATTLE_FONT,phase_shift);
	}
	else if(flag_any_end == 2)	//�R�}���h�`��
	{
		if(flag_char_commando != 5 && flag_char_commando != 2){
			if(flag_status_draw != 1)
			{
				for(int i = 0;i < COMMANDO_MAX;i++)
				{
					if(i == locate_cursor_commando)	m_graphics->DrawCC(70.f + 25.f,65.f + 42.5f * i,m_pTexture[T_BATTLE_FONT],T_BATTLE_FONT,i + R_MOVE);
					else	m_graphics->DrawCC( 70.f,65.f + 42.5f * i,m_pTexture[T_BATTLE_FONT],T_BATTLE_FONT,i + R_MOVE);
				}
			}
		}
	}
	if(flag_geme_end == 1){
		m_graphics->DrawCC(400.f,300.f,m_pTexture[T_STATUS_NAME],T_STATUS_NAME,R_GAME_OVER);
	}
	DamegeExtra();
}

void C_Battle::FieldDraw()
{
	static int a = 0;
	if(flag_status_draw != 1)
	{
		for(int j = 0;j < stage->GetMaptipYData();j++){
			for(int i = 0;i < stage->GetMaptipXData();i++){
				switch(stage->GetFieldMaptipData(i,j)){
					case MAPTIP_BLANK:
						break;
					case MAPTIP_CACTUS1:
						m_graphics->DrawCC(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y,m_pTexture[T_MAPTIP],T_MAPTIP,R_MAPTIP_CACTUS1);
						break;
					case MAPTIP_CACTUS2:
						m_graphics->DrawCC(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y,m_pTexture[T_MAPTIP],T_MAPTIP,R_MAPTIP_CACTUS2);
						break;
					case MAPTIP_ROCK1:
						m_graphics->DrawCC(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y,m_pTexture[T_MAPTIP],T_MAPTIP,R_MAPTIP_ROCK1);
						break;
					case MAPTIP_ROCK2:
						m_graphics->DrawCC(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y,m_pTexture[T_MAPTIP],T_MAPTIP,R_MAPTIP_ROCK2);
						break;
					case MAPTIP_SAND1:
						m_graphics->DrawCC(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y,m_pTexture[T_MAPTIP],T_MAPTIP,R_MAPTIP_SAND1);
						break;
					case MAPTIP_SAND2:
						m_graphics->DrawCC(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y,m_pTexture[T_MAPTIP],T_MAPTIP,R_MAPTIP_SAND2);
						break;
					case MAPTIP_SAND3:
						m_graphics->DrawCC(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y,m_pTexture[T_MAPTIP],T_MAPTIP,R_MAPTIP_SAND3);
						break;
					case MAPTIP_SAND4:
						m_graphics->DrawCC(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y,m_pTexture[T_MAPTIP],T_MAPTIP,R_MAPTIP_SAND4);
						break;
					case MAPTIP_GREEN1:
						m_graphics->DrawCC(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y,m_pTexture[T_MAPTIP],T_MAPTIP,R_MAPTIP_GREEN1);
						break;
					case MAPTIP_GREEN2:
						m_graphics->DrawCC(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y,m_pTexture[T_MAPTIP],T_MAPTIP,R_MAPTIP_GREEN2);
						break;
					case MAPTIP_GREEN3:
						m_graphics->DrawCC(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y,m_pTexture[T_MAPTIP],T_MAPTIP,R_MAPTIP_GREEN3);
						break;
					case MAPTIP_GREEN4:
						m_graphics->DrawCC(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y,m_pTexture[T_MAPTIP],T_MAPTIP,R_MAPTIP_GREEN4);
						break;
				}
				if(j == 19){
					if(i > 0 && i < 14){
						m_graphics->SetColor(D3DCOLOR_ARGB(100,255,255,255),R_MAPTIP_EREA);
						m_graphics->DrawCC(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y - 12.5f,m_pTexture[T_MAPTIP],T_MAPTIP,R_MAPTIP_EREA);
					}
				}
				//�G���A�`��
				if(stage->GetAreaInfoData(i,j) >= 1){
					if(flag_turn == PLAYER_TURN){
						m_graphics->SetColor(area_shift,R_MAPTIP_EREA);
						m_graphics->DrawCC(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y - 12.5f,m_pTexture[T_MAPTIP],T_MAPTIP,R_MAPTIP_EREA);
					}
				}
				//�J�[�\���̕`��
				if(i == locate_cursor_field.x && j == locate_cursor_field.y){
					if(flag_turn == PLAYER_TURN){
						m_graphics->SetColor(D3DCOLOR_ARGB(cursor_color,255,255,255),R_CURSOR_P);
						m_graphics->DrawCC(stage->GetFieldPositionData(locate_cursor_field.x,locate_cursor_field.y).x + 1.0f,stage->GetFieldPositionData(locate_cursor_field.x,locate_cursor_field.y).y - 13.5f,m_pTexture[T_MAPTIP],T_MAPTIP,R_CURSOR_P);
					}
					else{
						m_graphics->SetColor(D3DCOLOR_ARGB(cursor_color,255,255,255),R_CURSOR_E);
						m_graphics->DrawCC(stage->GetFieldPositionData(locate_cursor_field.x,locate_cursor_field.y).x + 1.0f,stage->GetFieldPositionData(locate_cursor_field.x,locate_cursor_field.y).y - 13.5f,m_pTexture[T_MAPTIP],T_MAPTIP,R_CURSOR_E);
					}
				}
				//�L�����N�^�[�̕`��(�G�D����)
				switch(stage->IdSeach(i,j)){
					case U_BLANK_AREA:
						break;
					case U_ZION:
						if(status_battle[StatusSeachPosi(i,j)].m_action_end != false)	m_graphics->SetColor(D3DCOLOR_ARGB(178,255,255,255),R_ZION_WAIT_LEFTFRONT+(status_battle[StatusSeachPosi(i,j)].m_direction*4) + charaWaitZion);

						else	m_graphics->SetColor(D3DCOLOR_ARGB(255,255,255,255),R_ZION_WAIT_LEFTFRONT+(status_battle[StatusSeachPosi(i,j)].m_direction*4) + charaWaitZion);

						m_graphics->DrawCC(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y - 13.5f  + BattleDrawConvert(stage->IdSeach(i,j)) ,m_pTexture[T_CHAR_ZION],T_CHAR_ZION,R_ZION_WAIT_LEFTFRONT  + (!charaAttack  ? ((status_battle[StatusSeachPosi(i,j)].m_direction * 4) + charaWaitZion) : ( keep_field_id[keep_char_select] != 10 ? status_battle[StatusSeachPosi(i,j)].m_direction : charaAttackCnt )));
						break;
					case U_VAN:
						if(status_battle[StatusSeachPosi(i,j)].m_action_end != false)	m_graphics->SetColor(D3DCOLOR_ARGB(178,255,255,255),R_VAN_WAIT_LEFTFRONT+(status_battle[StatusSeachPosi(i,j)].m_direction*4) + charaWaitVan);
						else	m_graphics->SetColor(D3DCOLOR_ARGB(255,255,255,255),R_VAN_WAIT_LEFTFRONT+(status_battle[StatusSeachPosi(i,j)].m_direction*4) + charaWaitVan);
						m_graphics->DrawCC(stage->GetFieldPositionData(i,j).x  + BattleDrawConvert(stage->IdSeach(i,j),true),stage->GetFieldPositionData(i,j).y - 13.5f  + BattleDrawConvert(stage->IdSeach(i,j)) ,m_pTexture[T_CHAR_VAN],T_CHAR_VAN,R_VAN_WAIT_LEFTFRONT  + (!charaAttack  ? (status_battle[StatusSeachPosi(i,j)].m_direction*4) + charaWaitVan : ( keep_field_id[keep_char_select] != 20 ? status_battle[StatusSeachPosi(i,j)].m_direction : charaAttackCnt )));
						break;
					case U_RIO:
						if(status_battle[StatusSeachPosi(i,j)].m_action_end != false)	m_graphics->SetColor(D3DCOLOR_ARGB(178,255,255,255),R_RIO_WAIT_LEFTFRONT+(status_battle[StatusSeachPosi(i,j)].m_direction*4) + charaWaitRio);
						else	m_graphics->SetColor(D3DCOLOR_ARGB(255,255,255,255),R_RIO_WAIT_LEFTFRONT+(status_battle[StatusSeachPosi(i,j)].m_direction*4) + charaWaitRio);
						m_graphics->DrawCC(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y - 13.5f,m_pTexture[T_CHAR_RIO],T_CHAR_RIO,R_RIO_WAIT_LEFTFRONT  + (!charaAttack  ? (status_battle[StatusSeachPosi(i,j)].m_direction*4) + charaWaitRio : ( keep_field_id[keep_char_select] != 30 ? status_battle[StatusSeachPosi(i,j)].m_direction : charaAttackCnt )));
						break;
					case U_SAHAGIN1:
						if(status_battle[StatusSeachPosi(i,j)].m_action_end != false)	m_graphics->SetColor(D3DCOLOR_ARGB(178,255,255,255),R_CHAR_WAIT_LEFTFRONT+(status_battle[StatusSeachPosi(i,j)].m_direction*4) + charaWaitSahagin1);
						else	m_graphics->SetColor(D3DCOLOR_ARGB(255,255,255,255),R_CHAR_WAIT_LEFTFRONT+(status_battle[StatusSeachPosi(i,j)].m_direction*4) + charaWaitSahagin1);
						m_graphics->DrawCC(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y - 13.5f + (StatusSeachPosi(locate_cursor_field) != StatusSeachPosi(i,j) ? 0.f :charaAttackEfCnt%3),m_pTexture[T_CHAR_SAHAGIN1],T_CHAR_SAHAGIN1,R_CHAR_WAIT_LEFTFRONT + (!charaAttack  ? (status_battle[StatusSeachPosi(i,j)].m_direction*4) + charaWaitSahagin1 : ( keep_field_id[keep_char_select] != stage->GetFieldCharacterData(i,j) ? status_battle[StatusSeachPosi(i,j)].m_direction : enemyAttackCnt )));
						if(cut_out == StatusSeachPosi(i,j)) {
							m_graphics->SetColor(D3DCOLOR_ARGB(100,255,255,255),R_FROZEN_BULLET1);
							m_graphics->DrawCC(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y - 13.5f,m_pTexture[T_ATK_EF],T_ATK_EF,R_FROZEN_BULLET1); 
						}
						break;
					case U_SAHAGIN2:
						if(status_battle[StatusSeachPosi(i,j)].m_action_end != false)	m_graphics->SetColor(D3DCOLOR_ARGB(178,255,255,255),R_CHAR_WAIT_LEFTFRONT+(status_battle[StatusSeachPosi(i,j)].m_direction*4) + charaWaitSahagin2);
						else	m_graphics->SetColor(D3DCOLOR_ARGB(255,255,255,255),R_CHAR_WAIT_LEFTFRONT+(status_battle[StatusSeachPosi(i,j)].m_direction*4) + charaWaitSahagin2);
						m_graphics->DrawCC(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y - 13.5f + (StatusSeachPosi(locate_cursor_field) != StatusSeachPosi(i,j) ? 0.f :charaAttackEfCnt%3),m_pTexture[T_CHAR_SAHAGIN2],T_CHAR_SAHAGIN2,R_CHAR_WAIT_LEFTFRONT + (!charaAttack  ? (status_battle[StatusSeachPosi(i,j)].m_direction*4) + charaWaitSahagin2 : ( keep_field_id[keep_char_select] != stage->GetFieldCharacterData(i,j) ? status_battle[StatusSeachPosi(i,j)].m_direction : enemyAttackCnt )));
						if(cut_out == StatusSeachPosi(i,j)) {
							m_graphics->SetColor(D3DCOLOR_ARGB(100,255,255,255),R_FROZEN_BULLET1);
							m_graphics->DrawCC(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y - 13.5f,m_pTexture[T_ATK_EF],T_ATK_EF,R_FROZEN_BULLET1); 
						}
						break;
					case U_LIZARDMAN1:
						if(status_battle[StatusSeachPosi(i,j)].m_action_end != false)	m_graphics->SetColor(D3DCOLOR_ARGB(178,255,255,255),R_CHAR_WAIT_LEFTFRONT+(status_battle[StatusSeachPosi(i,j)].m_direction*4) + charaWaitLizardman1);
						else	m_graphics->SetColor(D3DCOLOR_ARGB(255,255,255,255),R_CHAR_WAIT_LEFTFRONT+(status_battle[StatusSeachPosi(i,j)].m_direction*4) + charaWaitLizardman1);
						m_graphics->DrawCC(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y - 13.5f + (StatusSeachPosi(locate_cursor_field) != StatusSeachPosi(i,j) ? 0.f :charaAttackEfCnt%3),m_pTexture[T_CHAR_LIZARDMAN1],T_CHAR_LIZARDMAN1,R_CHAR_WAIT_LEFTFRONT + (!charaAttack  ? (status_battle[StatusSeachPosi(i,j)].m_direction*4) + charaWaitLizardman1 : ( keep_field_id[keep_char_select] != stage->GetFieldCharacterData(i,j) ? status_battle[StatusSeachPosi(i,j)].m_direction : enemyAttackCnt )));
						if(cut_out == StatusSeachPosi(i,j)) {
							m_graphics->SetColor(D3DCOLOR_ARGB(100,255,255,255),R_FROZEN_BULLET1);
							m_graphics->DrawCC(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y - 13.5f,m_pTexture[T_ATK_EF],T_ATK_EF,R_FROZEN_BULLET1); 
						}
						break;
					case U_LIZARDMAN2:
						if(status_battle[StatusSeachPosi(i,j)].m_action_end != false)	m_graphics->SetColor(D3DCOLOR_ARGB(178,255,255,255),R_CHAR_WAIT_LEFTFRONT+(status_battle[StatusSeachPosi(i,j)].m_direction*4) + charaWaitLizardman2);
						else	m_graphics->SetColor(D3DCOLOR_ARGB(255,255,255,255),R_CHAR_WAIT_LEFTFRONT+(status_battle[StatusSeachPosi(i,j)].m_direction*4) + charaWaitLizardman2);
						m_graphics->DrawCC(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y - 13.5f + (StatusSeachPosi(locate_cursor_field) != StatusSeachPosi(i,j) ? 0.f :charaAttackEfCnt%3),m_pTexture[T_CHAR_LIZARDMAN2],T_CHAR_LIZARDMAN2,R_CHAR_WAIT_LEFTFRONT + (!charaAttack  ? (status_battle[StatusSeachPosi(i,j)].m_direction*4) + charaWaitLizardman2 : ( keep_field_id[keep_char_select] != stage->GetFieldCharacterData(i,j) ? status_battle[StatusSeachPosi(i,j)].m_direction : enemyAttackCnt )));
						if(cut_out == StatusSeachPosi(i,j)) {
							m_graphics->SetColor(D3DCOLOR_ARGB(100,255,255,255),R_FROZEN_BULLET1);
							m_graphics->DrawCC(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y - 13.5f,m_pTexture[T_ATK_EF],T_ATK_EF,R_FROZEN_BULLET1); 
						}
						break;
					case U_LIZARDMAN3:
						if(status_battle[StatusSeachPosi(i,j)].m_action_end != false)	m_graphics->SetColor(D3DCOLOR_ARGB(178,255,255,255),R_CHAR_WAIT_LEFTFRONT+(status_battle[StatusSeachPosi(i,j)].m_direction*4) + charaWaitBoss);
						else	m_graphics->SetColor(D3DCOLOR_ARGB(255,255,255,255),R_CHAR_WAIT_LEFTFRONT+(status_battle[StatusSeachPosi(i,j)].m_direction*4) + charaWaitBoss);
						m_graphics->DrawCC(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y - 13.5f + (StatusSeachPosi(locate_cursor_field) != StatusSeachPosi(i,j) ? 0.f :charaAttackEfCnt%3),m_pTexture[T_CHAR_LIZARDMAN3],T_CHAR_LIZARDMAN3,R_CHAR_WAIT_LEFTFRONT + (!charaAttack  ? (status_battle[StatusSeachPosi(i,j)].m_direction*4) + charaWaitBoss : ( keep_field_id[keep_char_select] != stage->GetFieldCharacterData(i,j) ? status_battle[StatusSeachPosi(i,j)].m_direction : enemyAttackCnt )));
						if(cut_out == StatusSeachPosi(i,j)) {
							m_graphics->SetColor(D3DCOLOR_ARGB(100,255,255,255),R_FROZEN_BULLET1);
							m_graphics->DrawCC(stage->GetFieldPositionData(i,j).x,stage->GetFieldPositionData(i,j).y - 28.5f,m_pTexture[T_ATK_EF],T_ATK_EF,R_FROZEN_BULLET1); 
						}
						break;
				}
				AttackEffectDraw(i,j);
				CharaSkillDraw(i,j);
			}
		}
		if(flag_any_end == 1 || flag_any_end == 2 && flag_char_commando == 0 || flag_char_commando == 3)
		{
			SimpleStatusDraw();			//�n�`���ʊȈՃX�e�[�^�X�`��	
			SimpleCharaStatusDraw();	//�L�����ȈՃX�e�[�^�X�`��
		}
		BattleProcessDraw();
		BattleSkillDraw();
	}
	else if(flag_status_draw == 1)
	{
		StatusBackGroundDraw();
		StatusCharaDraw();
		StatusFontDraw();
		StatusDataDraw();
	}
}

void C_Battle::BattleClearDraw()
{
	m_graphics->DrawCC(650,550,m_pTexture[T_NOWLOADING],T_NOWLOADING,R_NOWLOADING);
}

void C_Battle::PlayerTurn(int* key)
{
	static int cnt_player = 0;
	static int deray_playertrun = 0;
	phase_shift = R_PLAYER_PHASE;
	if(flag_any_end == 0){
		locate_cursor_field.x = status_battle[StatusSeachId(U_ZION)].m_pos_chara_x;
		locate_cursor_field.y = status_battle[StatusSeachId(U_ZION)].m_pos_chara_y;
	}
	if(flag_any_end == 1){
		if(key[Z_PUSH-1] == Z_PUSH){	//�y�L�[�������ꂽ���L�����̂���|�W�V�����̏�ɃJ�[�\��������΃R�}���h�����Ɉڍs
			if(stage->IdSeach(locate_cursor_field.x,locate_cursor_field.y) != U_BLANK_AREA && stage->IdSeach(locate_cursor_field.x,locate_cursor_field.y) < U_SAHAGIN1){
				keep_char_select = stage->IdSeach(locate_cursor_field.x,locate_cursor_field.y) / 10;
				keep_field_id[keep_char_select] = stage->GetFieldCharacterData(locate_cursor_field.x,locate_cursor_field.y);
				if(status_battle[StatusSeachId(keep_field_id[keep_char_select])].m_action_end != true){
					flag_any_end = 2;
					keep_posi = locate_cursor_field;
					locate_cursor_commando = 0;
				}
			}
			key[Z_PUSH-1] = BLANK_KEY;
		}
	}
	BattleCombatSystem(key);
	if(!GetTurnEndflag()){
		if(deray_playertrun++ >= 30/*90*/){
			ChageActEnd();
			ApRecovery();
			flag_turn = ENEMY_TURN;
			flag_any_end = 0;
			cnt_turn++;
			deray_playertrun = 0;
		}
	}
}

void C_Battle::EnemyTurn(int* key)
{
	int cnt_enemy = 0;
	phase_shift = R_ENEMY_PHASE;
	if(flag_any_end == 0){
		locate_cursor_field.x =	status_battle[StatusSeachId(U_LIZARDMAN3)].m_pos_chara_x;
		locate_cursor_field.y = status_battle[StatusSeachId(U_LIZARDMAN3)].m_pos_chara_y;
	}
	if(flag_any_end == 1){
		EnemyAi(key);
	}
	BattleCombatSystem(key);
	if(!GetTurnEndflag()){
		if(flag_skill_ef[0] > 0){
			status[keep_skill_ef_id[0]].m_atk -= flag_skill_ef[0];
			flag_skill_ef[0] = 0;
		}
		if(flag_skill_ef[1] > 0){
			status[keep_skill_ef_id[1]].m_def -= flag_skill_ef[1];
			flag_skill_ef[1] = 0;
		}
		if(flag_skill_ef[2] > 0){
			status[keep_skill_ef_id[2]].m_atk -= flag_skill_ef[2];
			flag_skill_ef[2] = 0;
		}
		ChageActEnd();
		ApRecovery();
		flag_turn = PLAYER_TURN;
		flag_any_end = 0;
	}
}

void C_Battle::Release()
{
	for(int i = 0;i < MAX_S_BATTLE;i++)
	{
		SoundRelease(i);
	}
	for(int i = 0;i < MAX_TEXTURE_BATTLE;i++)
	{
		m_pTexture[i]->Release();
	}
}

void C_Battle::Sound()
{
	if(battle_change == BATTLE_CONDITION){
		if(flag_voice_setumei){
			SoundPlay(false,S_WIN_MAN + voice_change_setumei);
			flag_voice_setumei = false;
		}
	}
	if(battle_change == BATTLE_COMBAT){
		SoundPlay(true,S_BATTLE_BGM1);
		if(flag_voice){		//����{�C�X
			SoundPlay(false,S_MIRAGE_EDGE + voice_change);
			flag_voice = false;
		}
		if(flag_sound_sp){	//����T�E���h
			if(!SoundCheck(S_EF_BAKUENKEN + sound_ef_change_sp)){
				SoundPlay(false,S_EF_BAKUENKEN + sound_ef_change_sp);
				flag_sound_sp = false;
			}
		}
		if(flag_voice_attack){	//�U���{�C�X
			SoundPlay(false,S_ZION_ATTACK1 + voice_change_attack);
			flag_voice_attack = false;
		}
		if(flag_sound_ef){		//�U���T�E���h
			if(!SoundCheck(S_SWORDSWING1 + sound_ef_change_attack)){
				SoundPlay(false,S_SWORDSWING1 + sound_ef_change_attack);
				flag_sound_ef = false;
			}
		}
		if(flag_voice_ex){		//���`�{�C�X
			SoundPlay(false,S_ZION_ABUSORYUTOEND + voice_change_ex);
			flag_voice_ex = false;
		}
		if(flag_sound_ex){		//���`�T�E���h
			SoundPlay(false,S_SWORDSWING3 + sound_ef_change_ex);
			flag_sound_ex = false;
		}
		if(flag_sound_in){		//���`�C���T�E���h
			SoundPlay(false,S_OUGI_IN);
			flag_sound_in = false;
		}
		/*if(flag_sound_cursor){
			if(!SoundCheck(S_CURSOR_MOVE)){
				SoundPlay(false,S_CURSOR_MOVE);
			}
			flag_sound_cursor = false;
		}*/
	}
	else SoundStop(true,S_BATTLE_BGM2);
}

// �J�[�\����ɓ�����
void C_Battle::CursorUp(){
	
	if(locate_cursor_commando == CHAR_WAIT);
	else if(flag_any_end == 1){
		if(locate_cursor_field.y > 0){
			locate_cursor_field.y--;
		}
	}	//���݂̏c�̈ʒu���ŏ��łȂ���΁A�}�C�i�X
	else{
		if(stage->GetAreaInfoData(locate_cursor_field.x,locate_cursor_field.y - 1) >= 1){
			locate_cursor_field.y--;
		}
	}
	if(locate_cursor_commando == CHAR_MOVE || locate_cursor_commando == CHAR_WAIT){
		direction = RIGHT_BACK;
	}
	else{
		if(keep_posi.y > locate_cursor_field.y){
			direction = RIGHT_BACK;
		}
	}
}
// �J�[�\�����ɓ�����
void C_Battle::CursorDown(){

	if(locate_cursor_commando == CHAR_WAIT);
	else if(flag_any_end == 1){
		if(locate_cursor_field.y < HEIGHT_MAX - 1){
			locate_cursor_field.y++;
		}
	}	//���݂̏c�̈ʒu���ő�łȂ���΁A�v���X
	else{
		if(stage->GetAreaInfoData(locate_cursor_field.x,locate_cursor_field.y + 1) >= 1){
			locate_cursor_field.y++;
		}
	}
	if(locate_cursor_commando == CHAR_MOVE || locate_cursor_commando == CHAR_WAIT){
		direction = LEFT_FLONT;
	}
	else{
		if(keep_posi.y < locate_cursor_field.y){
			direction = LEFT_FLONT;
		}
	}
}
// �J�[�\�����ɓ�����
void C_Battle::CursorLeft(){

	if(locate_cursor_commando == CHAR_WAIT);
	else if(flag_any_end == 1){
		if(locate_cursor_field.x > 0){
			locate_cursor_field.x--;
		}
	}	//���݂̉��̈ʒu���ŏ��łȂ���΁A�}�C�i�X
	else{
		if(stage->GetAreaInfoData(locate_cursor_field.x - 1,locate_cursor_field.y) >= 1){
			locate_cursor_field.x--;
		}
	}
	if(locate_cursor_commando == CHAR_MOVE || locate_cursor_commando == CHAR_WAIT){
		direction = LEFT_BACK;
	}
	else{
		if(keep_posi.x > locate_cursor_field.x){
			direction = LEFT_BACK;
		}
	}
}
// �J�[�\���E�ɓ�����
void C_Battle::CursorRight(){
	if(locate_cursor_commando == CHAR_WAIT);
	else if(flag_any_end == 1){
		if(locate_cursor_field.x < WIDTH_MAX - 1){
			locate_cursor_field.x++;
		}
	}	//���݂̉��̈ʒu���ő�łȂ���΁A�v���X
	else{
		if(stage->GetAreaInfoData(locate_cursor_field.x + 1,locate_cursor_field.y) >= 1){
			locate_cursor_field.x++;
		}
	}
	if(locate_cursor_commando == CHAR_MOVE || locate_cursor_commando == CHAR_WAIT){
		direction = RIGHT_FLONT;
	}
	else{
		if(keep_posi.x < locate_cursor_field.x){
			direction = RIGHT_FLONT;
		}
	}
}

void C_Battle::CursorControlField(int* key)	//�J�[�\������(���݂̏c�C���݂̉��C�t�B�[���h���)
{
	int cursor_cnt=8;

	if(flag_turn == ENEMY_TURN)	return;
	if(flag_char_commando == 5) return;

	if(flag_any_end == 1 ||	flag_any_end == 2)
	{
		if(flag_char_commando == 0 && flag_any_end == 2 || flag_char_commando == 4 || flag_char_commando == 1)  return;
		//���������ꂽ��							// ��̃L�[�������ꑱ���Ă���
		if((key[KEY_UP - 1] == KEY_UP) || ((key[UP_PRESS - 1] == UP_PRESS) && (m_key_cnt++ > cursor_cnt))){
			m_key_cnt=0;
			CursorUp();
			flag_sound_cursor = true;
		}

		//���������ꂽ��							// ���̃L�[�������ꑱ���Ă���
		if((key[KEY_DOWN - 1] == KEY_DOWN) || ((key[DOWN_PRESS - 1] == DOWN_PRESS) && (m_key_cnt++ > cursor_cnt))){
			m_key_cnt=0;
			CursorDown();
			flag_sound_cursor = true;
		}

		//���������ꂽ��							// ���̃L�[�������ꑱ���Ă���
		if((key[LEFT_PUSH - 1] == LEFT_PUSH) || ((key[LEFT_PRESS - 1] == LEFT_PRESS && m_key_cnt++ > cursor_cnt))){
			m_key_cnt=0;
			CursorLeft();
			flag_sound_cursor = true;
		}

		//���������ꂽ��							// �E�̃L�[�������ꑱ���Ă���
		if((key[RIGHT_PUSH-1] == RIGHT_PUSH) || ((key[RIGHT_PRESS-1] == RIGHT_PRESS && m_key_cnt++ > cursor_cnt))){
			m_key_cnt=0;
			CursorRight();
			flag_sound_cursor = true;
		}
	}
}

void C_Battle::CursorControl(int* key,int max_cursor)	//�J�[�\������(��)
{
	if(flag_char_commando == 0 || flag_char_commando == 4)
	{
		//��܂��͍��������ꂽ��ʒu�����
		if(key[KEY_UP - 1] == KEY_UP || key[LEFT_PUSH - 1] == LEFT_PUSH){
			if(flag_char_commando == 4){
				locate_cursor_skill--;
				if(locate_cursor_skill < 0)		locate_cursor_skill = 0;
			}
			else{
				locate_cursor_commando--;
				if(locate_cursor_commando < 0)	locate_cursor_commando = max_cursor - 1;		//�����ʒu����ԏォ��܂���ɍs�����Ƃ������ԉ��Ɉړ�����(piece-1������Ă���͈̂�ԏ���O�ƍl���Ă��邩��)
			}
		}
		//���܂��͉E�������ꂽ��ʒu������
		if(key[KEY_DOWN - 1] == KEY_DOWN || key[RIGHT_PUSH-1] == RIGHT_PUSH){
			if(flag_char_commando == 4){
				locate_cursor_skill++;
				if(locate_cursor_skill > 1){
					if(status[StatusSeachPosi(locate_cursor_field)].m_mg == 100) { locate_cursor_skill = 2; }
					else { locate_cursor_skill = 0; }
				}
			}
			else{
				locate_cursor_commando++;
				if(locate_cursor_commando > max_cursor - 1)	locate_cursor_commando = 0;		//��Ƌt
			}
		}
	}
}

void C_Battle::StatusBackGroundDraw()//�X�e�[�^�X�̔w�i
{
	m_graphics->DrawCC(400.f,300.f,m_pTexture[T_STATUS_BG],T_STATUS_BG,R_STATUS_BG);
}

void C_Battle::StatusFontDraw()//�X�e�[�^�X�̌Œ�t�H���g�̕`��
{
	for(int i=R_STATUS_ATTRIBUTE1;i<=R_STATUS_SLASH3;i++)
	{	
		switch(i){
			//case R_STATUS_ATTRIBUTE1:
			//	font_center_x=50;
			//	font_center_y=75;
			//	font_increase_y=0;
			//	font_standard=R_STATUS_ATTRIBUTE1;
			//	break;

			case R_STATUS_HP:case R_STATUS_AP:case R_STATUS_MG:
				font_center_x=40;
				font_center_y=95;
				font_increase_y=35;
				font_standard=R_STATUS_HP;
				break;
			case R_STATUS_ATK:case R_STATUS_DEF:case R_STATUS_DEX:case R_STATUS_AGL:
				font_center_x=50;
				font_center_y=210;
				font_increase_y=35;
				font_standard=R_STATUS_ATK;
				break;
			case R_STATUS_MATRIX:case R_STATUS_MATERIAL:
				font_center_x=75;
				font_center_y=365;
				font_increase_y=35;
				font_standard=R_STATUS_MATRIX;
				break;
			case R_STATUS_SPECIAL:
				font_center_x=50;
				font_center_y=445;
				font_increase_y=0;
				font_standard=R_STATUS_SPECIAL;
				break;
			case R_STATUS_AP_R:
				font_center_x=300;
				font_center_y=95;
				font_increase_y=0;
				font_standard=R_STATUS_AP_R;
				break;
			case R_STATUS_MAG:case R_STATUS_RES:case R_STATUS_MOV:case R_STATUS_LUK:
				font_center_x=290;
				font_center_y=210;
				font_increase_y=35;
				font_standard=R_STATUS_MAG;
				break;
			case R_STATUS_ATTRIBUTE2:
				font_center_x=360;
				font_center_y=400;
				font_increase_y=0;
				font_standard=R_STATUS_ATTRIBUTE2;
				break;
			case R_STATUS_USE_AP1:case R_STATUS_USE_AP2:
				font_center_x=330;
				font_center_y=460;
				font_increase_y=70;
				font_standard=R_STATUS_USE_AP1;
				break;
			case R_STATUS_SLASH1:case R_STATUS_SLASH2:case R_STATUS_SLASH3:
				font_center_x=160;
				font_center_y=95;
				font_increase_y=35;
				font_standard=R_STATUS_SLASH1;
				break;
		}
		
		add_font_canter_y = (int)(font_center_y+font_increase_y*(i-font_standard));
		
		m_graphics->DrawCC((float)font_center_x,(float)add_font_canter_y,m_pTexture[T_STATUS_FC],T_STATUS_FC,i);
	}
}

void C_Battle::StatusDataDraw()//�X�e�[�^�X�̃p�����[�^�̕`��
{
	//p_data.LoadPlayerData(F_INITIAL);
	int data[15];
	chara_no = stage->IdSeach(locate_cursor_field.x,locate_cursor_field.y)/10;

	data[DATA_HP]	=	status[StatusSeachPosi(locate_cursor_field)].m_hp;
	data[DATA_AP]	=	status[StatusSeachPosi(locate_cursor_field)].m_ap;
	data[DATA_MG]	=	status[StatusSeachPosi(locate_cursor_field)].m_mg;
	data[DATA_MAXHP]=	status[StatusSeachPosi(locate_cursor_field)].m_maxhp;
	data[DATA_MAXAP]=	status[StatusSeachPosi(locate_cursor_field)].m_maxap;
	data[DATA_MAXMG]=	status[StatusSeachPosi(locate_cursor_field)].m_maxmg;
	data[DATA_ATK]	=	status[StatusSeachPosi(locate_cursor_field)].m_atk;
	data[DATA_DEF]	=	status[StatusSeachPosi(locate_cursor_field)].m_def;
	data[DATA_DEX]	=	status[StatusSeachPosi(locate_cursor_field)].m_dex;
	data[DATA_AGL]	=	status[StatusSeachPosi(locate_cursor_field)].m_agl;
	data[DATA_AP_R]	=	status[StatusSeachPosi(locate_cursor_field)].m_ap_r;
	data[DATA_MAG]	=	status[StatusSeachPosi(locate_cursor_field)].m_mag;
	data[DATA_RES]	=	status[StatusSeachPosi(locate_cursor_field)].m_res;
	data[DATA_MOV]	=	status[StatusSeachPosi(locate_cursor_field)].m_mov;
	data[DATA_LUK]	=	status[StatusSeachPosi(locate_cursor_field)].m_luk;

	for(int i = DATA_HP; i<=DATA_LUK;i++)
	{
		int num[3]={0};
		int figure=0;
		
		figure = (int)log10((double)data[i]) + 1;	//�X�R�A�̌����v�Z����

		if(data[i] == 0)	figure = 1;

		for(int j = figure ; j > 0 ; j--)															//�����Ƃ̐����Z�o
		{
			num[3-j] = data[i]/ (int)pow((double)10,j - 1) - data[i] / (int)pow((double)10,j) * 10;
		}
		for(int j = figure ; j > 0 ; j--)
		{
			F_RECT nownum=rect_battle[23+(3-j)];
			nownum.left+=30.f*num[3-j];
			nownum.right+=30.f*num[3-j];
			m_graphics->SetPostion(nownum,23+(3-j));
				switch(i)
				{
					case DATA_HP:case DATA_AP:case DATA_MG:
						num_center_x=75;
						num_center_y=95;
						num_increase_y=35;
						num_standard=DATA_HP;
						break;
					case DATA_MAXHP:case DATA_MAXAP:case DATA_MAXMG:
						num_center_x=180;
						num_center_y=95;
						num_increase_y=35;
						num_standard=DATA_MAXHP;
						break;
					case DATA_ATK:case DATA_DEF:case DATA_DEX:case DATA_AGL:
						num_center_x=85;
						num_center_y=210;
						num_increase_y=35;
						num_standard=DATA_ATK;
						break;
					case DATA_AP_R:
						num_center_x=355;
						num_center_y=95;
						num_increase_y=0;
						num_standard=DATA_AP_R;
						break;
					case DATA_MAG:case DATA_RES:case DATA_MOV:case DATA_LUK:
						num_center_x=355;
						num_center_y=210;
						num_increase_y=35;
						num_standard=DATA_MAG;
						break;
				}
		
			add_num_canter_y = (int)(num_center_y+num_increase_y*(i-num_standard));

			m_graphics->DrawCC((float)(num_center_x + (3-j) * 30.f),(float)add_num_canter_y,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_NUM100 + (3-j));
		}
	}
}

void C_Battle::StatusCharaDraw()//�X�e�[�^�X�̃L�����⑮���ɂ��`��
{
	chara_no = stage->IdSeach(locate_cursor_field.x,locate_cursor_field.y)/10;
	//�����鑮���`��
	//for(int i=R_STATUS_COVER1;i<=R_STATUS_COVER2;i++)
	//{
	//	int cover_atribution[2]={0};		//����
	//	switch(chara_no)
	//	{

	//		case ZION_ID:
	//			cover_atribution[0]=UNDINE;
	//			cover_atribution[1]=SYLPH;
	//			break;
	//		case VAN_ID:
	//			cover_atribution[0]=SALAMANDER;
	//			cover_atribution[1]=GNOME;
	//			break;
	//		case RIO_ID:
	//			cover_atribution[0]=SALAMANDER;
	//			cover_atribution[1]=UNDINE;
	//			break;
	//	}
	//	F_RECT cover=rect_battle[R_STATUS_COVER1+(i-R_STATUS_COVER1)];
	//	cover.left+=30.f*cover_atribution[i-R_STATUS_COVER1];
	//	cover.right+=30.f*cover_atribution[i-R_STATUS_COVER1];
	//	m_graphics->SetPostion(cover,R_STATUS_COVER1+(i-R_STATUS_COVER1));
	//	m_graphics->DrawCC((float)(115 +(i-R_STATUS_COVER1) * 50.f),75.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_COVER1+(i-R_STATUS_COVER1));
	//}

	//�L�����̃}�g���N�X�`��
	switch(chara_no)
	{
		case ZION_ID:
			mrx_increase_left=0;
			mrx_increase_right=0;
			mrx_center_x=-40;
			break;
		case VAN_ID:
			mrx_increase_left=0;
			mrx_increase_right=0;
			mrx_center_x=-10;
			break;
		case RIO_ID:
			mrx_increase_left=30;
			mrx_increase_right=270;
			mrx_center_x=80;
			break;
	}
	F_RECT matrix=rect_battle[R_STATUS_MATRIXNAME];
	matrix.left+=120.f*(chara_no-1)+mrx_increase_left;
	matrix.right+=150.f*(chara_no-1)+mrx_increase_right;
	m_graphics->SetPostion(matrix,R_STATUS_MATRIXNAME);
	
	if(chara_no==RIO_ID){
		m_graphics->SetSize(0.9f,0.9f,R_STATUS_MATRIXNAME);
	}
	m_graphics->DrawCC((float)(260+mrx_center_x),365.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_MATRIXNAME);
	
	//�L�����̃}�g���N�X����`��
	set_material = status[StatusSeachPosi(locate_cursor_field)].m_attribute;
	switch(set_material)
	{
		case SALAMANDER:
			mrl_increase_left=0;
			mrl_increase_right=0;
			mrl_center_x=0;
			break;
		case UNDINE:
			mrl_increase_left=0;
			mrl_increase_right=0;
			mrl_center_x=20;
			break;
		case SYLPH:
			mrl_increase_left=0;
			mrl_increase_right=30;
			mrl_center_x=35;
			break;
		case GNOME:
			mrl_increase_left=30;
			mrl_increase_right=60;
			mrl_center_x=35;
			break;
	}
	F_RECT material=rect_battle[R_STATUS_MATERIALNAME];
	material.left+=180.f*set_material-mrl_increase_left;
	material.right+=180.f*set_material-mrl_increase_right;
	m_graphics->SetPostion(material,R_STATUS_MATERIALNAME);
	m_graphics->DrawCC((float)(240-mrl_center_x),400.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_MATERIALNAME);
	
	//�L�����̃}�e���A���Z�A�ڍׁA����`�o�`��
	int Use_Ap[2]={0};
	switch(chara_no)
	{
		case ZION_ID:
			switch(set_material)
			{
				case UNDINE:
					Use_Ap[0]=AP_ICICLE_EDGE;
					Use_Ap[1]=AP_AQUA_CURE_Z;
					mrl_magic_1=R_STATUS_Z_UNDINE1;
					magic1_center_x=150;
					mrl_detail_1=R_STATUS_Z_UN_DATAIL1;
					mrl_detail1_center_x=190;
					mrl_magic_2=R_STATUS_Z_UNDINE2;
					magic2_center_x=125;
					mrl_detail_2=R_STATUS_RECOVERY_DATAIL;
					mrl_detail2_center_x=125;
					break;
				case SYLPH:
					Use_Ap[0]=AP_HEEL_WIND;
					Use_Ap[1]=AP_MIRAGE_EDGE;
					mrl_magic_1=R_STATUS_Z_SYLPH1;
					magic1_center_x=125;
					mrl_detail_1=R_STATUS_RECOVERY_DATAIL;
					mrl_detail1_center_x=115;
					mrl_magic_2=R_STATUS_Z_SYLPH2;
					magic2_center_x=130;
					mrl_detail_2=R_STATUS_Z_SY_DATAIL1;
					mrl_detail2_center_x=120;
					break;
			}
			break;
		case VAN_ID:
			switch(set_material)
			{
				case SALAMANDER:
					Use_Ap[0]=AP_BAKUENKEN;
					Use_Ap[1]=AP_GOUSYORAI;
					mrl_magic_1=R_STATUS_V_SALAMANDER1;
					magic1_center_x=90;
					mrl_detail_1=R_STATUS_V_SA_DATAIL1;
					mrl_detail1_center_x=205;
					mrl_magic_2=R_STATUS_V_SALAMANDER2;
					magic2_center_x=90;
					mrl_detail_2=R_STATUS_V_SA_DATAIL2;
					mrl_detail2_center_x=255;
					break;
				case GNOME:
					Use_Ap[0]=AP_TISAIJIN;
					Use_Ap[1]=AP_KOUSYORAI;
					mrl_magic_1=R_STATUS_V_GNOME1;
					magic1_center_x=90;
					mrl_detail_1=R_STATUS_V_GN_DATAIL1;
					mrl_detail1_center_x=180;
					mrl_magic_2=R_STATUS_V_GNOME2;
					magic2_center_x=90;
					mrl_detail_2=R_STATUS_V_GN_DATAIL2;
					mrl_detail2_center_x=250;
					break;
			}
			break;
		case RIO_ID:
			switch(set_material)
			{
				case SALAMANDER:
					Use_Ap[0]=AP_BLAZE_BULLET;
					Use_Ap[1]=AP_BURST;
					mrl_magic_1=R_STATUS_R_SALAMANDER1;
					magic1_center_x=120;
					mrl_detail_1=R_STATUS_R_SA_DATAIL1;
					mrl_detail1_center_x=175;
					mrl_magic_2=R_STATUS_R_SALAMANDER2;
					magic2_center_x=90;
					mrl_detail_2=R_STATUS_R_SA_DATAIL2;
					mrl_detail2_center_x=170;
					break;
				case UNDINE:
					Use_Ap[0]=AP_FROZEN_BULLET;
					Use_Ap[1]=AP_AQUA_CURE_R;
					mrl_magic_1=R_STATUS_R_UNDINE1;
					magic1_center_x=130;
					mrl_detail_1=R_STATUS_R_UN_DATAIL1;
					mrl_detail1_center_x=305;
					mrl_magic_2=R_STATUS_R_UNDINE2;
					magic2_center_x=120;
					mrl_detail_2=R_STATUS_RECOVERY_DATAIL;
					mrl_detail2_center_x=115;
					break;
			}
			break;
	}
	m_graphics->DrawCC((float)magic1_center_x,460.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,mrl_magic_1);
	m_graphics->DrawCC((float)mrl_detail1_center_x,495.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,mrl_detail_1);
	m_graphics->DrawCC((float)magic2_center_x,530.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,mrl_magic_2);
	m_graphics->DrawCC((float)mrl_detail2_center_x,565.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,mrl_detail_2);

	//�L�����̃t���l�[��

	F_RECT charaname=rect_battle[R_STATUS_CHARA_NAME];
	charaname.top+=30.f*(chara_no-1);
	charaname.bottom+=30.f*(chara_no-1);
	m_graphics->SetPostion(charaname,R_STATUS_CHARA_NAME);
	m_graphics->DrawCC(160.f,35.f,m_pTexture[T_STATUS_NAME],T_STATUS_NAME,R_STATUS_CHARA_NAME);

	//�L�����̕`��
	m_graphics->DrawCC(605.f,345.f,m_pTexture[T_STATUS_ZION_CG + chara_no - 1],T_STATUS_ZION_CG + chara_no-1,R_STATUS_ZION_CG + chara_no-1);
	
	//�����̕`��
	F_RECT quality=rect_battle[R_STATUS_COVER1];
	quality.left+=30.f * set_material;
	quality.right+=30.f * set_material;
	m_graphics->SetPostion(quality,R_STATUS_COVER1);
	m_graphics->DrawCC(410.f,400.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_COVER1);


	//����AP�̐��l��`��
	for(int i=0;i<2;i++)
	{
			F_RECT nownum=rect_battle[25];
			nownum.left+=30.f*Use_Ap[i];
			nownum.right+=30.f*Use_Ap[i];
			m_graphics->SetPostion(nownum,25);
			m_graphics->DrawCC(410.f,460.f + i * 70.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_NUM1);
	}

}



void C_Battle::CheckField()
{
	landform=stage->GetFieldMaptipData(locate_cursor_field);
	int topography_effect[2]={0};
	int skill_effect[2]={0};
	switch(landform)
	{
		case MAPTIP_BLANK:
			for(int i=0;i<2;i++)
			{
				topography_effect[i]=M_NOTHING;
				skill_effect[i]=SKILL_NOTHING;
			}
			break;
		case MAPTIP_CACTUS1:case MAPTIP_CACTUS2:case MAPTIP_ROCK1:case MAPTIP_ROCK2:
			m_graphics->DrawCC(SIMPLEMAPTIP_X,SIMPLEMAPTIP_Y,m_pTexture[T_MAPTIP],T_MAPTIP,R_MAPTIP_CACTUS1 + landform - 1);
			for(int i=0;i<2;i++)
			{
				topography_effect[i]=M_NOTHING;
				skill_effect[i]=SKILL_NOTHING;
			}
			break;
		case MAPTIP_SAND1:
			m_graphics->DrawCC(SIMPLEMAPTIP_X,SIMPLEMAPTIP_Y,m_pTexture[T_MAPTIP],T_MAPTIP,R_MAPTIP_SAND1);
			topography_effect[0]=M_SYLPH;
			topography_effect[1]=M_GNOME;
			skill_effect[0]=SKILL_UP;
			skill_effect[1]=SKILL_DOWN;
			break;
		case MAPTIP_SAND2:
			m_graphics->DrawCC(SIMPLEMAPTIP_X,SIMPLEMAPTIP_Y,m_pTexture[T_MAPTIP],T_MAPTIP,R_MAPTIP_SAND2);
			topography_effect[0]=M_GNOME;
			topography_effect[1]=M_SALAMANDER;
			skill_effect[0]=SKILL_UP;
			skill_effect[1]=SKILL_DOWN;
			break;
		case MAPTIP_SAND3:
			m_graphics->DrawCC(SIMPLEMAPTIP_X,SIMPLEMAPTIP_Y,m_pTexture[T_MAPTIP],T_MAPTIP,R_MAPTIP_SAND3);
			topography_effect[0]=M_SALAMANDER;
			topography_effect[1]=M_UNDINE;
			skill_effect[0]=SKILL_UP;
			skill_effect[1]=SKILL_DOWN;
			break;
		case MAPTIP_SAND4:
			m_graphics->DrawCC(SIMPLEMAPTIP_X,SIMPLEMAPTIP_Y,m_pTexture[T_MAPTIP],T_MAPTIP,R_MAPTIP_SAND4);
			for(int i=0;i<2;i++)
			{
				topography_effect[i]=M_NOTHING;
				skill_effect[i]=SKILL_NOTHING;
			}
			break;
		case MAPTIP_GREEN1:
			m_graphics->DrawCC(SIMPLEMAPTIP_X,SIMPLEMAPTIP_Y,m_pTexture[T_MAPTIP],T_MAPTIP,R_MAPTIP_GREEN1);
			topography_effect[0]=M_UNDINE;
			topography_effect[1]=M_SYLPH;
			skill_effect[0]=SKILL_UP;
			skill_effect[1]=SKILL_DOWN;
			break;
		case MAPTIP_GREEN2:
			m_graphics->DrawCC(SIMPLEMAPTIP_X,SIMPLEMAPTIP_Y,m_pTexture[T_MAPTIP],T_MAPTIP,R_MAPTIP_GREEN2);
			topography_effect[0]=M_NOTHING;
			topography_effect[1]=M_FULL;
			skill_effect[0]=SKILL_NOTHING;
			skill_effect[1]=SKILL_DOWN;
			break;
		case MAPTIP_GREEN3:
			m_graphics->DrawCC(SIMPLEMAPTIP_X,SIMPLEMAPTIP_Y,m_pTexture[T_MAPTIP],T_MAPTIP,R_MAPTIP_GREEN3);
			for(int i=0;i<2;i++)
			{
				topography_effect[i]=M_NOTHING;
				skill_effect[i]=SKILL_NOTHING;
			}
			break;
		case MAPTIP_GREEN4:
			m_graphics->DrawCC(SIMPLEMAPTIP_X,SIMPLEMAPTIP_Y,m_pTexture[T_MAPTIP],T_MAPTIP,R_MAPTIP_GREEN4);
			topography_effect[0]=M_FULL;
			topography_effect[1]=M_NOTHING;
			skill_effect[0]=SKILL_UP;
			skill_effect[1]=SKILL_NOTHING;
			break;				
	}
	for(int i=0;i<2;i++)
	{
		F_RECT maptip_operation=rect_battle[R_SIMPLE_EFFECT];
		maptip_operation.left+=30.f*topography_effect[i];
		maptip_operation.right+=30.f*topography_effect[i];
		m_graphics->SetPostion(maptip_operation,R_SIMPLE_EFFECT);

		F_RECT skill_detail=rect_battle[R_SIMPLE_UPDOWN];
		skill_detail.left+=30.f*skill_effect[i];
		skill_detail.right+=30.f*skill_effect[i];
		m_graphics->SetPostion(skill_detail,R_SIMPLE_UPDOWN);

		m_graphics->DrawCC(412.f+60*i,480.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_SIMPLE_EFFECT);
		m_graphics->DrawCC(442.f+60*i,480.f,m_pTexture[T_BATTLE_FONT],T_BATTLE_FONT,R_SIMPLE_UPDOWN);
	}
}

void C_Battle::SimpleStatusDraw()
{
	if(locate_cursor_commando == CHAR_ATTACK && flag_char_commando == 3 ||
		locate_cursor_commando == CHAR_SPECIAL && flag_char_commando == 3 ||
		locate_cursor_commando == CHAR_SP_EXTRA && flag_char_commando == 3){
	}
	else{
		m_graphics->DrawCC(468.f,518.f,m_pTexture[T_WAKU],T_WAKU,R_SIMPLE_BG);
	
		CheckField();
	}
}

void C_Battle::SimpleDrawFlag()
{
	if(locate_cursor_commando == CHAR_ATTACK && flag_char_commando == 3 ||
		locate_cursor_commando == CHAR_SPECIAL && flag_char_commando == 3 ||
		locate_cursor_commando == CHAR_SP_EXTRA && flag_char_commando == 3){
			flag_battle_status_draw = true;
			chara_id = stage->GetFieldCharacterData(locate_cursor_field.x,locate_cursor_field.y);
			switch(chara_id/10)
			{
				case U_BLANK_AREA:
					flag_simple_chara=0;
					break;
				case ZION_ID:case VAN_ID:case RIO_ID:
					flag_simple_chara = 1;
					break;
				case SAHAGIN1_ID:case SAHAGIN2_ID:
				case LIZARD1_ID:case LIZARD2_ID:case LIZARD3_ID:case BOSS_ID:
					flag_simple_chara = 2;
					break;
			}
	}
	else{
		flag_battle_status_draw = false;
		chara_id = stage->GetFieldCharacterData(locate_cursor_field.x,locate_cursor_field.y);
		switch(chara_id/10)
		{
			case U_BLANK_AREA:
				flag_simple_chara=0;
				break;
			case ZION_ID:case VAN_ID:case RIO_ID:
				flag_simple_chara = 1;
				break;
			case SAHAGIN1_ID:case SAHAGIN2_ID:
			case LIZARD1_ID:case LIZARD2_ID:case LIZARD3_ID:case BOSS_ID:
				flag_simple_chara = 2;
				break;
		}
	}
}

void C_Battle::SimpleCharaDraw()
{
	int simple_data[10];

	//�L�����N�^�[�̃p�����[�^
	if(flag_battle_status_draw == true && cnt_draw == 0 || flag_battle_status_draw == false){
		simple_data[S_DATA_HP]		= status[StatusSeachPosi(locate_cursor_field)].m_hp;
		simple_data[S_DATA_AP]		= status[StatusSeachPosi(locate_cursor_field)].m_ap;
		simple_data[S_DATA_MG]		= status[StatusSeachPosi(locate_cursor_field)].m_mg;
		simple_data[S_DATA_MAXHP]	= status[StatusSeachPosi(locate_cursor_field)].m_maxhp;
		simple_data[S_DATA_MAXAP]	= status[StatusSeachPosi(locate_cursor_field)].m_maxap;
		simple_data[S_DATA_MAXMG]	= status[StatusSeachPosi(locate_cursor_field)].m_maxmg;
		simple_data[S_DATA_MOVE]	= status[StatusSeachPosi(locate_cursor_field)].m_mov;
	}
	else{
		simple_data[S_DATA_HP]		= status[StatusSeachPosi(keep_posi)].m_hp;
		simple_data[S_DATA_AP]		= status[StatusSeachPosi(keep_posi)].m_ap;
		simple_data[S_DATA_MG]		= status[StatusSeachPosi(keep_posi)].m_mg;
		simple_data[S_DATA_MAXHP]	= status[StatusSeachPosi(keep_posi)].m_maxhp;
		simple_data[S_DATA_MAXAP]	= status[StatusSeachPosi(keep_posi)].m_maxap;
		simple_data[S_DATA_MAXMG]	= status[StatusSeachPosi(keep_posi)].m_maxmg;
		simple_data[S_DATA_MOVE]	= status[StatusSeachPosi(keep_posi)].m_mov;
	}

	if(flag_battle_status_draw == true && cnt_draw == 1 || flag_battle_status_draw == false){
		status_enemy = 0.f;
	}
	else{
		status_enemy = 380.f;
	}

	static int num_draw = 0;

	//�X�e�[�^�X�̃p�����[�^�̕���
	m_graphics->Draw(SIMPLE_HAM_X + status_enemy,SIMPLE_HAM_Y,m_pTexture[T_WAKU],T_WAKU,R_HP_FONT);
	if(flag_simple_chara == 1 || cnt_draw == 1){
		num_draw = 3;
		m_graphics->Draw(SIMPLE_HAM_X + status_enemy,SIMPLE_HAM_Y+SIMPLE_INCREASE_Y,m_pTexture[T_WAKU],T_WAKU,R_AP_FONT);
		m_graphics->Draw(SIMPLE_HAM_X + status_enemy,SIMPLE_HAM_Y+SIMPLE_INCREASE_Y*2,m_pTexture[T_WAKU],T_WAKU,R_MG_FONT);
	}
	else{
		num_draw = 1;
	}
	m_graphics->Draw(SIMPLE_HAM_X + status_enemy,SIMPLE_HAM_Y+SIMPLE_INCREASE_Y*3,m_pTexture[T_WAKU],T_WAKU,R_MOV_FONT);

	//�X���b�V��
	for(int i = 0;i < num_draw;i++)
	{
		//�o�b�N�p
		m_graphics->SetColor(0xFFFFFFFF,R_GAGE_HP_MAX + i);
		m_graphics->Draw(173.f + status_enemy,SIMPLE_HAM_Y + 5.5f + i * SIMPLE_INCREASE_Y,m_pTexture[T_WAKU],T_WAKU,R_GAGE_HP_MAX + i);
		//�c�聛���p
		if(i == 0){
			m_graphics->SetColor(0x88008888,R_GAGE_HP + i);
		}
		else if(i == 1){
			m_graphics->SetColor(0x88882222,R_GAGE_HP + i);
		}
		else{
			m_graphics->SetColor(0x88448888,R_GAGE_HP + i);
		}
		m_graphics->SetPostion(171.f,0.f,185.f,180.f * (float)simple_data[S_DATA_HP + i] / (float)simple_data[S_DATA_MAXHP + i],R_GAGE_HP + i);
		m_graphics->Draw(173.f + status_enemy,SIMPLE_HAM_Y + 5.75f + i * SIMPLE_INCREASE_Y,m_pTexture[T_WAKU],T_WAKU,R_GAGE_HP + i);
		//�Q�[�W�g
		m_graphics->Draw(173.f + status_enemy,SIMPLE_HAM_Y + 5.f + i * SIMPLE_INCREASE_Y,m_pTexture[T_WAKU],T_WAKU,R_GAGE_WAKU);
		//�X���b�V��
		m_graphics->Draw(251.f + status_enemy,SIMPLE_HAM_Y + 2.5f + i * SIMPLE_INCREASE_Y,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_SLASH_FONT);
	}

	for(int i = S_DATA_HP; i <= S_DATA_MOVE;i++)
	{
		int simple_num[3]={0};
		int figure=0;

		if(flag_simple_chara == 2 && cnt_draw == 0 || flag_simple_chara == 2 && flag_battle_status_draw == false){
			if(i == 1){
				i = 3;
			}
			if(i == 4){
				i = 6;
			}
		}
		
		figure = (int)log10((double)simple_data[i]) + 1;	//�X�R�A�̌����v�Z����

		if(simple_data[i] == 0)	figure = 1;

		for(int j = figure ; j > 0 ; j--)															//�����Ƃ̐����Z�o
		{
			simple_num[3-j] = simple_data[i]/ (int)pow((double)10,j - 1) - simple_data[i] / (int)pow((double)10,j) * 10;
		}
		for(int j = figure ; j > 0 ; j--)
		{
			F_RECT simnum=rect_battle[R_SIMPLE_NUM100+(3-j)];
			simnum.left+=20.f*simple_num[3-j];
			simnum.right+=20.f*simple_num[3-j];
			m_graphics->SetPostion(simnum,R_SIMPLE_NUM100+(3-j));
				switch(i)
				{
					case S_DATA_HP:case S_DATA_AP:case S_DATA_MG:
						simple_num_x = 226;
						simple_num_y = 495;
						sim_num_standard = S_DATA_HP;
						break;
					case S_DATA_MAXHP:case S_DATA_MAXAP:case S_DATA_MAXMG:
						simple_num_x = 270;
						simple_num_y = 495;
						sim_num_standard = S_DATA_MAXHP;
						break;
					case S_DATA_MOVE:
						simple_num_x = 180;
						simple_num_y = 562;
						sim_num_standard = S_DATA_MOVE;
						break;
				}
				if(sim_num_standard == S_DATA_MOVE){
					m_graphics->DrawCC((float)(simple_num_x + (3-j) * 10.f) + status_enemy,(float)simple_num_y+(i-sim_num_standard)*23.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_SIMPLE_NUM100 + (3-j));
				}
				else{
					m_graphics->DrawCC((float)(simple_num_x + (3-j) * 10.f) + status_enemy,(float)simple_num_y+(i-sim_num_standard)*23.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_SIMPLE_NUM100 + (3-j));
				}
		}
	}

	//�L�����N�^�[�̖��O�A�L�����G
	switch(chara_id/10)
	{
	case ZION_ID:
		simple_chara_name=0;
		m_graphics->DrawCC(SIMPLE_CHARA_X + status_enemy,SIMPLE_CHARA_Y,m_pTexture[T_STATUS_FACE_CG],T_STATUS_FACE_CG,R_FACE_ZION);
		break;
	case VAN_ID:
		simple_chara_name=1;
		m_graphics->DrawCC(SIMPLE_CHARA_X + status_enemy,SIMPLE_CHARA_Y,m_pTexture[T_STATUS_FACE_CG],T_STATUS_FACE_CG,R_FACE_VAN);
		break;
	case RIO_ID:
		simple_chara_name=2;
		m_graphics->DrawCC(SIMPLE_CHARA_X + status_enemy,SIMPLE_CHARA_Y,m_pTexture[T_STATUS_FACE_CG],T_STATUS_FACE_CG,R_FACE_RIO);
		break;
	case SAHAGIN1_ID:
		simple_chara_name=3;
		m_graphics->DrawCC(SIMPLE_CHARA_X + status_enemy,SIMPLE_CHARA_Y,m_pTexture[T_STATUS_FACE_CG],T_STATUS_FACE_CG,R_FACE_SAHAGIN1);
		break;
	case SAHAGIN2_ID:
		simple_chara_name=4;
		m_graphics->DrawCC(SIMPLE_CHARA_X + status_enemy,SIMPLE_CHARA_Y,m_pTexture[T_STATUS_FACE_CG],T_STATUS_FACE_CG,R_FACE_SAHAGIN2);
		break;
	case LIZARD1_ID:
		simple_chara_name=5;
		m_graphics->DrawCC(SIMPLE_CHARA_X + status_enemy,SIMPLE_CHARA_Y,m_pTexture[T_STATUS_FACE_CG],T_STATUS_FACE_CG,R_FACE_LIZARDMAN1);
		break;
	case LIZARD2_ID:
		simple_chara_name=6;
		m_graphics->DrawCC(SIMPLE_CHARA_X + status_enemy,SIMPLE_CHARA_Y,m_pTexture[T_STATUS_FACE_CG],T_STATUS_FACE_CG,R_FACE_LIZARDMAN2);
		break;
	case LIZARD3_ID:
		simple_chara_name=7;
		m_graphics->DrawCC(SIMPLE_CHARA_X + status_enemy,SIMPLE_CHARA_Y,m_pTexture[T_STATUS_FACE_CG],T_STATUS_FACE_CG,R_FACE_BOSS);
		break;
	}
	if(chara_id/10 == LIZARD1_ID || chara_id/10 == LIZARD2_ID || chara_id/10 == SAHAGIN2_ID){
		m_graphics->Draw(SIMPLE_CHARA_X - 47.f,457.f - 15.f + status_enemy,m_pTexture[T_STATUS_NAME],T_STATUS_NAME,R_STATENAME_ZION + simple_chara_name);		//�L�������O
	}
	else{
		m_graphics->DrawCC(SIMPLE_CHARA_X + status_enemy,457.f,m_pTexture[T_STATUS_NAME],T_STATUS_NAME,R_STATENAME_ZION + simple_chara_name);	//�L�������O
	}
	
	//�}�e���A������
	m_graphics->Draw(227.5f + status_enemy,445.f,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_MATERIALSALAMANDER + status[StatusSeachId(chara_id)].m_attribute);

}

void C_Battle::SimpleCharaStatusDraw()
{
	SimpleDrawFlag();
	if(flag_battle_status_draw == false){
		if(flag_simple_chara == 1)			//�v���C���[�L�����̏ꍇ
		{
			m_graphics->DrawCC(196.f,516.f,m_pTexture[T_WAKU],T_WAKU,R_BG_PLAYER);		//�ȈՃX�e�[�^�X�g�`��
			//m_graphics->DrawCC(400.f,300.f,m_pTexture[T_A],T_A,R_A);
			SimpleCharaDraw();
		}
		else if(flag_simple_chara == 2)		//�G�l�~�[�L�����̏ꍇ
		{
			m_graphics->DrawCC(196.f,516.f,m_pTexture[T_WAKU],T_WAKU,R_BG_ENEMY);		//�ȈՃX�e�[�^�X�g�`��
			//m_graphics->DrawCC(400.f,300.f,m_pTexture[T_A],T_A,R_A);
			SimpleCharaDraw();
		}
	}
	else{
		m_graphics->DrawCC(196.f,516.f,m_pTexture[T_WAKU],T_WAKU,R_BG_PLAYER);		//�ȈՃX�e�[�^�X�g�`��
		cnt_draw = 1;
		chara_id = stage->GetFieldCharacterData(keep_posi.x,keep_posi.y);
		SimpleCharaDraw();
		if(flag_simple_chara == 1)			//�v���C���[�L�����̏ꍇ
		{
			if(keep_posi.x == locate_cursor_field.x && keep_posi.y == locate_cursor_field.y){
			}
			else{
				m_graphics->DrawCC(196.f + 380.f,516.f,m_pTexture[T_WAKU],T_WAKU,R_BG_PLAYER);		//�ȈՃX�e�[�^�X�g�`��
				cnt_draw = 0;
				chara_id = stage->GetFieldCharacterData(locate_cursor_field.x,locate_cursor_field.y);
				SimpleCharaDraw();
			}
		}
		else if(flag_simple_chara == 2)		//�G�l�~�[�L�����̏ꍇ
		{
			m_graphics->DrawCC(196.f + 380.f,516.f,m_pTexture[T_WAKU],T_WAKU,R_BG_ENEMY);		//�ȈՃX�e�[�^�X�g�`��
			cnt_draw = 0;
			chara_id = stage->GetFieldCharacterData(locate_cursor_field.x,locate_cursor_field.y);
			SimpleCharaDraw();
		}
	}
}

void C_Battle::SetStatus()		//�S�̂����ăL�����ʂɊe�L�����ɃX�e�[�^�X������
{
	static int cnt_id = 0;
	for(int i = 0;i < stage->GetMaptipXData();i++){
		for(int j = 0;j < stage->GetMaptipYData();j++){
			switch(stage->IdSeach(i,j))
			{
			case U_BLANK_AREA:
				break;
			case U_ZION:
				status[0 + cnt_id] = zion->GetCharaState();
				status_battle[0 + cnt_id] = zion->GetCharaStateBattle();
				break;
			case U_VAN:
				status[0 + cnt_id] = van->GetCharaState();
				status_battle[0 + cnt_id] = van->GetCharaStateBattle();
				break;
			case U_RIO:
				status[0 + cnt_id] = rio->GetCharaState();
				status_battle[0 + cnt_id] = rio->GetCharaStateBattle();
				break;
			case U_SAHAGIN1:
				status[0 + cnt_id] = enemy1->GetCharaState();
				status_battle[0 + cnt_id] = enemy1->GetCharaStateBattle();
				break;
			case U_SAHAGIN2:
				status[0 + cnt_id] = enemy2->GetCharaState();
				status_battle[0 + cnt_id] = enemy2->GetCharaStateBattle();
				break;
			case U_LIZARDMAN1:
				status[0 + cnt_id] = enemy3->GetCharaState();
				status_battle[0 + cnt_id] = enemy3->GetCharaStateBattle();
				break;
			case U_LIZARDMAN2:
				status[0 + cnt_id] = enemy4->GetCharaState();
				status_battle[0 + cnt_id] = enemy4->GetCharaStateBattle();
				break;
			case U_LIZARDMAN3:
				status[0 + cnt_id] = boss->GetCharaState();
				status_battle[0 + cnt_id] = boss->GetCharaStateBattle();
				break;
			}
			if(stage->GetFieldCharacterData(i,j) != U_BLANK_AREA)
			{
				status[0 + cnt_id].m_id = stage->GetFieldCharacterData(i,j);
				status_battle[0 + cnt_id].m_id = stage->GetFieldCharacterData(i,j);
				status_battle[0 + cnt_id].m_pos_chara_x = i;
				status_battle[0 + cnt_id].m_pos_chara_y = j;
				cnt_id++;
			}
		}
	}
}

void C_Battle::InitStatus()		//�L�����̃X�e�[�^�X������������
{
	zion->Init();
	rio->Init();
	van->Init();
	enemy1->Init();
	enemy2->Init();
	enemy3->Init();
	enemy4->Init();
	boss->Init();
}

int C_Battle::StatusSeachId(int id)		//�X�e�[�^�X��ID���猟������
{
	int keep_id_no = stage->GetCharMaxData();
	for(int i = 0;i < stage->GetCharMaxData();i++){
		if(status_battle[i].m_id == id){
			keep_id_no = i;
			break;
		}
	}
	return keep_id_no;
}

int C_Battle::StatusSeachPosi(int x,int y)		//���W���炻�̏ꏊ�ɂ���L���������(���W��)
{
	int keep_id_no = stage->GetCharMaxData();
	for(int i = 0;i < stage->GetCharMaxData();i++)
	{
		if(stage->GetFieldCharacterData(x,y) != 1){
			if(status[i].m_id == stage->GetFieldCharacterData(x,y)){
				keep_id_no = i;
				break;
			}
		}
	}
	return keep_id_no;
}

int C_Battle::StatusSeachPosi(COORDINATE no)	//���W���炻�̏ꏊ�ɂ���L���������(�\���̔�)
{
	int keep_id_no = stage->GetCharMaxData();
	for(int i = 0;i < stage->GetCharMaxData();i++)
	{
		if(stage->GetFieldCharacterData(no.x,no.y) != 1){
			if(status[i].m_id == stage->GetFieldCharacterData(no.x,no.y)){
				keep_id_no = i;
				break;
			}
		}
	}
	return keep_id_no;
}

bool C_Battle::GetTurnEndflag()
{
	int player_end = 0;
	int enemy_end = 0;
	for(int i = 0;i < stage->GetCharMaxData();i++){
		if(status_battle[i].m_action_end == true){
			if(status_battle[i].m_id < U_SAHAGIN1){
				player_end++;
			}
			else{
				enemy_end++;
			}
		}
		else if(status_battle[i].m_battle_impossible == true){
			if(status_battle[i].m_id < U_SAHAGIN1){
				player_end++;
			}
			else{
				enemy_end++;
			}
		}
	}
	if(flag_turn == PLAYER_TURN && player_end == stage->GetPlayerMax()) { return false; }
	else if(flag_turn == ENEMY_TURN && enemy_end == stage->GetEnemyMax()){	return false; }
	return true;
}

void C_Battle::ChageActEnd()
{
	static int frozen_ef = 0;
	for(int i = 0;i < stage->GetCharMaxData();i++){
		if(flag_turn == PLAYER_TURN){
			if(frozen_ef == 1 && cut_out == i){
				cut_out = stage->GetCharMaxData();
				frozen_ef = 0;
			}
			if(status[i].m_id >= U_SAHAGIN1 && cut_out != i){
				status_battle[i].m_action_end = false;
			}
			else if(status[i].m_id >= U_SAHAGIN1) {
				frozen_ef++; 
				status_battle[i].m_action_end = true;
			}
		}
		else{
			if(status[i].m_id < U_SAHAGIN1){
				status_battle[i].m_action_end = false;
			}
		}
	}
}

double C_Battle::TopographyEffect()
{
	double effectpoint;
	chara_now_area=stage->GetFieldMaptipData(keep_posi);
	set_material = status[StatusSeachPosi(locate_cursor_field)].m_attribute;

	switch(chara_now_area)
	{
		case MAPTIP_BLANK:case MAPTIP_CACTUS1:case MAPTIP_CACTUS2:case MAPTIP_ROCK1:case MAPTIP_ROCK2:
			break;
		case MAPTIP_SAND1:
			switch(set_material)
			{
				case SYLPH:
					effectpoint=1.5;
					break;
				case SALAMANDER:case UNDINE:
					effectpoint=1.0;
					break;
				case GNOME:
					effectpoint=0.5;
					break;
			}
			break;
		case MAPTIP_SAND2:
			switch(set_material)
			{
				case GNOME:
					effectpoint=1.5;
					break;
				case UNDINE:case SYLPH:
					effectpoint=1.0;
					break;
				case SALAMANDER:
					effectpoint=0.5;
					break;
			}
			break;
		case MAPTIP_SAND3:
			switch(set_material)
			{
				case SALAMANDER:
					effectpoint=1.5;
					break;
				case SYLPH:case GNOME:
					effectpoint=1.0;
					break;
				case UNDINE:
					effectpoint=0.5;
					break;
			}
			break;
		case MAPTIP_SAND4:
			switch(set_material)
			{
				case GNOME:case UNDINE:case SYLPH:case SALAMANDER:
					effectpoint=1.0;
					break;
			}
			break;
		case MAPTIP_GREEN1:
			switch(set_material)
			{
				case UNDINE:
					effectpoint=1.5;
					break;
				case SALAMANDER:case GNOME:
					effectpoint=1.0;
					break;
				case SYLPH:
					effectpoint=0.5;
					break;
			}
			break;
		case MAPTIP_GREEN2:
			switch(set_material)
			{
				case GNOME:case UNDINE:case SYLPH:case SALAMANDER:
					effectpoint=0.5;
					break;
			}
			break;
		case MAPTIP_GREEN3:
			switch(set_material)
			{
				case GNOME:case UNDINE:case SYLPH:case SALAMANDER:
					effectpoint=1.0;
					break;
			}
			break;
		case MAPTIP_GREEN4:
			switch(set_material)
			{
				case GNOME:case UNDINE:case SYLPH:case SALAMANDER:
					effectpoint=1.5;
					break;
			}
			break;				
	}
	return effectpoint;
}

//�L�����N�^�[�̈ړ�����AP�̒l��Ԃ�
int C_Battle::UseMoveAP()
{
	int use_move_ap;
	chara_id=stage->GetFieldCharacterData(locate_cursor_field.x,locate_cursor_field.y);
	switch(chara_id/10)
	{
	case ZION_ID:case VAN_ID:case LIZARD1_ID:case LIZARD2_ID:case LIZARD3_ID:
		use_move_ap=3;
		break;
	case RIO_ID:case SAHAGIN1_ID:case SAHAGIN2_ID:
		use_move_ap=2;
		break;
	}
	return use_move_ap;
}

//�L�����N�^�[�̒ʏ�U������AP�̒l��Ԃ�
int C_Battle::UseNormalAttackAP()
{
	int use_normalattack_ap;
	chara_id=stage->GetFieldCharacterData(keep_posi.x,keep_posi.y);
	switch(chara_id/10)
	{
	case ZION_ID:case RIO_ID:case SAHAGIN2_ID:case LIZARD1_ID:case LIZARD3_ID:
		use_normalattack_ap=3;
		break;
	case VAN_ID:case LIZARD2_ID:
		use_normalattack_ap=4;
		break;
	case SAHAGIN1_ID:
		use_normalattack_ap=2;
		break;
	}
	return use_normalattack_ap;
}

//�L�����N�^�[�̓���U������AP�̒l��Ԃ�
int C_Battle::UseSpecialAP1()
{
	int use_special_ap1;

	chara_id=stage->GetFieldCharacterData(keep_posi.x,keep_posi.y);
	set_material = status[StatusSeachPosi(keep_posi)].m_attribute;
	switch(chara_id)
	{
		case U_ZION:
			switch(set_material)
			{
				case UNDINE:
					use_special_ap1=AP_ICICLE_EDGE;
					break;
				case SYLPH:
					use_special_ap1=AP_MIRAGE_EDGE;
					break;
			}
			break;
		case U_SAHAGIN2:case U_LIZARDMAN2:
			use_special_ap1=6;
			break;
		case U_VAN:
			switch(set_material)
			{
				case SALAMANDER:
					use_special_ap1=AP_BAKUENKEN;
					break;
				case GNOME:
					use_special_ap1=AP_TISAIJIN;
					break;
			}
			break;
		case U_LIZARDMAN3:
			use_special_ap1=5;
			break;
		case U_RIO:
			switch(set_material)
			{
				case SALAMANDER:
					use_special_ap1=AP_BLAZE_BULLET;
					break;
				case UNDINE:
					use_special_ap1=AP_FROZEN_BULLET;
					break;
			}
			break;
	}
	return use_special_ap1;
}

int C_Battle::UseSpecialAP2()
{
	int use_special_ap2;

	chara_id=stage->GetFieldCharacterData(keep_posi.x,keep_posi.y);
	set_material = status[StatusSeachPosi(keep_posi)].m_attribute;
	switch(chara_id)
	{
		case U_ZION:
			switch(set_material)
			{
				case UNDINE:
					use_special_ap2=AP_AQUA_CURE_Z;
					break;
				case SYLPH:
					use_special_ap2=AP_HEEL_WIND;
					break;
			}
			break;
		case U_LIZARDMAN2:
			use_special_ap2=5;
			break;
		case U_VAN:
			switch(set_material)
			{
				case SALAMANDER:
					use_special_ap2=AP_GOUSYORAI;
					break;
				case GNOME:
					use_special_ap2=AP_KOUSYORAI;
					break;
			}
			break;
		case U_LIZARDMAN3:
			use_special_ap2=7;
			break;
		case U_RIO:
			switch(set_material)
			{
				case SALAMANDER:
					use_special_ap2=AP_BURST;
					break;
				case UNDINE:
					use_special_ap2=AP_AQUA_CURE_R;
					break;
			}
			break;
	}
	return use_special_ap2;
}

//�L�����N�^�[�̖h��AP�̒l��Ԃ�
int C_Battle::UseDefenseAP()
{
	int use_defense_ap;
	chara_id=stage->GetFieldCharacterData(locate_cursor_field.x,locate_cursor_field.y);
	switch(chara_id)
	{
		case U_ZION:case U_VAN:case U_LIZARDMAN2:case U_LIZARDMAN3:
			use_defense_ap=3;
			break;
		case U_RIO:
			use_defense_ap=2;
			break;
	}
	return use_defense_ap;
}

void C_Battle::ApRecovery()
{
	if(flag_turn == PLAYER_TURN){
		for(int i = 0;i < stage->GetCharMaxData();i++){
			if(status[i].m_id >= U_SAHAGIN1){
				status[i].m_ap += status[i].m_ap_r;
				if(status[i].m_ap > status[i].m_maxap) { status[i].m_ap = status[i].m_maxap; }
			}
		}
	}
	else{
		for(int i = 0;i < stage->GetCharMaxData();i++){
			if(status[i].m_id < U_SAHAGIN1){
				status[i].m_ap += status[i].m_ap_r;
				if(status[i].m_ap > status[i].m_maxap) { status[i].m_ap = status[i].m_maxap; }
			}
		}
	}
}

void C_Battle::CursorSelectChara(int* key)
{
	static int keep_cursor_posi_id = 0;
	if(key[C_PUSH-1] == C_PUSH){
		if(stage->GetFieldCharacterData(locate_cursor_field.x,locate_cursor_field.y) != 0 && stage->GetFieldCharacterData(locate_cursor_field.x,locate_cursor_field.y) < U_SAHAGIN1){
			keep_cursor_posi_id = status[StatusSeachPosi(locate_cursor_field)].m_id;
			CharSeach(keep_cursor_posi_id,true);
		}
		else{
			keep_cursor_posi_id = status[StatusSeachId(U_ZION)].m_id;
			CharSeach(keep_cursor_posi_id,false);
		}
	}
}

void C_Battle::CharSeach(int keep_cursor_posi_id,bool select_player)
{
	if(select_player){
		if(keep_cursor_posi_id == U_ZION){
			if(status_battle[StatusSeachId(U_VAN)].m_action_end == false){
				locate_cursor_field.x = status_battle[StatusSeachId(U_VAN)].m_pos_chara_x;
				locate_cursor_field.y = status_battle[StatusSeachId(U_VAN)].m_pos_chara_y;
			}
			else{
				if(status_battle[StatusSeachId(U_RIO)].m_action_end == false){
					locate_cursor_field.x = status_battle[StatusSeachId(U_RIO)].m_pos_chara_x;
					locate_cursor_field.y = status_battle[StatusSeachId(U_RIO)].m_pos_chara_y;
				}
			}
		}
		else if(keep_cursor_posi_id == U_VAN){
			if(status_battle[StatusSeachId(U_RIO)].m_action_end == false){
				locate_cursor_field.x = status_battle[StatusSeachId(U_RIO)].m_pos_chara_x;
				locate_cursor_field.y = status_battle[StatusSeachId(U_RIO)].m_pos_chara_y;
			}
			else{
				if(status_battle[StatusSeachId(U_ZION)].m_action_end == false){
					locate_cursor_field.x = status_battle[StatusSeachId(U_ZION)].m_pos_chara_x;
					locate_cursor_field.y = status_battle[StatusSeachId(U_ZION)].m_pos_chara_y;
				}
			}
		}
		else{
			if(status_battle[StatusSeachId(U_ZION)].m_action_end == false){
				locate_cursor_field.x = status_battle[StatusSeachId(U_ZION)].m_pos_chara_x;
				locate_cursor_field.y = status_battle[StatusSeachId(U_ZION)].m_pos_chara_y;
			}
			else{
				if(status_battle[StatusSeachId(U_VAN)].m_action_end == false){
					locate_cursor_field.x = status_battle[StatusSeachId(U_VAN)].m_pos_chara_x;
					locate_cursor_field.y = status_battle[StatusSeachId(U_VAN)].m_pos_chara_y;
				}
			}
		}
	}
	else{
		if(status_battle[StatusSeachId(keep_cursor_posi_id)].m_action_end == false){
			locate_cursor_field.x = status_battle[StatusSeachId(keep_cursor_posi_id)].m_pos_chara_x;
			locate_cursor_field.y = status_battle[StatusSeachId(keep_cursor_posi_id)].m_pos_chara_y;
		}
		else{
			if(status_battle[StatusSeachId(U_VAN)].m_action_end == false){
				locate_cursor_field.x = status_battle[StatusSeachId(U_VAN)].m_pos_chara_x;
				locate_cursor_field.y = status_battle[StatusSeachId(U_VAN)].m_pos_chara_y;
			}
			else{
				if(status_battle[StatusSeachId(U_RIO)].m_action_end == false){
					locate_cursor_field.x = status_battle[StatusSeachId(U_RIO)].m_pos_chara_x;
					locate_cursor_field.y = status_battle[StatusSeachId(U_RIO)].m_pos_chara_y;
				}
			}
		}
	}
}

bool C_Battle::SelectedCommando()
{
	for(int i = 0;i < 3;i++){
		if(flag_char_selected[i] == 1) { return true; }
	}
	return false;
}

//void C_Battle::SahaginAITEST(int*key)
//{
//	if(stage->GetFieldCharacterData(locate_cursor_field.x,locate_cursor_field.y)==U_SAHAGIN1&&flag_any_end==0)
//	{
//		if(flag_any_end==0)
//		{
//			key[Z_PUSH - 1]=true;
//		}
//	}
//}

void C_Battle::EnemyAi(int* key)
{
	static int cnt2 = 0;
	if(status_battle[selectionId].m_id >= U_SAHAGIN1){
		if(status_battle[selectionId].m_battle_impossible != true){
			if(status_battle[selectionId].m_action_end == false){
				if(cnt2 == 0){
					locate_cursor_field.x = status_battle[selectionId].m_pos_chara_x;
					locate_cursor_field.y = status_battle[selectionId].m_pos_chara_y;
				}
				cnt2++;
				if(cnt2 >= 15)//���AI�𓮂����̂ɂP��120�ӂ肪��������
				{
					if(status_battle[selectionId].m_id == U_LIZARDMAN3){
						flag_char_selected[CHAR_MOVE] = 1;
						flag_char_selected[CHAR_ATTACK] = 1;
					}
					if(flag_char_selected[CHAR_MOVE] != 1) { EnemyMove(); }
					else if(flag_char_selected[CHAR_ATTACK] != 1) { EnemyAttack(); }
					else if(flag_char_selected[CHAR_MOVE] == 1 && flag_char_selected[CHAR_ATTACK] == 1){
						flag_char_selected[CHAR_MOVE] = 0;
						flag_char_selected[CHAR_ATTACK] = 0;
						status_battle[selectionId].m_action_end = true;
						selectionId++;
						cnt2 = 0;
					}
				}
			}
			else selectionId++;
		}
		else selectionId++;
	}
	else selectionId++;
	if(selectionId == stage->GetCharMaxData()){ selectionId = 0; }
	EnemyBattleProcess();
}

void C_Battle::EnemyMove()
{
	static int cnt = 0;
	if(cnt == 0){
		stage->AreaSeach(status_battle[selectionId].m_pos_chara_x,status_battle[selectionId].m_pos_chara_y,selectionId,status[selectionId].m_mov,CHAR_MOVE);
	}
	cnt++;
	if(cnt == 15){
		if(stage->GetAreaInfoData(locate_cursor_field.x,locate_cursor_field.y + 1) == 1){
			stage->SetFieldCharacterData(locate_cursor_field,U_BLANK_AREA);
			locate_cursor_field.y += 1;
			status_battle[selectionId].m_direction = LEFT_FLONT;
			stage->SetFieldCharacterData(locate_cursor_field,status[selectionId].m_id);
			cnt = 0;
		}
		else{
			flag_char_selected[CHAR_MOVE] = 1;
			keep_posi = locate_cursor_field;
			status_battle[selectionId].m_pos_chara_x = locate_cursor_field.x;
			status_battle[selectionId].m_pos_chara_y = locate_cursor_field.y;
			stage->AreaDeleat();
			cnt = 0;
		}
	}
}

void C_Battle::EnemyAttack()
{
	if(flag_enemy_atk > 0)	return ;
	static int cnt = 0;
	cnt++;
	if(cnt == 15){
		if(stage->GetFieldCharacterData(locate_cursor_field.x,locate_cursor_field.y+1) < U_SAHAGIN1 && stage->GetFieldCharacterData(locate_cursor_field.x,locate_cursor_field.y+1) != U_BLANK_AREA){
			flag_enemy_atk = 1;
			keep_char_select = stage->IdSeach(locate_cursor_field.x,locate_cursor_field.y) / 10;
			keep_field_id[keep_char_select] = stage->GetFieldCharacterData(locate_cursor_field.x,locate_cursor_field.y);
			keep_posi = locate_cursor_field;
			status_battle[StatusSeachId(keep_field_id[keep_char_select])].m_direction = 0;
			locate_cursor_field.y += 1;
			cnt = 0;
		}
		else if(stage->GetFieldCharacterData(locate_cursor_field.x,locate_cursor_field.y-1) < U_SAHAGIN1 && stage->GetFieldCharacterData(locate_cursor_field.x,locate_cursor_field.y-1) != U_BLANK_AREA){
			flag_enemy_atk = 4;
			keep_char_select = stage->IdSeach(locate_cursor_field.x,locate_cursor_field.y) / 10;
			keep_field_id[keep_char_select] = stage->GetFieldCharacterData(locate_cursor_field.x,locate_cursor_field.y);
			keep_posi = locate_cursor_field;
			status_battle[StatusSeachId(keep_field_id[keep_char_select])].m_direction = 3;
			locate_cursor_field.y -= 1;
			cnt = 0;
		}
		else if(stage->GetFieldCharacterData(locate_cursor_field.x+1,locate_cursor_field.y) < U_SAHAGIN1 && stage->GetFieldCharacterData(locate_cursor_field.x+1,locate_cursor_field.y) != U_BLANK_AREA){
			flag_enemy_atk = 2;
			keep_char_select = stage->IdSeach(locate_cursor_field.x,locate_cursor_field.y) / 10;
			keep_field_id[keep_char_select] = stage->GetFieldCharacterData(locate_cursor_field.x,locate_cursor_field.y);
			keep_posi = locate_cursor_field;
			status_battle[StatusSeachId(keep_field_id[keep_char_select])].m_direction = 2;
			locate_cursor_field.x += 1;
			cnt = 0;
		}
		else if(stage->GetFieldCharacterData(locate_cursor_field.x-1,locate_cursor_field.y) < U_SAHAGIN1 && stage->GetFieldCharacterData(locate_cursor_field.x-1,locate_cursor_field.y) != U_BLANK_AREA){
			flag_enemy_atk = 3;
			keep_char_select = stage->IdSeach(locate_cursor_field.x,locate_cursor_field.y) / 10;
			keep_field_id[keep_char_select] = stage->GetFieldCharacterData(locate_cursor_field.x,locate_cursor_field.y);
			keep_posi = locate_cursor_field;
			status_battle[StatusSeachId(keep_field_id[keep_char_select])].m_direction = 1;
			locate_cursor_field.x -= 1;
			cnt = 0;
		}
		else{
			flag_char_selected[CHAR_ATTACK] = 1;
			cnt = 0;
		}
	}
}

void C_Battle::EnemyBattleProcess()
{
	if(flag_enemy_atk == 0)	return ; //�A�^�b�N���Ă��Ȃ����͖���

	if(hitInit){
		//�f�[�^�Z�b�g
		EnemyBattleDataSet();

		if(! damegeCulc->HitResult( getPlData.status.m_dex, getEnemyData.status.m_agl ) ){	return ; }	//�q�b�g���Ă��Ȃ������珈�����I����
		//�������瓖�������ꍇ�̏���
		hitDamage = (double)damegeCulc->NormalAttackDamage( getPlData.status.m_atk, getEnemyData.status.m_def );
		
		if(hitDamage > 0){		//�_���[�W��1�ȏ゠���
			//�G�̌�������낾������
			if(getPlData.direction == getEnemyData.direction)	hitDamage *= 2.0;
			//�N���e�B�J���v�Z
			hitDamage *= damegeCulc->Critical(getPlData.status.m_luk);
		}else hitDamage = 0;	//�|�_���[�W��0�ɂ���

		charaAttack = true;	//�L�������U����Ԃɂ���B
		enemyAttackCnt = (getPlData.direction + 1 ) * 4;	//�L�����̍U���J�E���g�p
		keepAttackCnt = enemyAttackCnt;
	}

	if(charaAttack){
		if(deray[ keep_field_id[keep_char_select] / 10 - 1 ][ enemyAttackCnt - keepAttackCnt ] <= atkDeray++){
			enemyAttackCnt++; 
			atkDeray = 0;
		}
		if(getPlData.status.m_id < U_LIZARDMAN1){
			if(enemyAttackCnt - keepAttackCnt >= 4)	{ charaAttack = !charaAttack; }
		}
		else{ if(enemyAttackCnt - keepAttackCnt >= 3)	{ charaAttack = !charaAttack; } }
		return;
	}

	if(battleDrawEnd){
		//�U�������Ώۂ�HP�����炷
		SetDamage( StatusSeachId(getEnemyData.status.m_id), (int)hitDamage );

		//�o�g���I������
		BattleEndProcess();
		battleDrawEnd = false;
		hitInit = true;
	}
}

void C_Battle::EnemyBattleDataSet()
{
	//�X�e�[�^�X
	getPlData.status	= status[StatusSeachPosi (keep_posi.x,keep_posi.y)];
	getEnemyData.status	= status[StatusSeachPosi (locate_cursor_field.x,locate_cursor_field.y)];

	//�o�g���f�[�^
	getPlData.direction = status_battle[StatusSeachPosi (keep_posi.x,keep_posi.y)].m_direction;
	getEnemyData.direction	= status_battle[StatusSeachPosi (locate_cursor_field.x,locate_cursor_field.y)].m_direction;

	memset(drawBattleData, 0, sizeof(DrawBattleData) * 3);
}

void C_Battle::BattleSpExtra()
{  
	if(flag_sp_extra == 0) return ;
	if(hitInit){
		stage->AreaDeleat();
		//�f�[�^�Z�b�g
		BattleDataSet();
		//if(flag_sp_extra == 10){
		//	BattleDataSetZion();
		//}

		//if(flag_sp_extra > 10){
			if(! damegeCulc->HitResult( getPlData.status.m_dex, getEnemyData.status.m_agl ) ){	return ; }	//�q�b�g���Ă��Ȃ������珈�����I����
			//�������瓖�������ꍇ�̏���
			if(flag_sp_extra == 30){
				hitDamage = (double)damegeCulc->RioDeDamage( getPlData.status.m_mag );
			}
			else if(flag_sp_extra == 20){
				hitDamage = (double)damegeCulc->VanDamage(getPlData.status.m_atk);
			}
			else{
				hitDamage = (double)damegeCulc->ZionDamage(getPlData.status.m_atk,getEnemyData.status.m_def)*17.0;
			}
			
			if(hitDamage > 0){		//�_���[�W��1�ȏ゠���
				//�G�̌�������낾������
				if(getEnemyData.direction == getPlData.direction)	hitDamage *= 2.0;
				//�N���e�B�J���v�Z
				hitDamage *= damegeCulc->Critical(getPlData.status.m_luk);
			}else hitDamage = 0;	//�|�_���[�W��0�ɂ���
			fade_end = false;
		//}
		//else{
		//	if(! damegeCulc->HitResult( getPlData.status.m_dex,getEnemyData.status.m_agl ) ){ return ; }
		//	for(int i = 0;i < 17;i++){
		//		getenemydatazion[i].hitDamagevan = (double)damegeCulc->ZionDamage(getPlData.status.m_atk,getenemydatazion[i].status.m_def);
		//		if(getenemydatazion[i].hitDamagevan > 0){
		//			if(getenemydatazion[i].direction == getPlData.direction) getenemydatazion[i].hitDamagevan *= 2.0;
		//			getenemydatazion[i].hitDamagevan *= damegeCulc->Critical(getPlData.status.m_luk);
		//		}else getenemydatazion[i].hitDamagevan = 0;
		//		fade_end = false;
		//	}
		//}
	}
	if(!fade_end){
		fade_color += 8;
		if(fade_color > 255){
			fade_color = 0;
			flag_sp_extra_draw = true;
			fade_end = true;
		}
	}
	if(battleDrawEnd){
		//�U�������Ώۂ�HP�����炷
		SetDamage( StatusSeachId(stage->GetFieldCharacterData(locate_cursor_field.x,locate_cursor_field.y)), (int)hitDamage );

		//�o�g���I������
		flag_sp_extra = 0;
		BattleEndProcess();
		battleDrawEnd = false;
		hitInit = true;
		flag_sp_extra_draw = false;
		fade_color = 0;
		sp_end_extra = false;
		status[StatusSeachId(U_ZION)].m_mg = 0;
		status[StatusSeachId(U_ZION)].m_ap = 0;
	}
}

void C_Battle::SpExZionDraw()
{
	static int cnt2 = 0;
	static int cnt3 = 0;
	static int cnt4 = 0;
	static float cnt5 = 0;
	static int cnt6 = 0;
	static int cnt7 = 0;
	static int cnt8 = 0;
	static FIELD_POS zurasi = {0};
	static int change_ef = 0;

	if(cnt_ex_alltime >= 20 && cnt_ex_alltime <= 42){
		fade_black -= 40;
		if(fade_black < 0)	fade_black = 0;
	}
	if(cnt_ex_alltime >= 30 && cnt_ex_alltime <= 90){
		fade_out_black -= 4;
		if(fade_out_black < 0) fade_out_black = 0;
		if(cnt_ex_alltime == 90) flag_black = true;
	}
	else if(cnt_ex_alltime == 100) fade_black = 255;
	else if(cnt_ex_alltime > 100){
		fade_out_black += 4;
		if(fade_out_black > 255){
			fade_out_black = 255;
			if(cnt_ex_alltime%12 == 11){
				cnt2 += 1;
			}
		}
	}

	m_graphics->SetColor(D3DCOLOR_ARGB(fade_color,255,255,255),R_ZION_SP_BG);
	m_graphics->DrawCC(400.f,300.f,m_pTexture[T_ZION_SP_BG],T_ZION_SP_BG,R_ZION_SP_BG);

	m_graphics->DrawCC(stage->GetFieldPositionData(locate_cursor_field).x,stage->GetFieldPositionData(locate_cursor_field).y+charaAttackEfCnt%4,m_pTexture[T_CHAR_SAHAGIN1 + (getEnemyData.status.m_id / 10 - 4)],T_CHAR_SAHAGIN1 + (getEnemyData.status.m_id / 10 - 4),R_CHAR_WAIT_LEFTFRONT);

	if(!flag_black){
		m_graphics->SetColor(D3DCOLOR_ARGB(fade_out_black,fade_black,fade_black,fade_black),R_ZION_WAIT_RB_ATK_2);
		m_graphics->DrawCC(stage->GetFieldPositionData(locate_cursor_field.x,locate_cursor_field.y + 2).x,stage->GetFieldPositionData(locate_cursor_field.x,locate_cursor_field.y + 2).y,m_pTexture[T_CHAR_ZION],T_CHAR_ZION,R_ZION_WAIT_RB_ATK_2);
	}
	else{
		m_graphics->SetColor(D3DCOLOR_ARGB(fade_out_black,fade_black,fade_black,fade_black),R_RIO_WAIT_LF_ATK_4);
		m_graphics->DrawCC(stage->GetFieldPositionData(locate_cursor_field.x,locate_cursor_field.y - 3).x,stage->GetFieldPositionData(locate_cursor_field.x,locate_cursor_field.y - 3).y,m_pTexture[T_CHAR_ZION],T_CHAR_ZION,R_ZION_WAIT_RB_ATK_4);

		if(cnt_ex_alltime > 100){
			//�a����h�炷
			if(cnt_ex_alltime % 5 == 4){cnt6++;} 
			if(cnt6 <= 17){
				switch(cnt6%5){
					case 0:
						zurasi.x = 0.f;
						zurasi.y = 0.f;
						change_ef = 1;
						break;
					case 1:
						//zurasi.x = 10.f;
						//zurasi.y = 0.f;
						zurasi.x = 15.f;
						zurasi.y = -25.f;
						change_ef = 1;
						break;
					case 2:
						//zurasi.x = -10.f;
						//zurasi.y = 0.f;
						zurasi.x = 10.f;
						zurasi.y = 20.f;
						change_ef = 2;
						break;
					case 3:
						//zurasi.x = -10.f;
						//zurasi.y = 10.f;
						zurasi.x = -10.f;
						zurasi.y = 15.f;
						change_ef = 1;
						break;
					case 4:
						//zurasi.x = 10.f;
						//zurasi.y = -10.f;
						zurasi.x = -20.f;
						zurasi.y = -20.f;
						change_ef = 2;
						break;
				}
				switch(cnt_ex_alltime%4){
				case 0:
					m_graphics->SetColor2(0x00FFFFFF,0);
					m_graphics->SetColor2(0x00FFFFFF,1);
					m_graphics->SetColor2(0xFFFFFFFF,2);
					m_graphics->SetColor2(0xFFFFFFFF,3);
					break;
				case 1:
					m_graphics->SetColor2(0x55FFFFFF,0);
					m_graphics->SetColor2(0x55FFFFFF,1);
					m_graphics->SetColor2(0xAAFFFFFF,2);
					m_graphics->SetColor2(0xAAFFFFFF,3);
					break;
				case 2:
					m_graphics->SetColor2(0xAAFFFFFF,0);
					m_graphics->SetColor2(0xAAFFFFFF,1);
					m_graphics->SetColor2(0x55FFFFFF,2);
					m_graphics->SetColor2(0x55FFFFFF,3);
					break;
				case 3:
					m_graphics->SetColor2(0xFFFFFFFF,0);
					m_graphics->SetColor2(0xFFFFFFFF,1);
					m_graphics->SetColor2(0x00FFFFFF,2);
					m_graphics->SetColor2(0x00FFFFFF,3);
					break;
				}
				static int fade_out = 255;
				//�a�����g�債�Ă݂����t�Ɉ�a��(2�{)
				fade_out -= 12;
				if(fade_out < 0) fade_out = 0;
				/*m_graphics->SetSize(2.f,2.f,R_CUT_EF1 + change_ef);*/
				m_graphics->SetColor(D3DCOLOR_ARGB(fade_out,255,255,255),R_SLASH);
				m_graphics->DrawCC(400.f,300.f,m_pTexture[T_SLASH],T_SLASH,R_SLASH);
				m_graphics->DrawCC2(stage->GetFieldPositionData(locate_cursor_field).x+zurasi.x,stage->GetFieldPositionData(locate_cursor_field).y+zurasi.y,m_pTexture[T_ATK_SP_EF],T_ATK_SP_EF,R_CUT_EF1 + change_ef);
				//�a�����g�債�Ă݂�
				/*if(cnt_ex_alltime%8 == 7){
					m_graphics->SetSize(4.f,2.f,R_CUT_EF1);
					m_graphics->DrawCC2(400.f,300.f,m_pTexture[T_ATK_SP_EF],T_ATK_SP_EF,R_CUT_EF1);
				}*/
			}
			static int voice_in = 0;
			if(cnt6 == 0){
				if(voice_in++ == 1){
					flag_sound_ex = true;
					sound_ef_change_ex = 0;
				}
			}
			if(cnt6 == 1){
				voice_in = 0;
			}
			if(cnt6 == 17){
				if(voice_in++ == 1){
					flag_voice_ex = true;
					voice_change_ex = 0;
				}
			}
			charaAttackEfCnt++;
		}
	}
	if(cnt6 == 17 ){
		//flag_sp_draw_off = true;
		//DamegeExtraZion();
	}
	if(cnt_ex_alltime > 200/*flag_zion_num_end*/){
		//flag_sp_draw_off = false;
		m_graphics->SetColor(D3DCOLOR_ARGB(cnt3,255,255,255),R_WHITE_OUT);
		m_graphics->DrawCC(400.f,300.f,m_pTexture[T_WHITE_OUT],T_WHITE_OUT,R_WHITE_OUT);

		cnt3 += 8;
		if(cnt3 > 255) cnt3 = 255;
		//fade_end = false;
		cnt8++;
	}
	if(cnt_ex_alltime > 250){
		cnt_ex_alltime = 0;
		fade_black = 255;
		fade_out_black = 255;
		flag_black = false;
		cnt2 = 0;
		cnt3 = 0;
		cnt4 = 0;
		cnt5 = 0.f;
		cnt6 = 0;
		cnt7 = 0;
		cnt8 = 0;

		flag_sp_extra_draw = false;
		sp_end_extra = true;
		status[StatusSeachId(U_ZION)].m_mg = 0;
		status[StatusSeachId(U_ZION)].m_ap = 0;
		charaAttackEfCnt = 0;
	}
}

void C_Battle::SpExVanDraw()
{
	static int cnt2 = 0;
	static int cnt3 = 0;
	static int cnt4 = 0;
	static float cnt5 = 1.f;
	static int cnt6 = 0;
	static int cnt7 = 0;
	static int cnt8 = 0;
	static int ef_volume = 1;
	static int voice_in = 0;
	static int voice_in2 = 0;
	if(cnt_ex_alltime > 60){
		if(cnt_ex_alltime% 12 == 11){
			if(cnt4 < 14){
				cnt2++;
			}
		}
	}
	if(cnt2 > 0)cnt4++;
	m_graphics->SetColor(D3DCOLOR_ARGB(fade_color,255,255,255),R_VAN_SP_BG);
	m_graphics->DrawCC(400.f,300.f,m_pTexture[T_VAN_SP_BG],T_VAN_SP_BG,R_VAN_SP_BG);

	m_graphics->DrawCC(stage->GetFieldPositionData(locate_cursor_field).x,stage->GetFieldPositionData(locate_cursor_field).y + charaAttackEfCnt%4,m_pTexture[T_CHAR_SAHAGIN1 + (getEnemyData.status.m_id / 10 - 4)],T_CHAR_SAHAGIN1 + (getEnemyData.status.m_id / 10 - 4),R_CHAR_WAIT_LEFTFRONT);

	if(cnt4 == 0){
		m_graphics->DrawCC(stage->GetFieldPositionData(locate_cursor_field.x,locate_cursor_field.y + 2).x,stage->GetFieldPositionData(locate_cursor_field.x,locate_cursor_field.y + 2).y,m_pTexture[T_CHAR_VAN],T_CHAR_VAN,R_VAN_WAIT_RB_ATK_2 + cnt2%3);
		if(voice_in++ == 1){
			flag_voice_ex = true;
			voice_change_ex = 1;
		}
	}
	else{
		if(voice_in2++ == 1){
			flag_sound_ex = true;
			sound_ef_change_ex = 1;
		}
		if(cnt_ex_alltime > 100){
			if(cnt_ex_alltime%4 == 3){cnt6++;}
			/*if(cnt6%4 == 3){
				ef_volume++;
			}*/
			for(int i = -1;i < 2;i++){
				for(int j = -1;j < 2;j++){
				/*m_graphics->DrawCC(stage->GetFieldPositionData(locate_cursor_field).x + (float)((cnt6%2+1) * (cnt6%4 < 2 ? cnt6%2*(cnt6%10+10): -1*cnt6%2*(cnt6%10+5))*(ef_volume%4)),stage->GetFieldPositionData(locate_cursor_field).y + (float)((cnt6%2+1) * (cnt6%8 < 4 ? cnt6%2*(cnt6%10+10): -1*cnt6%2*(cnt6%10+5))*(ef_volume%4)),m_pTexture[T_ATK_SP_EF],T_ATK_SP_EF,R_EXPLODE1 + cnt6%4);*/
					//if(i == 0 && j == 0);
					//else{
					m_graphics->DrawCC(stage->GetFieldPositionData(locate_cursor_field.x + i,locate_cursor_field.y + j).x - 10.f/*(float)((cnt6%2+1) * (cnt6%4 < 2 ? cnt6%2*(cnt6%10+10): -1*cnt6%2*(cnt6%10+5))*(ef_volume%4))*/,stage->GetFieldPositionData(locate_cursor_field.x + i,locate_cursor_field.y + j).y - 10.f/*(float)((cnt6%2+1) * (cnt6%8 < 4 ? cnt6%2*(cnt6%10+10): -1*cnt6%2*(cnt6%10+5))*(ef_volume%4))*/,m_pTexture[T_ATK_EF],T_ATK_EF,R_BAKUEN1 + cnt6%5);
					charaAttackEfCnt++;
					//}
				}
			}
		}
		m_graphics->DrawCC(stage->GetFieldPositionData(locate_cursor_field.x,locate_cursor_field.y + 2 -1).x,stage->GetFieldPositionData(locate_cursor_field.x,locate_cursor_field.y + 2).y,m_pTexture[T_CHAR_VAN],T_CHAR_VAN,R_VAN_WAIT_RB_ATK_2 + cnt2%3);
	}
	if(cnt_ex_alltime > 180){
		if(cnt3 == 255){
			m_graphics->SetSize(cnt5 += 0.5,cnt5 += 0.5,R_WHITE_OUT_VAN);
		}
		m_graphics->SetColor(D3DCOLOR_ARGB(cnt3,255,255,255),R_WHITE_OUT_VAN);
		m_graphics->DrawCC(400.f,300.f,m_pTexture[T_WHITE_OUT_VAN],T_WHITE_OUT_VAN,R_WHITE_OUT_VAN);
		cnt3 += 8;
		if(cnt3 > 255) cnt3 = 255;
		//fade_end = false;
	}
	if(cnt_ex_alltime > 280){
		cnt_ex_alltime = 0;
		fade_black = 255;
		fade_out_black = 255;
		flag_black = false;
		cnt2 = 0;
		cnt3 = 0;
		cnt4 = 0;
		cnt5 = 0.f;
		cnt6 = 0;
		cnt7 = 0;
		cnt8 = 0;

		flag_sp_extra_draw = false;
		sp_end_extra = true;
		status[StatusSeachId(U_VAN)].m_mg = 0;
		status[StatusSeachId(U_VAN)].m_ap = 0;
		charaAttackEfCnt = 0;
	}
}

void C_Battle::SpExRioDraw()
{
	static int cnt2 = 0;
	static int cnt3 = 0;
	static int cnt4 = 0;
	static FIELD_POS zurasi = {0.f};
	//static int cnt6 = 0;
	//static int cnt7 = 0;
	//static int cnt8 = 0;
	if(cnt_ex_alltime >= 20 && cnt_ex_alltime <= 42){
		fade_black -= 40;
		if(fade_black < 0)	fade_black = 0;
	}
	if(cnt_ex_alltime >= 30 && cnt_ex_alltime <= 90){
		fade_out_black -= 4;
		if(fade_out_black < 0) fade_out_black = 0;
		if(cnt_ex_alltime == 90) flag_black = true;
	}
	else if(cnt_ex_alltime == 100) fade_black = 255;
	else if(cnt_ex_alltime > 100){
		fade_out_black += 4;
		if(fade_out_black > 255){
			fade_out_black = 255;
			if(cnt_ex_alltime%12 == 11){
				cnt2++;
				static int voice_in = 0;
				if(voice_in++ == 1){
					flag_sound_ex = true;
					sound_ef_change_ex = 2;
				}
			}
			if(cnt_ex_alltime%3 == 2){
				cnt4++;
			}
		}
	}
	m_graphics->SetColor(D3DCOLOR_ARGB(fade_color,255,255,255),R_RIO_SP_BG);
	m_graphics->DrawCC(400.f,300.f,m_pTexture[T_RIO_SP_BG],T_RIO_SP_BG,R_RIO_SP_BG);
	m_graphics->DrawCC(stage->GetFieldPositionData(locate_cursor_field).x,stage->GetFieldPositionData(locate_cursor_field).y + charaAttackEfCnt%4,m_pTexture[T_CHAR_SAHAGIN1 + (getEnemyData.status.m_id / 10 - 4)],T_CHAR_SAHAGIN1 + (getEnemyData.status.m_id / 10 - 4),R_CHAR_WAIT_LEFTFRONT);
	if(!flag_black){
		m_graphics->SetColor(D3DCOLOR_ARGB(fade_out_black,fade_black,fade_black,fade_black),R_RIO_WAIT_RB_ATK_2);
		m_graphics->DrawCC(stage->GetFieldPositionData(locate_cursor_field).x - 150.f,stage->GetFieldPositionData(locate_cursor_field).y + 75.f,m_pTexture[T_CHAR_RIO],T_CHAR_RIO,R_RIO_WAIT_RB_ATK_2);
	}
	else{
		for(int i = 0;i < 4;i++){
			m_graphics->SetColor(D3DCOLOR_ARGB(fade_out_black,fade_black,fade_black,fade_black),R_RIO_WAIT_LF_ATK_2 + i * 4);
		}
		m_graphics->DrawCC(stage->GetFieldPositionData(locate_cursor_field).x - 200.f,stage->GetFieldPositionData(locate_cursor_field).y + 150.f,m_pTexture[T_CHAR_RIO],T_CHAR_RIO,R_RIO_WAIT_RB_ATK_2 + cnt2%2);
		m_graphics->DrawCC(stage->GetFieldPositionData(locate_cursor_field).x + 200.f,stage->GetFieldPositionData(locate_cursor_field).y - 150.f,m_pTexture[T_CHAR_RIO],T_CHAR_RIO,R_RIO_WAIT_LF_ATK_2 + cnt2%2);
		m_graphics->DrawCC(stage->GetFieldPositionData(locate_cursor_field).x + 200.f,stage->GetFieldPositionData(locate_cursor_field).y + 150.f,m_pTexture[T_CHAR_RIO],T_CHAR_RIO,R_RIO_WAIT_LB_ATK_2 + cnt2%2);
		m_graphics->DrawCC(stage->GetFieldPositionData(locate_cursor_field).x - 200.f,stage->GetFieldPositionData(locate_cursor_field).y - 150.f,m_pTexture[T_CHAR_RIO],T_CHAR_RIO,R_RIO_WAIT_RF_ATK_2 + cnt2%2);
		if(cnt_ex_alltime > 160){
			switch(cnt4%8){
				case 3:
					zurasi.x = 0.f;
					zurasi.y = 0.f;
					break;
				/*case 7:
					zurasi.x = -10*/
			}
			m_graphics->DrawCC(stage->GetFieldPositionData(locate_cursor_field).x,stage->GetFieldPositionData(locate_cursor_field).y,m_pTexture[T_ATK_EF],T_ATK_EF,R_RIO_JUGEKI1 + cnt4%4);
			charaAttackEfCnt++;
		}
	}
	if(cnt_ex_alltime > 240){
		m_graphics->SetColor(D3DCOLOR_ARGB(cnt3,255,255,255),R_WHITE_OUT);
		m_graphics->DrawCC(400.f,300.f,m_pTexture[T_WHITE_OUT],T_WHITE_OUT,R_WHITE_OUT);
		cnt3 += 8;
		if(cnt3 > 255) cnt3 = 255;
		//fade_end = false;
	}
	if(cnt_ex_alltime > 300){
		cnt_ex_alltime = 0;
		fade_black = 255;
		fade_out_black = 255;
		flag_black = false;
		cnt2 = 0;
		cnt3 = 0;
		cnt4 = 0;
		//cnt5 = 0.f;
		//cnt6 = 0;
		//cnt7 = 0;
		//cnt8 = 0;
		charaAttackEfCnt = 0;

		flag_sp_extra_draw = false;
		sp_end_extra = true;
		status[StatusSeachId(U_RIO)].m_mg = 0;
		status[StatusSeachId(U_RIO)].m_ap = 0;
	}
}

void C_Battle::BattleSpExtradraw()
{
	//static int cnt = 0;
	//static int fade_black = 255;
	//static int fade_out_black = 255;
	//static bool flag_black = false;
	//static int cnt2 = 0;
	//static int cnt3 = 0;
	//static int cnt4 = 0;
	//static float cnt5 = 0.f;
	//static int cnt6 = 0;
	//static int cnt7 = 0;
	//static int cnt8 = 0;

	if(fade_end){
		if(fade_color < 255) { fade_color += 4; }
		if(fade_color > 255) {
			fade_color = 255; 
		}
		if(fade_color >= 255) {cnt_ex_alltime++;}
	}
	if(flag_sp_extra_draw){
		//�V�I��
		if(flag_sp_extra == U_ZION){
			SpExZionDraw();
		}
		//���@��
		else if(flag_sp_extra == U_VAN){
			SpExVanDraw();
		}
		//���I
		else if(flag_sp_extra == U_RIO){
			SpExRioDraw();
		}
	}
}

void C_Battle::DamegeExtra()
{
	if(flag_sp_extra == 0) return ;
	/*if(flag_sp_extra == 1) return ;*/

	//if(flag_sp_extra == 10){
	//	if(hitInit){
	//		for(int j = 0; j < 17;j++){
	//			for(int i = 0, num = (int)getenemydatazion[j].hitDamagevan; i < 3; i++, num /= 10){
	//				drawSpZionData[j][2 - i].damage = num % 10;
	//				drawSpZionData[j][2 - i].move = 20;
	//				drawSpZionData[j][2 - i].act = false;
	//				drawSpZionData[j][2 - i].posX = stage->GetFieldPositionData(locate_cursor_field.x,locate_cursor_field.y).x - 50.f;
	//				drawSpZionData[j][2 - i].posY = stage->GetFieldPositionData(locate_cursor_field.x,locate_cursor_field.y).y - 60.f;

	//				if(num == 0) break;
	//			}
	//			drawSpZionData[j][2 - (int)log10(getenemydatazion[j].hitDamagevan)].act = true;
	//			hitInit = false;
	//		}
	//	}
	//}
	//else{
		if(hitInit){
			for(int i = 0, num = (int)hitDamage; i < 3; i++, num /= 10){
				drawBattleData[2 - i].damage = num % 10;
				drawBattleData[2 - i].move = 20;
				drawBattleData[2 - i].act = false;
				drawBattleData[2 - i].posX = stage->GetFieldPositionData(locate_cursor_field.x,locate_cursor_field.y).x + (2 - i) * 30.f - 50.f;
				drawBattleData[2 - i].posY = stage->GetFieldPositionData(locate_cursor_field.x,locate_cursor_field.y).y - 60.f;

				if(num == 0) break;
			}
			drawBattleData[2 - (int)log10(hitDamage)].act = true;
			hitInit = false;
		}
	//}

	if(!sp_end_extra) return; //�L�������[�V�������͉��̏����͂��Ȃ�
	//if(flag_sp_extra == 10) return ;

	int num = (int)hitDamage;
	int loop = 0;
	static int cnt = 0;

	m_graphics->SetColor(D3DCOLOR_ARGB(255,255,255,255),R_STATUS_NUM100);
	do{
		m_graphics->SetPostion(rect_battle[R_STATUS_NUM100].top,rect_battle[R_STATUS_NUM100].left + 30.f * drawBattleData[2 - loop].damage ,rect_battle[R_STATUS_NUM100].bottom,rect_battle[R_STATUS_NUM100].right + 30.f * (num % 10),R_STATUS_NUM100);
		m_graphics->DrawCC(drawBattleData[2 - loop].posX,drawBattleData[2 - loop].posY - drawBattleData[2 - loop].move,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_NUM100);
		if(drawBattleData[2 - loop].move > 0 && drawBattleData[2 - loop].act) drawBattleData[2 - loop].move -= 5;
		else if(drawBattleData[loop].move <= 0 && loop <= 2) drawBattleData[loop+1].act = true;

		if(drawBattleData[2].move <= 0){
			if(cnt++ == 60){
				cnt = 0;
				battleDrawEnd = true;
			}
		}
		num /= 10;
		loop++;
	}while(num > 0);
}

void C_Battle::DamegeExtraZion()
{
	//if(flag_sp_extra != 10) return ;
	//static int cnt = 0;

	//if(!flag_sp_draw_off) return; //�L�������[�V�������͉��̏����͂��Ȃ�

	//int num = 0;
	//int loop = 0;
	//static int cnt2 = 0;

	//m_graphics->SetColor(D3DCOLOR_ARGB(255,255,255,255),R_STATUS_NUM100);
	//num = (int)getEnemydatavan[cnt2].hitDamagevan;
	//do{
	//	m_graphics->SetPostion(rect_battle[R_STATUS_NUM100].top,rect_battle[R_STATUS_NUM100].left + 30.f * drawBattleVanData[cnt2][2 - loop].damage ,rect_battle[R_STATUS_NUM100].bottom,rect_battle[R_STATUS_NUM100].right + 30.f * (num % 10),R_STATUS_NUM100);
	//	m_graphics->DrawCC(drawBattleVanData[cnt2][2 - loop].posX,drawBattleVanData[cnt2][2 - loop].posY - drawBattleVanData[cnt2][2 - loop].move,m_pTexture[T_STATUS_FC],T_STATUS_FC,R_STATUS_NUM100);
	//	if(drawBattleVanData[cnt2][2 - loop].move > 0 && drawBattleVanData[cnt2][2 - loop].act) drawBattleVanData[cnt2][2 - loop].move -= 5;
	//	else if(drawBattleVanData[cnt2][loop].move <= 0 && loop <= 2) drawBattleVanData[cnt2][loop+1].act = true;

	//	if(drawBattleVanData[cnt2][2].move <= 0){
	//		if(cnt2++ == 30){
	//			cnt++;
	//			cnt2 = 0;
	//		}
	//	}
	//	num /= 10;
	//	loop++;
	//}while(num > 0);
	//if(cnt2 == 17){
	//	flag_zion_num_end = true;
	//	cnt2 = 0;
	//}
}

void C_Battle::BattleDataSetZion()
{
	////�v���C���[�̃X�e�[�^�X�E�o�g���f�[�^
	//getPlData.status	= status[StatusSeachId( keep_field_id[keep_char_select] ) ];
	//getPlData.direction	= status_battle[StatusSeachId( keep_field_id[keep_char_select] ) ].m_direction;

	//memset(drawBattleVanData, 0, sizeof(DrawBattleData) * 3 * 12);

	//for(int i = 0;i < 17;i++){
	//	getenemydatazion[i].status = status[StatusSeachId(stage->GetFieldCharacterData(locate_cursor_field.x,locate_cursor_field.y))];
	//	getenemydatazion[i].direction = status_battle[StatusSeachId(stage->GetFieldCharacterData(locate_cursor_field.x,locate_cursor_field.y))].m_direction;
	//}
}