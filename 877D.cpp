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
const int nmax = 1010;
int n, m, k;
string a[nmax];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = "#" + a[i];
    }
    cin >> x1 >> y1 >> x2 >> y2;
    
    return 0;
}
