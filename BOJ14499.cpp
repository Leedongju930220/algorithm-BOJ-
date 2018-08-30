#include<cstdio>

int map[20][20];
int N, M, r, c, k;
int order[1000];
int dice[3][4];

void print_dice(){
	printf("%d\n", dice[1][1]);
}
int map_check(){
	if (map[r][c] == 0) return 0;
	else return 1;
}
void turn_dice(int d){
	int temp;
	if (d == 1){
		temp = dice[1][2];
		dice[1][2] = dice[3][1];
		dice[3][1] = dice[1][0];
		dice[1][0] = dice[1][1];
		dice[1][1] = temp;
	}
	if (d == 2){
		temp = dice[1][0];
		dice[1][0] = dice[3][1];
		dice[3][1] = dice[1][2];
		dice[1][2] = dice[1][1];
		dice[1][1] = temp;
	}
	if (d == 3){
		temp = dice[0][1];
		dice[0][1] = dice[3][1];
		dice[3][1] = dice[2][1];
		dice[2][1] = dice[1][1];
		dice[1][1] = temp;
	}
	if (d == 4){
		temp = dice[3][1];
		dice[3][1] = dice[0][1];
		dice[0][1] = dice[1][1];
		dice[1][1] = dice[2][1];
		dice[2][1] = temp;
	}
}
int map_check(int y, int x){
	if (y >= 0 && x >= 0 && y < N && x < M){
		r = y, c = x;
		return 1;
	}
	else return 0;
}
void dicecheck(int d){
	if (d == 1){
		if (map_check(r, c + 1) == 1){
			turn_dice(1);
			if (map_check() == 0){
				map[r][c] = dice[3][1];
			}
			else{
				dice[3][1] = map[r][c];
				map[r][c] = 0;
			}
			print_dice();
		}
		else return;
	}
	else if (d == 2){
		if (map_check(r, c - 1) == 1){
			turn_dice(2);
			if (map_check() == 0){
				map[r][c] = dice[3][1];
			}
			else{
				dice[3][1] = map[r][c];
				map[r][c] = 0;
			}
			print_dice();
		}
		else return;
	}
	else if (d == 3){
		if (map_check(r - 1, c) == 1){
			turn_dice(3);
			if (map_check() == 0){
				map[r][c] = dice[3][1];
			}
			else{
				dice[3][1] = map[r][c];
				map[r][c] = 0;
			}
			print_dice();
		}
		else return;
	}
	else{
		if (map_check(r + 1, c) == 1){
			turn_dice(4);
			if (map_check() == 0){
				map[r][c] = dice[3][1];
			}
			else{
				dice[3][1] = map[r][c];
				map[r][c] = 0;
			}
			print_dice();
		}
		else return;
	}
}
void start(){
	for (int i = 0; i < k; i++){
		dicecheck(order[i]);
	}
}
int main(){
	scanf("%d %d %d %d %d", &N, &M, &r, &c, &k);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 0; i < k; i++){
		scanf("%d", &order[i]);
	}
	start();


	return 0;
}
