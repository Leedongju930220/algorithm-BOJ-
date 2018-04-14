#include <stdio.h>

int num[1000001];
int min(int n1, int n2){
	if (n1<n2) return n1;
	return n2;
}
int main(){
	int N;
	scanf("%d", &N);

	for (int i = 2; i <= N; i++){
		num[i] = num[i - 1] + 1;
		if (i % 2 == 0)  num[i] = min(num[i], num[i / 2] + 1);
		if (i % 3 == 0)  num[i] = min(num[i], num[i / 3] + 1);
	}

	printf("%d\n", num[N]);
}
