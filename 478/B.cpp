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
ll a[15];
ll b[15];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    for (int i = 1; i <= 14; i++) cin >> a[i];
    ll res = 0;
    for (int i = 1; i <= 14; i++)
    if (a[i] > 0) {
        ll st = a[i];
        for (int j = 1; j <= 14; j++)
            b[j] = a[j];
        b[i] = 0;
        if (st <= 14 - i) {
            for (int k = i + 1; k <= i + st; k++) 
                b[k]++;
        }
        else {
            st -= 14 - i;
            for (int k = i + 1; k <= 14; k++)
                b[k]++;
            int x = st / 14;
            int y = st % 14;
            for (int k = 1; k <= 14; k++)
                b[k] += x;
            for (int k = 1; k <= y; k++)
                b[k]++;
        }
        ll cnt = 0;
        for (int j = 1; j <= 14; j++)
            if (b[j] % 2 == 0) cnt += b[j];
        res = max(res, cnt);
    }
    cout << res;
    return 0;
}
