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
const int nmax = 120010;
int n;
vector <ll> a;
int search(int l, int r, int u) {
    if (l > r) return false;
    int left = l, right = r;
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (a[mid] == u) return true;
        if (u > a[mid]) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    int res = 0;
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (ll j = 0; j < 32; j++) {
            ll sum = 1ll << j;
            if (search(0, i - 1, sum - a[i]) || search(i + 1, n - 1, sum - a[i])) {
                found = 1;
                break;
            }
        }
        if (!found) res++;
    }
    cout << res;
    return 0;
}