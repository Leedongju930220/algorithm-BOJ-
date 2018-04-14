#include <cstdio>
#include <algorithm>

using namespace std;
#define MAX 4000

int A[MAX], B[MAX], C[MAX], D[MAX];
int AB[2 * MAX];
int CD[2 * MAX];

int biSearch(int start, int end, int S_n){
	int mid = (start + end) / 2;

	if (S_n == CD[mid]) return 1;
	else if (S_n < CD[mid]){
		biSearch(0, mid - 1, S_n);
	}
	else if (S_n > CD[mid]){
		biSearch(mid + 1, end,S_n);
	}
	else return 0;
}
int main(){
	int array_size = 0;
	int count = 0;
	int SA_c = 0;
	scanf("%d", &array_size);

	for (int i = 0; i < array_size; i++){
		scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
	}

	for (int i = 0; i < array_size; i++){
		for (int j = 0; j < array_size; j++){
			AB[SA_c] = A[i] + B[j];
			CD[SA_c] = C[i] + D[j];
			SA_c++;
		}
	}

	sort(AB, AB + (2 * array_size)-1);
	sort(CD, CD + (2 * array_size)-1);

	for (int i = 0; i < (2 * array_size)-1; i++){
		if (biSearch(0, (2*array_size)-1, AB[i]) == 1){
			count++;
		}
	}

	printf("%d", count);

	return 0;
}
