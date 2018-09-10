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
const int tmax = 1e5 + 10;
int dx[tmax], dy[tmax];
int t, sx, sy, ex, ey;
string s;
ll cal(int x1, int y1, int x2, int y2) {
    ll res = (ll) (x1 - x2) * (x1 - x2) + (ll) (y1 - y2) * (y1 - y2);
    return res;
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> t >> sx >> sy >> ex >> ey;
    cin >> s;
    int curx = sx, cury = sy;
    for (int i = 1; i <= t; i++) {
        int dx, dy;
        if (s[i - 1] == 'N') dx = 0, dy = 1;
        if (s[i - 1] == 'S') dx = 0, dy = -1;
        if (s[i - 1] == 'E') dx = 1, dy = 0;
        if (s[i - 1] == 'W') dx = -1, dy = 0;
        if (cal(curx + dx, cury + dy, ex, ey) < cal(curx, cury, ex, ey)) {
            curx += dx;
            cury += dy;
            if (curx == ex && cury == ey) {
                cout << i;
                return 0;
            }
        }
    }    
    cout << -1;
    return 0;
}
