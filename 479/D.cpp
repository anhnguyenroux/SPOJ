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
int n;
ll a[nmax];
int adj[nmax][nmax];
int trace[nmax];
int cnt;
int flag;
void outRes(int f) {
    vector <int> path;
    while (f != -1) {
        path.push_back(f);
        f = trace[f];
    }
    for (int i = path.size() - 1; i >= 0; i--)
        cout << a[path[i]] << " ";
    exit(0);
}
void dfs(int u) {
    if (flag) return;
    cnt++;
    if (cnt == n) {
        outRes(u);
        flag = 1;
        return;
    }
    for (int v = 1; v <= n; v++)
        if (v != u && adj[u][v] && trace[v] == 0) {
            trace[v] = u;   
            dfs(v);
        }
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) 
        if (i == j) adj[i][j] = 1;
        else adj[i][j] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            if (i != j) {
                if (a[i] % 3 == 0 && a[i] / 3 == a[j]) adj[i][j] = 1;
                if (a[i] * 2 == a[j]) adj[i][j] = 1;
            }
    }
    flag = 0;
    for (int i = 1; i <= n; i++) {
        if (flag) return 0;
        for (int j = 1; j <= n; j++) trace[j] = 0;
        trace[i] = -1;
        cnt = 0;
        dfs(i);
    }
    return 0;
}
