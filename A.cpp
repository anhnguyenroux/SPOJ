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
const int nmax = 55;
int n, k, m;
string t;
int next[nmax];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.inp", "r", stdin);
		//freopen("output.out", "w", stdout);
	#endif
    cin >> n >> k;
    cin >> t;
    int m = t.length();
    for (int i = 1 ; i < m; i++) {
        int len = 0;
        int flag = 1;
        while (i + len < m && t[len] == t[i + len]) len++;
        if (i + len == m) {
            for (int j = 0; j < len; j++)
                cout << t[j];
            for (int j = 1; j <= k; j++)
                cout << t.substr(len, m - len + 1); 
            return 0;
        }
    }
    for (int j = 1; j <= k; j++)
        cout << t;
    return 0;
}
