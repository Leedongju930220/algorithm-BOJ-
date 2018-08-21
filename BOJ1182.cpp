#include<cstdio>

int N, S, sum, cnt;
int num[20];

void check(int x){
	if (x == N) return;
	if (sum + num[x] == S) cnt = cnt + 1;

	check(x + 1);
	
	sum += num[x];

	check(x + 1);

	sum -= num[x];

}
int main(){
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++){
		scanf("%d", &num[i]);
	}
	check(0);
	printf("%d", cnt);

	return 0;
}
