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
const int nmax = 35;
int n;
int L;
ll c[nmax];
int getbit(int x, int i) {
    return (x >> i) & 1;
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> L;
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 1; i < n; i++)
		c[i] = min(c[i], 2 * c[i - 1]);
    ll ans = LINF;
    ll sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        ll need = L / (1 << i);
        sum += need * c[i];
        L %= 1 << i;
        ans = min(ans, sum + (L > 0) * c[i]);
    }
    cout << ans;
    return 0;
}
