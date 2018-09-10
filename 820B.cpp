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
double a;
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n; 
    cin >> a;
    double mina = 180.0;
    int v3;
    for (int v = 3; v <= n; v++) {
        double ang = (double) 180 * (n - (v - 1)) / n;
        if (fabs(ang - a) < mina) {
            v3 = v;
            mina = fabs(ang - a);
        }
    }
    cout << 1 << " " << 2 << " " << v3;
    return 0;
}