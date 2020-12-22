//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "DxLib.h"
#include "stdlib.h"

//########## �}�N����` ##########
#define GAME_WIDTH			608	//��ʂ̉��̑傫��
#define GAME_HEIGHT			480	//��ʂ̏c�̑傫��
#define GAME_COLOR			32	//��ʂ̃J���[�r�b�g

#define GAME_WINDOW_BAR		0					//�^�C�g���o�[�̓f�t�H���g�ɂ���
#define GAME_WINDOW_NAME	"Two for One"		//�E�B���h�E�̃^�C�g��

//#define FONT_PATH_MAX      255//255�����܂�
//
//#define FONT_PIX_PATH     TEXT(".\\FONT\\PixelMplus10-Bold.ttf")
//#define FONT_PIX_NAME     TEXT("PixelMplus10")
//
//#define FONT_INSTALL_ERR_TITLE    TEXT("�t�H���g�C���X�g�[���G���[")
//#define FONT_CREATE_ERR_TITLE     TEXT("�t�H���g�쐬�G���[")

//�L�[�{�[�h�̎��
#define KEY_CODE_KIND		256	//256���

//�p�X�̒���
#define PATH_MAX			255	//255�����܂�
#define NAME_MAX			255	//255�����܂�

//�G���[���b�Z�[�W
#define IMAGE_LOAD_ERR_TITLE	TEXT("�摜�ǂݍ��݃G���[")
#define IMAGE_LOAD_ERR_END	    TEXT("�摜�ǂݍ��݃G���[")

//�摜�̃p�X
#define IMAGE_player_A_PATH		    TEXT(".\\IMAGE\\player_A.png")	    //�v���C���[A�̉摜
#define IMAGE_player_B_PATH		    TEXT(".\\IMAGE\\player_B.png")	    //�v���C���[B�̉摜
#define IMAGE_enemy_1_PATH		    TEXT(".\\IMAGE\\enemy1.png")	    //�G�P�̉摜
#define IMAGE_enemy_2_PATH		    TEXT(".\\IMAGE\\enemy2.png")	    //�G�Q�̉摜
#define IMAGE_enemy_3_PATH		    TEXT(".\\IMAGE\\enemy3.png")	    //�G�R�̉摜
#define IMAGE_TITLE_BK_PATH			TEXT(".\\IMAGE\\titleBK.png")		//�^�C�g���w�i�̉摜
#define IMAGE_TITLE_ROGO_PATH		TEXT(".\\IMAGE\\title_rogo.png")	//�^�C�g�����S�̉摜
#define IMAGE_TITLE_START_PATH		TEXT(".\\IMAGE\\title_button.png")	//�^�C�g���X�^�[�g�̉摜

//�}�b�v�̏��
#define GAME_FLOOR_MAX      2   //�t���A�̐�
#define GAME_MAP_TATE_MAX	15	//�}�b�v�̏c�̐�
#define GAME_MAP_YOKO_MAX	19	//�}�b�v�̉��̐�
#define GAME_MAP_KIND_MAX	1	//�}�b�v�̎�ނ̐�
#define GAME_MAP_PATH			TEXT(".\\IMAGE\\MAP\\mapchip.png")		//�}�b�v�̉摜
#define MAP_DIV_WIDTH		32	//�摜�𕪊����镝�T�C�Y
#define MAP_DIV_HEIGHT		32	//�摜�𕪊����鍂���T�C�Y
#define MAP_DIV_TATE		18	//�摜���c�ɕ������鐔
#define MAP_DIV_YOKO		2	//�摜�����ɕ������鐔
#define MAP_DIV_NUM	MAP_DIV_TATE * MAP_DIV_YOKO	//�摜�𕪊����鑍��

//�G���[���b�Z�[�W
#define START_ERR_TITLE		    TEXT("�X�^�[�g�ʒu�G���[")
#define START_ERR_CAPTION_A	    TEXT("A�̃X�^�[�g�ʒu�����܂��Ă��܂���")
#define START_ERR_CAPTION_B     TEXT("B�̃X�^�[�g�ʒu�����܂��Ă��܂���")
#define START_ERR_CAPTION_E1	TEXT("�G1�̃X�^�[�g�ʒu�����܂��Ă��܂���")
#define START_ERR_CAPTION_E2	TEXT("�G2�̃X�^�[�g�ʒu�����܂��Ă��܂���")
#define START_ERR_CAPTION_E3	TEXT("�G2�̃X�^�[�g�ʒu�����܂��Ă��܂���")


#define GOAL_ERR_TITLE      TEXT("�S�[���ʒu�G���[")
#define GOAL_ERR_CAPTION_A  TEXT("A�̃S�[���ʒu�����܂��Ă��܂���")
#define GOAL_ERR_CAPTION_B  TEXT("B�̃S�[���ʒu�����܂��Ă��܂���")

//���S�摜����p
#define IMAGE_TITLE_ROGO_ROTA		0.01		//�g�嗦
#define IMAGE_TITLE_ROGO_ROTA_MAX	1.0			//�g�嗦MAX
#define IMAGE_TITLE_ROGO_X_SPEED	1			//X�ړ����x
#define IMAGE_TITLE_START_CNT		1			//�_�ŃJ�E���^
#define IMAGE_TITLE_START_CNT_MAX	80			//�_�ŃJ�E���^MAX

//�G���h�R���v��ʗp
#define IMAGE_END_COMP_PATH        TEXT(".\\IMAGE\\mission_complete.png") //�G���h�R���v���S�摜
#define IMAGE_TITLE_END_PATH		TEXT(".\\IMAGE\\end_button.png")	//�G���h�{�^���̉摜
#define IMAGE_END_COMP_CNT         1       //�_�ŃJ�E���^
#define IMAGE_END_COMP_CNT_MAX     80      //�_�ŃJ�E���^MAX(�_�ł̑���)

//�L�����摜����p
#define IMAGE_DIV_WIDTH    32
#define IMAGE_DIV_HEIGHT   32

#define IMAGE_DIV_TATE     2
#define IMAGE_DIV_YOKO     4

#define IMAGE_DIV_NUM      IMAGE_DIV_TATE * IMAGE_DIV_YOKO

//�G���[���b�Z�[�W
#define MUSIC_LOAD_ERR_TITLE	   TEXT("���y�ǂݍ��݃G���[")

//BGM�p�X�w��
#define MUSIC_BGM_PATH              TEXT(".\\MUSIC\\play_BGM.mp3")                  //�v���C��ʂ�BGM
#define MUSIC_BGM_TITLE_PATH		TEXT(".\\MUSIC\\title_BGM.mp3")	                //�^�C�g����BGM
#define MUSIC_BGM_COMP_PATH			TEXT(".\\MUSIC\\end_BGM.mp3")				    //�R���v���[�gBGM
#define MUSIC_BGM_FAIL_PATH			TEXT(".\\MUSIC\\�q���̖�.mp3")					//�t�H�[���gBGM
#define MUSIC_SE_ATACK_PATH         TEXT(".\\MUSIC\\Atack.mp3")                     //�U����
#define MUSIC_SE_SWITCH_PATH        TEXT(".\\MUSIC\\SwitchOn.mp3")                  //�X�C�b�`��
#define MUSIC_SE_KEY_PATH           TEXT(".\\MUSIC\\KeyGet.mp3")                    //�����艹
#define MUSIC_SE_WEAPON_PATH        TEXT(".\\MUSIC\\WeaponGet.mp3")                 //������艹

//BGM����
#define MUSIC_VOLUME             0   //BGM�̉��ʁi0~100�j
//����{�^�����������Ƃ�
#define MSG_CLOSE_TITLE			TEXT("�I�����b�Z�[�W")
#define MSG_CLOSE_CAPTION		TEXT("�Q�[�����I�����܂����H")

//�f�o�b�O���[�h�̃I���I�t�iON:�I���@OFF:�I�t�j
#define DEBUG   TEXT("OFF")

//�����蔻��̑Ώۂ̎���
#define TRUE_t     0
#define TRUE_k     1
#define TRUE_s1    6
#define TRUE_m1    7
#define TRUE_s2    8
#define TRUE_m2    9
#define TRUE_ag    3
#define TRUE_bg    5
#define TRUE_s3    10
#define TRUE_m3    11
#define TRUE_s4    12
#define TRUE_m4    13
#define TRUE_ki    14
#define TRUE_kl    15
#define TRUE_br    16
#define TRUE_sp    17
#define TRUE_ca    18
#define TRUE_st    19
#define TRUE_w1    20
#define TRUE_w2    21
#define TRUE_e1    22
#define TRUE_e2    23
#define TRUE_e3    24

//�X�C�b�`�������ꂽ���ǂ����̎��ʁi1:�����ꂽ�@0:������ĂȂ��j
int s1_check = 0;  //�X�C�b�`1�p
int s2_check = 0;  //�X�C�b�`2�p
int s3_check = 0;  //�X�C�b�`3�p
int s4_check = 0;  //�X�C�b�`4�p

//�����Ƃ��Ă��邩�ǂ����̎��ʁi1:����Ă���@0:����Ă��Ȃ��j
int ki_check = 0;

//������Ƃ��Ă��邩�ǂ����̎��ʁi1:����Ă���@0:����Ă��Ȃ��j
int br_check = 0;
int sp_check = 0;
int ca_check = 0;

//���ǂ̊K�w�ɂ��邩�̎��ʁi1:�ʊK�w 0:�����K�w�j
int fl_check = 0;

//�t���A���ړ��������ǂ����̎��ʁi1:�ړ����� 0:�ړ����Ă��Ȃ��j
int move_floor = 0;

//���񂾂��ǂ����̎��ʁi1:�����Ă�@0:����ł�j
int player_live = 1;
int enemy1_live = 1;
int enemy2_live = 1;
int enemy3_live = 1;

//�G�̍s���p�����_����
int enemy1_rand = 0;
int enemy2_rand = 0;
int enemy3_rand = 0;

enum GAME_MAP_KIND
{
	n = -1,	//(NONE)����
	k = 1,	 //��
	t = 0,	 //�ʘH
	as = 2,	 //�v���C���[A�X�^�[�g
    ag = 3,	 //�v���C���[A�S�[��
	bs = 4,  //�v���C���[B�X�^�[�g
	bg = 5,  //�v���C���[B�S�[��
	s1 = 6,  //�X�C�b�`1
	m1 = 7,  //�M�~�b�N1
	s2 = 8,  //�X�C�b�`2
	m2 = 9,  //�M�~�b�N2
	s3 = 10, //�X�C�b�`3
	m3 = 11, //�M�~�b�N3
	s4 = 12, //�X�C�b�`4
	m4 = 13, //�M�~�b�N4
	ki = 14, //���A�C�e��
	kl = 15, //����
	br = 16, //��
	sp = 17, //��
	ca = 18, //��
	st = 23, //�K�i
	w1 = 24, //���[�v�����P
	w2 = 25, //���[�v�����Q
	e1 = 26, //�G�P�X�^�[�g
	e2 = 27, //�G�Q�X�^�[�g
	e3 = 28  //�G�R�X�^�[�g
};	//�}�b�v�̎��

enum GAME_SCENE {
	GAME_SCENE_START,
	GAME_SCENE_PLAY,
	GAME_SCENE_OVER,
	GAME_SCENE_END,
};	//�Q�[���̃V�[��

//int�^��POINT�\����
typedef struct STRUCT_I_POINT
{
	int x = 0;	//���W��������
	int y = 0;	//���W��������
}iPOINT;

typedef struct STRUCT_IMAGE
{
	char path[PATH_MAX];		//�p�X
	int handle;					//�n���h��
	int x;				    //X�ʒu
	int y;					//Y�ʒu
	int width;					//��
	int height;					//����
	BOOL IsDraw = FALSE;		//�`��ł��邩
}IMAGE;	//�摜�\����

typedef struct STRUCT_CHARA
{
	IMAGE image;				//IMAGE�\����
	RECT coll;
	iPOINT collBeforePt;

}CHARA;	//�v���C���[�A�G�̍\����

typedef struct STRUCT_MAP_IMAGE
{
	char path[PATH_MAX];				//�p�X
	int handle[MAP_DIV_NUM];			//���������}�b�v�̉摜�n���h�����擾
	int kind[MAP_DIV_NUM];				//�}�b�v�̎��
	int width;							//��
	int height;							//����
}MAPCHIP;	//MAP_IMAGE�\����

typedef struct STRUCT_MAP
{
	GAME_MAP_KIND kind;			//�}�b�v�̎��
	int x;						//X�ʒu
	int y;						//Y�ʒu
	int width;					//��
	int height;					//����
}MAP;	//MAP�\����

typedef struct STRUCT_IMAGE_ROTA
{
	IMAGE image;		//IMAGE�\����
	double angle;		//��]��
	double angleMAX;	//��]��MAX
	double rate;		//�g�嗦
	double rateMAX;		//�g�嗦MAX
}IMAGE_ROTA;	//��]�g�傷��摜�̍\����

typedef struct STRUCT_IMAGE_BLINK
{
	IMAGE image;		//IMAGE�\����
	int Cnt;			//�_�ŃJ�E���^
	int CntMAX;			//�_�ł��鎞��MAX
	BOOL IsDraw;		//�`��ł��邩�H
}IMAGE_BLINK;  //�_�ł���摜�̍\����

typedef struct STRUCT_MUSIC
{
	char path[PATH_MAX];		//�p�X
	int handle;					//�n���h��
}MUSIC;//���y�\����

//�Q�[���֘A
int GameScene;		//�Q�[���V�[�����Ǘ�

IMAGE       ImageTitleBK;               //�^�C�g���w�i�̉摜
IMAGE_ROTA  ImageTitleROGO;             //�^�C�g�����S�̉摜
IMAGE_BLINK ImageTitleSTART;            //�^�C�g���X�^�[�g�̉摜

IMAGE_BLINK ImageEndCOMP;              //�G���h�R���v�̉摜
IMAGE_BLINK ImageTitleEND;             //�G���h�{�^���̉摜

//���y�֘A
MUSIC BGM;  //�Q�[����BGM
MUSIC BGM_TITLE;	//�^�C�g����BGM
MUSIC BGM_COMP;		//�R���v���[�g��BGM
MUSIC BGM_FAIL;		//�t�H�[���g��BGM
MUSIC SE_ATACK;     //�U����SE
MUSIC SE_SWITCH;    //�X�C�b�`��SE
MUSIC SE_KEY;       //�������SE
MUSIC SE_WEAPON;    //��������SE

//�摜�֘A
IMAGE ImageBack;
CHARA player_A;		//�v���C���[A
CHARA player_B;		//�v���C���[B
CHARA enemy_1;
CHARA enemy_2;
CHARA enemy_3;

GAME_MAP_KIND mapDatafirst[GAME_FLOOR_MAX][GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX]
{ 
	{
	//  0 ,1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,0 ,1 ,2 ,3 ,4 ,5 ,6 ,7 ,8

		k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k,	//0

		k ,w1,k ,k ,k ,k ,k ,e1,s3,k ,s4,k ,t ,t ,t ,t ,t ,t ,k,	//1

		k ,t ,t ,t ,t ,t ,t ,t ,k ,k ,ca,e2,t ,k ,k ,k ,k ,t ,k,	//2

		k ,k ,k ,m2,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,t ,w2,k ,t ,k,	//3

		k ,t ,t ,t ,t ,t ,t ,t ,k ,k ,t ,k ,t ,t ,t ,t ,t ,t ,k,	//4

		k ,t ,k ,k ,k ,k ,k ,t ,k ,k ,t ,m1,t ,k ,k ,k ,k ,k ,k,	//5

		k ,t ,k ,t ,t ,t ,t ,t ,t ,k ,t ,k ,t ,t ,t ,t ,t ,k ,k,	//6

		k ,s1,k ,t ,k ,k ,k ,k ,k ,k ,br,k ,k ,k ,k ,k ,t ,k ,k,	//7

		k ,k ,k ,t ,k ,k ,t ,t ,t ,k ,s2,k ,ki,t ,t ,k ,t ,k ,k,	//8

		k ,st,sp,t ,t ,t ,t ,k ,t ,k ,k ,k ,t ,k ,t ,k ,t ,k ,k,	//9

		k ,k ,k ,k ,k ,k ,k ,k ,t ,k ,t ,m3,t ,k ,t ,k ,kl,k ,k,	//10

		k ,t ,t ,t ,t ,t ,t ,t ,t ,k ,t ,k ,t ,k ,t ,t ,t ,st,k,	//11

		k ,t ,k ,m4,k ,k ,k ,k ,k ,k ,t ,k ,t ,k ,k ,k ,k ,k ,k,	//12

		k ,as,k ,t ,t ,t ,t ,e3,ag,k ,bg,k ,t ,t ,t ,t ,t ,bs,k,	//13

		k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k		//14
	},
	{
		//  0 ,1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,0 ,1 ,2 ,3 ,4 ,5 ,6 ,7 ,8

			k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k,	//0

			k ,t ,k ,k ,k ,k ,k ,t ,t ,k ,t ,k ,t ,t ,t ,t ,t ,t ,k,	//1

			k ,t ,t ,t ,t ,t ,t ,t ,k ,k ,t ,t ,t ,k ,k ,k ,k ,t ,k,	//2

			k ,k ,k ,t ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,t ,t ,k ,t ,k,	//3

			k ,t ,t ,t ,t ,t ,t ,t ,k ,k ,t ,k ,t ,t ,t ,t ,t ,t ,k,	//4

			k ,t ,k ,k ,k ,k ,k ,t ,k ,k ,t ,t ,t ,k ,k ,k ,k ,k ,k,	//5

			k ,t ,k ,t ,t ,t ,t ,t ,t ,k ,t ,k ,t ,t ,t ,t ,t ,k ,k,	//6

			k ,t ,k ,t ,k ,k ,k ,k ,k ,k ,t ,k ,k ,k ,k ,k ,t ,k ,k,	//7

			k ,k ,k ,t ,k ,k ,t ,t ,t ,k ,t ,k ,t ,t ,t ,k ,t ,k ,k,	//8

			k ,st,t ,t ,t ,t ,t ,k ,t ,k ,k ,k ,t ,k ,t ,k ,t ,k ,k,	//9

			k ,k ,k ,k ,k ,k ,k ,k ,t ,k ,t ,t ,t ,k ,t ,k ,kl,k ,k,	//10

			k ,t ,t ,t ,t ,t ,t ,t ,t ,k ,t ,k ,t ,k ,t ,t ,t ,st,k,	//11

			k ,t ,k ,t ,k ,k ,k ,k ,k ,k ,t ,k ,t ,k ,k ,k ,k ,k ,k,	//12

			k ,t ,k ,t ,t ,t ,t ,t ,t ,k ,t ,k ,t ,t ,t ,t ,t ,t ,k,	//13

			k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k		//14

	}
};	//�Q�[���̃}�b�v

//�Q�[���}�b�v�̊K�w�������p
GAME_MAP_KIND mapDatafirstInit[GAME_FLOOR_MAX][GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX];

//�}�b�v�`�b�v�̉摜���Ǘ�
MAPCHIP mapChip;

//�}�b�v�̏ꏊ�ƕ\������摜���Ǘ�
MAP map[GAME_FLOOR_MAX][GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX];

//�X�^�[�g�̈ʒu(�v���C���[�ƓG�̂��ꂼ��̍��W�j
iPOINT startPt_A;
iPOINT startPt_B;
iPOINT startEPt_1;
iPOINT startEPt_2;
iPOINT startEPt_3;

//���ꂼ��̃��[�v�̈ʒu
iPOINT w1_where;
iPOINT w2_where;

//�}�b�v�̓����蔻��
RECT mapColl[GAME_FLOOR_MAX][GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX];
//�}�b�v�̓����蔻�菉�����p
RECT mapCollInit[GAME_FLOOR_MAX][GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX];

//�S�[���������̔���
RECT GoalRect_A = { -1,-1,-1,-1 };  //�v���C���[A�p
RECT GoalRect_B = { -1,-1,-1,-1 };  //�v���C���[B�p

//�t�H���g�p
//FONT FontPixel;

//########## �v���g�^�C�v�錾 ##########
VOID MY_START(VOID);		//�X�^�[�g���
VOID MY_START_PROC(VOID);	//�X�^�[�g��ʂ̏���
VOID MY_START_DRAW(VOID);	//�X�^�[�g��ʂ̕`��

VOID MY_PLAY_INIT(VOID);	//�v���C��ʏ�����
VOID MY_PLAY(VOID);			//�v���C���
VOID MY_PLAY_PROC(VOID);	//�v���C��ʂ̏���
VOID MY_PLAY_DRAW(VOID);	//�v���C��ʂ̕`��

VOID MY_OVER(VOID);         //�Q�[���I�[�o�[���
VOID MY_OVER_PROC(VOID);    //�Q�[���I�[�o�[��ʂ̏���
VOID MY_OVER_DRAW(VOID);    //�Q�[���I�[�o�[��ʂ̕`��

VOID MY_END(VOID);			//�G���h���
VOID MY_END_PROC(VOID);		//�G���h��ʂ̏���
VOID MY_END_DRAW(VOID);		//�G���h��ʂ̕`��

BOOL MY_LOAD_IMAGE(VOID);		//�摜���܂Ƃ߂ēǂݍ��ފ֐�
VOID MY_DELETE_IMAGE(VOID);		//�摜���܂Ƃ߂č폜����֐�

BOOL MY_LOAD_MUSIC(VOID);		//���y���܂Ƃ߂ēǂݍ��ފ֐�
VOID MY_DELETE_MUSIC(VOID);		//���y���܂Ƃ߂č폜����֐�

int MY_CHECK_MAP1_PLAYER_COLL(RECT);   //�}�b�v�ƃv���C���[�̓����蔻�������֐�
BOOL MY_CHECK_RECT_COLL(RECT, RECT);    //�̈�̓����蔻�������֐�

//BOOL MY_FONT_INSTALL_ONCE(VOID);
//VOID MY_FONT_UNINSTALL_ONCE(VOID);
//BOOL MY_FONT_CREATE(VOID);
//VOID MY_FONT_DELETE(VOID);

//########## �v���O�����ōŏ��Ɏ��s�����֐� ##########
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	SetOutApplicationLogValidFlag(FALSE);				//Log.txt���o�͂��Ȃ�
	ChangeWindowMode(TRUE);								//�E�B���h�E���[�h�ɐݒ�
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);	//�w��̐��l�ŃE�B���h�E��\������
	SetWindowStyleMode(GAME_WINDOW_BAR);				//�^�C�g���o�[�̓f�t�H���g�ɂ���
	SetMainWindowText(TEXT(GAME_WINDOW_NAME));			//�E�B���h�E�̃^�C�g���̕���
	SetAlwaysRunFlag(TRUE);								//��A�N�e�B�u�ł����s����
	SetWindowUserCloseEnableFlag(FALSE);				//����{�^���ŁA����ɃE�B���h�E�����Ȃ��悤�ɂ���

	if (DxLib_Init() == -1) { return -1; }	//�c�w���C�u��������������

	//�t�H���g���ꎞ�I�ɃC���X�g�[��
	//if (MY_FONT_INSTALL_ONCE() == FALSE) { return -1; }

	//�t�H���g�n���h�����쐬
	//if (MY_FONT_CREATE() == FALSE) { return -1; }

	//�摜��ǂݍ���
	if (MY_LOAD_IMAGE() == FALSE) { return -1; }

	//���y��ǂݍ���
	if (MY_LOAD_MUSIC() == FALSE) { return -1; }

	GameScene = GAME_SCENE_START;	//�Q�[���V�[���̓X�^�[�g��ʂ���
	SetDrawScreen(DX_SCREEN_BACK);	//Draw�n�֐��͗���ʂɕ`��

	for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
		{
			//�v���C���[A�̃X�^�[�g�ʒu��T��
			if (mapDatafirst[0][tate][yoko] == as)
			{
				//�v���C���[A�̃X�^�[�g�ʒu���v�Z
				startPt_A.y = mapChip.height * tate;	//Y���W���擾
				startPt_A.x = mapChip.width * yoko;	//X���W���擾
				
			}

			//�v���C���[B�̃X�^�[�g�ʒu��T��
			if (mapDatafirst[0][tate][yoko] == bs)
			{
				//�v���C���[B�̃X�^�[�g�ʒu���v�Z
				startPt_B.x = mapChip.width * yoko;	//X���W���擾
				startPt_B.y = mapChip.height * tate;	//Y���W���擾
			}

			//�G�P�̃X�^�[�g�ʒu��T��
			if (mapDatafirst[0][tate][yoko] == e1)
			{
				//�G�P�̃X�^�[�g�ʒu���v�Z
				startEPt_1.x = mapChip.width * yoko;	//X���W���擾
				startEPt_1.y = mapChip.height * tate;	//Y���W���擾
			}

			//�G2�̃X�^�[�g�ʒu��T��
			if (mapDatafirst[0][tate][yoko] == e2)
			{
				//�G2�̃X�^�[�g�ʒu���v�Z
				startEPt_2.x = mapChip.width * yoko;	//X���W���擾
				startEPt_2.y = mapChip.height * tate;	//Y���W���擾
			}

			//�G3�̃X�^�[�g�ʒu��T��
			if (mapDatafirst[0][tate][yoko] == e3)
			{
				//�G3�̃X�^�[�g�ʒu���v�Z
				startEPt_3.x = mapChip.width * yoko;	//X���W���擾
				startEPt_3.y = mapChip.height * tate;	//Y���W���擾
			}

			//�v���C���[A�̃S�[���ʒu��T��
			if (mapDatafirst[0][tate][yoko] == ag) 
			{
				GoalRect_A.left = mapChip.width * yoko;
				GoalRect_A.top = mapChip.height * tate;
				GoalRect_A.right = mapChip.width * (yoko + 1);
				GoalRect_A.bottom = mapChip.height * (tate + 1);
			}

			//�v���C���[B�̃S�[���ʒu��T��
			if (mapDatafirst[0][tate][yoko] == bg)
			{
				GoalRect_B.left = mapChip.width * yoko;
				GoalRect_B.top = mapChip.height * tate;
				GoalRect_B.right = mapChip.width * (yoko + 1);
				GoalRect_B.bottom = mapChip.height * (tate + 1);
			}

			//���[�v�P�̈ʒu��T��
			if (mapDatafirst[0][tate][yoko] == w1)
			{
				//���[�v�P�̈ʒu���v�Z
				w1_where.y = mapChip.height * tate;	//Y���W���擾
				w1_where.x = mapChip.width * yoko;	//X���W���擾
			}

			//���[�v�Q�̈ʒu��T��
			if (mapDatafirst[0][tate][yoko] == w2)
			{
				//���[�v�Q�̈ʒu���v�Z
				w2_where.y = mapChip.height * tate;	//Y���W���擾
				w2_where.x = mapChip.width * yoko;	//X���W���擾
			}

		}

		//�X�^�[�g�����܂��Ă���΁A���[�v�I��
		if (startPt_A.x != 0 && startPt_A.y != 0 && startPt_B.x != 0 && startPt_B.y != 0 &&
			startEPt_1.x != 0 && startEPt_1.y != 0 && startEPt_2.x != 0 && startEPt_2.y != 0 &&
			startEPt_3.x != 0 && startEPt_3.y != 0) { break; }
	}

	//A�̃X�^�[�g�����܂��Ă��Ȃ����
	if (startPt_A.x == 0 && startPt_A.y == 0)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), START_ERR_CAPTION_A, START_ERR_TITLE, MB_OK);	return -1;
	}
	//B�̃X�^�[�g�����܂��Ă��Ȃ����
	if (startPt_B.x == 0 && startPt_B.y == 0)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), START_ERR_CAPTION_B, START_ERR_TITLE, MB_OK);	return -1;
	}

	//�G�P�̃X�^�[�g�����܂��Ă��Ȃ����
	if (startEPt_1.x == 0 && startEPt_1.y == 0)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), START_ERR_CAPTION_E1, START_ERR_TITLE, MB_OK);	return -1;
	}

	//�G2�̃X�^�[�g�����܂��Ă��Ȃ����
	if (startEPt_2.x == 0 && startEPt_2.y == 0)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), START_ERR_CAPTION_E2, START_ERR_TITLE, MB_OK);	return -1;
	}

	//�G3�̃X�^�[�g�����܂��Ă��Ȃ����
	if (startEPt_3.x == 0 && startEPt_3.y == 0)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), START_ERR_CAPTION_E3, START_ERR_TITLE, MB_OK);	return -1;
	}

	//A�̃S�[�������܂��Ă��Ȃ����
	if (GoalRect_A.left == -1)
	{
		MessageBox(GetMainWindowHandle(), GOAL_ERR_CAPTION_A, GOAL_ERR_TITLE, MB_OK);	return -1;
	}

	//B�̃S�[�������܂��Ă��Ȃ����
	if (GoalRect_B.left == -1)
	{
		MessageBox(GetMainWindowHandle(), GOAL_ERR_CAPTION_B, GOAL_ERR_TITLE, MB_OK);	return -1;
	}

	//�v���C���[A�̉摜���W�������ʒu�ɐݒ�
	player_A.image.x = startPt_A.x;
	player_A.image.y = startPt_A.y;

	//�v���C���[A�̉摜���W�������ʒu�ɐݒ�
	player_B.image.x = startPt_B.x;
	player_B.image.y = startPt_B.y;

	//�G�P�̉摜���W�������ʒu�ɐݒ�
	enemy_1.image.x = startEPt_1.x;
	enemy_1.image.y = startEPt_1.y;

	//�G2�̉摜���W�������ʒu�ɐݒ�
	enemy_2.image.x = startEPt_2.x;
	enemy_2.image.y = startEPt_2.y;

	//�G3�̉摜���W�������ʒu�ɐݒ�
	enemy_3.image.x = startEPt_3.x;
	enemy_3.image.y = startEPt_3.y;

	//�������[�v
	while (TRUE)
	{
		if (ProcessMessage() != 0) { break; }	//���b�Z�[�W�����̌��ʂ��G���[�̂Ƃ��A�����I��
		if (ClearDrawScreen() != 0) { break; }	//��ʂ������ł��Ȃ������Ƃ��A�����I��

		//��ʂ̕���{�^���������ꂽ�Ƃ�
		if (GetWindowUserCloseFlag(TRUE))
		{
			//�I���_�C�A���O��\��
			int Ret = MessageBox(GetMainWindowHandle(), MSG_CLOSE_CAPTION, MSG_CLOSE_TITLE, MB_YESNO | MB_ICONASTERISK);
			if (Ret == IDYES) { break; }	//YES�Ȃ�A�Q�[���𒆒f����
		}

		//�V�[�����Ƃɏ������s��
		switch (GameScene)
		{
		case GAME_SCENE_START:
			MY_START();	//�X�^�[�g���
			break;
		case GAME_SCENE_PLAY:
			MY_PLAY();	//�v���C���
			break;
		case GAME_SCENE_OVER:
			MY_OVER();
			break;
		case GAME_SCENE_END:
			MY_END();	//�G���h���
			break;
		}
		ScreenFlip();		//���j�^�̃��t���b�V�����[�g�̑����ŗ���ʂ��ĕ`��
	}

	//�摜�n���h����j��
	MY_DELETE_IMAGE();

	//���y�n���h����j��
	MY_DELETE_MUSIC();

	DxLib_End();	//�c�w���C�u�����g�p�̏I������

	return 0;
}

//�X�^�[�g���
VOID MY_START(VOID)
{
	MY_START_PROC();	//�X�^�[�g��ʂ̏���
	MY_START_DRAW();	//�X�^�[�g��ʂ̕`��

	return;
}

//�X�^�[�g��ʂ̏���
VOID MY_START_PROC(VOID)
{
	//BGM������Ă��Ȃ��Ȃ�
	if (CheckSoundMem(BGM_TITLE.handle) == 0)
	{
		//BGM�̉��ʂ�������
		ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, BGM_TITLE.handle);	//MUSIC_VOLUME�ŉ��ʒ���
		PlaySoundMem(BGM_TITLE.handle, DX_PLAYTYPE_LOOP);
	}

	//�G���^�[�L�[����������A�v���C�V�[���ֈړ�����
	if (CheckHitKey(KEY_INPUT_RETURN) == TRUE)
	{
		//BGM������Ă���Ȃ�
		if (CheckSoundMem(BGM_TITLE.handle) != 0)
		{
			StopSoundMem(BGM_TITLE.handle);	//BGM���~�߂�
		}

		//�Q�[���̃V�[�����v���C��ʂɂ���
		GameScene = GAME_SCENE_PLAY;

		return;  //�����I�Ƀv���C��ʂ�
	}

	//�^�C�g�����S���g��
	if (ImageTitleROGO.rate < ImageTitleROGO.rateMAX)
	{
		ImageTitleROGO.rate += IMAGE_TITLE_ROGO_ROTA;
	}

	//�^�C�g�����S���ړ�
	if (ImageTitleROGO.image.x < GAME_WIDTH / 2)
	{
		ImageTitleROGO.image.x += IMAGE_TITLE_ROGO_X_SPEED;
	}
	else
	{
		//�^�C�g�����S���ړ�����������

		//�X�^�[�g��_��
		if (ImageTitleSTART.Cnt < ImageTitleSTART.CntMAX)
		{
			ImageTitleSTART.Cnt += IMAGE_TITLE_START_CNT;
		}
		else
		{
			//�`�悷��/���Ȃ������߂�
			if (ImageTitleSTART.IsDraw == FALSE)
			{
				ImageTitleSTART.IsDraw = TRUE;
			}
			else if (ImageTitleSTART.IsDraw == TRUE)
			{
				ImageTitleSTART.IsDraw = FALSE;
			}
			ImageTitleSTART.Cnt = 0;
		}
	}

	return;
}

//�X�^�[�g��ʂ̕`��
VOID MY_START_DRAW(VOID)
{
	DrawGraph(ImageTitleBK.x, ImageTitleBK.y, ImageTitleBK.handle, TRUE);	//�^�C�g���w�i�̕`��

	//�^�C�g�����S����]���Ȃ���`��
	DrawRotaGraph(
		ImageTitleROGO.image.x, ImageTitleROGO.image.y,	//�摜�̍��W
		ImageTitleROGO.rate,							//�摜�̊g�嗦
		ImageTitleROGO.angle,							//�摜�̉�]��
		ImageTitleROGO.image.handle, TRUE);				//�摜�̃n���h��

	//�_��
	if (ImageTitleSTART.IsDraw == TRUE)
	{
		//�^�C�g���X�^�[�g�̕`��
		DrawGraph(ImageTitleSTART.image.x, ImageTitleSTART.image.y, ImageTitleSTART.image.handle, TRUE);
	}

	//�f�o�b�O���肪ON�Ȃ�f�o�b�O�p�\��������
	if (DEBUG == "ON") {
		DrawString(0, 0, "�X�^�[�g���(�G���^�[�L�[�������ĉ�����)", GetColor(255, 255, 255));
	}

	return;
}

//�v���C��ʏ�����
VOID MY_PLAY_INIT(VOID)
{
	for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
	{
		for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
		{
			for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
			{
				//�}�b�v��������
				map[floor][tate][yoko].kind = mapDatafirstInit[floor][tate][yoko];

				//�}�b�v�̓����蔻��̏�����
				mapColl[floor][tate][yoko].left = mapCollInit[floor][tate][yoko].left;
				mapColl[floor][tate][yoko].top = mapCollInit[floor][tate][yoko].top;
				mapColl[floor][tate][yoko].right = mapCollInit[floor][tate][yoko].right;
				mapColl[floor][tate][yoko].bottom = mapCollInit[floor][tate][yoko].bottom;
			}
		}
	}

	player_A.image.x = startPt_A.x;
	player_A.image.y = startPt_A.y;

	player_B.image.x = startPt_B.x;
	player_B.image.y = startPt_B.y;

	enemy_1.image.x = startEPt_1.x;
	enemy_1.image.y = startEPt_1.y;

	enemy_2.image.x = startEPt_2.x;
	enemy_2.image.y = startEPt_2.y;

	enemy_3.image.x = startEPt_3.x;
	enemy_3.image.y = startEPt_3.y;

	s1_check = 0;
	s2_check = 0;
	s3_check = 0;
	s4_check = 0;

	ki_check = 0;
	br_check = 0;
	sp_check = 0;
	ca_check = 0;

	fl_check = 0;
	move_floor = 0;

	player_live = 1;
	enemy1_live = 1;
	enemy2_live = 1;
	enemy3_live = 1;

	return;
}

//�v���C���
VOID MY_PLAY(VOID)
{
	MY_PLAY_PROC();	//�v���C��ʂ̏���
	MY_PLAY_DRAW();	//�v���C��ʂ̕`��

	return;
}

//�v���C��ʂ̏���
VOID MY_PLAY_PROC(VOID)
{
	//�X�y�[�X�L�[����������A�G���h�V�[���ֈړ�����
	if (CheckHitKey(KEY_INPUT_SPACE) == TRUE)
	{
		if (CheckSoundMem(BGM.handle) != 0)
		{
			StopSoundMem(BGM.handle);	//BGM���~�߂�
		}

		GameScene = GAME_SCENE_END;

		return;	//�����I�ɃG���h��ʂɔ��
	}

	//BGM������Ă��Ȃ��Ȃ�
	if (CheckSoundMem(BGM.handle) == 0)
	{
		//BGM�̉��ʂ�������
		ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, BGM.handle);	//MUSIC_VOLUME�ŉ��ʒ���

		//BGM�𗬂�
		//DX_PLAYTYPE_NORMAL:�@�m�[�}���Đ�
		//DX_PLAYTYPE_BACK  : �o�b�N�O���E���h�Đ�
		//DX_PLAYTYPE_LOOP  : ���[�v�Đ�
		PlaySoundMem(BGM.handle, DX_PLAYTYPE_LOOP);
	}

	//�v���C���[A�𑀍삷��
	if (CheckHitKey(KEY_INPUT_W)) { player_A.image.y -= MAP_DIV_HEIGHT; }
	if (CheckHitKey(KEY_INPUT_S)) { player_A.image.y += MAP_DIV_HEIGHT; }
	if (CheckHitKey(KEY_INPUT_A)) { player_A.image.x -= MAP_DIV_WIDTH; }
	if (CheckHitKey(KEY_INPUT_D)) { player_A.image.x += MAP_DIV_WIDTH; }

	//�v���C���[B�𑀍삷��
	if (CheckHitKey(KEY_INPUT_UP)) { player_B.image.y -= MAP_DIV_HEIGHT; }
	if (CheckHitKey(KEY_INPUT_DOWN)) { player_B.image.y += MAP_DIV_HEIGHT; }
	if (CheckHitKey(KEY_INPUT_LEFT)) { player_B.image.x -= MAP_DIV_WIDTH; }
	if (CheckHitKey(KEY_INPUT_RIGHT)) { player_B.image.x += MAP_DIV_WIDTH; }

	//�G�P�̃����_������ݒ�
	enemy1_rand = rand() % 4 + 1;
	if (enemy1_rand == 1) { enemy_1.image.y -= MAP_DIV_HEIGHT; }
	if (enemy1_rand == 2) { enemy_1.image.y += MAP_DIV_HEIGHT; }
	if (enemy1_rand == 3) { enemy_1.image.x -= MAP_DIV_WIDTH; }
	if (enemy1_rand == 4) { enemy_1.image.x += MAP_DIV_WIDTH; }

	//�G2�̃����_������ݒ�
	enemy2_rand = rand() % 4 + 1;
	if (enemy2_rand == 1) { enemy_2.image.y -= MAP_DIV_HEIGHT; }
	if (enemy2_rand == 2) { enemy_2.image.y += MAP_DIV_HEIGHT; }
	if (enemy2_rand == 3) { enemy_2.image.x -= MAP_DIV_WIDTH; }
	if (enemy2_rand == 4) { enemy_2.image.x += MAP_DIV_WIDTH; }

	//�G3�̃����_������ݒ�
	enemy3_rand = rand() % 4 + 1;
	if (enemy3_rand == 1) { enemy_3.image.y -= MAP_DIV_HEIGHT; }
	if (enemy3_rand == 2) { enemy_3.image.y += MAP_DIV_HEIGHT; }
	if (enemy3_rand == 3) { enemy_3.image.x -= MAP_DIV_WIDTH; }
	if (enemy3_rand == 4) { enemy_3.image.x += MAP_DIV_WIDTH; }

	//-----------------------�����蔻��֌W��������------------------------
	//�v���C���[A�̓����蔻��̐ݒ�
	player_A.coll.left = player_A.image.x;
	player_A.coll.top = player_A.image.y;
	player_A.coll.right = player_A.image.x + mapChip.width;
	player_A.coll.bottom = player_A.image.y + mapChip.height;

	//�v���C���[B�̓����蔻��̐ݒ�
	player_B.coll.left = player_B.image.x;
	player_B.coll.top = player_B.image.y;
	player_B.coll.right = player_B.image.x + mapChip.width;
	player_B.coll.bottom = player_B.image.y + mapChip.height;

	//�G�P�̓����蔻��̐ݒ�
	enemy_1.coll.left = enemy_1.image.x;
	enemy_1.coll.top = enemy_1.image.y;
	enemy_1.coll.right = enemy_1.image.x + mapChip.width;
	enemy_1.coll.bottom = enemy_1.image.y + mapChip.height;

	//�G2�̓����蔻��̐ݒ�
	enemy_2.coll.left = enemy_2.image.x;
	enemy_2.coll.top = enemy_2.image.y;
	enemy_2.coll.right = enemy_2.image.x + mapChip.width;
	enemy_2.coll.bottom = enemy_2.image.y + mapChip.height;

	//�G3�̓����蔻��̐ݒ�
	enemy_3.coll.left = enemy_3.image.x;
	enemy_3.coll.top = enemy_3.image.y;
	enemy_3.coll.right = enemy_3.image.x + mapChip.width;
	enemy_3.coll.bottom = enemy_3.image.y + mapChip.height;

	BOOL IsMove_A = TRUE;
	BOOL IsMove_B = TRUE;
	BOOL IsMove_E1 = TRUE;
	BOOL IsMove_E2 = TRUE;
	BOOL IsMove_E3 = TRUE;

	//�����������������v���C���[A�����蔻�肱�����灥����������������������
	//�v���C���[A�ƕǂ��������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_k)
	{
		//�v���C���[A�̍��W���P�O�̍��W�ɒu��������
		player_A.image.x = player_A.collBeforePt.x;
		player_A.image.y = player_A.collBeforePt.y;

		IsMove_A = FALSE;
	}

	//�v���C���[A�ƃM�~�b�N1���������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_m1)
	{
		//�v���C���[A�̍��W���P�O�̍��W�ɒu��������
		player_A.image.x = player_A.collBeforePt.x;
		player_A.image.y = player_A.collBeforePt.y;

		IsMove_A = FALSE;
	}

	//�v���C���[A�ƃM�~�b�N2���������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_m2)
	{
		//�v���C���[A�̍��W���P�O�̍��W�ɒu��������
		player_A.image.x = player_A.collBeforePt.x;
		player_A.image.y = player_A.collBeforePt.y;

		IsMove_A = FALSE;
	}

	//�v���C���[A�ƃM�~�b�N3���������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_m3)
	{
		//�v���C���[A�̍��W���P�O�̍��W�ɒu��������
		player_A.image.x = player_A.collBeforePt.x;
		player_A.image.y = player_A.collBeforePt.y;

		IsMove_A = FALSE;
	}

	//�v���C���[A�ƃM�~�b�N4���������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_m4)
	{
		//�v���C���[A�̍��W���P�O�̍��W�ɒu��������
		player_A.image.x = player_A.collBeforePt.x;
		player_A.image.y = player_A.collBeforePt.y;

		IsMove_A = FALSE;
	}

	//�v���C���[A���X�C�b�`1�ɓ������Ă�����
		if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_s1)
		{
			for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
			{
				for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
				{
					for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
					{
						//�X�C�b�`��������Ă��Ȃ��Ȃ�
						if (CheckSoundMem(SE_SWITCH.handle) == 0 && s1_check == 0)
						{
							//�X�C�b�`���̉��ʂ�������
							ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, SE_SWITCH.handle); //MUSIC_VOLUME�ŉ��ʒ���
							PlaySoundMem(SE_SWITCH.handle, DX_PLAYTYPE_BACK, TRUE);
						}

						//�M�~�b�N1��ʘH�ɂ��ď���
						if (map[floor][tate][yoko].kind == m1)
						{
							map[floor][tate][yoko].kind = t;
							s1_check = 1;

						}
					}
				}
			}
		}

	//�v���C���[A���X�C�b�`2�ɓ������Ă�����
		if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_s2)
		{
			for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
			{
				for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
				{
					for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
					{
						//�X�C�b�`��������Ă��Ȃ��Ȃ�
						if (CheckSoundMem(SE_SWITCH.handle) == 0 && s2_check == 0)
						{
							//�X�C�b�`���̉��ʂ�������
							ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, SE_SWITCH.handle); //MUSIC_VOLUME�ŉ��ʒ���
							PlaySoundMem(SE_SWITCH.handle, DX_PLAYTYPE_BACK, TRUE);
						}

						//�M�~�b�N2��ʘH�ɂ��ď���
						if (map[floor][tate][yoko].kind == m2)
						{
							map[floor][tate][yoko].kind = t;
							s2_check = 1;

						}
					}
				}
			}
		}

	//�v���C���[A���X�C�b�`3�ɓ������Ă�����
		if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_s3)
		{
			for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
			{
				for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
				{
					for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
					{
						//�X�C�b�`��������Ă��Ȃ��Ȃ�
						if (CheckSoundMem(SE_SWITCH.handle) == 0 && s3_check == 0)
						{
							//�X�C�b�`���̉��ʂ�������
							ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, SE_SWITCH.handle); //MUSIC_VOLUME�ŉ��ʒ���
							PlaySoundMem(SE_SWITCH.handle, DX_PLAYTYPE_BACK, TRUE);
						}

						//�M�~�b�N2��ʘH�ɂ��ď���
						if (map[floor][tate][yoko].kind == m3)
						{
							map[floor][tate][yoko].kind = t;
							s3_check = 1;

						}
					}
				}
			}
		}

	//�v���C���[A���X�C�b�`4�ɓ������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_s4)
	{
		for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
		{
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{
					//�X�C�b�`��������Ă��Ȃ��Ȃ�
					if (CheckSoundMem(SE_SWITCH.handle) == 0 && s4_check == 0)
					{
						//�X�C�b�`���̉��ʂ�������
						ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, SE_SWITCH.handle); //MUSIC_VOLUME�ŉ��ʒ���
						PlaySoundMem(SE_SWITCH.handle, DX_PLAYTYPE_BACK, TRUE);
					}

					//�M�~�b�N2��ʘH�ɂ��ď���
					if (map[floor][tate][yoko].kind == m4)
					{
						map[floor][tate][yoko].kind = t;
						s4_check = 1;

					}
				}
			}
		}
	}

	//�v���C���[A�ƌ������������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_kl)
	{
		if (ki_check == 0) {
			//�v���C���[A�̍��W���P�O�̍��W�ɒu��������
			player_A.image.x = player_A.collBeforePt.x;
			player_A.image.y = player_A.collBeforePt.y;

			IsMove_A = FALSE;
		}
		else if (ki_check == 1) {

			for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
			{
				for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
				{
					for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
					{
						//������ʘH�ɂ��ď���
						if (map[floor][tate][yoko].kind == kl)
						{
							map[floor][tate][yoko].kind = t;
						}
					}
				}
			}
		}
	}

	//�v���C���[A�����ɓ������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_ki)
	{
		for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
		{
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{
					//�����艹������Ă��Ȃ��Ȃ�
					if (CheckSoundMem(SE_KEY.handle) == 0 && ki_check == 0)
					{
						//�����艹�̉��ʂ�������
						ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, SE_KEY.handle); //MUSIC_VOLUME�ŉ��ʒ���
						PlaySoundMem(SE_KEY.handle, DX_PLAYTYPE_BACK, TRUE);
					}

					//����ʘH�ɂ��ď���
					if (map[floor][tate][yoko].kind == ki)
					{
						map[floor][tate][yoko].kind = t;
						ki_check = 1;

					}
				}
			}
		}
	}

	//�v���C���[A�����ɓ������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_br)
	{
		for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
		{
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{
					//������艹������Ă��Ȃ��Ȃ�
					if (CheckSoundMem(SE_WEAPON.handle) == 0 && br_check == 0)
					{
						//������艹�̉��ʂ�������
						ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 70, SE_WEAPON.handle); //MUSIC_VOLUME�ŉ��ʒ���
						PlaySoundMem(SE_WEAPON.handle, DX_PLAYTYPE_BACK, TRUE);
					}

					//����ʘH�ɂ��ď���
					if (map[floor][tate][yoko].kind == br)
					{
						map[floor][tate][yoko].kind = t;
						br_check = 1;

					}
				}
			}
		}
	}

	//�v���C���[A�����ɓ������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_sp)
	{
		for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
		{
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{
					//������艹������Ă��Ȃ��Ȃ�
					if (CheckSoundMem(SE_WEAPON.handle) == 0 && sp_check == 0)
					{
						//������艹�̉��ʂ�������
						ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 70, SE_WEAPON.handle); //MUSIC_VOLUME�ŉ��ʒ���
						PlaySoundMem(SE_WEAPON.handle, DX_PLAYTYPE_BACK, TRUE);
					}

					//����ʘH�ɂ��ď���
					if (map[floor][tate][yoko].kind == sp)
					{
						map[floor][tate][yoko].kind = t;
						sp_check = 1;

					}
				}
			}
		}
	}

	//�v���C���[A����ɓ������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_ca)
	{
		for (int floor = 0; floor <= GAME_FLOOR_MAX - 1 ; floor++)
		{
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{
					//������艹������Ă��Ȃ��Ȃ�
					if (CheckSoundMem(SE_WEAPON.handle) == 0 && ca_check == 0)
					{
						//������艹�̉��ʂ�������
						ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 70, SE_WEAPON.handle); //MUSIC_VOLUME�ŉ��ʒ���
						PlaySoundMem(SE_WEAPON.handle, DX_PLAYTYPE_BACK, TRUE);
					}

					//���ʘH�ɂ��ď���
					if (map[floor][tate][yoko].kind == ca)
					{
						map[floor][tate][yoko].kind = t;
						ca_check = 1;

					}
				}
			}
		}
	}

	//�v���C���[A�����[�v�P�ɓ������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_w1 && move_floor == 1)
	{
		for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
		{
			for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
			{
					move_floor = 0;
					player_A.image.x = w2_where.x;
					player_A.image.y = w2_where.y;
			}
		}
	}

	//�v���C���[A�����[�v2�ɓ������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_w2 && move_floor == 1)
	{
		for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
		{
			for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
			{
					move_floor = 0;
					player_A.image.x = w1_where.x;
					player_A.image.y = w1_where.y;
			}
		}
	}

	//�v���C���[A���G�P�ɓ������Ă�����
	if (MY_CHECK_RECT_COLL(player_A.coll, enemy_1.coll) == TRUE)
	{
		for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
		{
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{
					//���������Ă��āA�G�P�������Ă�����
					if (br_check == 1 && enemy1_live == 1)
					{
						enemy1_live = 0;

						//�U����������Ă��Ȃ��Ȃ�
						if (CheckSoundMem(SE_ATACK.handle) == 0)
						{
							//�U�����̉��ʂ�������
							ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, SE_ATACK.handle); //MUSIC_VOLUME�ŉ��ʒ���
							PlaySoundMem(SE_ATACK.handle, DX_PLAYTYPE_BACK, TRUE);
						}

					}
					//���������Ă��Ȃ�������A
					else if (br_check == 0)
					{
						//�v���C���[�摜�����S�p�ɏ���������

						//BGM������Ă���Ȃ�
						if (CheckSoundMem(BGM.handle) != 0)
						{
							StopSoundMem(BGM.handle);	//BGM���~�߂�
						}

						//�Q�[���I�[�o�[��\������
						GameScene = GAME_SCENE_OVER;
					}
				}
			}
		}
	}

	//�v���C���[A���G�Q�ɓ������Ă�����
	if (MY_CHECK_RECT_COLL(player_A.coll, enemy_2.coll) == TRUE)
	{
		for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
		{
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{

					//���������Ă��āA�G�Q�������Ă�����
					if (sp_check == 1 && enemy2_live == 1)
					{
						enemy2_live = 0;

						//�U����������Ă��Ȃ��Ȃ�
						if (CheckSoundMem(SE_ATACK.handle) == 0)
						{
							//�U�����̉��ʂ�������
							ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, SE_ATACK.handle); //MUSIC_VOLUME�ŉ��ʒ���
							PlaySoundMem(SE_ATACK.handle, DX_PLAYTYPE_BACK, TRUE);
						}

					}
					//���������Ă��Ȃ�������A
					else if (sp_check == 0)
					{
						//�v���C���[�摜�����S�p�ɏ���������


						//BGM������Ă���Ȃ�
						if (CheckSoundMem(BGM.handle) != 0)
						{
							StopSoundMem(BGM.handle);	//BGM���~�߂�
						}

						//�Q�[���I�[�o�[��\������
						GameScene = GAME_SCENE_OVER;
					}
				}
			}
		}
	}

	//�v���C���[A���G�R�ɓ������Ă�����
	if (MY_CHECK_RECT_COLL(player_A.coll, enemy_3.coll) == TRUE)
	{
		for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
		{
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{

					//��������Ă��āA�G�R�������Ă�����
					if (ca_check == 1 && enemy3_live == 1)
					{
						enemy3_live = 0;

						//�U����������Ă��Ȃ��Ȃ�
						if (CheckSoundMem(SE_ATACK.handle) == 0)
						{
							//�U�����̉��ʂ�������
							ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, SE_ATACK.handle); //MUSIC_VOLUME�ŉ��ʒ���
							PlaySoundMem(SE_ATACK.handle, DX_PLAYTYPE_BACK, TRUE);
						}

					}
					//��������Ă��Ȃ�������A
					else if (ca_check == 0)
					{
						//�v���C���[�摜�����S�p�ɏ���������

						//BGM������Ă���Ȃ�
						if (CheckSoundMem(BGM.handle) != 0)
						{
							StopSoundMem(BGM.handle);	//BGM���~�߂�
						}

						//�Q�[���I�[�o�[��\������
						GameScene = GAME_SCENE_OVER;
					}
				}
			}
		}
	}

	//���������������������������������v���C���[A�����蔻�肱���܂Ł�����������������������



	//�����������������v���C���[B�����蔻�肱�����灥����������������������
	//�v���C���[B�ƕǂ��������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_k)
	{
		//�v���C���[B�̍��W���P�O�̍��W�ɒu��������
		player_B.image.x = player_B.collBeforePt.x;
		player_B.image.y = player_B.collBeforePt.y;

		IsMove_B = FALSE;
	}

	//�v���C���[B�ƃM�~�b�N1���������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_m1)
	{
		//�v���C���[A�̍��W���P�O�̍��W�ɒu��������
		player_B.image.x = player_B.collBeforePt.x;
		player_B.image.y = player_B.collBeforePt.y;

		IsMove_B = FALSE;
	}

	//�v���C���[B�ƃM�~�b�N2���������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_m2)
	{
		//�v���C���[A�̍��W���P�O�̍��W�ɒu��������
		player_B.image.x = player_B.collBeforePt.x;
		player_B.image.y = player_B.collBeforePt.y;

		IsMove_B = FALSE;
	}

	//�v���C���[B�ƃM�~�b�N3���������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_m3)
	{
		//�v���C���[A�̍��W���P�O�̍��W�ɒu��������
		player_B.image.x = player_B.collBeforePt.x;
		player_B.image.y = player_B.collBeforePt.y;

		IsMove_B = FALSE;
	}

	//�v���C���[B�ƃM�~�b�N4���������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_m4)
	{
		//�v���C���[A�̍��W���P�O�̍��W�ɒu��������
		player_B.image.x = player_B.collBeforePt.x;
		player_B.image.y = player_B.collBeforePt.y;

		IsMove_B = FALSE;
	}

	//�v���C���[B���X�C�b�`1�ɓ������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_s1)
	{
		for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
		{
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{
					//�M�~�b�N1��ʘH�ɂ��ď���
					if (map[floor][tate][yoko].kind == m1)
					{
						map[floor][tate][yoko].kind = t;
						s1_check = 1;
					}

					//�X�C�b�`��������Ă��Ȃ��Ȃ�
					if (CheckSoundMem(SE_SWITCH.handle) == 0  && s1_check == 0)
					{
						//�X�C�b�`���̉��ʂ�������
						ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, SE_SWITCH.handle); //MUSIC_VOLUME�ŉ��ʒ���
						PlaySoundMem(SE_SWITCH.handle, DX_PLAYTYPE_BACK, TRUE);
					}
				}
			}
		}
	}

	//�v���C���[B���X�C�b�`2�ɓ������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_s2)
	{
		for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
		{
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{
					//�M�~�b�N2��ʘH�ɂ��ď���
					if (map[floor][tate][yoko].kind == m2)
					{
						map[floor][tate][yoko].kind = t;
						s2_check = 1;

					}

					//�X�C�b�`��������Ă��Ȃ��Ȃ�
					if (CheckSoundMem(SE_SWITCH.handle) == 0 && s2_check == 0)
					{
						//�X�C�b�`���̉��ʂ�������
						ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, SE_SWITCH.handle); //MUSIC_VOLUME�ŉ��ʒ���
						PlaySoundMem(SE_SWITCH.handle, DX_PLAYTYPE_BACK, TRUE);
					}
				}
			}
		}
	}

	//�v���C���[B���X�C�b�`3�ɓ������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_s3)
	{
		for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
		{
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{
					//�M�~�b�N3��ʘH�ɂ��ď���
					if (map[floor][tate][yoko].kind == m3)
					{
						map[floor][tate][yoko].kind = t;
						s3_check = 1;

					}

					//�X�C�b�`��������Ă��Ȃ��Ȃ�
					if (CheckSoundMem(SE_SWITCH.handle) == 0 && s3_check == 0)
					{
						//�X�C�b�`���̉��ʂ�������
						ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, SE_SWITCH.handle); //MUSIC_VOLUME�ŉ��ʒ���
						PlaySoundMem(SE_SWITCH.handle, DX_PLAYTYPE_BACK, TRUE);
					}
				}
			}
		}
	}

	//�v���C���[B���X�C�b�`4�ɓ������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_s4)
	{
		for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
		{
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{
					//�M�~�b�N4��ʘH�ɂ��ď���
					if (map[floor][tate][yoko].kind == m4)
					{
						map[floor][tate][yoko].kind = t;
						s4_check = 1;

					}

					//�X�C�b�`��������Ă��Ȃ��Ȃ�
					if (CheckSoundMem(SE_SWITCH.handle) == 0 && s4_check == 0)
					{
						//�X�C�b�`���̉��ʂ�������
						ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, SE_SWITCH.handle); //MUSIC_VOLUME�ŉ��ʒ���
						PlaySoundMem(SE_SWITCH.handle, DX_PLAYTYPE_BACK, TRUE);
					}
				}
			}
		}
	}

	//�v���C���[B�ƌ������������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_kl)
	{
		if (ki_check == 0) {
			//�v���C���[B�̍��W���P�O�̍��W�ɒu��������
			player_B.image.x = player_B.collBeforePt.x;
			player_B.image.y = player_B.collBeforePt.y;

			IsMove_B = FALSE;
		}
		else if (ki_check == 1)
		{

			for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
			{
				for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
				{
					for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
					{
						//������ʘH�ɂ��ď���
						if (map[floor][tate][yoko].kind == kl)
						{
							map[floor][tate][yoko].kind = t;
						}
					}
				}
			}
		}
	}

	//�v���C���[B�����ɓ������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_ki)
	{
		for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
		{
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{
					//�����艹������Ă��Ȃ��Ȃ�
					if (CheckSoundMem(SE_KEY.handle) == 0 && ki_check == 0)
					{
						//�����艹�̉��ʂ�������
						ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, SE_KEY.handle); //MUSIC_VOLUME�ŉ��ʒ���
						PlaySoundMem(SE_KEY.handle, DX_PLAYTYPE_BACK, TRUE);
					}

					//����ʘH�ɂ��ď���
					if (map[floor][tate][yoko].kind == ki)
					{
						map[floor][tate][yoko].kind = t;
						ki_check = 1;
					}
				}
			}
		}
	}

	//�v���C���[B�����ɓ������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_br)
	{
		for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
		{
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{
					//������艹������Ă��Ȃ��Ȃ�
					if (CheckSoundMem(SE_WEAPON.handle) == 0 && br_check == 0)
					{
						//������艹�̉��ʂ�������
						ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 70, SE_WEAPON.handle); //MUSIC_VOLUME�ŉ��ʒ���
						PlaySoundMem(SE_WEAPON.handle, DX_PLAYTYPE_BACK, TRUE);
					}

					//����ʘH�ɂ��ď���
					if (map[floor][tate][yoko].kind == br)
					{
						map[floor][tate][yoko].kind = t;
						br_check = 1;

					}
				}
			}
		}
	}

	//�v���C���[B�����ɓ������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_sp)
	{
		for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
		{
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{
					//������艹������Ă��Ȃ��Ȃ�
					if (CheckSoundMem(SE_WEAPON.handle) == 0 && sp_check == 0)
					{
						//������艹�̉��ʂ�������
						ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 70, SE_WEAPON.handle); //MUSIC_VOLUME�ŉ��ʒ���
						PlaySoundMem(SE_WEAPON.handle, DX_PLAYTYPE_BACK, TRUE);
					}

					//����ʘH�ɂ��ď���
					if (map[floor][tate][yoko].kind == sp)
					{
						map[floor][tate][yoko].kind = t;
						sp_check = 1;

					}
				}
			}
		}
	}

	//�v���C���[B����ɓ������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_ca)
	{
		for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
		{
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{
					//������艹������Ă��Ȃ��Ȃ�
					if (CheckSoundMem(SE_WEAPON.handle) == 0 && ca_check == 0)
					{
						//������艹�̉��ʂ�������
						ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 70, SE_WEAPON.handle); //MUSIC_VOLUME�ŉ��ʒ���
						PlaySoundMem(SE_WEAPON.handle, DX_PLAYTYPE_BACK, TRUE);
					}

					//���ʘH�ɂ��ď���
					if (map[floor][tate][yoko].kind == ca)
					{
						map[floor][tate][yoko].kind = t;
						ca_check = 1;

					}
				}
			}
		}
	}

	//�v���C���[B�����[�v�P�ɓ������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_w1 && move_floor == 1)
	{
		for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
		{
			for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
			{
				move_floor = 0;
				player_B.image.x = w2_where.x;
				player_B.image.y = w2_where.y;
			}
		}
	}

	//�v���C���[B�����[�v2�ɓ������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_w2 && move_floor == 1)
	{
		for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
		{
			for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
			{
				move_floor = 0;
				player_B.image.x = w1_where.x;
				player_B.image.y = w1_where.y;
			}
		}
	}

	//�v���C���[B���G�P�ɓ������Ă�����
	if (MY_CHECK_RECT_COLL(player_B.coll, enemy_1.coll) == TRUE)
	{
		for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
		{
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{
					//���������Ă��āA�G�P�������Ă�����
					if (br_check == 1 && enemy1_live == 1)
					{
						enemy1_live = 0;

						//�U����������Ă��Ȃ��Ȃ�
						if (CheckSoundMem(SE_ATACK.handle) == 0)
						{
							//�U�����̉��ʂ�������
							ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, SE_ATACK.handle); //MUSIC_VOLUME�ŉ��ʒ���
							PlaySoundMem(SE_ATACK.handle, DX_PLAYTYPE_BACK, TRUE);
						}

					}
					//���������Ă��Ȃ�������A
					else if (br_check == 0)
					{
						//�v���C���[�摜�����S�p�ɏ���������

						//BGM������Ă���Ȃ�
						if (CheckSoundMem(BGM.handle) != 0)
						{
							StopSoundMem(BGM.handle);	//BGM���~�߂�
						}

						//�Q�[���I�[�o�[��\������
						GameScene = GAME_SCENE_OVER;
					}
				}
			}
		}
	}

	//�v���C���[B���G�Q�ɓ������Ă�����
	if (MY_CHECK_RECT_COLL(player_B.coll, enemy_2.coll) == TRUE)
	{
		for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
		{
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{

					//���������Ă��āA�G�Q�������Ă�����
					if (sp_check == 1 && enemy2_live == 1)
					{
						enemy2_live = 0;

						//�U����������Ă��Ȃ��Ȃ�
						if (CheckSoundMem(SE_ATACK.handle) == 0)
						{
							//�U�����̉��ʂ�������
							ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, SE_ATACK.handle); //MUSIC_VOLUME�ŉ��ʒ���
							PlaySoundMem(SE_ATACK.handle, DX_PLAYTYPE_BACK, TRUE);
						}

					}
					//���������Ă��Ȃ�������A
					else if (sp_check == 0)
					{
						//�v���C���[�摜�����S�p�ɏ���������

						//BGM������Ă���Ȃ�
						if (CheckSoundMem(BGM.handle) != 0)
						{
							StopSoundMem(BGM.handle);	//BGM���~�߂�
						}

						//�Q�[���I�[�o�[��\������
						GameScene = GAME_SCENE_OVER;
					}
				}
			}
		}
	}

	//�v���C���[B���G�R�ɓ������Ă�����
	if (MY_CHECK_RECT_COLL(player_B.coll, enemy_3.coll) == TRUE)
	{
		for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
		{
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{

					//��������Ă��āA�G�R�������Ă�����
					if (ca_check == 1 && enemy3_live == 1)
					{
						enemy3_live = 0;

						//�U����������Ă��Ȃ��Ȃ�
						if (CheckSoundMem(SE_ATACK.handle) == 0)
						{
							//�U�����̉��ʂ�������
							ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, SE_ATACK.handle); //MUSIC_VOLUME�ŉ��ʒ���
							PlaySoundMem(SE_ATACK.handle, DX_PLAYTYPE_BACK, TRUE);
						}

					}
					//��������Ă��Ȃ�������A
					else if (ca_check == 0)
					{
						//�v���C���[�摜�����S�p�ɏ���������

						//BGM������Ă���Ȃ�
						if (CheckSoundMem(BGM.handle) != 0)
						{
							StopSoundMem(BGM.handle);	//BGM���~�߂�
						}

						//�Q�[���I�[�o�[��\������
						GameScene = GAME_SCENE_OVER;
					}
				}
			}
		}
	}
	//���������������������������������v���C���[B�����蔻�肱���܂Ł�����������������������

	//���������������������������������G�P�����蔻�肱�����灥������������������������������
	//�G�P�ƕǂ��������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(enemy_1.coll) == TRUE_k)
	{
		//�G�P�̍��W���P�O�̍��W�ɒu��������
		enemy_1.image.x = enemy_1.collBeforePt.x;
		enemy_1.image.y = enemy_1.collBeforePt.y;

		IsMove_E1 = FALSE;
	}

	//�G�P�ƃM�~�b�N1���������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(enemy_1.coll) == TRUE_m1)
	{
		//�G�P�̍��W���P�O�̍��W�ɒu��������
		enemy_1.image.x = enemy_1.collBeforePt.x;
		enemy_1.image.y = enemy_1.collBeforePt.y;

		IsMove_E1 = FALSE;
	}

	//�G�P�ƃM�~�b�N2���������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(enemy_1.coll) == TRUE_m2)
	{
		//�G�P�̍��W���P�O�̍��W�ɒu��������
		enemy_1.image.x = enemy_1.collBeforePt.x;
		enemy_1.image.y = enemy_1.collBeforePt.y;

		IsMove_E1 = FALSE;
	}

	//�G�P�ƃM�~�b�N3���������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(enemy_1.coll) == TRUE_m3)
	{
		//�G�P�̍��W���P�O�̍��W�ɒu��������
		enemy_1.image.x = enemy_1.collBeforePt.x;
		enemy_1.image.y = enemy_1.collBeforePt.y;

		IsMove_E1 = FALSE;
	}

	//�G�P�ƃM�~�b�N4���������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(enemy_1.coll) == TRUE_m4)
	{
		//�G�P�̍��W���P�O�̍��W�ɒu��������
		enemy_1.image.x = enemy_1.collBeforePt.x;
		enemy_1.image.y = enemy_1.collBeforePt.y;

		IsMove_E1 = FALSE;
	}

	//���������������������������������G�P�����蔻�肱���܂Ł�����������������������

	//���������������������������������G�Q�����蔻�肱�����灥������������������������������
	//�G�Q�ƕǂ��������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(enemy_2.coll) == TRUE_k)
	{
		//�G2�̍��W���P�O�̍��W�ɒu��������
		enemy_2.image.x = enemy_2.collBeforePt.x;
		enemy_2.image.y = enemy_2.collBeforePt.y;

		IsMove_E2 = FALSE;
	}

	//�G2�ƃM�~�b�N1���������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(enemy_2.coll) == TRUE_m1)
	{
		//�G2�̍��W���P�O�̍��W�ɒu��������
		enemy_2.image.x = enemy_2.collBeforePt.x;
		enemy_2.image.y = enemy_2.collBeforePt.y;

		IsMove_E2 = FALSE;
	}

	//�G2�ƃM�~�b�N2���������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(enemy_2.coll) == TRUE_m2)
	{
		//�G2�̍��W���P�O�̍��W�ɒu��������
		enemy_2.image.x = enemy_2.collBeforePt.x;
		enemy_2.image.y = enemy_2.collBeforePt.y;

		IsMove_E2 = FALSE;
	}

	//�G2�ƃM�~�b�N3���������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(enemy_2.coll) == TRUE_m3)
	{
		//�G2�̍��W���P�O�̍��W�ɒu��������
		enemy_2.image.x = enemy_2.collBeforePt.x;
		enemy_2.image.y = enemy_2.collBeforePt.y;

		IsMove_E2 = FALSE;
	}

	//�G2�ƃM�~�b�N4���������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(enemy_2.coll) == TRUE_m4)
	{
		//�G2�̍��W���P�O�̍��W�ɒu��������
		enemy_2.image.x = enemy_2.collBeforePt.x;
		enemy_2.image.y = enemy_2.collBeforePt.y;

		IsMove_E2 = FALSE;
	}

	//���������������������������������G�Q�����蔻�肱���܂Ł�����������������������

	//���������������������������������G3�����蔻�肱�����灥������������������������������
	//�G3�ƕǂ��������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(enemy_3.coll) == TRUE_k)
	{
		//�G3�̍��W���P�O�̍��W�ɒu��������
		enemy_3.image.x = enemy_3.collBeforePt.x;
		enemy_3.image.y = enemy_3.collBeforePt.y;

		IsMove_E3 = FALSE;
	}

	//�G3�ƃM�~�b�N1���������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(enemy_3.coll) == TRUE_m1)
	{
		//�G3�̍��W���P�O�̍��W�ɒu��������
		enemy_3.image.x = enemy_3.collBeforePt.x;
		enemy_3.image.y = enemy_3.collBeforePt.y;

		IsMove_E3 = FALSE;
	}

	//�G3�ƃM�~�b�N2���������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(enemy_3.coll) == TRUE_m2)
	{
		//�G3�̍��W���P�O�̍��W�ɒu��������
		enemy_3.image.x = enemy_3.collBeforePt.x;
		enemy_3.image.y = enemy_3.collBeforePt.y;

		IsMove_E3 = FALSE;
	}

	//�G3�ƃM�~�b�N3���������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(enemy_3.coll) == TRUE_m3)
	{
		//�G3�̍��W���P�O�̍��W�ɒu��������
		enemy_3.image.x = enemy_3.collBeforePt.x;
		enemy_3.image.y = enemy_3.collBeforePt.y;

		IsMove_E3 = FALSE;
	}

	//�G3�ƃM�~�b�N4���������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(enemy_3.coll) == TRUE_m4)
	{
		//�G3�̍��W���P�O�̍��W�ɒu��������
		enemy_3.image.x = enemy_3.collBeforePt.x;
		enemy_3.image.y = enemy_3.collBeforePt.y;

		IsMove_E3 = FALSE;
	}

	//���������������������������������G�Q�����蔻�肱���܂Ł�����������������������


	//�v���C���[A��B���t���A���ړ�������
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_t && MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_t)
	{
		move_floor = 1;
	}

	//�v���C���[A��B���K�i�ɓ������Ă�����
		if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_st) {
			if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_st) {
				for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
				{
					for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
					{
						if (move_floor == 1)
						{
							if (fl_check == 0)
							{
								move_floor = 0;
								fl_check = 1;
							}
							else if (fl_check == 1)
							{
								move_floor = 0;
								fl_check = 0;
							}
						}
					}
				}

					return;
			}
		}

	//�v���C���[A��B���S�[���ɓ������Ă�����
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_ag) {
		if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_bg) {

			//BGM������Ă���Ȃ�
			if (CheckSoundMem(BGM.handle) != 0)
			{
				StopSoundMem(BGM.handle);	//BGM���~�߂�
			}
			GameScene = GAME_SCENE_END;

			return;
		}
	}

	
	//�v���C���[A���ړ���ɓ�����Ȃ�
	if (IsMove_A == TRUE)
	{
		//�������Ă��Ȃ����̃v���C���[A�̍��W���擾
		player_A.collBeforePt.x = player_A.image.x;
		player_A.collBeforePt.y = player_A.image.y;
	}

	//�v���C���[B���ړ���ɓ�����Ȃ�
	if (IsMove_B == TRUE)
	{
		//�������Ă��Ȃ����̃v���C���[B�̍��W���擾
		player_B.collBeforePt.x = player_B.image.x;
		player_B.collBeforePt.y = player_B.image.y;
	}

	//�G�P���ړ���ɓ�����Ȃ�
	if (IsMove_E1 == TRUE)
	{
		//�������Ă��Ȃ����̓G�P�̍��W���擾
		enemy_1.collBeforePt.x = enemy_1.image.x;
		enemy_1.collBeforePt.y = enemy_1.image.y;
	}

	//�G2���ړ���ɓ�����Ȃ�
	if (IsMove_E2 == TRUE)
	{
		//�������Ă��Ȃ����̓G�P�̍��W���擾
		enemy_2.collBeforePt.x = enemy_2.image.x;
		enemy_2.collBeforePt.y = enemy_2.image.y;
	}

	//�G3���ړ���ɓ�����Ȃ�
	if (IsMove_E3 == TRUE)
	{
		//�������Ă��Ȃ����̓G�P�̍��W���擾
		enemy_3.collBeforePt.x = enemy_3.image.x;
		enemy_3.collBeforePt.y = enemy_3.image.y;
	}
	//-----------------------�����蔻��֌W�����܂�------------------------
	return;
}

//�v���C��ʂ̕`��
VOID MY_PLAY_DRAW(VOID)
{
		for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
		{
			for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
			{
				if (fl_check == 0)
				{
					//�����K�w�}�b�v��`��
					DrawGraph(
						map[0][tate][yoko].x,
						map[0][tate][yoko].y,
						mapChip.handle[map[0][tate][yoko].kind],
						TRUE);
				}
				else if(fl_check == 1 )
				{
					//�ʊK�w�}�b�v��`��
					DrawGraph(
						map[1][tate][yoko].x,
						map[1][tate][yoko].y,
						mapChip.handle[map[1][tate][yoko].kind],
						TRUE);
				}
			}
		}


	if (ki_check == 1) {
		//���擾��Ԃ�`��
		DrawGraph(
			MAP_DIV_WIDTH * 7,
			MAP_DIV_HEIGHT * 14,
			mapChip.handle[19],
			TRUE);
	}

	if (br_check == 1) {
		//���擾��Ԃ�`��
		DrawGraph(
			MAP_DIV_WIDTH * 8,
			MAP_DIV_HEIGHT * 14,
			mapChip.handle[20],
			TRUE);
	}

	if (sp_check == 1) {
		//���擾��Ԃ�`��
		DrawGraph(
			MAP_DIV_WIDTH * 9,
			MAP_DIV_HEIGHT * 14,
			mapChip.handle[21],
			TRUE);
	}

	if (ca_check == 1) {
		//��擾��Ԃ�`��
		DrawGraph(
			MAP_DIV_WIDTH * 10,
			MAP_DIV_HEIGHT * 14,
			mapChip.handle[22],
			TRUE);
	}

	//�v���C���[A��`�悷��
	strcpy_s(ImageBack.path, IMAGE_player_A_PATH);
	LoadGraphScreen(player_A.image.x , player_A.image.y, ImageBack.path, FALSE);

	//�v���C���[B��`�悷��
	strcpy_s(ImageBack.path, IMAGE_player_B_PATH);
	LoadGraphScreen(player_B.image.x , player_B.image.y, ImageBack.path, FALSE);

	if (enemy1_live == 1)
	{
		//�G�P��`�悷��
		strcpy_s(ImageBack.path, IMAGE_enemy_1_PATH);
		LoadGraphScreen(enemy_1.image.x, enemy_1.image.y, ImageBack.path, FALSE);
	}

	if (enemy2_live == 1)
	{
		//�G2��`�悷��
		strcpy_s(ImageBack.path, IMAGE_enemy_2_PATH);
		LoadGraphScreen(enemy_2.image.x, enemy_2.image.y, ImageBack.path, FALSE);
	}

	if (enemy3_live == 1)
	{
		//�G3��`�悷��
		strcpy_s(ImageBack.path, IMAGE_enemy_3_PATH);
		LoadGraphScreen(enemy_3.image.x, enemy_3.image.y, ImageBack.path, FALSE);
	}
	WaitTimer(60);

	//�f�o�b�O���肪ON�Ȃ�f�o�b�O�p�\��������
	if (DEBUG == "ON") {
		//�����蔻��̕`��i�f�o�b�O�p�j
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{
					if (fl_check == 0)
					{
						//�ǂȂ�ΕǗp�̓����蔻���`��
						if (mapDatafirst[fl_check][tate][yoko] == k)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 0, 255), FALSE);
						}

						//�M�~�b�N1�ł���A�Ȃ����X�C�b�`1��������Ă��Ȃ��is1_check=0�j�Ȃ�΃M�~�b�N�p�̓����蔻���`��
						if (mapDatafirst[fl_check][tate][yoko] == m1 && s1_check == 0)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
						}

						//�M�~�b�N2�ł���A�Ȃ����X�C�b�`2��������Ă��Ȃ��is2_check=0�j�Ȃ�΃M�~�b�N�p�̓����蔻���`��
						if (mapDatafirst[fl_check][tate][yoko] == m2 && s2_check == 0)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
						}

						//�M�~�b�N3�ł���A�Ȃ����X�C�b�`3��������Ă��Ȃ��is3_check=0�j�Ȃ�΃M�~�b�N�p�̓����蔻���`��
						if (mapDatafirst[fl_check][tate][yoko] == m3 && s3_check == 0)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
						}

						//�M�~�b�N4�ł���A�Ȃ����X�C�b�`4��������Ă��Ȃ��is4_check=0�j�Ȃ�΃M�~�b�N�p�̓����蔻���`��
						if (mapDatafirst[fl_check][tate][yoko] == m4 && s4_check == 0)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
						}

						//�����ł���A�Ȃ��������Ƃ��Ă��Ȃ��is4_check=0�j�Ȃ�΃M�~�b�N�p�̓����蔻���`��
						if (mapDatafirst[fl_check][tate][yoko] == kl && ki_check == 0)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
						}

						//�ʘH�Ȃ�ΒʘH�p�̓����蔻���`��
						if (mapDatafirst[fl_check][tate][yoko] == t)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 255, 255), FALSE);
						}

						//�X�C�b�`1�Ȃ�΃X�C�b�`1�p�̓����蔻���`��
						if (mapDatafirst[fl_check][tate][yoko] == s1)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 255, 0), FALSE);
						}

						//�X�C�b�`2�Ȃ�΃X�C�b�`2�p�̓����蔻���`��
						if (mapDatafirst[fl_check][tate][yoko] == s2)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 255, 0), FALSE);
						}

						//�X�C�b�`3�Ȃ�΃X�C�b�`3�p�̓����蔻���`��
						if (mapDatafirst[fl_check][tate][yoko] == s3)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 255, 0), FALSE);
						}

						//�X�C�b�`4�Ȃ�΃X�C�b�`4�p�̓����蔻���`��
						if (mapDatafirst[fl_check][tate][yoko] == s4)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 255, 0), FALSE);
						}

						//���Ȃ�Ό��p�̓����蔻���`��
						if (mapDatafirst[fl_check][tate][yoko] == ki)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(255, 255, 0), FALSE);
						}

						//�K�i�Ȃ�ΊK�i�̓����蔻���`��
						if (mapDatafirst[fl_check][tate][yoko] == st)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 0, 0), FALSE);
						}
					}
					else if (fl_check == 1)
					{
						//�ǂȂ�ΕǗp�̓����蔻���`��
						if (mapDatafirst[fl_check][tate][yoko] == k)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 0, 255), FALSE);
						}

						//�M�~�b�N1�ł���A�Ȃ����X�C�b�`1��������Ă��Ȃ��is1_check=0�j�Ȃ�΃M�~�b�N�p�̓����蔻���`��
						if (mapDatafirst[fl_check][tate][yoko] == m1 && s1_check == 0)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
						}

						//�M�~�b�N2�ł���A�Ȃ����X�C�b�`2��������Ă��Ȃ��is2_check=0�j�Ȃ�΃M�~�b�N�p�̓����蔻���`��
						if (mapDatafirst[fl_check][tate][yoko] == m2 && s2_check == 0)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
						}

						//�M�~�b�N3�ł���A�Ȃ����X�C�b�`3��������Ă��Ȃ��is3_check=0�j�Ȃ�΃M�~�b�N�p�̓����蔻���`��
						if (mapDatafirst[fl_check][tate][yoko] == m3 && s3_check == 0)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
						}

						//�M�~�b�N4�ł���A�Ȃ����X�C�b�`4��������Ă��Ȃ��is4_check=0�j�Ȃ�΃M�~�b�N�p�̓����蔻���`��
						if (mapDatafirst[fl_check][tate][yoko] == m4 && s4_check == 0)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
						}

						//�����ł���A�Ȃ��������Ƃ��Ă��Ȃ��is4_check=0�j�Ȃ�΃M�~�b�N�p�̓����蔻���`��
						if (mapDatafirst[fl_check][tate][yoko] == kl && ki_check == 0)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
						}

						//�ʘH�Ȃ�ΒʘH�p�̓����蔻���`��
						if (mapDatafirst[fl_check][tate][yoko] == t)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 255, 255), FALSE);
						}

						//�X�C�b�`1�Ȃ�΃X�C�b�`1�p�̓����蔻���`��
						if (mapDatafirst[fl_check][tate][yoko] == s1)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 255, 0), FALSE);
						}

						//�X�C�b�`2�Ȃ�΃X�C�b�`2�p�̓����蔻���`��
						if (mapDatafirst[fl_check][tate][yoko] == s2)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 255, 0), FALSE);
						}

						//�X�C�b�`3�Ȃ�΃X�C�b�`3�p�̓����蔻���`��
						if (mapDatafirst[fl_check][tate][yoko] == s3)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 255, 0), FALSE);
						}

						//�X�C�b�`4�Ȃ�΃X�C�b�`4�p�̓����蔻���`��
						if (mapDatafirst[fl_check][tate][yoko] == s4)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 255, 0), FALSE);
						}

						//���Ȃ�Ό��p�̓����蔻���`��
						if (mapDatafirst[fl_check][tate][yoko] == ki)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(255, 255, 0), FALSE);
						}

						//�K�i�Ȃ�ΊK�i�̓����蔻���`��
						if (mapDatafirst[fl_check][tate][yoko] == st)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 0, 0), FALSE);
						}
					}

					DrawString(0, 0, "�v���C���(�X�y�[�X�L�[�������ĉ�����)", GetColor(255, 255, 255));
				}
			}

		//�v���C���[A�̓����蔻��̕`��i�f�o�b�O�p�j
		DrawBox(player_A.coll.left, player_A.coll.top, player_A.coll.right, player_A.coll.bottom, GetColor(255, 0, 0), FALSE);

		//�v���C���[B�̓����蔻��̕`��i�f�o�b�O�p�j
		DrawBox(player_B.coll.left, player_B.coll.top, player_B.coll.right, player_B.coll.bottom, GetColor(255, 0, 0), FALSE);

	}

	//DrawString(0, 0, "�v���C���[A�FWASD�ő���\n�v���C���[B�F�����L�[�ő���", GetColor(255, 255, 255));
	return;
}

//�Q�[���I�[�o�[���
VOID MY_OVER(VOID)
{
	MY_OVER_PROC();  //����
	MY_OVER_DRAW();  //�`��
	MY_PLAY_INIT();     //�v���C��ʂ̏�����

	return;
}

//�Q�[���I�[�o�[��ʂ̏���
VOID MY_OVER_PROC(VOID)
{
	//�G�X�P�[�v�L�[����������A�X�^�[�g�V�[���ֈړ�����
	if (CheckHitKey(KEY_INPUT_ESCAPE) == TRUE)
	{
		//BGM������Ă���Ȃ�
		if (CheckSoundMem(BGM_COMP.handle) != 0)
		{
			StopSoundMem(BGM_COMP.handle);	//BGM���~�߂�
		}
		GameScene = GAME_SCENE_START;
		return;
	}

	//BGM������Ă��Ȃ��Ȃ�
	if (CheckSoundMem(BGM_COMP.handle) == 0)
	{
		//BGM�̉��ʂ�������
		ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, BGM_COMP.handle); //MUSIC_VOLUME�ŉ��ʒ���
		PlaySoundMem(BGM_COMP.handle, DX_PLAYTYPE_LOOP);
	}

	//�R���v���[�g�̓_��
	if (ImageEndCOMP.Cnt < ImageEndCOMP.CntMAX)
	{
		ImageEndCOMP.Cnt += IMAGE_END_COMP_CNT;
	}
	else
	{
		//�`�悷��/���Ȃ������߂�
		if (ImageEndCOMP.IsDraw == FALSE)
		{
			ImageEndCOMP.IsDraw = TRUE;
		}
		else if (ImageEndCOMP.IsDraw == TRUE)
		{
			ImageEndCOMP.IsDraw = FALSE;
		}
		ImageEndCOMP.Cnt = 0;
	}

	return;
}

//�Q�[���I�[�o�[��ʂ̕`��
VOID MY_OVER_DRAW(VOID)
{
	DrawGraph(ImageTitleBK.x, ImageTitleBK.y, ImageTitleBK.handle, TRUE);	//�Q�[���I�[�o�[�w�i�̕`��

	//�_��
	if (ImageEndCOMP.IsDraw == TRUE)
	{
		//�R���v���[�g���S�̕`��
		DrawGraph(ImageEndCOMP.image.x, ImageEndCOMP.image.y, ImageEndCOMP.image.handle, TRUE);

		//�G���h�^�C�g���̕`��
		DrawGraph(ImageTitleEND.image.x, ImageTitleEND.image.y, ImageTitleEND.image.handle, TRUE);
	}

	return;
}


//�G���h���
VOID MY_END(VOID)
{
	MY_END_PROC();	//�G���h��ʂ̏���
	MY_END_DRAW();	//�G���h��ʂ̕`��
	MY_PLAY_INIT();     //�v���C��ʂ̏�����

	return;
}

//�G���h��ʂ̏���
VOID MY_END_PROC(VOID)
{
	//�v���C��ʏ�����
	MY_PLAY_INIT();

	//�G�X�P�[�v�L�[����������A�X�^�[�g�V�[���ֈړ�����
	if (CheckHitKey(KEY_INPUT_ESCAPE) == TRUE)
	{
		//BGM������Ă���Ȃ�
		if (CheckSoundMem(BGM_COMP.handle) != 0)
		{
			StopSoundMem(BGM_COMP.handle);	//BGM���~�߂�
		}
		GameScene = GAME_SCENE_START;
		return;
	}

	//BGM������Ă��Ȃ��Ȃ�
	if (CheckSoundMem(BGM_COMP.handle) == 0)
	{
		//BGM�̉��ʂ�������
		ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, BGM_COMP.handle); //MUSIC_VOLUME�ŉ��ʒ���
		PlaySoundMem(BGM_COMP.handle, DX_PLAYTYPE_LOOP);
	}

	//�R���v���[�g�̓_��
	if (ImageEndCOMP.Cnt < ImageEndCOMP.CntMAX)
	{
		ImageEndCOMP.Cnt += IMAGE_END_COMP_CNT;
	}
	else
	{
		//�`�悷��/���Ȃ������߂�
		if (ImageEndCOMP.IsDraw == FALSE)
		{
			ImageEndCOMP.IsDraw = TRUE;
		}
		else if (ImageEndCOMP.IsDraw == TRUE)
		{
			ImageEndCOMP.IsDraw = FALSE;
		}
		ImageEndCOMP.Cnt = 0;
	}

	return;
}

//�G���h��ʂ̕`��
VOID MY_END_DRAW(VOID)
{
	DrawGraph(ImageTitleBK.x, ImageTitleBK.y, ImageTitleBK.handle, TRUE);	//�G���h�w�i�̕`��

	//�_��
	if (ImageEndCOMP.IsDraw == TRUE)
	{
		//�R���v���[�g���S�̕`��
		DrawGraph(ImageEndCOMP.image.x, ImageEndCOMP.image.y, ImageEndCOMP.image.handle, TRUE);

		//�G���h�^�C�g���̕`��
		DrawGraph(ImageTitleEND.image.x, ImageTitleEND.image.y, ImageTitleEND.image.handle, TRUE);
	}

	//�f�o�b�O���肪ON�Ȃ�f�o�b�O�p�\��������
	/*if (DEBUG == "ON") {
		DrawString(0, 0, "�G���h���(�G�X�P�[�v�L�[�������ĉ�����)", GetColor(255, 0, 255));
	}*/
	return;
}

//�摜���܂Ƃ߂ēǂݍ��ފ֐�
BOOL MY_LOAD_IMAGE(VOID)
{
	//�v���C���[A�̉摜
	strcpy_s(player_A.image.path, IMAGE_player_A_PATH);		//�p�X�̐ݒ�
	player_A.image.handle = LoadGraph(player_A.image.path);	//�ǂݍ���
	if (player_A.image.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), IMAGE_player_A_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//�v���C���[B�̉摜
	strcpy_s(player_B.image.path, IMAGE_player_B_PATH);		//�p�X�̐ݒ�
	player_B.image.handle = LoadGraph(player_B.image.path);	//�ǂݍ���
	if (player_B.image.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), IMAGE_player_B_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//�G�P�̉摜
	strcpy_s(enemy_1.image.path, IMAGE_enemy_1_PATH);		//�p�X�̐ݒ�
	enemy_1.image.handle = LoadGraph(enemy_1.image.path);	//�ǂݍ���
	if (enemy_1.image.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), IMAGE_enemy_1_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//�G2�̉摜
	strcpy_s(enemy_2.image.path, IMAGE_enemy_2_PATH);		//�p�X�̐ݒ�
	enemy_2.image.handle = LoadGraph(enemy_2.image.path);	//�ǂݍ���
	if (enemy_2.image.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), IMAGE_enemy_2_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//�G3�̉摜
	strcpy_s(enemy_3.image.path, IMAGE_enemy_3_PATH);		//�p�X�̐ݒ�
	enemy_3.image.handle = LoadGraph(enemy_3.image.path);	//�ǂݍ���
	if (enemy_3.image.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), IMAGE_enemy_3_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//�^�C�g���w�i
	strcpy_s(ImageTitleBK.path, IMAGE_TITLE_BK_PATH);			//�p�X�̐ݒ�
	ImageTitleBK.handle = LoadGraph(ImageTitleBK.path);			//�ǂݍ���
	if (ImageTitleBK.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_BK_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageTitleBK.handle, &ImageTitleBK.width, &ImageTitleBK.height);	//�摜�̕��ƍ�����f�擾
	ImageTitleBK.x = GAME_WIDTH / 2 - ImageTitleBK.width / 2;		//���E��������
	ImageTitleBK.y = GAME_HEIGHT / 2 - ImageTitleBK.height / 2;		//�㉺��������

	//�^�C�g�����S
	strcpy_s(ImageTitleROGO.image.path, IMAGE_TITLE_ROGO_PATH);					//�p�X�̐ݒ�
	ImageTitleROGO.image.handle = LoadGraph(ImageTitleROGO.image.path);			//�ǂݍ���
	if (ImageTitleROGO.image.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_ROGO_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageTitleROGO.image.handle, &ImageTitleROGO.image.width, &ImageTitleROGO.image.height);	//�摜�̕��ƍ������擾
	ImageTitleROGO.image.x = 230;							//�����Ă��镔������`�悵����
	ImageTitleROGO.image.y = GAME_HEIGHT / 2;				//������
	ImageTitleROGO.angle = DX_PI * 2;						//��]��
	ImageTitleROGO.angleMAX = DX_PI * 2;					//��]��MAX
	ImageTitleROGO.rate = 0.0;								//�g�嗦
	ImageTitleROGO.rateMAX = IMAGE_TITLE_ROGO_ROTA_MAX;		//�g�嗦MAX

	//�^�C�g���X�^�[�g
	strcpy_s(ImageTitleSTART.image.path, IMAGE_TITLE_START_PATH);					//�p�X�̐ݒ�
	ImageTitleSTART.image.handle = LoadGraph(ImageTitleSTART.image.path);			//�ǂݍ���
	if (ImageTitleSTART.image.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_START_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageTitleSTART.image.handle, &ImageTitleSTART.image.width, &ImageTitleSTART.image.height);	//�摜�̕��ƍ������擾
	ImageTitleSTART.image.x = GAME_WIDTH / 2 - ImageTitleSTART.image.width / 2;					//���E��������
	ImageTitleSTART.image.y = ImageTitleROGO.image.y + ImageTitleROGO.image.height / 2 + 10;	//���S�̉��ɕ\��
	ImageTitleSTART.Cnt = 0.0;								//�J�E���^
	ImageTitleSTART.CntMAX = IMAGE_TITLE_START_CNT_MAX;		//�J�E���^MAX
	ImageTitleSTART.IsDraw = FALSE;							//�`�悳���Ȃ�

	//�G���h�R���v
	strcpy_s(ImageEndCOMP.image.path, IMAGE_END_COMP_PATH);
	ImageEndCOMP.image.handle = LoadGraph(ImageEndCOMP.image.path);
	if (ImageEndCOMP.image.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_END_COMP_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	GetGraphSize(ImageEndCOMP.image.handle, &ImageEndCOMP.image.width, &ImageEndCOMP.image.height);	//�摜�̕��ƍ������擾
	ImageEndCOMP.image.x = GAME_WIDTH / 2 - ImageEndCOMP.image.width / 2;			//���E��������
	ImageEndCOMP.image.y = GAME_HEIGHT / 2 - ImageEndCOMP.image.height / 2;			//�㉺��������
	ImageEndCOMP.Cnt = 0.0;									//�J�E���^
	ImageEndCOMP.CntMAX = IMAGE_END_COMP_CNT_MAX;			//�J�E���^MAX
	ImageEndCOMP.IsDraw = TRUE;							//�`�悳���Ȃ�

	//�G���h�^�C�g��
	strcpy_s(ImageTitleEND.image.path, IMAGE_TITLE_END_PATH);					//�p�X�̐ݒ�
	ImageTitleEND.image.handle = LoadGraph(ImageTitleEND.image.path);			//�ǂݍ���
	if (ImageTitleEND.image.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_END_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageTitleEND.image.handle, &ImageTitleEND.image.width, &ImageTitleEND.image.height);	//�摜�̕��ƍ������擾
	ImageTitleEND.image.x = GAME_WIDTH / 2 - ImageTitleEND.image.width / 2 + 10;					//���E��������
	ImageTitleEND.image.y = ImageEndCOMP.image.y + ImageEndCOMP.image.height / 2 + 150;	//���S�̉��ɕ\��
	ImageTitleEND.Cnt = 0.0;								//�J�E���^
	ImageTitleEND.CntMAX = IMAGE_END_COMP_CNT_MAX;		    //�J�E���^MAX
	ImageTitleEND.IsDraw = FALSE;							//�`�悳���Ȃ�

	//�}�b�v�̉摜�𕪊�����
	int mapRes = LoadDivGraph(
		GAME_MAP_PATH,										//�}�b�v�̃p�X
		MAP_DIV_NUM, MAP_DIV_TATE, MAP_DIV_YOKO,			//�}�b�v�𕪊����鐔
		MAP_DIV_WIDTH, MAP_DIV_HEIGHT,						//�摜�𕪊�����̕��ƍ���
		&mapChip.handle[0]);								//���������摜������n���h��

	if (mapRes == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), GAME_MAP_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//���ƍ������擾
	GetGraphSize(mapChip.handle[0], &mapChip.width, &mapChip.height);

	for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
	{
		for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
		{
			for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
			{
				//�}�b�v�f�[�^�������p�ɏ����R�s�[
				mapDatafirstInit[floor][tate][yoko] = mapDatafirst[floor][tate][yoko];

				//�����K�w�}�b�v�̎�ނ��R�s�[
				map[floor][tate][yoko].kind = mapDatafirst[floor][tate][yoko];

				//�}�b�v�̕��ƍ������R�s�[
				map[floor][tate][yoko].width = mapChip.width;
				map[floor][tate][yoko].height = mapChip.height;

				//�}�b�v�̍��W��ݒ�
				map[floor][tate][yoko].x = yoko * map[floor][tate][yoko].width;
				map[floor][tate][yoko].y = tate * map[floor][tate][yoko].height;
			}
		}
	}

	//�}�b�v�̓����蔻���ݒ肷��
	for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
	{
		for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
		{
			for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
			{
				//�}�b�v�̓����蔻���ݒ�
				mapColl[floor][tate][yoko].left = (yoko + 0) * mapChip.width + 1;
				mapColl[floor][tate][yoko].top = (tate + 0) * mapChip.height + 1;
				mapColl[floor][tate][yoko].right = (yoko + 1) * mapChip.width - 1;
				mapColl[floor][tate][yoko].bottom = (tate + 1) * mapChip.height - 1;

				//�}�b�v�̏�����Ԃ�ݒ�
				mapCollInit[floor][tate][yoko].left = mapColl[floor][tate][yoko].left;
				mapCollInit[floor][tate][yoko].top = mapColl[floor][tate][yoko].top;
				mapCollInit[floor][tate][yoko].right = mapColl[floor][tate][yoko].right;
				mapCollInit[floor][tate][yoko].bottom = mapColl[floor][tate][yoko].bottom;

			}
		}
	}

	return TRUE;
}

//�摜���܂Ƃ߂č폜����֐�
VOID MY_DELETE_IMAGE(VOID)
{
	DeleteGraph(ImageTitleBK.handle);           //�^�C�g���w�i�폜
	DeleteGraph(ImageTitleROGO.image.handle);   //�^�C�g�����S�폜
	DeleteGraph(ImageTitleSTART.image.handle);  //�^�C�g�������폜
	DeleteGraph(ImageEndCOMP.image.handle);     //�G���h�R���v���S�폜
	DeleteGraph(ImageTitleEND.image.handle);     //�G���h�^�C�g���폜
	DeleteGraph(ImageBack.handle);              //�v���C�w�i�폜
	DeleteGraph(player_A.image.handle);           //�v���C���[A�摜�폜
	DeleteGraph(player_B.image.handle);           //�v���C���[B�摜�폜
	DeleteGraph(enemy_1.image.handle);           //�G1�摜�폜
	DeleteGraph(enemy_2.image.handle);           //�G2�摜�폜
	DeleteGraph(enemy_3.image.handle);           //�G3�摜�폜

	for (int i_num = 0; i_num < MAP_DIV_NUM; i_num++) { DeleteGraph(mapChip.handle[i_num]); }

	return;
}

//���y���܂Ƃ߂ēǂݍ��ފ֐�
BOOL MY_LOAD_MUSIC(VOID)
{
	//�v���C��ʂ�BGM
	strcpy_s(BGM.path, MUSIC_BGM_PATH);
	BGM.handle = LoadSoundMem(BGM.path);
	if (BGM.handle == -1) {
		MessageBox(GetMainWindowHandle(), MUSIC_BGM_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//�^�C�g����BGM
	strcpy_s(BGM_TITLE.path, MUSIC_BGM_TITLE_PATH);				//�p�X�̐ݒ�
	BGM_TITLE.handle = LoadSoundMem(BGM_TITLE.path);			//�ǂݍ���
	if (BGM_TITLE.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), MUSIC_BGM_TITLE_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//�R���v���[�gBGM
	strcpy_s(BGM_COMP.path, MUSIC_BGM_COMP_PATH);				//�p�X�̐ݒ�
	BGM_COMP.handle = LoadSoundMem(BGM_COMP.path);				//�ǂݍ���
	if (BGM_COMP.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), MUSIC_BGM_COMP_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//�U����
	strcpy_s(SE_ATACK.path, MUSIC_SE_ATACK_PATH);				//�p�X�̐ݒ�
	SE_ATACK.handle = LoadSoundMem(SE_ATACK.path);				//�ǂݍ���
	if (SE_ATACK.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), MUSIC_SE_ATACK_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//�X�C�b�`��
	strcpy_s(SE_SWITCH.path, MUSIC_SE_SWITCH_PATH);				//�p�X�̐ݒ�
	SE_SWITCH.handle = LoadSoundMem(SE_SWITCH.path);				//�ǂݍ���
	if (SE_SWITCH.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), MUSIC_SE_SWITCH_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//�����艹
	strcpy_s(SE_KEY.path, MUSIC_SE_KEY_PATH);				//�p�X�̐ݒ�
	SE_KEY.handle = LoadSoundMem(SE_KEY.path);				//�ǂݍ���
	if (SE_KEY.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), MUSIC_SE_KEY_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//������艹
	strcpy_s(SE_WEAPON.path, MUSIC_SE_WEAPON_PATH);				//�p�X�̐ݒ�
	SE_WEAPON.handle = LoadSoundMem(SE_WEAPON.path);				//�ǂݍ���
	if (SE_WEAPON.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), MUSIC_SE_WEAPON_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	return TRUE;
}

//���y���܂Ƃ߂č폜����֐�
VOID MY_DELETE_MUSIC(VOID)
{
	DeleteSoundMem(BGM.handle);

	return;
}

//�}�b�v�ƃv���C���[�̓����蔻�������֐�
int MY_CHECK_MAP1_PLAYER_COLL(RECT player)
{
	//�}�b�v�̓����蔻���ݒ肷��
	for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
	{
		for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
		{
			for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
			{
				//�v���C���[�ƃ}�b�v���������Ă���Ƃ�
				if (MY_CHECK_RECT_COLL(player, mapColl[floor][tate][yoko]) == TRUE)
				{
					//�ʘH�̎�
					if (map[floor][tate][yoko].kind == t) { return TRUE_t; }

					//�ǂ̎�
					if (map[floor][tate][yoko].kind == k) { return TRUE_k; }

					//�M�~�b�N1�̎�
					if (map[floor][tate][yoko].kind == m1) { return TRUE_m1; }

					//�M�~�b�N2�̎�
					if (map[floor][tate][yoko].kind == m2) { return TRUE_m2; }

					//�M�~�b�N3�̎�
					if (map[floor][tate][yoko].kind == m3) { return TRUE_m3; }

					//�M�~�b�N4�̎�
					if (map[floor][tate][yoko].kind == m4) { return TRUE_m4; }

					//�X�C�b�`1�̎�
					if (map[floor][tate][yoko].kind == s1) { return TRUE_s1; }

					//�X�C�b�`2�̎�
					if (map[floor][tate][yoko].kind == s2) { return TRUE_s2; }

					//�X�C�b�`3�̎�
					if (map[floor][tate][yoko].kind == s3) { return TRUE_s3; }

					//�X�C�b�`4�̎�
					if (map[floor][tate][yoko].kind == s4) { return TRUE_s4; }

					//���̎�
					if (map[floor][tate][yoko].kind == ki) { return TRUE_ki; }

					//�����̎�
					if (map[floor][tate][yoko].kind == kl) { return TRUE_kl; }

					//���̎�
					if (map[floor][tate][yoko].kind == br) { return TRUE_br; }

					//���̎�
					if (map[floor][tate][yoko].kind == sp) { return TRUE_sp; }

					//��̎�
					if (map[floor][tate][yoko].kind == ca) { return TRUE_ca; }

					//�v���C���[A�p�̃S�[���̎�
					if (map[floor][tate][yoko].kind == ag) { return TRUE_ag; }

					//�v���C���[B�p�̃S�[���̎�
					if (map[floor][tate][yoko].kind == bg) { return TRUE_bg; }

					//�K�i�̎�
					if (map[floor][tate][yoko].kind == st) { return TRUE_st; }

					//���[�v�����P�̎�
					if (map[floor][tate][yoko].kind == w1) { return TRUE_w1; }

					//���[�v�����Q�̎�
					if (map[floor][tate][yoko].kind == w2) { return TRUE_w2; }
				}
			}
		}
	}

	return FALSE;
}

//�̈�̓����蔻�������֐�
BOOL MY_CHECK_RECT_COLL(RECT a, RECT b)
{
	if (a.left < b.right &&
		a.top < b.bottom &&
		a.right > b.left &&
		a.bottom > b.top 
		)
	{
		return TRUE;  //�������Ă���
	}

	return FALSE;     //�������Ă��Ȃ�
}