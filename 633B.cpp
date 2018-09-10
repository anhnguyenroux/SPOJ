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
const int nmax = 1e6;
int f[nmax + 10];
void precal() {
    int f2 = 0, f5 = 0;
    for (int i = 1; i <= nmax; i++) {
        int t = i;
        while (t % 2 == 0) t /= 2, f2++;
        while (t % 5 == 0) t /= 5, f5++;
        f[i] = min(f2, f5);
    }
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    precal();
    int k; cin >> k;
    vector <int> res;
    for (int i = 1; i <= nmax; i++)
        if (f[i] == k) res.push_back(i); 
        else 
            if (f[i] > k) break;
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " "; 
    return 0;
}
