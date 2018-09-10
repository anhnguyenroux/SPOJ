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
string s,t;
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> s >> t;
    int n = s.length();
    int m = t.length();
    int res = n + m;
    s = "#" + s;
    t = "#" + t;
    for (int cnt = 1; cnt <= min(n, m); cnt++)
        if (s[n - cnt + 1] == t[m - cnt + 1]) {
            res = n + m - 2 * cnt;
        }
        else break;
    cout << res;
    return 0;
}
