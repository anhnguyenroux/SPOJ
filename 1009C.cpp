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
ll n, m;
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.inp", "r", stdin);
		freopen("output.out", "w", stdout);
	#endif
    scanf("%lld %lld", &n, &m);
    ll sum = 0;
    ll p;
    if (n % 2 == 0) p = n / 2;
    else p = (n / 2) + 1;
    for (int i = 1; i <= m; i++) {
        ll x, d;
        scanf("%lld %lld", &x, &d);
        sum += x * n;
        if (d < 0) {
            sum += d * (p - 1) * p / 2;
            sum += d * (n - p) * (n - p + 1) / 2;
        }
        else sum += d * (n - 1) * n / 2;
    }
    printf("%0.10lf", (double) sum / n);
    return 0;
}
