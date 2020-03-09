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
const int nmax = 1010;
int n;
int a[nmax][nmax];
vector <int> adj[nmax];
int fre[nmax];
void dfs(int p, int u) {
    fre[u] = 0;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (fre[v]) {
            if (p != 0 && a[v][p]) {
                cout << p << " " << u << " " << v;
                exit(0);
            } 
            dfs(u, v);
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
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) adj[i].push_back(j);
        }
    }
    for (int i = 1; i <= n; i++) fre[i] = 1;
    for (int i = 1; i <= n; i++)
        if (fre[i])
            dfs(0, i);
    cout << "-1 -1 -1";
    return 0;
}
// Hình như thuật sai rồi ạ
