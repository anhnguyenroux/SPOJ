#include <bits/stdc++.h>
using namespace std;
const int oo        = 1e9;
const int NMAX      = 1e6;
const int MAX       = 510;
bool prime[NMAX + 10];
int n, m;
int a[MAX][MAX];
int nxtPrime[NMAX];
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
    memset(prime, 1, sizeof(prime));
    prime[1] = 0;
    for (int i = 2; i <= NMAX; i++)
    if (prime[i]) {
        for (int j = 2; j * i <= NMAX; j++)
            prime[i * j] = 0;
    }
    for (int i = 1; i * 2 <= NMAX; i++) {
        for (int j = i; j <= 2 * i; j++)
        if (prime[j]) {
            nxtPrime[i] = j;
            break;
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) a[i][j] = nxtPrime[a[i][j]] - a[i][j];
    int res = oo;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++)
            cnt += a[i][j];
        res = min(res, cnt);
    }
    for (int j = 0; j < m; j++) {
        int cnt = 0;
        for (int i = 0; i < n; i++)
            cnt += a[i][j];
        res = min(res, cnt);
    }
    printf("%d", res);
    return 0;
}
/*
    We need to find the next prime of every a_i_j, which means finding X is a prime that X >= a_i_j
    Transform the table that a[i][j] = nxtPrime(a[i][j]) - a[i][j]
    Then we need to find the minimum sum of every rows and columns
*/
