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
const int nmax = 5e5 + 10;
int n, k;
string s;
void solve2() {
    int res0 = 0, res1 = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1 && s[i] != 'A') res0++;
        if (i % 2 == 0 && s[i] != 'B') res0++;
    }
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1 && s[i] != 'B') res1++;
        if (i % 2 == 0 && s[i] != 'A') res1++;
    }
    if (res0 < res1) {
        cout << res0 << "\n";
        for (int i = 1; i <= n; i++)
            if (i % 2 == 1) cout << "A"; else cout << "B";
    }
    else {
        cout << res1 << "\n";
        for (int i = 1; i <= n; i++)
            if (i % 2 == 1) cout << "B"; else cout << "A"; 
    }
}
void solve() {
    int res = 0;
    for (int i = 2; i <= n; i++)
        if (s[i] == s[i - 1]) s[i] = '0';
    for (int i = 1; i < n; i++) 
    if (s[i] == '0') {
        res++;
        if (s[i - 1] != 'A' && s[i + 1] != 'A') s[i] = 'A';
        else 
            if (s[i - 1] != 'B' && s[i + 1] != 'B') s[i] = 'B';
            else s[i] = 'C';
    }
    if (s[n] == '0') {
        res++;
        if (s[n - 1] == 'A') s[n] = 'B';
        else 
            s[n] = 'A';
    }
    cout << res << "\n";
    for (int i = 1; i <= n; i++)
        cout << s[i];
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.inp", "r", stdin);
		//freopen("output.out", "w", stdout);
	#endif
    cin >> n >> k;
    cin >> s;
    s = "#" + s;
    if (k == 2) solve2();
    else 
        solve();
    return 0;
}
