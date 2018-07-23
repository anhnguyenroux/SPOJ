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
const int nmax = 255;
struct node {
    int u, v; 
    int k;
    node(int _u, int _v, int _k) {
        u = _u;
        v = _v;
        k = _k;
    }
};
int n, m;
int s, t;
vector <int> adj[nmax];
int f[nmax][nmax][2];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> m;
    cin >> s >> t;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) 
    for (int j = 1; j <= n; j++) {
        f[i][j][0] = -1;
        f[i][j][1] = -1;
    }
    queue <node> q;
    q.push(node(s, t, 0));
    f[s][t][0] = 0;
    while (!q.empty()) {
        int u = q.front().u, v = q.front().v, k = q.front().k;
        q.pop();
        if (k == 0) {
            for (int i = 0; i < adj[u].size(); i++) {
                int ux = adj[u][i];
                if (f[ux][v][1] == -1) {
                    f[ux][v][1] = f[u][v][0];
                    q.push(node(ux, v, 1));
                }
            }
        }
        if (k == 1) {
            for (int i = 0; i < adj[v].size(); i++) {
                int vx = adj[v][i];
                if (f[u][vx][0] == -1) {
                    f[u][vx][0] = f[u][v][1] + 1;
                    q.push(node(u, vx, 0));
                }
            }
        }
    }
    int res = INF;
    for (int i = 1; i <= n; i++)
        if (f[i][i][0] != -1)
            res = min(res, f[i][i][0]);
    if (res == INF) cout << -1;
    else cout << res;
    return 0;
}
