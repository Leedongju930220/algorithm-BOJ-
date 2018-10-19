#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v1;

bool com(int a, int b){
	return a > b;  // a>b 이면 내림차순(큰거부터) , a<b 이면 오름차순(작은거부터)
}
int main(){
	for (int i = 0; i < 10; i++){
		int a = 0; 
		scanf("%d", &a);
		v1.push_back(a);
	}
	sort(v1.begin(), v1.end() , com);
	for (int i = 0; i < 10; i++){
		printf("%d ", v1.at(i));
	}



	return 0;
}
