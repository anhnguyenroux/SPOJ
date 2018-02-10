#include <stdio.h>
#include <string.h>
const int MAX = 250;
const int kx[4] = {-1, 0, 1, 0};
const int ky[4] = {0, 1, 0, -1};
int N, M;
char a[MAX][MAX];
bool mark[MAX][MAX];
void inpProcess() {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
        scanf("%s", a[i] + 1);
}
void dfs(int u, int v) {
    mark[u][v] = false;
    for (int i = 0; i < 4; i++) {
        int ux = u + kx[i];
        int vy = v + ky[i];
        if (ux <= 0 || ux > N || vy <= 0 || vy > M) continue;
        if (mark[ux][vy] && a[ux][vy] == '#') dfs(ux, vy);
    }
}
void Process() {
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            mark[i][j] = true;
    int cnt = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if (mark[i][j] && a[i][j] == '#') {
                cnt++;
                dfs(i, j);
            }
    printf("%d", cnt);
}
int main() {
    inpProcess();
    Process();
    return 0;
}
/*
        x - 1, y
x, y - 1   x,y   x, y + 1
        x + 1, y
*/