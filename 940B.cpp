#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0);
#define all(v) (v).begin(), (v).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pi;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const int nmax = 1e6 + 10;
ll x, k, a, b;
int main() {
    IO;
    cin >> x >> k >> a >> b;
    ll cost = 0;
    while (true) {
        if (x == 1) break;
        if (k == 1) {
            cost = (x - 1) * a;
            break;
        }
        if (x < k) cost += (x - 1) * a, x = 1;
        if (x > k && x % k != 0) cost += (x % k) * a, x -= (x % k);
        if (x % k == 0) cost += min(b, (x - x / k) * a), x = x / k;
    }
    cout << cost;
    return 0;
}
/*
    For an optimal way, if k = 1, the cost must be (x - 1) * a.
    if (x < k) the cost is (x - 1) * a as well.
    With x > k and x % k != 0, we have to substract x by (x % k) with the cost (x % k) * a, so that we have x % k == 0
    With x % k == 0, we have 2 cost that must be considered, they are b (when we use second operation);
    we must see the cost when substract x to reduce x to x / k is (x - x/k) with the cost is (x - x / k) * a.
*/
