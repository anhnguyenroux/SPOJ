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
const int nmax = 1e5 + 10;
string s;
int n;
int a[nmax];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> s;
    n = s.length();
    s = "?" + s;
    int last;
    for (int i = 1; i <= n; i++) 
        if (s[i] == '#') last = i;
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '#' || s[i] == ')') a[i] = a[i - 1] - 1;
        else 
            a[i] = a[i - 1] + 1;
    }
    for (int i = 1; i <= n; i++)
        if (a[i] < 0) {
            cout << -1;
            return 0;
        }
    a[last] -= a[n];
    for (int i = last + 1; i <= n; i++) 
        if (s[i] == '(') a[i] = a[i - 1] + 1;
            else a[i] = a[i - 1] - 1;
    for (int i = 1; i <= n; i++) 
        if (a[i] < 0) {
            cout << -1;
            return 0;
        }
    if (a[n] != 0) cout << -1;
    else {
        for (int i = 1; i <= n; i++)
        if (s[i] == '#') {
            cout << -(a[i] - a[i - 1]) << "\n";
        }
    }
    return 0;
}
