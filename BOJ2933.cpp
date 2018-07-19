#include<cstdio>
#include<vector>

using namespace std;

struct axis{
    int x;  //row
    int y;  //colum
};
int R, C, N;
char map[101][101];
int visit[101][101];
vector<axis> v;
//vector<axis> m_v;
int dx[4] = {0, -1, 1, 0};
int dy[4] = {1,  0,0, -1};

void dfs(int y ,int x){
    axis  value;
    value.x = x;
    value.y = y;
    v.push_back(value);
    visit[y][x] = 2;
    for (int i = 0; i < 4; i++){
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        if (next_x >= 0 && next_x < C && next_y >= 0 && next_y < R && visit[next_y][next_x] == 1){
            dfs(next_y, next_x);
        }
    }
}
axis start_point_check(int order, int h){
    axis value;
    if (order % 2 != 1){
        for (int i = 0; i < C; i++){
            if (visit[R - h][i] != 0){
                value.x = i;
                value.y = R - h;
                return value;
            }
        }
    }
    else{
        for (int i = C - 1; i >= 0; i--){
            if (visit[ R- h][i] != 0){
                value.x = i;
                value.y = R - h;
                return value;
            }
        }
    }
    value.x = 1000;
    value.y = 1000;
    return value;
}
void set(){
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            if (visit[i][j] != 0) visit[i][j] = 1;
        }
    }
}
void move_check(){
    axis value;
    int size = v.size();
    //m_v.clear();
    int i = 1;
    int flag = true;
    for (int p = 0; p < size; p++){
        visit[v[p].y][v[p].x] = 0;
        //value.x = v[i].x;
        //value.y = v[i].y;
        //m_v.push_back(value);
    }
    for (i= 1 ; i < R; i++){
        for (int j = 0; j < size; j++){
            if (!(v[j].x >= 0 && v[j].x < C && v[j].y + i >= 0 && v[j].y + i < R && visit[v[j].y + i][v[j].x] == 0)){
                flag = false;
                break;
            }
        }
        if (flag == false) break;
    }
    for (int t = 0; t < size; t++){
        visit[v[t].y + (i - 1)][v[t].x] = 2;
    }
    v.clear();
}
int main(){
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            scanf(" %c", &map[i][j]);
            if (map[i][j] != '.') visit[i][j] = 1;  //미네랄 또는 클러스터
        }
    }
    scanf("%d", &N);
    axis value;
    int h;
    for (int i = 0; i < N; i++){
        scanf("%d", &h);
        value = start_point_check(i, h);
        if (value.x == 1000) continue;
        visit[value.y][value.x] = 0;
        set();
        for (int i = 0; i < 4; i++){
            v.clear();
            int next_x = value.x + dx[i];
            int next_y = value.y + dy[i];
            if (next_x >= 0 && next_x < C && next_y >= 0 && next_y < R && visit[next_y][next_x] == 1){
                dfs(next_y, next_x);
                move_check();
            }
        }
    }
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            if (visit[i][j] == 0) printf(".");
            else printf("x");
        }
        printf("\n");
    }

    return 0;
}
