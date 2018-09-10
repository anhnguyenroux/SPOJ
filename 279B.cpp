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
int t; 
int n;
int a[nmax];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> t;
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int left = i, right = n;
        int x = -1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (a[mid] - a[i - 1] <= t) {
                x = mid;
                left = mid + 1;
            }
            else right = mid - 1;
        }
        if (x != -1)
            res = max(res, x - i + 1); 
    }
    cout << res;
    return 0;
}
