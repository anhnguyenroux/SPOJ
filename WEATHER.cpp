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
int n, m;
vector <int> adj[nmax];
int num[nmax], low[nmax];
int p[nmax];
int c[nmax];
int cnt;
int dfs(int u) {
    num[u] = ++cnt;
    low[u] = n + 1;
    c[u] = 1;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (p[v] == 0) {
            p[v] = u;
            dfs(v);
            c[u] += c[v];
            low[u] = min(low[u], low[v]);
        }
        else if (v != p[u])
            low[u] = min(low[u], num[v]);
    }
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        p[i] = 0;
        c[i] = 0;
    }
    cnt = 0;
    p[1] = -1;
    dfs(1);
    int res = 0;
    for (int v = 1; v <= n; v++)
        if (low[v] >= num[v]) res += c[v] * (n - c[v]);
    cout << res;
    return 0;
}
