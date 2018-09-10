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
int n, q, c;
int cnt[15][110][110];
int getsum(int s, int x1, int y1, int x2, int y2) {
    int res = cnt[s][x2][y2] - cnt[s][x1 - 1][y2] - cnt[s][x2][y1 - 1] + cnt[s][x1 - 1][y1 - 1];
    return res;
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> q >> c;
    for (int p = 0; p <= c; p++) 
    for (int i = 0; i <= 100; i++)
    for (int j = 0; j <= 100; j++) cnt[p][i][j] = 0;
    for (int i = 1; i <= n; i++) {
        int x, y, s;
        cin >> x >> y >> s;
        cnt[s][x][y]++;
    }
    for (int p = 0; p <= c; p++)
    for (int i = 0; i <= 100; i++)
    for (int j = 0; j <= 100; j++)
        cnt[p][i][j] += cnt[p][i - 1][j] + cnt[p][i][j - 1] - cnt[p][i - 1][j - 1];
    while (q-- > 0) {
        int t; 
        int x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        int res = 0;
        for (int s = 0; s <= c; s++) {
            res += ((s + t) % (c + 1)) * getsum(s, x1, y1, x2, y2);
        }
        cout << res << "\n"; 
    }
    return 0;
}
