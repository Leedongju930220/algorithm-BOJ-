#include <cstdio>

int a_sum[11] = { 1, 2, 4 };
int main(){
	
	int T = 0;
	scanf("%d", &T);

	for (int i = 3; i < 11; i++){
		a_sum[i] = a_sum[i - 3] + a_sum[i - 2] + a_sum[i - 1];
	}
	while (T--){
		int l;
		scanf("%d", &l);
		printf("%d\n", a_sum[l-1]);
	}
	return 0;
}
