#include <stdio.h>

bool d[10001];

int main(){
	int num, pos;

	for (int i = 1; i <= 10000; i++){
		num = i; pos = i;
		for (int j = 1; j <= 4; j++){
			num += pos % 10;
			pos /= 10;
		}
		d[num] = true;
	}

	for (int i = 1; i <= 10000; i++){
		if (!d[i]) printf("%d\n", i);
	}

	return 0;
}
