#include <stdio.h>
const int NMAX      =   510;
int N;
int a[NMAX][NMAX];
int s[NMAX][NMAX];
int f[NMAX][NMAX];
void readInp() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            scanf("%d", &a[i][j]);
}
void process() {
    for (int i = 0; i <= N; i++) {
        s[i][0] = 0;
        s[0][i] = 0;
        f[i][0] = 0;
        f[0][i] = 0;
    }
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            s[i][j] = s[i - 1][j] + s[i][j - 1] + a[i][j] - s[i - 1][j - 1];
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            f[i][j] = (f[i - 1][j] == 0 && (s[i][j] - s[i - 1][j]) % 2 == 0) || (f[i][j - 1] == 0 && (s[i][j] - s[i][j - 1]) % 2 == 0);
    if (f[N][N]) printf("YES\n");
    else 
        printf("NO\n");
}
int main() {
    int test;
    scanf("%d", &test);
    while (test-- > 0) {
        readInp();
        process();
    }
    return 0;
}