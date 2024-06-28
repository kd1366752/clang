#include<stdio.h>
enum BitState {
	Base = 0,//0000 0000í èÌ
	Poison = 1 << 0,//0000 0001ì≈
	Sleep = 1 << 1,//0000 0010ÇÀÇﬁÇË
	Paralysis = 1 << 2,//0000 0100Ç‹Ç–
	Burn = 1 << 3,//0000 1000Ç‚ÇØÇ«
	AtkUp = 1 << 4,//0001 0000çUåÇóÕÉAÉbÉv
	AtkDown = 1 << 5,//0010 0000çUåÇóÕÉ_ÉEÉì
};

typedef unsigned int UINT;

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
	printf("****åªç›ÇÃèÛë‘****\n");
	if (s & Poison) {
		printf("ì≈\n");
	}
	if (s & Sleep) {
		printf("êáñ∞\n");
	}
	if (s & Paralysis) {
		printf("Ç‹Ç–\n");
	}
	if (s & Burn) {
		printf("âŒèù\n");
	}
	if (s & AtkUp) {
		printf("çUåÇÉAÉbÉv\n");
	}
	if (s & AtkDown) {
		printf("çUåÇÉ_ÉEÉì\n");
	}
	if (s == Base) {
		printf("í èÌçUåÇ\n");
	}
	printf("******************\n");
}

void ChangeFlag(UINT* s) {
	int a;
	while (1) {
		printf("Ç«ÇÃèÛë‘Ç…ÇµÇ‹Ç∑Ç©?\n");
		printf("1:ì≈ 2:êáñ∞ 3:ñÉ·É 4:âŒèù 5:çUåÇÅ™ 6:çUåÇÅ´ 0:èIóπ>");
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
		printf("Ç«ÇÃèÛë‘ÇâèúÇµÇ‹Ç∑Ç©?\n");
		printf("1:ì≈ 2:êáñ∞ 3:ñÉ·É 4:âŒèù 5:çUåÇÅ™ 6:çUåÇÅ´ 7:ëSâèú 0:èIóπ>");
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