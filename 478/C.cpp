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
const int nmax = 2e5 + 10;
int n, q;
ll a[nmax];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> q;
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    int flag = 0;
    ll arr = 0;
    while (q-- > 0) {
        ll x;
        cin >> x;
        if (flag == 0) arr += x;
        else {
            arr = x;
            flag = 0;
        }
        int left = 1, right = n;
        int j = 0;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (arr >= a[mid]) {
                j = mid;
                left = mid + 1;
            }
            else right = mid - 1;
        }
        if (j == n) {
            cout << n << "\n";
            flag = 1;
        }
        else 
            cout << n - j << "\n";
    }
    return 0;
}
