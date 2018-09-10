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
const int nmax = 1e5 + 10;
int n;
ll a[nmax * 2];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.inp", "r", stdin);
		//freopen("output.out", "w", stdout);
	#endif
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n; i++) scanf("%lld", &a[i]);
    sort(a + 1, a + 1 + 2 * n);
    ll res = (a[n] - a[1]) * (a[2 * n] - a[n + 1]);
    for (int i = 1; i <= n; i++)
        res = min(res, (a[2 * n] - a[1]) * (a[i + n - 1] - a[i]));
    printf("%lld", res);
    return 0;
}
