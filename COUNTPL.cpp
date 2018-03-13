/*
    COUNTPL : http://vn.spoj.com/problems/COUNTPL/
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int NMAX      =   256;
char s[NMAX];
int n;
int g[NMAX][NMAX];
int f[NMAX][NMAX];
void process() {
    gets(s);
    n = strlen(s);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            g[i][j] = 0;
    for (int i = 1; i <= n; i++)
        g[i][i] = 1;
    for (int j = 1; j <= n; j++)
        for (int i = j - 1; i >= 1; i--) 
            if (s[i - 1] == s[j - 1]) {
                g[i][j] = g[i + 1][j - 1];
                if (i + 1 >= j - 1) g[i][j] = 1;
            }
            else g[i][j] = 0;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            f[i][j] = 0;
    for (int i = 1; i <= n; i++)
        f[i][i] = 1;
    for (int j = 1; j <= n; j++) 
    for (int i = j - 1; i >= 1; i--) {
        f[i][j] = j - i + 1;
        for (int k = i; k <= j; k++)
            if (g[i][k])
                f[i][j] = min(f[i][j], f[k + 1][j] + 1);
    }
    printf("%d", f[1][n]);
}
int main() {
    process();
    return 0;
}