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
int n, q;
vector <int> adj[nmax];
int fre[nmax];
int c[nmax];
int num[nmax];
int cnt;
void dfs(int u) {
    fre[u] = 0;
    c[u] = 1;
    cnt++;
    num[u] = cnt;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (fre[v]) {
            dfs(v);
            c[u] += c[v];
        }
    }
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        c[i] = 0;
        fre[i] = 1;
    }
    cnt = 0;
    dfs(1);
    map <int, int> m;
    map <int, int> :: iterator it;
    for (int i = 1; i <= n; i++)
        m.insert(make_pair(num[i], i));
    while (q-- > 0) {
        int u, k;
        cin >> u >> k;
        if (k > c[u]) cout << -1 << "\n";
        else {
            it = m.find(num[u] + k - 1);
            cout << it->second << "\n";
        }
    }
    return 0;
}
