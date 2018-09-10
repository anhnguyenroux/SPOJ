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
const int nmax = 3e5;
int n, m;
vector <int> T[4 * nmax];
void update(int k, int l, int r, int u, int v, int x) {
    if (l > v || r < u) return;
    if (l >= u && r <= v) {
        T[k].push_back(x);
        return;
    }
    int mid = (l + r) >> 1;
    update(k * 2, l, mid, u, v, x);
    update(k * 2 + 1, mid + 1, r, u, v, x);
}
int get(int k, int l, int r, int u) {
    if (l == u && u == r) {
        for (int i = 0; i < T[k].size(); i++)
            if (T[k][i] != u) return T[k][i];
        return 0;
    }
    int mid = (l + r) >> 1;
    if (u <= mid) return get(k * 2, l, mid, u);
    else return get(k * 2 + 1, mid + 1, r, u);
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> m;
    while (m-- > 0) {
        int l, r, x;
        cin >> l >> r >> x;
        update(1, 1, n, l, r, x);
    }
    for (int i = 1; i <= n; i++)
        cout << get(1, 1, n, i) << " ";
    return 0;
}
