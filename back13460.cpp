#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<queue>

using namespace std;


int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int N, M,time= 0,resultTime = -1;
char map[11][11];
bool visit[11][11][11][11];
typedef struct node {
	int ry, rx, by, bx;
}node;
queue<node> q;

void input() {
	int ry, rx, by, bx;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'B') {
				by = i;
				bx = j;
			}
			if (map[i][j] == 'R') {
				ry = i;
				rx = j;
			}
			
		}
	}
	visit[ry][rx][by][bx] = 1;
	node cur = { ry,rx,by,bx };
	q.push(cur);
}
void bfs() {
	node cur;
	bool flag = 0;
	bool bflag = 0;
	while (!q.empty()) {
		int size = q.size();
		time++;
		if (time > 10) {
			resultTime = -1;
			return;
		}
		while (size--) {
			
			cur = q.front();
			q.pop();

			for (int dir = 0; dir < 4; dir++) {
				flag = 0;
				bflag = 0;
				int nextRy = cur.ry, nextRx = cur.rx, nextBy = cur.by, nextBx = cur.bx;
				int rC = 0, bC = 0;
				while (1) {
					if (map[nextRy + dy[dir]][nextRx + dx[dir]] == '#') break;
					if (map[nextRy + dy[dir]][nextRx + dx[dir]] == 'O') {
						flag = 1;
						break;
					}
					nextRy = nextRy + dy[dir];
					nextRx = nextRx + dx[dir];
					rC++;
				}
				while (1) {
					if (map[nextBy + dy[dir]][nextBx + dx[dir]] == '#') break;
					if (map[nextBy + dy[dir]][nextBx + dx[dir]] == 'O') {
						bflag = 1;
						break;
					}
					nextBy = nextBy + dy[dir];
					nextBx = nextBx + dx[dir];
					bC++;
				}
				if (nextRy == nextBy && nextRx == nextBx) {
					if (rC > bC) {
						nextRy = nextRy - dy[dir];
						nextRx = nextRx - dx[dir];
					}
					if (rC < bC) {
						nextBy = nextBy - dy[dir];
						nextBx = nextBx - dx[dir];
					}
				}
				if (flag == 1 && bflag == 0) {
					resultTime = time;
					return;
				}
				if (flag == 1 && bflag == 1) {
					continue;
				}
				if (bflag == 1) {
					continue;
				}
				if (visit[nextRy][nextRx][nextBy][nextBx] == 1) {
					continue;
				}
				visit[nextRy][nextRx][nextBy][nextBx] = 1;
				q.push({ nextRy,nextRx, nextBy,nextBx });

			}

			
		}
		
	}

}
int main() {
	input();
	
	bfs();
	printf("%d", resultTime);

	return 0;
}
