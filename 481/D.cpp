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
int n;
int a[nmax];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int res = -1;
    for (int x = -1; x <= 1; x++)
    for (int y = -1; y <= 1; y++) {
        bool flag = 1;
        int d = (a[2] + y) - (a[1] + x);
        int pre = a[2] + y;
        int cnt = 0;
        for (int i = 3; i <= n; i++) {
            int d1 = (a[i] - pre);
            if (abs(d1 - d) > 1) {
                flag = 0;
                break;
            }
            if (d1 == d + 1) {
                cnt++;
                pre = a[i] - 1;
            }
            if (d1 == d - 1) {
                cnt++;
                pre = a[i] + 1;
            }
            if (d1 == d) pre = a[i];
        }
        if (flag) {
            if (x != 0) cnt++;
            if (y != 0) cnt++;
            if (res == -1) res = cnt;
            else res = min(res, cnt);
        }
    }
    cout << res;
    return 0;
}
