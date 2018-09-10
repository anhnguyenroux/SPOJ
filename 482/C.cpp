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
const int nmax = 3e5 + 10;
int n, x, y;
vector <int> adj[nmax];
bool fre[nmax];
ll dfs(int u, int k) {
    fre[u] = 0;
    ll res = 1;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (fre[v] && v != k) 
            res += dfs(v, k);
    }
    return res;
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> x >> y;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) fre[i] = 1;
    ll tmp1 = n - dfs(y, x);
    for (int i = 1; i <= n; i++) fre[i] = 1;
    ll tmp2 = n - dfs(x, y);
    cout << (ll) n * (n - 1) - (ll) tmp1 * tmp2;
    return 0;
}
