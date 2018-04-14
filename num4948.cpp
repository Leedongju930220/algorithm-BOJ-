#include <cstdio>
#include <math.h>



int main(){
	int num = 0;
	scanf("%d", &num);
	int sq_num = (int)sqrt((double)num);

	for (int i = 2; i <= sq_num;){
		if (num % i == 0){
			printf("%d\n", i);
			num = num / i;
		}
		else i++;
	}
	if (num != 1){
		printf("%d\n", num);
	}

	return 0;
}
