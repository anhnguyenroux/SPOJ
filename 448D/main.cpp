#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX   =   5e5;
int main() {
    ll n, m;
    ll k;
    cin >> n >> m >> k;
    ll ans = -1;
    ll left = 1, right = MAX * MAX + 1;
    while (left <= right) {
        ll mid = (left + right) >> 1;
        ll cnt = 0;
        for (int i = 1; i <= n; i++)
            cnt = cnt + min((ll)(mid - 1) / i, (ll) m);
        if (cnt < k) {
            ans = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }
    cout << ans;
    return 0;
}
/*
    Use binary search with answer. Finding the largest value X that amount of number is less than X in each row is less than k.
    Complexity : O(n * log(mn))
*/
