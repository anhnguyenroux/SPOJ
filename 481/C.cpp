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
int n, m;
ll a[nmax];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> m;
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    while (m-- > 0) {
        ll x;
        cin >> x;
        int pos = -1;
        int left = 1, right = n;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (a[mid] >= x) {
                pos = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }
        cout << pos << " " << x - a[pos - 1] << "\n";
    }
    return 0;
}
