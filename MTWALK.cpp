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
const int nmax = 110;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
int n;
int h[nmax][nmax];
int hmin, hmax;
int fre[nmax][nmax];
int check(int h1, int h2) {
    if (h[1][1] < h1 || h[1][1] > h2) return 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            fre[i][j] = 1;
    queue <ii> q;
    q.push(ii(1, 1));
    fre[1][1] = 0;
    while (!q.empty()) {
        ii cur = q.front(); q.pop();
        int u = cur.fi, v = cur.se;
        for (int k = 0; k < 4; k++) {
            int ux = u + dx[k];
            int vx = v + dy[k];
            if (ux >= 1 && ux <= n && vx >= 1 && vx <= n) 
            if (h[ux][vx] >= h1 && h[ux][vx] <= h2)
            if (fre[ux][vx]) {
                if (ux == n && vx == n) return 1;
                fre[ux][vx] = 0;
                q.push(ii(ux, vx));
            }
        }
    }
    return 0;
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n;
    hmax = 0, hmin = INF;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> h[i][j];
            hmin = min(hmin, h[i][j]);
            hmax = max(hmax, h[i][j]);
        }
    int res = hmax - hmin;
    for (int i = hmin; i <= h[1][1]; i++) {
        int left = 0, right = hmax - hmin;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (check(i, i + mid)) {
                res = min(res, mid);
                right = mid - 1;
            }
            else left = mid + 1;
        }
    }
    cout << res;
    return 0;
}
