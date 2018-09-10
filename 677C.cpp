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
const int modulo = 1e9 + 7;
int cnt[65];
int changecode(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
    if (c >= 'a' && c <= 'z') return c - 'a' + 36;
    if (c == '-') return 62;
    if (c == '_') return 63;
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    string s;
    cin >> s;
    int n = s.length();
    s = "#" + s;
    for (int i = 0; i < 64; i++)
    for (int j = 0; j < 64; j++)
        cnt[i & j]++;
    ll res = 1;
    for (int i = 1; i <= n; i++)
        res = (res * cnt[changecode(s[i])]) % modulo;
    cout << res;
    return 0;
}
