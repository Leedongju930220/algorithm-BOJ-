#include <cstdio>

int n[100];
int result[100] = { 1, 1, 1, 2, 2 };

int main(){

	int T;
	int i = 0;
	int c_T;
	scanf("%d", &T);
	c_T = T;
	while (T--){
		scanf("%d", &n[i]);
		i++;
	}

	for (int i = 5; i < 101; i++){
		if (i == (result[i - 1]+1) * (result[i - 1]+1)){
			result[i] = result[i - 1] + 1;
		}
		else{ result[i] = result[i - 1]; }
	}


	int j = 0;
	while (c_T--){
		printf("%d\n", result[n[j]]);
		j++;
	}
	return 0;
}
