#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int nmax = 1e5 + 10;
const int hmax = 1e6;
int n;
int a[nmax];
int f[hmax + 10];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++) cin >> a[i], f[a[i]]++;
    for (int h = hmax; h >= 1; h--)
    if (f[h] % 2 == 1) {
        if (f[h - 1] > 0) f[h]--, f[h - 1]++;
        else
            if (f[h - 1] == 0) f[h]--;
    }
    ll res = 0;
    int pre = 0;
    for (int h = hmax; h >= 1; h--)
    if (f[h]) {
        if (pre) {
            res += (ll) pre * h;
            f[h] -= 2;
            pre = 0;
        }
        if (f[h] >= 4) {
            int sl = f[h] / 4;
            res += (ll) sl * h * h;
            f[h] %= 4;
        }
        if (f[h] == 2)
        if (!pre) pre = h;
        else {
            res += (ll) pre * h;
            pre = 0;
        }
    }
    cout << res;
    return 0;
}
