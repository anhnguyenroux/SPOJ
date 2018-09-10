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
const int nmax = 2010;
int n;
ll a[nmax][nmax];
ll d1[2 * nmax], d2[2 * nmax];
bool check(int x1, int y1, int x2, int y2) {
    if ((x1 + y1) % 2 == (x2 + y2) % 2) return 0;
    return 1;
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n;
    for (int i = 0; i < 2 * n; i++) d1[i] = 0, d2[i] = 0;
    for (int i = 0; i < n; i++) 
    for (int j = 0; j < n; j++) {
        cin >> a[i][j];
        d1[i + j] += a[i][j];
        d2[i - j + n - 1] += a[i][j];
    }
    int x1, y1;
    ll res1 = -1;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) 
        if (d1[i + j] + d2[i - j + n - 1] - a[i][j] > res1) {
            x1 = i;
            y1 = j;
            res1 = d1[i + j] + d2[i - j + n - 1] - a[i][j];
        }
    d1[x1 + y1] = -1;
    d2[x1 - y1 + n - 1] = -1;
    int x2, y2;
    ll res2 = -1;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) 
        if (check(x1, y1, i, j)) {
            ll tmp = d1[i + j] + d2[i - j + n - 1] - a[i][j];
            if (tmp > res2) {
                res2 = tmp;
                x2 = i;
                y2 = j;
            }
        }
    cout << res1 + res2 << "\n";
    cout << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1;
    return 0;
}
