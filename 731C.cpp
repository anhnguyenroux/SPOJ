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
const int nmax = 2e5 + 10;
int n, m, k;
int c[nmax];
bool fre[nmax];
map <int, int> f;
vector <int> d;
int cnt;
int cmax;
vector <int> adj[nmax];
void dfs(int u) {
    cnt++;
    d.push_back(c[u]);
    fre[u] = 0;
    f[c[u]]++;
    cmax = max(cmax, f[c[u]]);
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (fre[v]) dfs(v);
    }
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) fre[i] = 1;
    for (int i = 1; i <= n; i++) f[c[i]] = 0;
    int res = 0;
    for (int i = 1; i <= n; i++)
    if (fre[i]) {
        d.clear();
        cnt = 0;
        cmax = 0;
        dfs(i);
        res += cnt - cmax;
        for (int j = 0; j < d.size(); j++) 
            f[d[j]] = 0;
    }
    cout << res;
    return 0;
}
