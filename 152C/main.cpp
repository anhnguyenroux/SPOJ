#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int nmax = 110;
const int modulo = 1e9 + 7;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m;
    string s[nmax];
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> s[i];
    ll res = 0;
    for (int j = 0; j < m; j++) {
        int a[26] = {};
        for (int i = 1; i <= n; i++)
            a[s[i][j] - 'A']++;
        int cnt = 0;
        for (int i = 0; i < 26; i++)
            if (a[i]) cnt++;
        if (!res) res = cnt % modulo;
        else res = (res * (cnt % modulo)) % modulo;
    }
    cout << res;
    return 0;
}
