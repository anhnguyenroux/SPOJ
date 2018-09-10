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
const int nmax = 1e6 + 10;
const int mmax = 1e3 + 10;
int n, m;
int a[nmax];
int f[mmax][mmax];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
    }
    if (n > m) {
        cout << "YES";
        return 0;
    }
    for (int r = 0; r < m; r++)
        f[0][r] = 0;
    for (int i = 1; i <= n; i++) {
        f[i][a[i]] = 1;
        for (int r = 0; r < m; r++) { 
            f[i][r] = f[i][r] | f[i - 1][r];
            f[i][r] = f[i][r] | f[i - 1][(r - a[i] + m) % m];
        }
    }
    if (f[n][0]) cout << "YES"; else cout << "NO"; 
    return 0;
}
