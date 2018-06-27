#include<cstdio>
#include<vector>
#include<memory.h>

using namespace std;
int num[10001];
vector<int> v;
void init(){
    memset(num, 0, sizeof(num));
    v.clear();
}
int main(){
    int tc, N, size, value;
    scanf("%d", &tc);
    for (int i = 1; i <= tc; i++){
        v.push_back(0);
        scanf("%d", &N);
        for (int j = 0; j < N; j++){
            scanf("%d", &value);
            size = v.size();
            if (num[value] == 0){
                v.push_back(value);
                num[value] = 1;
            }
            for (int k = 0; k < size; k++){
                if (num[value + v.at(k)] == 0){
                    num[value + v.at(k)] = 1;
                    v.push_back(value + v.at(k));
                }
            }
        }
        printf("#%d %d\n", i, v.size());
        init();
    }

    return 0;
}
