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
int a[nmax];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.inp", "r", stdin);
		//freopen("output.out", "w", stdout);
	#endif
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    map <int, int> cnt;
    vector <ii> res;
    int l = 0;
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
        if (cnt[a[i]] == 2) {
            res.push_back(ii(l + 1, i + 1));
            l = i + 1;
            cnt.clear();
        }
    }
    if (res.size() == 0) {
        cout << -1;
        return 0;
    }
    res[res.size() - 1].se = n;
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++)
        cout << res[i].fi << " " << res[i].se << "\n";
    return 0;
}
