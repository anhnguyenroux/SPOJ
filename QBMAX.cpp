#include <stdio.h>
const int MAX       =   110;
const int oo        =   1e6;
int n, m;
int a[MAX][MAX];
int f[MAX][MAX];
void readInp() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
}
int max(int a, int b, int c) {
    int res = a;
    if (b > res) res = b;
    if (c > res) res = c;
    return res;
}
void process() {
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++)
            f[i][j] = -oo;
    for (int i = 1; i <= n; i++)
        f[i][1] = a[i][1];
    for (int j = 2; j <= m; j++)
        for (int i = 1; i <= n; i++) {
            f[i][j] = max(f[i - 1][j - 1], f[i][j - 1], f[i + 1][j - 1]) + a[i][j];
        } 
    int res = -oo;
    for (int i = 1; i <= n; i++)
        if (f[i][m] > res) res = f[i][m];
    printf("%d", res);
}
int main() {
    readInp();
    process();
    return 0;
}