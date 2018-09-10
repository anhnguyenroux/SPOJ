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
int n, m;
vector <int> adj[nmax];
int cnt;
int sl;
int tt[nmax];
int fre[nmax];
void dfs(int u) {
    sl++;
    fre[u] = cnt;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (fre[v] == 0) dfs(v);
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
    for (int i = 1; i <= n; i++) 
        fre[i] = 0;
    cnt = 0;
    for (int i = 1; i <= n; i++)
        if (fre[i] == 0) {
            cnt++;
            sl = 0;
            dfs(i);
        }
    
    for (int i = 1; i <= cnt; i++) tt[i] = 1;
    for (int u = 1; u <= n; u++) {
        int x = 0;
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (fre[u] == fre[v]) x++;
        }
        if (x != 2) tt[fre[u]] = 0;
    }
    int res = 0;
    for (int i = 1; i <= cnt; i++)
        if (tt[i]) res++;
    cout << res;
    return 0;
}
