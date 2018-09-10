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
int a[35];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    int m, n;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        printf("1\n");
        fflush(stdout);
        int ans;
        scanf("%d", &ans);
        if (ans == 0) exit(0);
        if (ans == 1) a[i] = 1; else a[i] = 0;
    }
    int lo = 1, hi = m;
    for (int t = n; t < 60; t++) {
        int mid = (lo + hi) >> 1;
        printf("%d\n", mid);
        fflush(stdout);
        int ans;
        scanf("%d", &ans);
        if (ans == 0) exit(0);
        if (a[t % n] == 0) ans *= -1;
        if (ans == -1) hi = mid - 1;
            else 
                lo = mid + 1;
    }
    return 0;
}
