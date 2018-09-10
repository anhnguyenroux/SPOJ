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
const int nmax = 1010;
const int oo = 1e9;
int n;
ll w;
ll a[nmax];
bool check1(int v) {
    for (int i = 1; i <= n; i++) 
        if (v + a[i] < 0) return 0;
    return 1;
}
bool check2(int v) {
    for (int i = 1; i <= n; i++)
        if (v + a[i] > w) return 0;
    return 1;
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> w;
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    int lres = oo + 1, rres = -1;
    ll left = 0, right = w;
    while (left <= right) {
        ll mid = (left + right) >> 1;
        if (check1(mid)) {
            lres = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    left = 0, right = w;
    while (left <= right) {
        ll mid = (left + right) >> 1;
        if (check2(mid)) {
            rres = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }
    if (lres > rres) cout << 0;
    else
        cout << rres - lres + 1;
    return 0;
}
