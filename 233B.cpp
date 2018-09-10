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
ll n;
int sum(ll x) {
    int ret = 0;
    while (x > 0) {
        ret += x % 10;
        x /= 10;
    }
    return ret;
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    scanf("%lld", &n);
    ll res = LINF;
    for (int s = 1; s <= 162; s++) {
        ll t = sqrt(s * s + 4 * n);
        if (t * t != s * s + 4 * n) continue;
        ll x1 = (-s + t) / 2;
        ll x2 = (s + t) / 2;
        if (sum(x1) == s) res = min(res, x1);
        if (sum(x2) == s) res = min(res, x2);
    }
    if (res == LINF) printf("-1");
    else
        printf("%lld", res);
    return 0;
}
