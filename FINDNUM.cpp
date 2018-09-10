#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0);
#define all(v) (v).begin(), (v).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ll oo = 1e18 + 100;
const int p[8] = {2, 3, 5, 7, 11, 13, 17, 23};
const int nmax = 1010;
int n;
int a[nmax];
ll l[10][100];
int g[10];
ll f[nmax][8];
void init() {
    for (int i = 1; i <= 8; i++) {
        l[i][0] = 1;
        g[i] = 0;
        ll u = 1;
        while (u < oo / p[i - 1]) {
            u *= p[i - 1];
            g[i]++;
            l[i][g[i]] = u;
        }
    }
}
ll get(int n, int k) {
    if (n == 1) return 1;
    if (k < 0) return oo;
    if (f[n][k] != -1) return f[n][k];
    ll res = get(n, k - 1);
    for (int j = 1; j <= g[k]; j++)
        if (n % (j + 1) == 0) {
            ll u = get(n / (j + 1), k - 1);
            if (u < oo / l[k][j]) 
                res = min(res, u * l[k][j]);
        }
    f[n][k] = res;
    return f[n][k];
}
int main() {
    IO;
    cin >> n;
    if (n == 1) {
        cout << 1;
        return 0;
    }
    init();
    for (int i = 0; i <= n; i++)
    for (int j = 0; j <= 8; j++) 
        f[i][j] = -1;
    cout << get(n, 8);
    return 0;
}
