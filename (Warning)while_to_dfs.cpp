#include<conio.h>
#include<cstdio>

using namespace std;

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
int map[9][9], T;

bool check(int y, int x){
	if (y < 0 || x < 0 || y >= T || x >= T ) return false;
	return true;
}


/*
@@@알고리즘에서 while보다는 dfs로 하자 ( 확장해나갈때 ) 인덱스 실수 많이 한다 while은(위험)
void color(int y, int x, int dir){
	printf("초기값 y [%d] x [%d]  방향 [%d] \n", y, x,dir);
	int ny = y + dy[dir], nx = x + dx[dir];
	while (1){
		printf("와일들어옴 y [%d]  x [%d]\n",ny,nx);
		if (check(ny, nx) == false){
			printf("1 %d %d \n", ny, nx);
			break;
		}
		else if (map[ny][nx] == 6){
			printf("2  %d %d \n", ny, nx);
			break;
		}
		else if(map[ny][nx] != 6){
			_getch();
			if (map[ny][nx] != 2){
				printf("3  %d %d\n", ny, nx);
				map[ny][nx] = 9;
				color(ny, nx, dir);
				break;
			}
			else color(ny, nx, dir);
		}
		break;
		_getch();
	}
}*/


void color(int y, int x, int dir){
	int ny = y + dy[dir], nx = x + dx[dir];
	if (check(ny, nx) == true){
		if (map[ny][nx] == 0){
			map[ny][nx] = 9;
		}
		color(ny, nx, dir);
	}
}
void dcolor(int y, int x, int dir){
	int ny = y + dy[dir], nx = x + dx[dir];
	if (check(ny, nx) == true){
		if (map[ny][nx] == 9){
			map[ny][nx] = 0;
		}
		dcolor(ny, nx, dir);
	}
}

int main(){

	scanf("%d", &T);
	for (int i = 0; i < T; i++){
		for (int j = 0; j < T; j++){
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < 4; i++){
		color(3, 5, i);

		for (int i = 0; i < T; i++){
			for (int j = 0; j < T; j++){
				printf("%d ", map[i][j]);
			}printf("\n");
		}

		_getch();
	}
	for (int i = 0; i < 4; i++){

		dcolor(3, 5, i);
		for (int i = 0; i < T; i++){
			for (int j = 0; j < T; j++){
				printf("%d ", map[i][j]);
			}printf("\n");
		}
		_getch();
	}

	return 0;
}
