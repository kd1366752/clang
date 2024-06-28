#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define Skil_Num 3
#define Mob_Num 3

typedef unsigned int UINT;

typedef struct {//Skill�^�\����
	char name[20];//�X�L����
	int type;//�X�L���̎��(0:HP�񕜗� 1:AtkUp 2:)
	int use_mp;//�g�pMP��
	int effect;//�X�L������
}Skill;

typedef struct {//Spec�^�\����
	char name[20];//���O
	int hp;//HP
	int atk;//�U����
	int def;//�h���
	UINT state;//���
}Spec;

typedef struct {//Chara�^�\����
	Spec sp;//Spec�^�\���̕ϐ�
	int maxhp;//�ő�HP
	int mp;//MP
	Skill skl[Skil_Num];//Skill�^�\���̔z��
}Chara;

typedef struct {//Mob�^�\����
	Spec sp;//Spec�^�\���̕ϐ�
	int rate;//��Ԉُ�U���������[�g%�\�L
}Mob;

enum BitState {
	Base = 0,//0000 0000�ʏ�
	Poison = 1 << 0,//0000 0001��
	Sleep = 1 << 1,//0000 0010�˂ނ�
	Paralysis = 1 << 2,//0000 0100�܂�
	Burn = 1 << 3,//0000 1000�₯��
	AtkUp = 1 << 4,//0001 0000�U���̓A�b�v
	AtkDown = 1 << 5,//0010 0000�U���̓_�E��
};

void DisplayStatus(UINT s);
void ChangeFlag(UINT* s);
void ClearFlag(UINT* s);

main() 
{
	UINT  MyState = Base;
	ChangeFlag(&MyState);
	DisplayStatus(MyState);
	ClearFlag(&MyState);
	DisplayStatus(MyState);
}

void DisplayStatus(UINT s) {
	printf("****���݂̏��****\n");
	if (s & Poison) {
		printf("��\n");
	}
	if (s & Sleep) {
		printf("����\n");
	}
	if (s & Paralysis) {
		printf("�܂�\n");
	}
	if (s & Burn) {
		printf("�Ώ�\n");
	}
	if (s & AtkUp) {
		printf("�U���A�b�v\n");
	}
	if (s & AtkDown) {
		printf("�U���_�E��\n");
	}
	if (s == Base) {
		printf("�ʏ�U��\n");
	}
	printf("******************\n");
}

void ChangeFlag(UINT* s) {
	int a;
	while (1) {
		printf("�ǂ̏�Ԃɂ��܂���?\n");
		printf("1:�� 2:���� 3:��� 4:�Ώ� 5:�U���� 6:�U���� 0:�I��>");
		scanf("%d", &a);
		if (a == 0) {
			break;
		}
		switch (a) {
		case 1:
			*s |= Poison;
			break;
		case 2:
			*s |= Sleep;
			break;
		case 3:
			*s |= Paralysis;
			break;
		case 4:
			*s |= Burn;
			break;
		case 5:
			*s |= AtkUp;
			break;
		case 6:
			*s |= AtkDown;
			break;
		}
	}
}

void ClearFlag(UINT* s) {
	int a;
	while (1) {
		printf("�ǂ̏�Ԃ��������܂���?\n");
		printf("1:�� 2:���� 3:��� 4:�Ώ� 5:�U���� 6:�U���� 7:�S���� 0:�I��>");
		scanf("%d", &a);
		if (a == 0) {
			break;
		}
		switch (a) {
		case 1:
			*s &= ~Poison;
			break;
		case 2:
			*s &= ~Sleep;
			break;
		case 3:
			*s &= ~Paralysis;
			break;
		case 4:
			*s &= ~Burn;
			break;
		case 5:
			*s &= ~AtkUp;
			break;
		case 6:
			*s &= ~AtkDown;
			break;
		case 7:
			*s = Base;
			break;
		}
	}
}