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
const int nmax = 1e3 + 10;
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
    int res = 0;
    for (int i = 1; i <= n; i++) 
    if (a[i] != 0) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (i != j && a[i] == a[j]) cnt++;
            if (cnt >= 2) break;
        }
        if (cnt >= 2) {
            cout << -1;
            return 0;
        }
        if (cnt == 1) res++;
    }
    cout << res / 2;
    return 0;
}
