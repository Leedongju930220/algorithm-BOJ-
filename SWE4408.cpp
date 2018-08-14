#include<cstdio>

int map[201];
int max = 0;

void init(){
	for (int i = 0; i < 201; i++){
		map[i] = 0;
	}
}
void iter(int start, int end){
	for (int i = start; i <= end ; i++){
		map[i] = map[i] + 1;
	}
}
void check(){
	for (int i = 0; i < 201; i++){
		if (map[i] > max) max = map[i];
	}
}
int main(){
	int tc = 0, start = 0, end = 0, N;
	scanf("%d", &tc);
	for (int i = 1; i <= tc; i++){
		max = 0;
		init();
		scanf("%d", &N);

		for (int j = 0; j < N; j++){
			scanf("%d %d", &start, &end);
			/*if (start < end){
				iter((start+1)/2, (end+1)/2);
			}
			else{
				iter((end+1)/2, (start+1)/2);
			}*/
			if (end > start){
				iter((start + 1) / 2, (end + 1) / 2);
			}
			else{
				iter((end + 1) / 2, (start + 1) / 2);
			}
		}
		check();

		printf("#%d %d\n", i, max);
	}
	return 0;
}
