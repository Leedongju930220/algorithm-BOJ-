#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

pair<int, char> p;

vector<pair<int, char>> vc;

int main()
{
	int N = 0;
	scanf("%d", &N);
	int coef = 0;
	int exp = 0;
	int sum = 0;
	for (int i = 0; i < N; i++){
		scanf("%d %d", &coef, &exp);
		vc.push_back(make_pair(coef, exp));
	}
	for (int i = 0; i < N; i++){
		sum += vc[i].first * vc[i].second;
	}
	printf("%d", sum);

	return 0;
}
