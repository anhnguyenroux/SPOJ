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
const int mmax = 50010;
const int nmax = 7;
int m, n;
int ti[mmax][nmax];
int f[mmax];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> m >> n;
    for (int i = 1; i <= m; i++) 
    for (int j = 1; j <= n; j++) cin >> ti[i][j];
    for (int i = 1; i <= m; i++) 
        f[i] = 0;
    for (int i = 1; i <= n; i++) {
        int t = 0;
        for (int j = 1; j <= m; j++) {
            int start = max(t, f[j]);
            f[j] = start + ti[j][i];
            t = f[j];
        }
    }
    for (int i = 1; i <= m; i++)
        cout << f[i] << " ";
    return 0;
}
