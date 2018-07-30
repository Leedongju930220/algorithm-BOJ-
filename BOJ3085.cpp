#include <stdio.h>
int t, n,res;
int map[51][51];
int yd[4] = { 1,0,-1,0 };
int xd[4] = { 0,1,0,-1 };

void print()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d", map[i][j]);
        }
        printf("\n");
    }
}

void mov(int y, int x)
{
    //세로
    int now = map[0][x];
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        int next = map[i][x];
        if (now == next)cnt++;      
        else
        {
            cnt = 1;
            now = next;
        }
        if (res < cnt) res = cnt;

    }
    //printf("세로 res [%d] ", res);
    // 가로
    now = map[y][0];
    cnt = 1;
    for (int i = 1; i < n; i++)
    {
        int next = map[y][i];
        if (now == next)cnt++;
        else
        {
            cnt = 1;
            now = next;
        }
        if (res < cnt) res = cnt;

    }
    //printf("가로 res [%d]\n", res);
}

int main(void)
{
    res = 0;
    scanf("%d", &n);
    char c;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf(" %1c", &c);
            if (c == 'C') map[i][j] = 1;
            else if (c == 'P') map[i][j] = 2;
            else if (c == 'Z') map[i][j] = 3;
            else if (c == 'Y') map[i][j] = 4;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sy = i, sx = j;
            int ny, nx;
            for (int a = 0; a < 4; a++)
            {
                //printf("sy %d sx %d  dir %d\n", i, j, a);
                ny = sy + yd[a];
                nx = sx + xd[a];
                if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
                int tmp = map[sy][sx];
                map[sy][sx] = map[ny][nx];
                map[ny][nx] = tmp;
                //print();
                mov(sy, sx);
                mov(ny, nx);
                map[ny][nx] = map[sy][sx];
                map[sy][sx] = tmp;
            }
        }   
    }
    printf("%d\n", res);
}
