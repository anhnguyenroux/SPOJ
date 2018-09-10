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
const int nmax = 1e6 + 10;
struct node {
    int ans;
    int open, close;
};
node it[4 * nmax];
string s;
int n;
node combine(node l, node r) {
    node res;
    //int tmp = min(l.open, r.close);
    res.ans = l.ans + r.ans + min(l.open, r.close);
    res.open = l.open + r.open - min(l.open, r.close);
    res.close = l.close + r.close - min(l.open, r.close);
    return res;
}
void build(int k, int l, int r) {
    if (l == r) {
        it[k].ans = 0;
        it[k].open = 0;
        it[k].close = 0;
        if (s[l] == '(') 
            it[k].open = 1;
        else 
            it[k].close = 1;
        return;
    }
    int m = (l + r) >> 1;
    build(k << 1 | 0, l, m);
    build(k << 1 | 1, m + 1, r);
    it[k] = combine(it[k << 1 | 0], it[k << 1 | 1]);
}
node get(int k, int l, int r, int left, int right) {
    if (r < left || l > right) {
        node res;
        res.ans = 0;
        res.open = 0;
        res.close = 0;
        return res;
    }
    if (left <= l && r <= right) {
        return it[k];
    }
    int m = (l + r) >> 1;
    return combine(get(k << 1 | 0, l, m, left, right), 
                   get(k << 1 | 1, m + 1, r, left, right));
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
    cin >> s;
    n = s.length();
    s = "#" + s;
    build(1, 1, n);
    int m;
    cin >> m;
    while(m-- > 0) {
        int u, v;
        cin >> u >> v;
        node res = get(1, 1, n, u, v);
        cout << res.ans * 2 << "\n";
    }
    return 0;
}
