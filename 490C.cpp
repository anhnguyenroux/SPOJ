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
const int nmax = 1e6 + 10;
int a, b;
vector <int> d;
int f1[nmax], f2[nmax];
int POW[nmax];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    string s;
    cin >> s;
    cin >> a >> b;
    for (int i = 0; i < s.length(); i++)
        d.push_back(s[i] - '0');
    int n = d.size();
    f1[0] = 0;
    for (int i = 1; i <= n; i++)
        f1[i] = ((f1[i - 1] * (10 % a)) % a + d[i - 1] % a) % a;
    POW[0] = 1;
    for (int i = 1; i <= n; i++) POW[i] = (POW[i - 1] * 10) % b;
    f2[n] = d[n - 1] % b;
    for (int i = n - 1; i >= 1; i--) 
        f2[i] = (f2[i + 1] + ((d[i - 1] % b) * POW[n - i] % b) % b) % b;
    int pos = -1;
    for (int i = 1; i < n; i++) 
        if (d[i] != 0 && f1[i] == 0 && f2[i + 1] == 0) {
            pos = i;
            break;
        }
    if (pos == -1) cout << "NO";
    else {
        cout << "YES" << "\n";
        for (int i = 1; i <= pos; i++) cout << d[i - 1];
        cout << "\n";
        for (int i = pos + 1; i <= n; i++) cout << d[i - 1];
    }
    return 0;
}
