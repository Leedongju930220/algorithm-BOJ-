#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, pair<int, int>>> v;
queue<pair <int, int>> q;


int main(){
	int N, C, M;
	int cur = 0;
	scanf("%d%d%d", &N, &C, &M);
	for (int i = 0; i < M; i++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		v.push_back(make_pair(a, make_pair(b, c)));
	}
	sort(v.begin(), v.end());
	int t = 0;
	for (int i = 0; i < C; i++){
		for (int j =t; j < i+1; ++t){
			if (cur < C){
				q.push(make_pair(v[j].second.first, v[j].second.second));
			}
		}
	}

	return 0;
}
