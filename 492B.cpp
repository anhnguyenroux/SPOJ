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
int n, l;
int a[nmax];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    scanf("%d %d", &n, &l);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    int res = 2 * max(a[0], l - a[n - 1]);
    for (int i = 0; i < n - 1; i++)
        res = max(res, a[i + 1] - a[i]);
    printf("%.10f", res / (double) 2);
    return 0;
}
