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
int m;
int a[nmax];
int b[nmax];
int check(double f) {
    for (int i = 1; i < n; i++) {
        f -= (m + f) / a[i];
        f -= (m + f) / b[i + 1];
    }
    f -= (m + f) / a[n];
    f -= (m + f) / b[1];
    if (f >= 0) return 1;
    else return 0;
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    int found = 0;
    double res = -1;
    double lo = 0, hi = 1e9 + 10;
    for (int t = 1; t <= 55; t++) {
        double mid = (lo + hi) / 2;
        if (check(mid)) {
            found = 1;
            res = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    if (found)
        printf("%.10lf", res);
    else 
        printf("-1");
    return 0;
}
