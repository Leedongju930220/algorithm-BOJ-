#include <iostream>


int dp[1000];

int main(){
	int N = 0;
	scanf("%d", &N);

	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i < N+1; i++){
		dp[i] = (2 * dp[i - 2] + dp[i - 1]) %10007;
	}
	printf("%d", dp[N]%10007);

	return 0;
}

v
