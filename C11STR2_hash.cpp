#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MOD       =   1e9 + 7;
const int MAX       =   1e5 + 10;
char a[MAX], b[MAX];
ll POW[MAX];
ll hashA[MAX], hashB[MAX];
inline ll getHashA(int i, int j) {
    ll res = (hashA[j] - hashA[i - 1] * POW[j - i + 1] + (ll) MOD * MOD) % MOD;
    return res;
}
inline ll getHashB(int i, int j) {
    ll res = (hashB[j] - hashB[i - 1] * POW[j - i + 1] + (ll) MOD * MOD) % MOD;
    return res;
}
int main() {
    scanf("%s", &a[1]);
    scanf("%s", &b[1]);
    int n = strlen(a + 1), m = strlen(b + 1);
    POW[0] = 1;
    for (int i = 1; i <= max(n, m); i++) 
        POW[i] = (POW[i - 1] * 26) % MOD;
    hashA[0] = 0;
    for (int i = 1; i <= n; i++)
        hashA[i] = (hashA[i - 1] * 26 + a[i] - 'a') % MOD;
    hashB[0] = 0;
    for (int i = 1; i <= m; i++)
        hashB[i] = (hashB[i - 1] * 26 + b[i] - 'a') % MOD;
    for (int len = n; len >= 1; len--) 
        if (getHashA(n - len + 1, n) == getHashB(1, len)) {
            printf("%s%s", a + 1, b + len + 1);
            return 0;
        }
    printf("%s%s", a + 1, b + 1);
    return 0;
}