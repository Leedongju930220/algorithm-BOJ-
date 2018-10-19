#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct node{
	int y;
	int x;
	int z;
}node;

vector<node> v;

bool com(node a, node b){
	return a.z < b.z;    // < 오름차순//작은거부터                > 내림차순//
}
int main(){

	for (int i = 0; i < 10; i++){
		int a = 0, b = 0,c=0;
		scanf("%d %d %d", &a, &b, &c);
		v.push_back({ a, b ,c});
	}

	sort(v.begin(), v.end(), com);
	printf("-------------\n");
	for (int i = 0; i < 10; i++){
		printf("%d   %d   %d\n", v.at(i).y, v.at(i).x, v.at(i).z);
	}

	return 0;
}
