#include <stdio.h>
#include <queue>
using namespace std;
int n,m,sy,sx,sd,gy,gx,gd;
int map[101][101];
bool visit[101][101][4];
int yd[4] = { 0,0,1,-1 };
int xd[4] = { 1,-1,0,0 };
int turn(int d, bool r)
{
    if (r)
    {
        if (d == 1) return 3;
        else if (d == 2) return 4;
        else if (d == 3) return 2;
        else if (d == 4) return 1;
    }
    else
    {
        if (d == 1) return 4;
        else if (d == 2) return 3;
        else if (d == 3) return 1;
        else if (d == 4) return 2;
    }
}
int bfs()
{
    queue < pair<int,int>> q;
    queue<int>qd;
    q.push(make_pair(sy, sx));
    qd.push(sd);
    visit[sy][sx][sd] = 1;
    int cnt = 0;
    bool suc = 0;
    while (!q.empty())
    {
        int q_sz = q.size();
        while (q_sz--)
        {
            int y, x, d;
            y = q.front().first;
            x = q.front().second;
            d = qd.front();
            q.pop(); qd.pop();
            if (y == gy && x == gx && d == gd)
            {
                suc = 1;
                break;
            }
            int ny, nx, nd;
            for (int i = 1; i <= 3; i++)
            {
                ny = y + yd[d - 1] * i;
                nx = x + xd[d - 1] * i;
                if (ny <1 || nx <1 || ny >n || nx > m) continue;
                if (map[ny][nx]) break;
                if (visit[ny][nx][d]) continue;
                visit[ny][nx][d] = 1;
                q.push(make_pair(ny, nx));
                qd.push(d);
            }
            for (int i = 0; i < 2; i++)
            {
                nd = turn(d, i);
                if (visit[y][x][nd]) continue;
                visit[y][x][nd] = 1;
                q.push(make_pair(y, x));
                qd.push(nd);
            }
        }
        if (suc) break;
        cnt++;
    }
    while (!q.empty()) q.pop();
    while (!qd.empty()) qd.pop();
    return cnt;
}
int main(void)
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) for (int j = 1; j <=m; j++) scanf("%d", &map[i][j]);
    scanf("%d %d %d", &sy, &sx, &sd);
    scanf("%d %d %d", &gy, &gx, &gd);
    printf("%d\n", bfs());
    
    return 0;
}
