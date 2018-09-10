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
const int nmax = 1e5 + 10;
int n;
vector <ii> adj[nmax];
bool fre[nmax];
bool f[nmax];
bool fix[nmax];
void dfs(int u) {
    fre[u] = 0;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i].fi;
        int k = adj[u][i].se;
        if (fre[v]) {
            if (k == 2) {
                f[v] = 1;
                f[u] = 0;
                fix[v] = 1;
            }
            dfs(v);
            if (fix[v]) {
                f[u] = 0;
                fix[u] = 1;
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
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, k;
        cin >> u >> v >> k;
        adj[u].push_back(ii(v, k));
        adj[v].push_back(ii(u, k));
    }
    f[1] = 0;
    for (int i = 1; i <= n; i++) fre[i] = 1;
    for (int i = 1; i <= n; i++) fix[i] = 0;
    dfs(1);
    vector <int> res;
    for (int i = 1; i <= n; i++) 
        if (f[i]) res.push_back(i);
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    return 0;
}
