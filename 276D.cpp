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
int getbit(ll x, int i) {
    return (x >> i) & 1;
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    ll l, r;
    cin >> l >> r;
    if (l == r) {
        cout << 0;
        return 0;
    }
    int p;
    for (int k = 60; k >= 0; k--)
        if (getbit(l, k) != getbit(r, k)) {
            p = k;
            break;
        }
    ll res = (1ll << (p + 1)) - 1ll;
    cout << res;
    return 0;
}
