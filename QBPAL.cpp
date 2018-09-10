#include <stdio.h>
#include <string.h>
const int NMAX      =   125;
char s[NMAX];
long long f[NMAX][NMAX];
int n;
void process() {
    gets(s);
    n = strlen(s);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            f[i][j] = 0;
    for (int i = 1; i <= n; i++)
        f[i][i] = 1;
    for (int j = 1; j <= n; j++)
        for (int i = j - 1; i >= 1; i--) {
            f[i][j] = f[i + 1][j] + f[i][j - 1];
            if (s[i - 1] == s[j - 1]) f[i][j] += 1;
            else f[i][j] -= f[i + 1][j - 1];
        }
    printf("%lld", f[1][n]);
}
int main() {
    process();
    return 0;
}