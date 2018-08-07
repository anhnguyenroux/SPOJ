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
const int nmax = 810;
int n, m;
int cnt;
vector <int> adj[nmax];
int fre[nmax];
int num[nmax], low[nmax];
stack <int> st;
int sltp = 0;
int tp[nmax];
int deg[nmax];
void dfs(int u) {
    num[u] = ++cnt;
    low[u] = cnt;
    st.push(u);
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (fre[v]) {
            if (num[v] == 0) {
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
            else low[u] = min(low[u], num[v]);
        }
    }
    if (num[u] == low[u]) {
        sltp++;
        int v;
        do {
            v = st.top();
            st.pop();
            tp[v] = sltp;
            fre[v] = 0;
        } while (v != u);
    }
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        fre[i] = 1;
        num[i] = 0;
    }
    cnt = 0;
    for (int i = 1; i <= n; i++) 
        if (num[i] == 0) dfs(i);
    for (int i = 1; i <= sltp; i++) 
        deg[i] = 0;
    for (int u = 1; u <= n; u++) {
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (tp[u] != tp[v]) deg[tp[v]]++;
        }
    }
    int res = 0;
    for (int i = 1; i <= sltp; i++) 
        if (deg[i] == 0) res++;
    printf("%d", res);
    return 0;
}
