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
const int nmax = 3e5 + 10;
struct seg {
    int l, r;
    int pos;
};
int n; 
seg a[nmax];
int cmp(seg a, seg b) {
    if (a.l != b.l) return (a.l < b.l);
    return (a.r > b.r);
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].l >> a[i].r;
        a[i].pos = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    int res = 1;
    for (int i = 2; i <= n; i++)
        if (a[i].r <= a[res].r) {
            cout << a[i].pos << " " << a[res].pos;
            return 0;
        }
        else res = i;
    cout << "-1 -1";
    return 0;
}
