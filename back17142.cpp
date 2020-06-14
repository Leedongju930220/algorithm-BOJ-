#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<queue>
#include<vector>

using namespace std;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int map[50][50];
int cMap[50][50];
int N, M, minValue = 987654321,zeroCnt,cZeroCnt;
typedef struct node {
	int y;
	int x;
}node;
queue<node> q;
vector<node> v;
bool virusVisit[10];

void setVirus() {
	node cur;
	while (!q.empty()) {
		q.pop();
	}
	for (int i = 0; i < v.size(); i++) {
		cur = v[i];
		if (virusVisit[i] == 0) {
			map[cur.y][cur.x] = -1; // 비활성 바이러스 = -1
		}
		else {
			map[cur.y][cur.x] = 1;  // 활성은 1부터 시작 
			q.push({ cur.y,cur.x });
		}
	}
}
void bfs() {
	int time = 0;
	int size = 0;
	node cur;
	bool flag = true;
	while (!q.empty()) {
		size = q.size();
		time++;
		for (int i = 0; i < size; i++) {
			cur = q.front();
			q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nextY = cur.y + dy[dir];
				int nextX = cur.x + dx[dir];
				if (nextY < 0 || nextX < 0 || nextY == N || nextX == N)continue;
				if (map[nextY][nextX]  == -3) continue;
				if (map[nextY][nextX] == 0 || map[nextY][nextX] == -1) {
					if (map[nextY][nextX] == 0)zeroCnt--;
					map[nextY][nextX] = time + 1;
					q.push({ nextY,nextX });
				}
				if (zeroCnt == 0) {
					flag = false;
					break;
				}
			}
			if (flag == false) break;

		}
		if (flag == false) break;
	}
	if (zeroCnt == 0 && time < minValue) {
		minValue = time;
	}
	return;
}
void dfs(int depth , int cur) {
	if (depth >= M) {
		zeroCnt = cZeroCnt;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cMap[i][j] = map[i][j];
			}
		}
		setVirus();
		bfs();

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = cMap[i][j];
			}
		}
		return;
	}
	for (int i = cur; i < v.size(); i++) {
		if (virusVisit[i] == 0) {
			virusVisit[i] = 1;
			dfs(depth + 1, i+1);
			virusVisit[i] = 0;
		}
	}
}
void input() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for(int j = 0 ; j < N  ;j++){
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) {
				v.push_back({ i,j });
			}
			if (map[i][j] == 0) {
				zeroCnt++;
			}
			if (map[i][j] == 1) {
				map[i][j] = -3; //벽이면 -3
			}
		}
	}
}
int main() {
	input();
	cZeroCnt = zeroCnt;
	if(zeroCnt !=0)dfs(0,0);

	if (cZeroCnt == 0) printf("0");
	else if (minValue == 987654321) printf("-1");
	else printf("%d", minValue);

	return 0;
}
