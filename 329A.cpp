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
int n;
string s[nmax];
int row[nmax], col[nmax];
int p[nmax][nmax];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.inp", "r", stdin);
		freopen("output.out", "w", stdout);
	#endif
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = "#" + s[i];
    }
    bool row = 0, col = 0;
    for (int i = 1; i <= n; i++) {
        int flag = 1;
        for (int j = 1; j <= n; j++)
            if (s[i][j] == '.') {
                flag = 0;
                break;
            }
        if (flag) {
            row = 1;
            break;
        }
    }
    for (int j = 1; j <= n; j++) {
        int flag = 1;
        for (int i = 1; i <= n; i++) 
            if (s[i][j] == '.') {
                flag = 0;
                break;
            }
        if (flag) {
            col = 1;
            break;
        }
    }
    if (row && col) {
        cout << -1;
        return 0;
    }
    if (row) {
        for (int j = 1; j <= n; j++)
            for (int i = 1; i <= n; i++)
                if (s[i][j] == '.') {
                    cout << i << " " << j << "\n";
                    break;
                }
    }
    else {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (s[i][j] == '.') {
                    cout << i << " " << j << "\n";
                    break;
                }
    }
    return 0;
}
