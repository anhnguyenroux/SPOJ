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
const int nmax = 310;
int x, y;
int _x, _y;
int n;
int a, b, c;
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> x >> y;
    cin >> _x >> _y;
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b >> c;
        ll tmp1 =  (ll) a * x + (ll) b * y + c;
        ll tmp2 =  (ll) a * _x + (ll) b * _y + c;
        if ((tmp1 > 0 && tmp2 < 0) || (tmp1 < 0 && tmp2 > 0)) res++;
    }
    cout << res;
    return 0;
}
