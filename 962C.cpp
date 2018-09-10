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
vector <int> d;
int n;
int getbit(int x, int i) {
    return (x >> i) & 1;
}
bool issqrt(ll x) {
    ll i = sqrt(x);
    if (i * i == x) return 1;
    return 0;
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
        d.push_back(s[i] - '0');
    n = d.size();
    int res = -1;
    for (int i = 1; i <= (1 << n) - 1; i++) {
        ll tmp = 0;
        int cnt = 0;
        for (int j = 0; j < n; j++)
            if (getbit(i, j)) {
                if (d[j] == 0) {
                    if (tmp != 0) {
                        cnt++;
                        tmp = tmp * 10 + d[j];
                    }
                }
                else {
                    cnt++;
                    tmp = tmp * 10 + d[j];
                }
            }
        if (tmp > 0)
        if (issqrt(tmp)) 
            if (res == -1)
                res = n - cnt;
            else 
                res = min(res, n - cnt);
    }
    cout << res;
    return 0;
}
