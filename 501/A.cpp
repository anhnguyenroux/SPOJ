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
int a[150];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) 
        a[i] = 0;
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        for (int j = l; j <= r; j++)
            a[j]++;
    }
    vector <int> res;
    for (int i = 1; i <= m; i++) 
        if (a[i] == 0) res.push_back(i);
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    return 0;
}
