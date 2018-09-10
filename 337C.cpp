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
const int modulo = 1e9 + 9;
ll get(int e) {
    if (e == 0) return 1;
    if (e == 1) return 2;
    ll res = get(e / 2);
    if (e % 2 == 0) return (res * res) % modulo;
    else 
        return (2 * res * res) % modulo;
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.inp", "r", stdin);
		//freopen("output.out", "w", stdout);
	#endif
    ll n, m, k;
    cin >> n >> m >> k;
    ll p;
    ll w = n - m;
    ll a = min(m / (k - 1), w);
    p = (a * (k - 1)) % modulo;
    m -= a * (k - 1);
    if (m > 0) {
        int f = m / k;
        int l = m % k;
        p = (p + ((((get(f) - 1 + modulo) % modulo)* 2 * (k % modulo)) % modulo)) % modulo;
        p = (p + (l % modulo)) % modulo; 
    }
    cout << p;
    return 0;
}
