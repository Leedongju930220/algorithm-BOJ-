#include<cstdio>

int N, M, H;
int map[32][12];
int i_cnt;
typedef struct node{
	  int f_y;
	  int f_x;
};
node able_labber[270];
int result = 5;

int check(){
	  int compare;
	  for (int i = 1; i <= N; i++){
		  compare = i;
		  for (int j = 1; j <= H; j++){
			  if (map[j][compare] == 1){
				  compare += 1;
			  }
			  else if (map[j][compare] == -1){
				  compare -= 1;
			  }
			  //else continue;
		  }
		  if (compare != i) return 1;
	  }
	  return 0;
}

void combi(int cur, int index){
	  if (check() == 0){
		  if (result > cur) result = cur;
		  return;
	  }
	  if (cur >= 3 || cur >= result) return;
	  for (int i = index; i < i_cnt; i++){
		  if (map[able_labber[i].f_y][able_labber[i].f_x] == 0 && map[able_labber[i].f_y][able_labber[i].f_x + 1] == 0){
			  map[able_labber[i].f_y][able_labber[i].f_x] = 1;
			  map[able_labber[i].f_y][able_labber[i].f_x + 1] = -1;
			  combi(cur + 1, i + 1);
			  map[able_labber[i].f_y][able_labber[i].f_x] = 0;
			  map[able_labber[i].f_y][able_labber[i].f_x + 1] = 0;
		  }
	  }
}
int main(){
	  scanf("%d %d %d", &N, &M, &H); // H : 세로 N : 가로
	  int a, b;
	  for (int i = 0; i < M; i++){
		  scanf("%d %d", &a, &b);
		  map[a][b] = 1;
		  map[a][b + 1] = -1;
	  }
	  for (int i = 1; i <= H; i++){
		  for (int j = 1; j <= N - 1; j++){
			  if (map[i][j] == 0 && map[i][j + 1] == 0){
				  able_labber[i_cnt] = { i, j };
				  i_cnt++;
			  }
		  }
	  }

	  combi(0, 0);

	  if (result <= 3) printf("%d", result);
	  else printf("-1");

	  return 0;
}
