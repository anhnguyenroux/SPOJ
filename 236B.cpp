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
const int nmax = 1e6;
const ll modulo = 1073741824;
int a, b, c;
int d[nmax + 1];
void precal() {
    for (int i = 1; i <= nmax; i++) {
        d[i] = 1;
        int t = i;
        for (int j = 2; j * j <= t; j++)
            if (t % j == 0) {
                int cnt = 0;
                while (t % j == 0) cnt++, t /= j;
                d[i] *= (cnt + 1);
            }
        if (t > 1) d[i] *= 2;
    }
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> a >> b >> c;
    precal();
    ll sum = 0;
    for (int i = 1; i <= a; i++)
    for (int j = 1; j <= b; j++)
    for (int k = 1; k <= c; k++)
        sum = (sum + (d[i * j * k] % modulo)) % modulo;
    cout << sum;
    return 0;
}
