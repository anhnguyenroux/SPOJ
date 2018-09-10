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
int n;
int sx, sy;
int x[nmax], y[nmax];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    int res = 0;
    int dir = 0;
    for (int i = 2; i < n; i++) {
        int newdir;
        if (x[i] == x[i + 1]) {
            if (y[i] < y[i + 1]) newdir = 0;
            else 
                newdir = 2;
        }
        if (y[i] == y[i + 1]) {
            if (x[i] < x[i + 1]) newdir = 1;
            else 
                newdir = 3;
        }
        if (dir == (newdir + 1) % 4) res++;
        dir = newdir;
    }
    cout << res;
    return 0;
}
