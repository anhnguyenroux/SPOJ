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
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.inp", "r", stdin);
		//freopen("output.out", "w", stdout);
	#endif
    int n;
    cin >> n;
    int sum1 = 0, sum2 = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        sum1 += x;
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        sum2 += x;
    }
    if (sum2 <= sum1) cout << "Yes";
    else cout << "No";
    return 0;
}
