#include <cstdio>
#include <math.h>
int num[1000001];
int stan = 0;

void check(int n){
	int pos = n;
	n = 123456789;
	int count = 0;
	while (count > 1000001 || stan == n){
		count++;
		for (int i = 0; i < 6; i++){
			n += (pos % 10) * (pos * 10);
			pos /= 10;
			if (i == 0){
				stan = n;
			}
			if (i != 0 && n == stan){
				num[n] = 0;
				break;
			}
			if (n == 1)break;
		}
	}
}

int main(){
	int sq_num = (int)sqrt(1000001.0
		);
	for (int i = 1; i < 1000001; i++){
		num[i] = i;
	}
	num[2] = 0;

	for (int j = 2; j < sq_num; j++){
		for (int i = j*j ; i < 1000001; i++){
			if (i%j == 0) num[i] = 0;
		}
	}
	
	for (int i = 0; i < 1000001; i++){
		if (num[i] != 0)printf("%d\n", num[i]);
	}
	


	return 0;
}
