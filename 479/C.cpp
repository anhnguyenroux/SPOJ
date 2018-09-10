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
int n, k;
int a[nmax];
int cnt(int v) {
    int left = 0, right = n - 1;
    int res = -1;
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (a[mid] <= v) {
            res = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }
    return res + 1;
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int left = 1, right = INF;
    while (left <= right) {
        int mid = (left + right) >> 1;
        int v = cnt(mid);
        if (v == k) {
            cout << mid;
            return 0;
        }
        if (v > k) right = mid - 1;
        else left = mid + 1;
    }
    cout << -1;
    return 0;
}
