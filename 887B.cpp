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
int a[4][7];
int f[1000];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 6; j++) 
            cin >> a[i][j];
    for (int i = 0; i <= 999; i++)  
        f[i] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 6; j++)
            f[a[i][j]] = 1;
    if (n == 2) {
        for (int i = 1; i <= 6; i++)
        for (int j = 1; j <= 6; j++) {
            int u = a[1][i];
            int v = a[2][j];
            if (u != 0) f[u * 10 + v] = 1;
            if (v != 0) f[v * 10 + u] = 1;
        }
    }
    if (n == 3) {
        for (int i1 = 1; i1 <= n; i1++)
        for (int i2 = 1; i2 <= n; i2++)
            if (i1 != i2) {
                for (int j1 = 1; j1 <= 6; j1++)
                for (int j2 = 1; j2 <= 6; j2++) {
                    int u = a[i1][j1];
                    int v = a[i2][j2];
                    if (u != 0) f[u * 10 + v] = 1;
                }
            }
        for (int i1 = 1; i1 <= n; i1++)
        for (int i2 = 1; i2 <= n; i2++)
        for (int i3 = 1; i3 <= n; i3++)
            if (i1 != i2 && i1 != i3 && i2 != i3) {
                for (int j1 = 1; j1 <= 6; j1++)
                for (int j2 = 1; j2 <= 6; j2++)
                for (int j3 = 1; j3 <= 6; j3++) {
                    int u = a[i1][j1];
                    int v = a[i2][j2];
                    int t = a[i3][j3];
                    if (u != 0) f[u * 100 + v * 10 + t] = 1;
                }
            }
    }
    int res = -1;
    for (int i = 1; i <= 999; i++) 
        if (!f[i]) {
            res = i - 1;
            break;
        }
    cout << res;
    return 0;
}
