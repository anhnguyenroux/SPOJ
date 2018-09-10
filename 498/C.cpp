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
int n;
int a[nmax];
ll f1[nmax], f2[nmax];
int search(int i) {
    int left = i + 1, right = n;
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (f2[mid] == f1[i]) return 1;
        if (f2[mid] > f1[i]) left = mid + 1;
        else right = mid - 1;
    }
    return 0;
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    f1[0] = 0;
    for (int i = 1; i <= n; i++) f1[i] = (ll) a[i] + f1[i - 1];
    f2[n + 1] = 0;
    for (int i = n; i >= 1; i--) f2[i] = (ll) a[i] + f2[i + 1];
    ll res = 0;
    for (int i = 1; i <= n; i++) 
        if (search(i)) res = max(res, f1[i]);
    printf("%lld", res);
    return 0;
}
