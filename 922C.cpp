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
ll n, k;
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> k;
    if (k > 1000) {
        cout << "No";
        return 0;
    }
    int d[1001];
    for (int i = 0; i < k; i++) d[i] = 0;
    for (int i = 1; i <= k; i++) {
        int r = n % i;
        if (d[r]) {
            cout << "No";
            return 0;
        }
        d[r] = 1;
    }
    cout << "Yes";
    return 0;
}
