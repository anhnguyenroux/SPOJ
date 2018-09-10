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
const int nmax = 2010;
int n, m;
int a[nmax];
vector <int> d[nmax];
vector <int> can;
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] <= m) d[a[i]].push_back(i);
        else can.push_back(i);
    }
    for (int i = 1; i <= m; i++)
        if (d[i].size() > (n / m)) {
            int sz = d[i].size();
            for (int j = 1; j <= sz - (n / m); j++) {
                int u = d[i].back();
                can.push_back(u);
                d[i].pop_back();
            }
        }
    int cnt = 0;
    for (int i = 1; i <= m; i++) 
        if (d[i].size() < (n / m)) {
            int sz = d[i].size();
            for (int j = 1; j <= (n / m) - sz; j++) {
                cnt++;
                int u = can.back();
                d[i].push_back(u);
                can.pop_back();
            }
        }
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < d[i].size(); j++) 
            a[d[i][j]] = i;
    cout << (n / m) << " " << cnt << "\n";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}
