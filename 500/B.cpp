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
const int nmax = 1e5;
int n, x;
int a[nmax + 10];
int f1[nmax + 10], f2[nmax + 10];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.inp", "r", stdin);
		freopen("output.out", "w", stdout);
	#endif
    scanf("%d %d", &n, &x);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 0; i <= nmax; i++)
        f1[i] = 0, f2[i] = 0;
    for (int i = 1; i <= n; i++) {
        f1[a[i]]++;
        if ((a[i] & x) != a[i])
            f2[a[i] & x]++;
    }
    int ans = 3;
    for (int i = 0; i <= nmax; i++) {
        if (f1[i] >= 2) ans = min(ans, 0);
        if (f1[i] >= 1 && f2[i] >= 1) ans = min(ans, 1);
        if (f2[i] >= 2) ans = min(ans, 2);
    }
    if (ans == 3) printf("-1");
    else printf("%d", ans);
    return 0;
}
