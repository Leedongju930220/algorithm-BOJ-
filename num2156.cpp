#include <stdio.h>
#define MAX(a,b) (((a) > (b)) ? (a) : (b)) 

int N; 
int W[10001];
int D[10001]; 

int main(void) {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		scanf("%d", &W[i]);

	D[1] = W[1]; 
	D[2] = W[1] + W[2];  
 
	for ( int i = 3; i <= N; i++) {
		D[i] = MAX(D[i - 2] + W[i], D[i - 3] + W[i - 1] + W[i]); 
		D[i] = MAX(D[i - 1], D[i]); 
	}

	printf("%d", D[N]);

	return 0;
}
