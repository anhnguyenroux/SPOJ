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
const int nmax = 1010;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
int n, m;
char a[nmax][nmax];
int d[nmax][nmax];
void bfs() {
    deque <ii> q;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        d[i][j] = INF;
    q.push_back(ii(0, 0));
    d[0][0] = 0;
    while (!q.empty()) {
        int u = q.front().fi, v = q.front().se;
        q.pop_front();
        if (u == n - 1 && v == m - 1) {
            cout << d[u][v] << "\n";
            return;
        }
        for (int k = 0; k < 4; k++) {
            int ux = u + dx[k], vx = v + dy[k];
            if (ux >= 0 && ux < n && vx >= 0 && vx < m) {
                int w = (a[u][v] != a[ux][vx]);
                if (d[ux][vx] > (d[u][v] + w)) {
                    d[ux][vx] = d[u][v] + w;
                    if (w == 0) q.push_front(ii(ux, vx));
                    else q.push_back(ii(ux, vx));
                }
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
    int t;
    scanf("%d", &t);
    while (t-- > 0) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) scanf("%s", &a[i]);
        bfs();
    }
    return 0;
}
