#include <stdio.h>
#include <vector>

using namespace std;

int visited[102][102] = { 0, };
int yy[4] = { 1, 0, -1, 0 };
int xx[4] = { 0, -1, 0, 1 };
int result = 0;
int x, y;

void visit(int xxx, int yyy){
	if (xxx >= 0 && xxx <= 100 && yyy >= 0 && yyy <= 100)
		visited[xxx][yyy] = 1;
}
void dragon_c(vector<int> dragon, int gene){
	for (int j = 0 ; j<gene; j++){
		for (int i = dragon.size()-1; i>=0; i--){
			int next_d = (dragon[i] + 1) % 4;
			x = x + xx[next_d];
			y = y + yy[next_d];
			visit(y, x);
			dragon.push_back(next_d);
			}
	}
}
int main(){
	int d, g, N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d %d %d %d", &y, &x, &d, &g);
		visit(y, x);
		x = x + xx[d], y = y + yy[d];
		visit(y, x);
		vector<int> dragon;
		dragon.push_back(d);
		dragon_c(dragon, g);
	}
	for (int i = 0; i < 100; i++){
		for (int j = 0; j < 100; j++){
			if (visited[i][j] == 1 && visited[i][j + 1] == 1 && visited[i + 1][j] == 1 && visited[i + 1][j+1] == 1){
				result++;
			}
		}
	}
	printf("%d", result);

	return 0;
}
// 모듈러의 활용!!
