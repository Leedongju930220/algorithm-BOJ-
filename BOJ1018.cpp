#include<cstdio>

int map[51][51];
int total_min_value = 987654321;
int N, M;
int black[8][8] = { { 1, 0, 1, 0, 1, 0, 1, 0 },
{ 0, 1, 0, 1, 0, 1, 0, 1 },
{ 1, 0, 1, 0, 1, 0, 1, 0 },
{ 0, 1, 0, 1, 0, 1, 0, 1 },
{ 1, 0, 1, 0, 1, 0, 1, 0 },
{ 0, 1, 0, 1, 0, 1, 0, 1 },
{ 1, 0, 1, 0, 1, 0, 1, 0 },
{ 0, 1, 0, 1, 0, 1, 0, 1 } };
int white[8][8] = { { 0, 1, 0, 1, 0, 1, 0, 1 },
{ 1, 0, 1, 0, 1, 0, 1, 0 },
{ 0, 1, 0, 1, 0, 1, 0, 1 },
{ 1, 0, 1, 0, 1, 0, 1, 0 },
{ 0, 1, 0, 1, 0, 1, 0, 1 },
{ 1, 0, 1, 0, 1, 0, 1, 0 },
{ 0, 1, 0, 1, 0, 1, 0, 1 },
{ 1, 0, 1, 0, 1, 0, 1, 0 } };
int compare(int a, int b){
    if (a > b) return b;
    else return a;
}
int white_check(int i, int j){
    int count = 0, l_r = 0, l_c = 0;
    for (int r = i, l_r = 0; r < i + 8; r++, l_r++){
        for (int c = j, l_c = 0; c < j + 8; c++, l_c++){
            if (map[r][c] != white[l_r][l_c]) count++;
        }
    }
    return count;
}
int black_check(int i, int j){
    int count = 0, l_r = 0, l_c = 0;
    for (int r = i, l_r = 0; r < i + 8; r++, l_r++){
        for (int c = j, l_c = 0; c < j + 8; c++, l_c++){
            if (map[r][c] != black[l_r][l_c]) count++;
        }
    }
    return count;
}
int main(){
    char v;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            scanf(" %c", &v);
            if (v == 'W') map[i][j] = 0;
            if (v == 'B') map[i][j] = 1;
        }
    }
    for (int i = 0; i < N - 7; i++){
        for (int j = 0; j < M - 7; j++){
            total_min_value = compare(total_min_value, compare(white_check(i,j), black_check(i,j)));
        }
    }
    if(total_min_value == 63) total_min_value = 64-total_min_value;
    printf("%d\n", total_min_value);

    return 0;
}
