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
int n, m;
int a[nmax];
int l[nmax], r[nmax];
int fre[nmax];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
    int sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> l[i] >> r[i];
        if (l[i] <= sum && sum <= r[i]) {
            cout << sum;
            return 0;
        }
    }
    for (int i = 0; i < m; i++) 
        if (l[i] >= sum) {
            cout << l[i];
            return 0;
        }
    cout << -1;
    return 0;
}
