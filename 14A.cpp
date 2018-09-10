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
    const int nmax = 55;
    int n, m;
    string s[nmax];
    int main() {
        IO;
        #ifndef ONLINE_JUDGE
            freopen("input.txt", "r", stdin);
            //freopen("output.txt", "w", stdout);
        #endif
        cin >> n >> m;
        for (int i = 0; i < n; i++) cin >> s[i];
        int i1 = 0, j1 = 0, i2 = n - 1, j2 = m - 1;
        while (true) {
            bool flag = 1;
            for (int j = 0; j < m; j++)
                if (s[i1][j] == '*') {
                    flag = 0;
                    break;
                }
            if (flag) i1++;
            else break;
        }
        while (true) {
            bool flag = 1;
            for (int j = 0; j < m; j++)
                if (s[i2][j] == '*') {
                    flag = 0;
                    break;
                }
            if (flag) i2--;
            else break;
        }
        while (true) {
            bool flag = 1;
            for (int i = 0; i < n; i++)
                if (s[i][j1] == '*') {
                    flag = 0;
                    break;
                }
            if (flag) j1++;
            else break;
        }
        while (true) {
            bool flag = 1;
            for (int i = 0; i < n; i++)
                if (s[i][j2] == '*') {
                    flag = 0;
                    break;
                }
            if (flag) j2--;
            else break;
        }
        for (int i = i1; i <= i2; i++) {
            for (int j = j1; j <= j2; j++)
                cout << s[i][j];
            cout << "\n";
        }
        return 0;
    }
