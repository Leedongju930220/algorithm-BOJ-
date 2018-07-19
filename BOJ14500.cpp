#include <iostream>
#include <algorithm>

using namespace std;

#define MIN_INF -99999
#define MAX_INF 99999

int ans = MIN_INF;
int n, m;
int map[501][501];
bool visited[501][501];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

bool IsRange(int x, int y)
{
    return 0 <= x && x < n && 0 <= y && y < m;
}

void Dfs(int x, int y, int curr_cnt, int curr_sum)
{

    if (curr_cnt == 4)
    {
        ans = max(ans, curr_sum);
        return;
    }

    visited[x][y] = true;

    for (int k = 0; k < 4; k++)
    {
        int next_x = x + dx[k], next_y = y + dy[k];

        if (!IsRange(next_x, next_y)) continue;

        if (visited[next_x][next_y] == false)
        {
            Dfs(next_x, next_y, curr_cnt + 1, curr_sum + map[x][y]);
        }
    }

    visited[x][y] = false;
}

void Check(int x, int y)
{
    int min = MAX_INF;
    int sum = map[x][y];
    int cnt = 0;

    for (int k = 0; k < 4; k++)
    {
        int next_x = x + dx[k], next_y = y + dy[k];

        if (!IsRange(next_x, next_y)) continue;

        cnt++;
        sum += map[next_x][next_y];
        if (min > map[next_x][next_y])
            min = map[next_x][next_y];
    }

    if (cnt == 4)
        sum -= min;

    ans = max(ans, sum);

}

int main()
{
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            Dfs(i, j, 0, 0);
            Check(i, j);
        }
    }

    printf("%d\n", ans);

    return 0;
}
