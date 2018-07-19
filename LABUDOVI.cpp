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
const int nmax = 1510;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
int n, m;
char a[nmax][nmax];
int sx, sy, ex, ey;
int d[nmax][nmax];
int avail[nmax][nmax];
void tanbang() {
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        d[i][j] = -1;
    queue <ii> q;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        if (a[i][j] != 'X') {
            d[i][j] = 0;
            q.push(ii(i, j));
        }
    while (!q.empty()) {
        int u = q.front().fi, v = q.front().se; 
        q.pop();
        for (int k = 0; k < 4; k++) {
            int ux = u + dx[k], vx = v + dy[k];
            if (ux >= 1 && ux <= n && vx >= 1 && vx <= m) 
                if (d[ux][vx] == -1) {
                    d[ux][vx] = d[u][v] + 1;
                    q.push(ii(ux, vx));
                }
        }
    }
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> m;
    sx = -1, sy = -1;
    ex = -1, ey = -1;
    for (int i = 1; i <= n; i++) {
        string x;
        cin >> x;
        x = "#" + x;
        for (int j = 1; j <= m; j++) {
            a[i][j] = x[j];
            if (x[j] == 'L') 
                if (sx == -1) sx = i, sy = j; 
                else 
                    ex = i, ey = j;
        }
    }
    tanbang();
    queue <ii> q1, q2;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) 
        avail[i][j] = 1;
    q1.push(ii(sx, sy));
    avail[sx][sy] = 0;
    for (int step = 0; !q1.empty(); step++) {
        while (!q1.empty()) {
            int u = q1.front().fi, v = q1.front().se;
            q1.pop();
            q2.push(ii(u, v));
            for (int k = 0; k < 4; k++) {
                int ux = u + dx[k], vx = v + dy[k];
                if (ux >= 1 && ux <= n && vx >= 1 && vx <= m) 
                if (avail[ux][vx] && d[ux][vx] <= step) {
                    avail[ux][vx] = 0;
                    q1.push(ii(ux, vx));
                }
            }
        }
        while (!q2.empty()) {
            int u = q2.front().fi, v = q2.front().se;
            q2.pop();
            if (u == ex && v == ey) {
                cout << step;
                return 0;
            }
            for (int k = 0; k < 4; k++) {
                int ux = u + dx[k], vx = v + dy[k];
                if (ux >= 1 && ux <= n && vx >= 1 && vx <= m) 
                if (avail[ux][vx] && d[ux][vx] <= step + 1) {
                    avail[ux][vx] = 0;
                    q1.push(ii(ux, vx));
                }
            }
        }
    }
    return 0;
}
