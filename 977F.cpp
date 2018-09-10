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
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    map <int, int> f;
    int res = 0;
    int last = 0;
    for (int i = 1; i <= n; i++) {
        f[a[i]] = 1;
        f[a[i]] = f[a[i] - 1] + 1;
        if (f[a[i]] > res) {
            res = f[a[i]];
            last = a[i];
        }
    }
    printf("%d\n", res);
    vector <int> q;
    for (int i = n; i >= 1; i--)
        if (a[i] == last) {
            q.push_back(i);
            res--;
            last--;
            if (res == 0) break;
        }
    for (int i = q.size() - 1; i >= 0; i--)
        printf("%d ", q[i]);
    return 0;
}
