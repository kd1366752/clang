#include<stdio.h>
#define MapNum 3
#define W 10
#define H 5

typedef struct {
	int m_map[H][W];
}Map;

void SetMap(char* filename, Map* m);
void DrawMap(Map m);

main() {
	Map MapData;
	char* MapFileName[MapNum] =
	{ "map0.txt","map1.txt","map2.txt" };
	int select;
	printf("マップデータ(0,1,2)>");
	scanf("%d", &select);
	if (select >= 0 && select < MapNum) {
		SetMap(MapFileName[select], &MapData);
		DrawMap(MapData);
	}
}

void SetMap(char* filename, Map* m) {
	FILE* fp;
	char ch;
	int i, j;
	if (fp = fopen("map0.txt","r")){
		for (i = 0; i < H; i++) {
			for (j = 0; j < W; j++) {
				ch = fgets(fp);
				m->m_map[i][j] = ch - '0';
			}
			fgets(fp);
		}
	}
}

void DrawMap(Map m) {
	int i, j;
	for (i = 0; i < H; i++) {
		for (j = 0; j < W; j++) {
			if (m.m_map[i][j] == 1) {
				printf("■");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
}