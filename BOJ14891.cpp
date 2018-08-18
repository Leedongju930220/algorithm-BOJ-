#include<cstdio>

int tooth[5][9];
int n, th, di,result,temp;
int tooth_di[5];

void check(){
	if (th == 1){
		tooth_di[1] = 1;
		if (tooth[1][3] != tooth[2][7]){
			tooth_di[2] = 1;
			if (tooth[2][3] != tooth[3][7]){
				tooth_di[3] = 1;
				if (tooth[3][3] != tooth[4][7]){
					tooth_di[4] = 1;
				}
			}
		}
	}
	if (th == 2){
		tooth_di[2] = 1;
		if (tooth[2][7] != tooth[1][3]){
			tooth_di[1] = 1;
		}if (tooth[2][3] != tooth[3][7]){
			tooth_di[3] = 1;
			if (tooth[3][3] != tooth[4][7]){
				tooth_di[4] = 1;
			}
		}
	}
	if (th == 3){
		tooth_di[3] = 1;
		if (tooth[3][3] != tooth[4][7]){
			tooth_di[4] = 1;
		}
		if (tooth[3][7] != tooth[2][3]){
			tooth_di[2] = 1;
			if (tooth[2][7] != tooth[1][3]){
				tooth_di[1] = 1;
			}
		}
	}
	if (th == 4){
		tooth_di[4] = 1;
		if (tooth[4][7] != tooth[3][3]){
			tooth_di[3] = 1;
			if (tooth[3][7] != tooth[2][3]){
				tooth_di[2] = 1;
				if (tooth[2][7] != tooth[1][3]){
					tooth_di[1] = 1;
				}
			}
		}
	}
}
void tuning(){
	if (th == 1){
		tooth_di[1] = di;
		for (int i = 2; i < 5; i++){
			if (tooth_di[i] == 0) return;
			if (tooth_di[i] = tooth_di[i - 1] * -1);
		}
		return;
	}
	if (th == 4){
		tooth_di[4] = di;
		for (int i = 3; i > 0; i--){
			if (tooth_di[i] == 0)return;
			if (tooth_di[i] = tooth_di[i + 1] * -1);
		}
		return;
	}
	if (th == 2){
		tooth_di[2] = di;
		if (tooth_di[1] == 1){
			tooth_di[1] = tooth_di[2] * -1;
		}
		if (tooth_di[3] == 1){
			tooth_di[3] = tooth_di[2] * -1;
			if (tooth_di[4] == 1){
				tooth_di[4] = tooth_di[3] * -1;
			}
			else return;
		}
		else return;
	}
	if (th == 3){
		tooth_di[3] = di;
		if (tooth_di[4] == 1){
			tooth_di[4] = tooth_di[3] * -1;
		}
		if (tooth_di[2] == 1){
			tooth_di[2] = tooth_di[3] * -1;
			if (tooth_di[1] == 1){
				tooth_di[1] = tooth_di[2] * -1;
			}
			else return;
		}
		else return;
	}
}
void turn(){
	for (int i = 1; i < 5; i++){
		if (tooth_di[i] == 0)continue;
		if (tooth_di[i] == -1){
			temp = tooth[i][1];
			for (int j = 2; j <= 8; j++){
				tooth[i][j - 1] = tooth[i][j];
			}
			tooth[i][8] = temp;
		}
		if(tooth_di[i] ==1){
			temp = tooth[i][8];
			for (int j = 7; j >=1; j--){
				tooth[i][j + 1] = tooth[i][j];
			}
			tooth[i][1] = temp;
		}
	}

}
void cal(){
	int mul = 1;
	for (int i = 1; i < 5; i++){
		if (tooth[i][1] == 1){
			result = result  + mul;
		}
		mul *= 2;
	}
}
int main(){
	for (int i = 1; i < 5; i++){
		for (int j = 1; j < 9; j++){
			scanf("%1d", &tooth[i][j]);
		}
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d %d", &th, &di);
		check();
		tuning();
		turn();
		for (int i = 0; i < 5; i++){
			tooth_di[i] = 0;
		}
	}
	cal();
	printf("%d", result);
	return 0;
}
