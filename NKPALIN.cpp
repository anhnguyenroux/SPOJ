#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int LMAX      =   2100;
char s[LMAX];
int n;
int f[LMAX][LMAX];
char kq[LMAX];
void process() {
    gets(s);
    n = strlen(s);
    for (int i = 1; i <= n; i++)
        f[i][i] = 1;
    for (int j = 1; j <= n; j++)
        for (int i = j - 1; i >= 1; i--)
            if (s[i - 1] == s[j - 1]) f[i][j] = f[i + 1][j - 1] + 2;
            else 
                f[i][j] = max(f[i + 1][j], f[i][j - 1]);
    int i = 1, j = n;
    int p1 = 1, p2 = f[1][n];
    while (i <= j) {
        if (s[i - 1] == s[j - 1]) {
            kq[p1++] = s[i - 1];
            kq[p2--] = s[i - 1];
            i++;
            j--;
        }
        else {
            if (f[i][j] == f[i + 1][j]) i++;
            else j--;
        }
    }
    for (int i = 1; i <= f[1][n]; i++)
        printf("%c", kq[i]);
}
int main() {
    process();
    return 0;
}
/*
    F[i][j] : The maximum length of palindrome of S from i to j 
    F[i][i] = 1 for every i <= n (n : length of S)
    if (S[i] = S[j]) f[i][j] = f[i + 1][j - 1] + 2
    if (S[i] != S[j]) f[i][j] = max(f[i + 1][j], f[i][j - 1])
    Then we can trace the result
*/