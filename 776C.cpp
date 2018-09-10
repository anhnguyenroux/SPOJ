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
const ll smax = 1e14;
int n, k;
ll a[nmax];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> k;
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    if (k == 1) {
        ll res = 0;
        map <ll, ll> f;
        for (int i = n; i >= 1; i--) {
            f[a[i]]++; 
            if (f.find(a[i - 1] + 1) != f.end())
                res += f[a[i - 1] + 1];
        }
        cout << res;
        return 0;
    }
    if (k == -1) {
        ll res = 0;
        map <ll, ll> f;
        for (int i = n; i >= 1; i--) {
            f[a[i]]++;
            if (f.find(a[i - 1] + 1) != f.end()) 
                res += f[a[i - 1] + 1];
            if (f.find(a[i - 1] - 1) != f.end()) 
                res += f[a[i - 1] - 1];
        }
        cout << res;
        return 0;
    }
    ll res = 0;
    map <ll, ll> f;
    for (int i = n; i >= 1; i--) {
        f[a[i]]++;
        ll cur = 1;
        while (cur <= smax) {
            if (f.find(cur + a[i - 1]) != f.end()) 
                res += f[cur + a[i - 1]];
            if (cur * k > smax) break;
            else cur *= k;
        }
    }
    cout << res;
    return 0;
}
