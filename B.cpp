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
int n;
int a[nmax];
int f[nmax], r[nmax];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.inp", "r", stdin);
		freopen("output.out", "w", stdout);
	#endif
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
        
    for (int i = 1; i <= n; i++) {
        int left = i + 1, right = n;
        int res = -1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (a[mid] <= a[i] * 2) {
                res = mid;
                left = mid + 1;
            }
            else right = mid - 1;
        }
        if (res != -1) {
            cout << i << " " << i + 1 << " " << res << "\n";
            f[i + 1]++;
            f[res + 1]--;
        }
    } 
    r[0] = 0;
    for (int i = 1; i <= n; i++) r[i] = f[i] + r[i - 1];
    int res = 1;
    for (int i = 1; i <= n; i++) res = max(res, r[i]);
    cout << res;
    return 0;
}
