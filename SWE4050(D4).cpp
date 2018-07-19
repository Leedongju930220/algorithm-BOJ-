#include<cstdio>
#include<vector>
#include<algorithm>
#include <functional>

using namespace std;

vector<int> cost;
int main(){
    int tc, N, v;
    scanf("%d", &tc);
    for (int i = 1; i <= tc; i++){
        cost.clear();
        scanf("%d", &N);
        int total = 0, third_cost = 0;
        for (int j = 0; j < N; j++){
            scanf("%d", &v);
            total += v;
            cost.push_back(v);
        }
        sort(cost.begin(), cost.end(), greater<int>());
        for (int k = 2; k < cost.size(); k = k + 3){
            third_cost += cost[k];
        }
        printf("#%d %d\n", i, total - third_cost);
    }

    return 0;
}
