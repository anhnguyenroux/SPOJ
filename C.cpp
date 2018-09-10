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
const int nmax = 3e5 + 10;
int n;
multiset <int> x, y;
ii p[nmax];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.inp", "r", stdin);
		//freopen("output.out", "w", stdout);
	#endif
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i].fi >> p[i].se;
        x.insert(p[i].fi);
        y.insert(p[i].se);
    }
    int res = 0;
    multiset <int> :: iterator ix, iy;
    for (int i = 0; i < n; i++) {
        ix = x.find(p[i].fi);
        x.erase(ix);
        iy = y.find(p[i].se);
        y.erase(iy);
        int xmax = *(x.rbegin());
        int ymin = *(y.begin());
        if (xmax <= ymin) res = max(res, ymin - xmax);
        x.insert(p[i].fi);
        y.insert(p[i].se);
    }
    cout << res;
    return 0;
}
