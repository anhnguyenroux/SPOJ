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
const int modulo = 1e9 + 7;
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    ll a, b;
    cin >> a >> b;
    ll x = ((b - 1) * b / 2) % modulo;
    ll y = ((a + 1) * a / 2) % modulo;
    ll r1 = (y * b + a) % modulo;
    cout << (r1 * x) % modulo;
    return 0;
}
