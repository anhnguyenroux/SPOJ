#include <bits/stdc++.h>
using namespace std;
const int nmax = 110;
string s[nmax];
int n, k;
int f[nmax][nmax];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = "+" + s[i];
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) f[i][j] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
        if (s[i][j] == '.') {
            int cnt = 0;
            for (int x = j; x <= min(j + k - 1, n); x++)
                if (s[i][x] == '.') cnt++;
                else break;
            if (cnt == k)
                for (int x = j; x <= j + k - 1; x++) f[i][x]++;
        }
    }
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++)
        if (s[i][j] == '.') {
            int cnt = 0;
            for (int x = i; x <= min(i + k - 1, n); x++)
                if (s[x][j] == '.') cnt++;
                else break;
            if (cnt == k)
                for (int x = i; x <= i + k - 1; x++) f[x][j]++;
        }
    }
    int res = 0;
    int u = 1, v = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        if (f[i][j] > res) {
            res = f[i][j];
            u = i;
            v = j;
        }
    cout << u << " " << v;
    return 0;
}
