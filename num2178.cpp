#include <cstdio>

using namespace std;

int arr[100][100];
int v_arr[100][100];

int f_x, f_y;
int a[4] = { 1, 0, -1, 0 };
int b[4] = { 0, -1, 0, 1 };

void bfs(int x, int y){
	int step = 1;
	arr[x][y] = step;
	v_arr[x][y] = 1;
	while ((x != f_x) && (y != f_y)){
		step++;
		for (int i = 0; i < 4; i++){
			int m_x = x + a[i];
			int m_y = y + b[i];
			if (v_arr[m_x][m_y] != 1){
				arr[m_x][m_y] = step;
				v_arr[m_x][m_y] = 1;
			}
		}
	}
	return;
}
int main(){
	scanf("%d %d", &f_y, &f_x);

	for (int i = 0; i < f_y; i++){
		for (int j = 0; j < f_x; j++){
			scanf("%1d", &arr[i][j]);
			if (arr[i][j] == 0){
				v_arr[i][j] = 1;       //visit이 1이면 못가는 곳
			}
			else v_arr[i][j] = 0;
		}
	}

	bfs(0, 0);


	printf("%d", arr[f_x - 1, f_y - 1]);
	return 0;
}
