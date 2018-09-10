#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int nmax = 1e5 + 10;
int a[nmax];
int f[nmax];
int n;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    ll res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 31; j >= 0; j--) {
            int v = (1 << j) - a[i];
            res += upper_bound(a + i + 1, a + n, v) - lower_bound(a + i + 1, a + n, v);
        }
    }
    cout << res;
    return 0;
}
