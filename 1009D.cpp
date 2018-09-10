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
int gcd(int x, int y) {
    while (y != 0) {
        int r = x % y;
        x = y;
        y = r;
    }
    return x;
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.inp", "r", stdin);
		//freopen("output.out", "w", stdout);
	#endif
    int n, m;
    cin >> n >> m;
    if (m < n - 1) {
        cout << "Impossible";
        return 0;
    }
    vector <ii> res;
    int cnt = 0;
    for (int i = 1; i <= n; i++) 
        for (int j = i + 1; j <= n; j++)
            if (gcd(i, j) == 1) {
                res.push_back(ii(i, j));
                cnt++;
                if (cnt == m) {
                    cout << "Possible" << "\n";
                    for (int t = 0; t < res.size(); t++)
                        cout << res[t].fi << " " << res[t].se << "\n";
                    return 0;
                }
            }
    cout << "Impossible";
    return 0;
}
