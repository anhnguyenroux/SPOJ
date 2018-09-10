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
ll a[nmax];
multiset <ii> s;
multiset <ll> sum;
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n;
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    s.insert(ii(1, n));
    sum.insert(a[n]);
    for (int i = 1; i < n; i++) {
        int x; cin >> x;
        multiset <ii> :: iterator it;
        it = s.lower_bound(ii(x + 1, 0));
        it--;
        ii u = *it;
        s.erase(u);
        sum.erase(sum.lower_bound(a[u.se] - a[u.fi - 1]));
        if (u.fi != x) {
            s.insert(ii(u.fi, x - 1));
            sum.insert(a[x - 1] - a[u.fi - 1]);
        }
        if (u.se != x) {
            s.insert(ii(x + 1, u.se));
            sum.insert(a[u.se] - a[x]);
        }
        multiset <ll> :: iterator it2;
        it2 = sum.end();
        it2--;
        cout << *it2 << "\n";
    }
    cout << 0;
    return 0;
}