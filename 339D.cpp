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
const int nmax = 1 << 20;
int n, m;
int a[nmax];
int T[4 * nmax];
void build(int h, int k, int l, int r) {
    if (l == r) {
        T[k] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(h + 1, k * 2, l, mid);
    build(h + 1, k * 2 + 1, mid + 1, r);
    if (h % 2 == 0) {
        if (n % 2 == 0) T[k] = T[k * 2] ^ T[k * 2 + 1];
        else T[k] = T[k * 2] | T[k * 2 + 1];
    }
    else {
        if (n % 2 == 0) T[k] = T[k * 2] | T[k * 2 + 1];
        else T[k] = T[k * 2] ^ T[k * 2 + 1];
    }
}
void update(int h, int k, int l, int r, int u, int v) {
    if (l > u || r < u) return;
    if (l == u && r == u) {
        T[k] = v;
        return;
    }
    if (h == n) return;
    int mid = (l + r) >> 1;
    update(h + 1, k * 2, l, mid, u, v);
    update(h + 1, k * 2 + 1, mid + 1, r, u, v);
    if (h % 2 == 0) {
        if (n % 2 == 0) T[k] = T[k * 2] ^ T[k * 2 + 1];
        else T[k] = T[k * 2] | T[k * 2 + 1];
    }
    else {
        if (n % 2 == 0) T[k] = T[k * 2] | T[k * 2 + 1];
        else T[k] = T[k * 2] ^ T[k * 2 + 1];
    }
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> m;
    for (int i = 1; i <= (1 << n); i++) 
        cin >> a[i];
    build(0, 1, 1, 1 << n);
    while (m-- > 0) {
        int p, b;
        cin >> p >> b;
        update(0, 1, 1, 1 << n, p, b);
        cout << T[1] << "\n";
    }
    return 0;
}
