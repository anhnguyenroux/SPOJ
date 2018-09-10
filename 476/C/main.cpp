#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, m, d;
vector <ll> opt;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k >> m >> d;
    ll res = 0;
    for (int d1 = 1; d1 <= d; d1++) {
        ll left = 1, right = m;
        while (left <= right) {
            ll mid = (left + right) >> 1;
            ll s = n / mid;
            ll spi = (s + k - 1) / k;
            if (spi == d1) {
                res = max(res, (ll) d1 * mid);
                left = mid + 1;
            }
            else
                if (spi > d1) left = mid + 1;
                    else if (spi < d1) right = mid - 1;
        }
    }
    cout << res;
    return 0;
}
