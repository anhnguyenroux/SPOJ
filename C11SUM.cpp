/*
    C11SUM : http://vn.spoj.com/problems/C11SUM/
    Explanation and Complexity are below
*/
#include <stdio.h>
#include <string.h>
const int NMAX      =   1e6 + 10;
const int modulo    =   1e9 + 7;
char s[NMAX];
long long f[NMAX];
int main() {
    gets(s);
    f[1] = s[0] - '0';
    int n = strlen(s);
    for (int i = 2; i <= n; i++) {
        f[i] = (f[i - 1] * 10 + (s[i - 1] - 48) * i) % modulo;
    }
    long long res = 0;
    for (int i = 1; i <= n; i++)
        res = (res + f[i]) % modulo;
    printf("%d", res);
    return 0;
}
/*
    F[i] : the sum of subsequences that end in i.
    F[i] = F[i - 1] * 10 + (s[i] - '0') * i;
    result : sum of F[i] 1 <= i <= n (n : length of string)
    Complexity : O(N)
*/