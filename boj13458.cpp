#include<cstdio>

long long room[1000001];
long long c, sub_c, N;
long long sum;

int main(){
	scanf("%lld", &N);
	for (int i = 0; i < N; i++){
		scanf("%lld", &room[i]);
	}
	scanf("%lld %lld", &c, &sub_c);
	for (int i = 0; i < N; i++){
		int cnt = 0;
		if (room[i] >= c){
			room[i] = room[i] - c;
			cnt++;
			if (room[i] % sub_c == 0){
				cnt += (room[i] / sub_c);
			}
			else cnt += (room[i] / sub_c) + 1;
		}
		else cnt++;
		sum += cnt;
	}

	printf("%lld", sum);

	return 0;
}
