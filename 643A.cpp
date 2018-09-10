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
const int nmax = 5010;
int n;
int a[nmax];
int res[nmax];
int cnt[nmax];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.inp", "r", stdin);
		//freopen("output.out", "w", stdout);
	#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) res[i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cnt[j] = 0;
        int cur = 0;
        int d = 0;
        for (int j = i; j <= n; j++) {
            cnt[a[j]]++;
            if (cnt[a[j]] > d || (cnt[a[j]] == d && a[j] < cur)) {
                cur = a[j];
                d = cnt[a[j]];
            }
            res[cur]++;
        }
    }
    for (int i = 1; i <= n; i++) printf("%d ", res[i]);
    return 0;
}
