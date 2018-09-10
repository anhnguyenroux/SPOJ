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
const int nmax = 35;
const int kmax = 35;
int n, k;
int a[nmax];
vector <int> res[nmax];
int fre[nmax * kmax];
stack <int> c;
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> k;
    for (int i = 1; i <= n * k; i++)    
        fre[i] = 1;
    for (int i = 1; i <= k; i++) cin >> a[i];
    for (int i = 1; i <= k; i++) {
        res[i].push_back(a[i]);
        fre[a[i]] = 0;
    }
    for (int i = 1; i <= n * k; i++) 
        if (fre[i]) c.push(i);
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j < n; j++) {
            res[i].push_back(c.top());
            c.pop();
        }
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
