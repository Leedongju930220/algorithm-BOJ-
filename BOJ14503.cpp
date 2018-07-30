#include <cstdio>

int n, m, r, c, d, res;    
int map[50][50];
int xx[] = { -1, 0, 1, 0 };
int yy[] = { 0, 1, 0, -1 };
int b_xx[] = { 1, 0, -1, 0 };
int b_yy[] = { 0, -1, 0, 1 };

void dfs(int x, int y, int d) {   // 북 동 남 서
    res++;
    map[x][y] = 2;

    int next_x, next_y;
    for (int i = 1; i <= 4; i++) {
        int dd = (d - i < 0) ? d - i + 4 : d - i;

        next_x = x + xx[dd];
        next_y = y + yy[dd];

        if (map[next_x][next_y] == 0) {
            dfs(next_x, next_y, dd);
            return;
        }
    }

    next_x = x + b_xx[d];
    next_y = y + b_yy[d];
    if (map[next_x][next_y] != 1) {
        dfs(next_x, next_y, d);
    }
}

int count() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 2)cnt++;
        }
    }
    return cnt;
}

int main() {
    scanf("%d %d %d %d %d", &n, &m, &r, &c, &d);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d",&map[i][j]);
        }
    }

    dfs(r, c, d);

    printf("%d", count());
}
