#include<cstdio>

int num[2][16];
int max=-987654321,w,sum;

void dfs(int index){

	if (sum > max) max = sum;

	for (int i = index; i <= w; i++){
		if ((i + num[0][i]) <= w+1){
			sum += num[1][i];
			dfs(i + num[0][i]);
			sum -= num[1][i];
		}
	}
}
int main(){
	scanf("%d", &w);
	int a, b;
	for (int i = 1; i <= w; i++){
		scanf("%d %d", &a, &b);
		num[0][i] = a, num[1][i] = b;
	}
	dfs(1);

	printf("%d", max);

	return 0;
}
