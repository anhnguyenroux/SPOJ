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
const int modulo = 1e9 + 7;
int n, m;
int a[nmax];
vector <int> adj[nmax];
int number[nmax], low[nmax];
bool fre[nmax];
int cnt = 0;
stack <int> st;
ll cost;
ll way;
void dfs(int u) {
    cnt++;
    number[u] = cnt;
    low[u] = number[u];
    st.push(u);
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (fre[v]) {
            if (number[v] == 0) {
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
            else 
                low[u] = min(low[u], number[v]);
        }
    }
    //cout << u << " " << number[u] << " " << low[u] << "\n";
    if (number[u] == low[u]) {
        int v;
        int mm = INF + 1;
        int w = 0;
        do {
            v = st.top();
            st.pop();
            fre[v] = 0;
            if (a[v] < mm) {
                mm = a[v];
                w = 1;
            }
            else 
                if (a[v] == mm) w++;
            //cout << v << " ";
        } while (v != u);
        //cout << "\n";
        cost += mm;
        way = (way * w) % modulo;
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
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        number[i] = 0;
        fre[i] = 1;
    }
    cost = 0; 
    way = 1;
    for (int i = 1; i <= n; i++)
        if (number[i] == 0) dfs(i);
    cout << cost << " " << way;
    return 0;
}
