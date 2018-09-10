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
ll n, m, k;
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> m >> k;
    if (k < n) {
        cout << k + 1 << " " << 1;
        return 0;
    }
    ll x = (k - n) / (m - 1);
    ll y = (k - n) % (m - 1);
    if (x % 2 == 0) cout << n - x << " " << 2 + y;
    else 
        cout << n - x << " " << m - y;
    return 0;
}
