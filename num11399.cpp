#include <cstdio>
#include <algorithm>

using namespace std;
int P[1000];

int main(){
	int N = 0, i = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++){
		scanf("%d", &P[i]);
	}

	sort(P, P + N);

	for (int i = 1; i < N; i++){
		P[i] = P[i - 1] + P[i];
	}
	int sum = 0;
	for (int i = 0; i < N; i++){
		sum += P[i];
	}

	printf("%d", sum);
	


	return 0;
}v
