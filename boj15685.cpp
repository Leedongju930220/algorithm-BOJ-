#include <stdio.h>
#include <vector>

using namespace std;

int visit[102][102] = { 0, };
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int result = 0;
int x, y;

void visit_check(int c_x, int c_y){
    if (c_x >= 0 && c_x <= 100 && c_y >= 0 && c_y <= 100)
        visit[c_x][c_y] = 1;
}
void c_check(vector<int> dragon, int generator){
    for (int i = 0; i<generator; i++){
        for (int j = dragon.size()-1; j>=0; j--){
            int next_d = (dragon[j] + 1) % 4;
            x = x + dx[next_d];
            y = y + dy[next_d];
            visit_check(y, x);
            dragon.push_back(next_d);
            }
    }
}
void check(){
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            if (visit[i][j] == 1 && visit[i][j + 1] == 1 && visit[i + 1][j] == 1 && visit[i + 1][j + 1] == 1){
                result++;
            }
        }
    }
}
int main(){
    int d, g, N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        scanf("%d %d %d %d", &y, &x, &d, &g);
        visit_check(y, x);
        y = y + dy[d], x = x + dx[d];
        visit_check(y, x);
        vector<int> dragon;
        dragon.push_back(d);
        c_check(dragon, g);
    }
    check();

    printf("%d", result);

    return 0;
}
