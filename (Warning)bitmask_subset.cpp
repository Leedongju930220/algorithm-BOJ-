#include<cstdio>
#include<conio.h>

int N;
int arr[100];

void print(){
	for (int i = 0; i < 20; i++){
		printf("%d ", arr[i]);
	}printf("\n");
}
void init(){
	for (int i = 0; i < 20; i++){
		arr[i] = 0;
	}
}
int main(){
	scanf("%d", &N);
	for (int i = 0; i < (1 << 5); i++){
		for (int j = 0; j < N; j++){
			if (i &(1 << j)){
				arr[j] = 1;
			}
		}
		print();
		init();
		_getch();
	}


	return 0;
}
