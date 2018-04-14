#include <stdio.h>

/*int main(){
	int N = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N - i; j++){
			printf("＊");
		}
		printf("\n");
	}


	return 0;
}*/
#include <stdio.h>

int main(){

	int i, j, N;

	scanf("%d", &N);

	for (i = 1; i <= N; i++){

		for (j = N; j >= i; j--){

			printf("*");
		}

		printf("\n");
	}

}
