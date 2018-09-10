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
const int nmax = 2e5 + 10;
int n;
string s;
int dp[nmax];
int l, r, u, d;
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n;
    cin >> s;
    s = "#" + s;
    l = r = u = d = 0;
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'L' || s[i] == 'R') {
            dp[i] = min(dp[u], dp[d]) + 1;
            if (s[i] == 'L') l = i;
            if (s[i] == 'R') r = i;
        }
        if (s[i] == 'U' || s[i] == 'D') {
            dp[i] = min(dp[l], dp[r]) + 1;
            if (s[i] == 'U') u = i;
            if (s[i] == 'D') d = i;
        }
    }
    cout << dp[n] + 1;
    return 0;
}
