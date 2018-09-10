#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0);
#define all(v) (v).begin(), (v).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pi;
const int INF = (int) 1e9;
const ll LINT = (ll) 1e18;
const int nmax = 5e3 + 10;
int main() {
    IO; 
    string s;
    cin >> s;
    int n = s.length();
    s = "#" + s;
    int fa[nmax], fb[nmax];
    fa[0] = 0, fb[0] = 0;
    for (int i = 1; i <= n; i++) {
        fa[i] = fa[i - 1], fb[i] = fb[i - 1];
        if (s[i] == 'a') fa[i] += 1;
        if (s[i] == 'b') fb[i] += 1;
    }
    int res = 0;
    for (int i = 0; i <= n; i++)
    for (int j = i; j <= n; j++) {
        int v = fb[i];
        if (i + 1 <= j) v += fa[j] - fa[i];
        if (j + 1 <= n) v += fb[n] - fb[j];
        res = max(res, n - v);
    }
    cout << res;
    return 0;
}
