#include<cstdio>

int main(){
	int N, cnt = 0, one = 0, ten=0,pre_one = 0, post_num=0;
	scanf("%d", &N);
	if (N < 10){
		ten = 10;
	}
	int NN = N;
	while (1){
		pre_one = N % 10;
		ten = N / 10;
		one = N % 10;
		post_num = pre_one*10 + (ten + one)%10;
		if (NN == post_num) break;
		cnt++;
		N = post_num;
	}
	printf("%d", cnt+1);

	return 0;
}
