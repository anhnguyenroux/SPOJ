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
const int nmax = 1e7;
int n;
int a[nmax + 10];
bool prime[nmax + 10];
ll f[nmax + 10];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n;
    for (int i = 1; i <= nmax; i++)
        a[i] = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    for (int i = 1; i <= nmax; i++) prime[i] = 1;
    prime[1] = 0;
    for (int i = 2; i <= nmax; i++) 
    if (prime[i]) {
        f[i] += a[i];
        for (int j = 2; j * i <= nmax; j++) {
            prime[i * j] = 0;
            f[i] += a[i * j];
        }
    }
    for (int i = 1; i <= nmax; i++) f[i] += f[i - 1];
    int m;
    cin >> m;
    while (m-- > 0) {
        int l, r;
        cin >> l >> r;
        l = min(nmax, l);
        r = min(nmax, r);
        cout << f[r] - f[l - 1] << "\n";
    }
    return 0;
}
