/*
    MBLAST : http://vn.spoj.com/problems/MBLAST/
    Explanation and Complexity are below 
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
const int NMAX      =   2010;
char a[NMAX], b[NMAX];
int n, m;
int k;
int f[NMAX][NMAX];
void readInp() {
    gets(a);
    gets(b);
    scanf("%d", &k);
}
void process() {
    n = strlen(a);
    while (a[n - 1] == ' ') n--;
    m = strlen(b);
    while (b[m - 1] == ' ') m--;
    for (int i = 0; i <= n; i++)
        f[i][0] = k * i;
    for (int j = 0; j <= m; j++)
        f[0][j] = k * j;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            f[i][j] = min(f[i - 1][j - 1] + abs(a[i - 1] - b[j - 1]), min(f[i - 1][j], f[i][j - 1]) + k);
    printf("%d", f[n][m]);
}
int main() {
    readInp();
    process();
    return 0;
}
/*
    We will DP with a 2D - array. F[i][j] : the minimum cost when we changed string a from 1->i and string b from 1->j 
    F[i][j] = F[i - 1][j] + k when we insert one "-" in i - position in string a.
    F[i][j] = F[i][j - 1] + k when we insert one "-" in j - position in string b.
    F[i][j] = F[i - 1][j - 1] + ord(a[i] - b[j]) when we subtract the different between 2 characters.
*/