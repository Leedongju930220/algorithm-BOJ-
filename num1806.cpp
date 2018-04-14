#include <iostream>

#define MAX 100001
int n = 0;
long long arr[MAX] = { 0 };
long long s_arr[MAX] = { 0 };
long long s = 0;
int min = 10002;

int main(){
	int l_count = 0;
	scanf("%d %d", &n, &s);
	for (int i = 1; i < n+1; i++){
		scanf("%d", &arr[i]);
		s_arr[i] = s_arr[i -1] + arr[i];
	}
	for (int i = 1; i < n+1; i++){
		int j = i + 1;
		while (s_arr[j]- s_arr[i] < s ){
			j++;
			if (s_arr[j] - s_arr[i] > s){
				l_count = j - i + 1;
				if (min > l_count) min = l_count;
			}
		}
	}
	if (min > s){
		printf("0");
	}
	else printf("%d", l_count);

	return 0;
}
