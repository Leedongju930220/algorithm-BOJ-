#include <stdio.h>
  
#define MAX_N 10000
  
int camera[MAX_N];
int diff[MAX_N];
  
void mergeSort(int input[MAX_N], int first, int last)
{
    if (first == last)
    {
        return;
    }
  
    int mid = (first + last) / 2;
  
    mergeSort(input, first, mid);
    mergeSort(input, mid + 1, last);
  
    int p, lp, rp;
  
    p = lp = first, rp = mid + 1;
  
    int temp[MAX_N];
  
    while (lp <= mid && rp <= last)
    {
        if (input[lp] < input[rp])
        {
            temp[p++] = input[lp++];
        }
        else
        {
            temp[p++] = input[rp++];
        }
    }
  
    while (lp <= mid)
    {
        temp[p++] = input[lp++];
    }
  
    while (rp <= last)
    {
        temp[p++] = input[rp++];
    }
  
    for (int i = first; i <= last; i++)
    {
        input[i] = temp[i];
    }
}
  
int main()
{
    int T; scanf("%d", &T);
  
    for (int tc = 1; tc <= T; tc++)
    {
        int N, K; scanf("%d%d", &N, &K);
  
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &camera[i]);
        }
  
        mergeSort(camera, 0, N - 1);
  
        int cnt = 0;
  
        for (int i = 0; i < N-1; i++)
        {
            if (camera[i] == camera[i + 1])
            {
                continue;
            }
  
            diff[cnt++] = camera[i + 1] - camera[i];
        }
  
        mergeSort(diff, 0, cnt - 1);
  
        int len = camera[N - 1] - camera[0];
  
        if (cnt <= K - 1)
        {
            len = 0;
        }
        else
        {
            for (int i = K - 1; i >= 1; i--)
            {
                len -= diff[--cnt];
            }
        }
  
        printf("#%d %d\n", tc, len);
    }
  
    return 0;
}
