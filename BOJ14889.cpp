#include<cstdio>
#define MAX 20
int num[MAX];
int result = 987654321;
int NN;
int map[MAX+1][MAX+1];

void cal(){
	int team1 = 0, team2 = 0;
	for (int i = 0; i < NN - 1; i++){
		if (num[i] == 1){
			for (int j = i + 1; j < NN; j++){
				if (num[j] == 1){
					team1 = team1 + map[i][j] + map[j][i];		
				}
			}
		}
		else{
			for (int j = i + 1; j < NN; j++){
				if (num[j] == 0){	
					team2 = team2 + map[i][j] + map[j][i];
				}
			}
		}
	}
	int min = team1 - team2;
	if (min < 0) min *= -1;
	if (result > min) result = min;
	return;
}
void combi(int p, int d){
	if (d == NN/2){
		cal();
		return;
	}
	if (p == NN) return;
	num[p] = 1;
	combi(p + 1, d + 1);
	num[p] = 0;
	combi(p + 1, d);
}
int main(){
	scanf("%d", &NN);
	for (int i = 0; i < NN; i++){
		for (int j = 0; j < NN; j++){
			scanf("%d", &map[i][j]);
		}
	}
	combi(1, 0);
	printf("%d", result);
	return 0;
}
