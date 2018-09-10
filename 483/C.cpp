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
const int nmax = 1e5 + 10;
ll p[nmax], q[nmax], b[nmax];
set <ll> base[nmax];
ll gcd(ll a, ll b) {
    while (b != 0) {
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    int n;
    scanf("%d", &n);
    ll p, q, b;
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld %lld", &p, &q, &b);
        ll g = gcd(p, q);
        q /= g;
        b = gcd(q, b);
        cout << q << " " << b << "\n";
        while (b != 1) {
            while (q % b == 0) q/= b;
            b = gcd(b, q);
            cout << q << " " << b << "\n";
        }
        if (q == 1) printf("Finite\n");
        else printf("Infinite\n");
    } 
    return 0;
}
