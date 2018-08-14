#include<cstdio>
#include<queue>

using namespace std;
char map[51][51];
int visit[51][51];
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };
int R, C;

typedef struct node{
	int y;
	int x;
	int w;
}node;
int flag = 0;
queue<node> Q;

void bfs(){
	node use;
	while (!Q.empty()){
		use = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++){
			int next_y = use.y + dy[i];
			int next_x = use.x + dx[i];
			if (next_y < 0 || next_x < 0 || next_x == C || next_y == R || map[next_y][next_x] == 'X' || visit[next_y][next_x] != 0) continue;
			if (map[next_y][next_x] == 'D'){
				if (use.w == 1){
					printf("%d", visit[use.y][use.x]);
					flag = 1;
					return;
				}
				else continue;
			}
			visit[next_y][next_x] = visit[use.y][use.x] + 1;
			Q.push({ next_y, next_x, use.w });
		}
		//for (int r = 0; r < R; r++){
		//	for (int c = 0; c < C; c++){
		//		printf("%d  ", visit[r][c]);
		//	}printf("\n");
		//}printf("-------------------------------------\n");
	}
}
int main(){
	scanf("%d %d", &R, &C);
	int s_x, s_y;
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'S'){
				visit[i][j] = 1;
				s_x = j, s_y = i;
				//Q.push({ i, j, 1 }); //1 두더지
			}
			if (map[i][j] == '*'){
				visit[i][j] = 1;
				Q.push({ i, j, 0 }); //0 빗물
			}
		}
	}
	Q.push({ s_y, s_x, 1 });
	bfs();
	if (flag == 0) printf("KAKTUS");

	return 0;
}
