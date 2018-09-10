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
const int nmax = 1000;
int n, m;
vector <int> adj[nmax];
int cnt;
int res;
int fre[nmax], num[nmax];
void dfs(int u) {
    fre[u] = 0;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (fre[v]) {
            num[v] = num[u] + 1;
            dfs(v);
        }
        else {
            if (num[v] == num[u] - 2) res++;
        }
    }
}
void solver(int test_case) {
    for (int i = 1; i <= n; i++) num[i] = 0;
    for (int i = 1; i <= n; i++) fre[i] = 1;
    res = 0;
    num[1] = 1;
    dfs(1);
    cout << "Case #" << test_case << "\n";
    cout << n - res << "\n";
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
    int test;
    cin >> test;
    for (int t = 1; t <= test; t++) {
        cin >> n >> m;
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        solver(t);
        for (int i = 1; i <= n; i++)
            adj[i].clear();
    }
    return 0;
}
