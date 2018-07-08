/*#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int map[401][401];
vector<int> v[400];
int n;
int check_num;

bool cannotcheck(int number){
	for (int i = 1; i <= n; i++){
		if (map[i][number] == 1) return true;
	}
	return false;
}
void cancheck(int first, int second){

	for (int i = 0; i < v[first].size(); i++){
		if (v[first][i] == second){
			check_num = -1;
			return;
		}
		cancheck(v[first][i], second);
		if (check_num == -1) return;
	}
	check_num = 1;
	return;
}
int main(){
	int k, s;
	int first, second;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++){
		scanf("%d %d", &first, &second);
		map[first][second] = map[second][first] = 1;
		v[first].push_back(second);
	}
	for (int i = 0; i < n; i++){
		sort(v[i].begin(), v[i].end());
	}
	scanf("%d", &s);
	for (int i = 0; i < s; i++){
		scanf("%d %d", &first, &second);
		if (cannotcheck(first) == false || cannotcheck(second) == false){
			printf("%d\n", 0);
		}
		else{ 
			cancheck(first, second);
			printf("%d\n", check_num);
		}
	}
	return 0;
}*/

#include<cstdio>

int map[401][401];

int main(){
	int n, k, s;
	int first, second;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++){
		scanf("%d %d", &first, &second);
		map[first][second] = -1;
		map[second][first] = 1;
	}

	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (map[i][k] == 1 && map[k][j] == 1) map[i][j] = 1, map[j][i] = -1;
			}
		}
	}

	scanf("%d", &s);
	for (int i = 0; i < s; i++){
		scanf("%d %d", &first, &second);
		printf("%d\n", map[first][second]);
	}

	return 0;
}
