#include <iostream>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j1 = 0; j1 < N - i - 1; j1++){
			printf(" %d",j1);
		}
		for (int j2 = 0; j2 < 2 * i + 1; j2++){
			printf(" %d", j2);
		}
		printf("\n");
	}

	return 0;
}
