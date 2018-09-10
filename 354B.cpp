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
int n;
int t;
int a[12][12];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++) a[i][j] = 0;
    for (int ti = 1; ti <= t; ti++) {
         int amount = 2048;
         a[1][1] += amount;
         for (int i = 1; i <= n; i++)
         for (int j = 1; j <= i; j++)
            if (a[i][j] > amount) {
                int sp = a[i][j] - amount;
                a[i][j] = amount;
                a[i + 1][j] += sp / 2;
                a[i + 1][j + 1] += sp / 2;
            }
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++)
        if (a[i][j] == 2048) res++;
    cout << res;
    return 0;
}
