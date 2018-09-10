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
struct product {
    ll k, l;
    ll val1;
    ll val2;
};
int n, f;
product a[nmax];
int cmp(product x, product y) {
    return (x.val2 - x.val1 > y.val2 - y.val1);
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> f;
    for (int i = 0; i < n; i++) {
        cin >> a[i].k >> a[i].l;
        a[i].val1 = min(a[i].k, a[i].l);
        a[i].val2 = min(a[i].k * 2, a[i].l);
    }
    sort(a, a + n, cmp);
    ll res = 0;
    for (int i = 0; i < n; i++) 
        if (i < f) res += (ll) min(a[i].k * 2, a[i].l);
        else res += (ll) min(a[i].k, a[i].l);
    cout << res;
    return 0;
}