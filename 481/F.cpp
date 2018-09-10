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
typedef pair <int, int> ii;
int n, k;
int a[nmax];
int d[nmax];
ii b[nmax];
int fen[nmax];
void zip() {
    for (int i = 1; i <= n; i++) {
        b[i].fi = a[i];
        b[i].se = i;
    }
    sort(b + 1, b + 1 + n);
    a[b[1].se] = 1;
    int v = 1;
    for (int i = 2; i <= n; i++)
        if (b[i].fi == b[i - 1].fi) a[b[i].se] = v;
        else
            a[b[i].se] = ++v;
}
void update(int i) {
    while (i <= n) {
        fen[i]++;
        i += i & (-i);
    }
}
int getsum(int i) {
    int sum = 0;
    while (i > 0) {
        sum += fen[i];
        i -= i & (-i);
    }
    return sum;
} 
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    zip();
    for (int i = 1; i <= n; i++) d[i] = 0;
    for (int i = 1; i <= k; i++) {
        int u, v;
        cin >> u >> v;
        if (a[v] < a[u]) d[u]++;
        if (a[u] < a[v]) d[v]++;
    }
    for (int i = 1; i <= n; i++)
        fen[i] = 0;
    for (int i = 1; i <= n; i++) update(a[i]);
    for (int i = 1; i <= n; i++)
        cout << getsum(a[i] - 1) - d[i] << " ";
    return 0;
}
