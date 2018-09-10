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
const int nmax = 110;
int n, q;
int a[nmax];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> q;
    for (int i = 1; i <= n; i++) a[i] = 0;
    while (q-- > 0) {
        int t, k, d;
        cin >> t >> k >> d;
        for (int i = 1; i <= n; i++)
            if (a[i] < t) a[i] = 0;
        int cnt = 0;
        for (int i = 1; i <= n; i++) 
            if (a[i] == 0) cnt++;
        if (cnt < k) cout << -1 << "\n";
        else {
            cnt = 0;
            int sum = 0;
            for (int i = 1; i <= n; i++)
                if (a[i] == 0) {
                    cnt++;
                    sum += i;
                    a[i] = t + d - 1;
                    if (cnt == k) break;
                }
            cout << sum << "\n";
        }
    }
    return 0;
}
