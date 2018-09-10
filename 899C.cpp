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
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    int n;
    cin >> n;
    ll s = (ll) n * (n + 1) / 2;
    ll p1 = s / 2;
    cout << abs((s - p1) - p1) << "\n";
    vector <int> res;
    int i = n;
    while (p1 > 0) {
        if (p1 >= i) {
            res.push_back(i);
            p1 -= i;
            i--;
        }
        else {
            res.push_back(p1);
            break;
        }
    }
    cout << res.size() << " ";
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    return 0;
}
