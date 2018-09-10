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
const int nmax = 1005;
int n;
int a[nmax];
vector <int> res;
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) 
        if (a[i] == 1) {
            int cnt = 1;
            while (a[i + cnt] != 1 && i + cnt < n) cnt++;
            res.push_back(cnt);
        }
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    return 0;
}
