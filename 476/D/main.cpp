#include <bits/stdc++.h>
using namespace std;
const int nmax = 1e5 + 10;
const int lmax = 1e5 + 10;
typedef long long ll;
typedef pair <int, int> ii;
int n, l;
int a[nmax];
int f[lmax];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> l;
    for (int i = 1; i < n; i++)
        cin >> a[i];
    f[0] = 0;
    for (int i = 1; i < n; i++)
        f[i] = f[i - 1] + a[i];
    ll res = f[l];
    for (int i = l + 1; i < n; i++) res = min(res, (ll) f[i] - f[i - l]);
    cout << res;
    return 0;
}
