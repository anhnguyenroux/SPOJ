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
int a[55];
int f[1010];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    int n;
    cin >> n;
    queue <int> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= 1010; i++) f[i] = 1;
    for (int i = n; i >= 1; i--) {
        if (f[a[i]]) {
            q.push(a[i]);
            f[a[i]] = 0;
        }
    }
    vector <int> res;
    while (!q.empty()) {
        res.push_back(q.front());
        q.pop();
    }
    cout << res.size() << "\n";
    for (int i = res.size() - 1; i >= 0; i--)
        cout << res[i] << " ";
    return 0;
}
