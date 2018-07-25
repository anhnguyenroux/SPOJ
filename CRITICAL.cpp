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
const int nmax = 20010;
int n, m;
vector <int> adj[nmax];
int p[nmax], c[nmax];
int num[nmax], low[nmax];
int cnt;
int cp;
int sl[nmax], lt[nmax];
int dchild[nmax];
int isCut[nmax];
void dfs(int u) {
    num[u] = ++cnt;
    low[u] = n + 1;
    c[u] = 1;
    lt[u] = cp;
    sl[cp]++;
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
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        p[i] = 0;
        sl[i] = 0;
    }
    cnt = 0;
    cp = 0;
    for (int i = 1; i <= n; i++)
        if (p[i] == 0) {
            cp++;
            p[i] = -1;
            dfs(i);
        }
    for (int i = 1; i <= n; i++) dchild[i] = 0;
    for (int v = 1; v <= n; v++) {
        int u = p[v];
        if (u > 0) dchild[u]++;
    }
    for (int i = 1; i <= n; i++) isCut[i] = 0;
    for (int v = 1; v <= n; v++)
        if (p[v] > 0) {
            int u = p[v];
            if (low[v] >= num[u]) {
                isCut[u] = isCut[u] || (p[u] != -1) || (dchild[u] >= 2);
            }
        }
    double res = 0;
    for (int u = 1; u <= n; u++) 
        if (isCut[u]) {
            int cl = 0;
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i];
                if (p[v] == u && low[v] >= num[u]) {
                    res += c[v] * (sl[lt[u]] - c[v] - 1);
                    cl += c[v];
                }
            }
            res += cl * (sl[lt[u]] - cl - 1);
        }
    res /= 2;
    printf("%.2lf", res / n);
    return 0;
}
