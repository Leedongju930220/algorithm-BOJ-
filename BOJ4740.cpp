#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>

using namespace std;

int N, M, Q;
char table[31][31];

void gravity();
int isEmpty();
void Rfunction();
void Lfunction();
void Ufunction(char* row);
void Dfunction();
int isAllRow();

void Ufunction(char* row) {
    for (int j = 1;j <= M;j++) {
        for (int i = 1;i <= N - 1;i++) {
            table[i][j] = table[i + 1][j];
        }
    }

    for (int j = 1;j <= M;j++) table[N][j] = row[j];
}

struct Node {
    int x, y;
    Node(int a, int b) : x(a), y(b) {}
};

int visited[32][32];
int dir[4][2] = { { 0,1 } ,{ 1, 0 } ,{ -1, 0 },{ 0, -1 } };

int back(int y, int x, char ch) {
    int cnt = 0;
    for (int i = 0;i <= 3;i++) {
        int ny = y + dir[i][0];
        int nx = x + dir[i][1];
        if (ny <= N && ny > 0) {
            if (nx <= M && nx > 0) {
                if (table[ny][nx] == ch && visited[ny][nx] == 0) {
                    visited[ny][nx] = 1;
                    cnt = cnt + back(ny, nx, ch) + 1;
                }
            }
        }
    }

    return cnt;
}

void erase(int y, int x, char ch) {
    for (int i = 0;i <= 3;i++) {
        int ny = y + dir[i][0];
        int nx = x + dir[i][1];
        if (ny <= N && ny > 0) {
            if (nx <= M && nx > 0) {
                if (table[ny][nx] == ch && visited[ny][nx] == 0) {
                    visited[ny][nx] = 1;
                    table[ny][nx] = '#';
                    erase(ny, nx, ch);
                }
            }
        }
    }
}

void Dfunction() {
    int arr[1000][3], acnt = 0;
    for (int i = 1;i <= N;i++)
        for (int j = 1;j <= M;j++)
            visited[i][j] = 0;

    int max = 0, p;
    for (int i = 1;i <= N;i++) {
        for (int j = 1;j <= M;j++) {
            if (table[i][j] != '#' && visited[i][j] == 0) {
                visited[i][j] = 1;
                int cnt = back(i, j, table[i][j]) + 1;
                arr[++acnt][0] = cnt;
                arr[acnt][1] = i;
                arr[acnt][2] = j;
                if (max < cnt) {
                    max = cnt;
                    p = acnt;
                }
            }
        }
    }

    for (int i = 1;i <= N;i++)
        for (int j = 1;j <= M;j++)
            visited[i][j] = 0;

    for (int i = 1;i <= acnt;i++) {
        if (max == arr[i][0]) {
            visited[arr[i][1]][arr[i][2]] = 1;
            erase(arr[i][1], arr[i][2], table[arr[i][1]][arr[i][2]]);
            table[arr[i][1]][arr[i][2]] = '#';
        }
    }
}

void Rfunction() {
    int queue[42];
    for (int i = 1;i <= N;i++) {
        int head = 0, tail = 0;
        for (int j = M;j >= 1;j--) {
            if (table[i][j] == '#') {
                queue[tail++] = j;
            }
            else {
                if (head < tail) {
                    int x = queue[head];
                    table[i][x] = table[i][j];
                    table[i][j] = '#';
                    queue[tail++] = j;
                    head++;
                }
            }
        }
    }
}

void Lfunction() {
    int queue[42];
    for (int i = 1;i <= N;i++) {
        int head = 0, tail = 0;
        for (int j = 1;j <= M;j++) {
            if (table[i][j] == '#') {
                queue[tail++] = j;
            }
            else {
                if (head < tail) {
                    int x = queue[head];
                    table[i][x] = table[i][j];
                    table[i][j] = '#';
                    queue[tail++] = j;
                    head++;
                }
            }
        }
    }
} // ok

void gravity() {
    int queue[32];
    for (int j = 1;j <= M;j++) {
        int t = N;
        int head = 0, tail = 0;
        for (int i = N;i >= 1;i--) {
            if (table[i][j] == '#') {
                queue[tail++] = i;
            }
            else {
                if (head < tail) {
                    int y = queue[head];
                    table[y][j] = table[i][j];
                    table[i][j] = '#';
                    queue[tail++] = i;
                    head++;
                }
            }
        }
    }
} // ok

int isAllRow() {
    for (int i = 1;i <= N;i++) {
        int flag = 0;
        for (int j = 1;j <= M;j++) {
            if (table[i][j] != '#') {
                flag = 1; break;
            }
        }
        if (flag == 0) return 0; // 빈 행이 있는 경우 
    }
    return 1;
}

int isEmpty() {
    for (int i = 1;i <= N;i++) {
        for (int j = 1;j <= M;j++) {
            if (table[i][j] == '#') continue;
            return 0;
        }
    }
    return 1;
}

int main(void) {
    int T;
    char buf;
    char row[32];
    scanf( "%d", &T);
    for (int tc = 1;tc <= T;tc++) {
        scanf( "%d %d %d", &N, &M, &Q);
        for (int i = 1;i <= N;i++) {
            scanf( "%s", &table[i][1]);
        }
        gravity();

        for (int i = 1;i <= Q;i++) {
            char step[3];
            scanf( "%s", &step);
            if (step[0] == 'U') {
                scanf( "%s", &row[1]);
                if (isAllRow()) continue;
                Ufunction(&row[0]);
                gravity();
            }
            else if (!isEmpty()) {
                if (step[0] == 'L') Lfunction();
                else if (step[0] == 'R') Rfunction();
                else if (step[0] == 'D') {
                    Dfunction();
                    gravity();
                }
            }
        }

        printf( "#%d\n", tc);

        for (int i = 1;i <= N;i++) {
            for (int j = 1;j <= M;j++) {
                printf( "%c", table[i][j]);
            }
            printf( "\n");
        }
        printf( "\n");
    }

    return 0;
}
