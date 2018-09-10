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
const int nmax = 1010;
int n, m;
string l[nmax];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.inp", "r", stdin);
		//freopen("output.out", "w", stdout);
	#endif
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> l[i];
    set <int> res;
    for (int i = 0; i < n; i++) {
        int g, s;
        for (int j = 0; j < l[i].length(); j++) {
            if (l[i][j] == 'G') g = j;
            if (l[i][j] == 'S') s = j;
        }
        if (s < g) {
            cout << -1;
            return 0;
        }
        res.insert(s - g);
    }
    cout << res.size();
    return 0;
}
