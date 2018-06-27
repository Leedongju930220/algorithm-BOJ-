#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<map>
using namespace std;
int arr[5][5];
int temp[8];
int xrr[4] = { 0,0,1,-1 }; int yrr[4] = { 1,-1,0,0 };
int ans = 0;
map<int, int>mp;
void dfs(int x, int y,int cnt)
{
    if (cnt > 6)
    {   
        int sum = 0;
        int k = 1000000;
        for (int i = 0; i < cnt; i++)
        {
            sum += k*temp[i];
            k /= 10;
        }
        if (mp[sum] == 0)
        {
            mp[sum] = 1;
            ans++;
        }
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + xrr[i];
        int ny = y + yrr[i];
        if (0 < nx&&nx < 5 && 0 < ny&&ny < 5)
        {
            temp[cnt] = arr[nx][ny];
            dfs(nx, ny, cnt + 1);
        }
    }

}
int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {

        ans = 0;
        mp.clear();
        for (int i = 1; i <= 4; i++)
        {
            for (int j = 1; j <= 4; j++)
            {
                scanf("%d", &arr[i][j]);
            }
        }
        for (int i = 1; i <= 4; i++)
        {
            for (int j = 1; j <= 4; j++)
            {               
                temp[0] = arr[i][j];
                dfs(i, j,1);           
            }
        }   
        printf("#%d %d\n", t, ans);
    }
}
