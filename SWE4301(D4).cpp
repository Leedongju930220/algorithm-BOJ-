#include<cstdio>
int main(){
    int tc, n, m,cnt;
    scanf("%d", &tc);
    for (int i= 1; i <= tc; i++){
        cnt = 0;
        scanf("%d %d", &n, &m);
        for (int y = 0; y < n; y++){
            for (int x = 0; x < m; x++){
                if ((x % 4 == 0 || x % 4 == 1) && (y % 4 == 0 || y % 4 == 1)) cnt++;
                if ((x % 4 == 2 || x % 4 == 3) && (y % 4 == 2 || y % 4 == 3)) cnt++;
            }
        }
        printf("#%d %d\n", i, cnt);
    }
    return 0;
}
