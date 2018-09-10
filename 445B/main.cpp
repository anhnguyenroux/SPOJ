#include <bits/stdc++.h>
using namespace std;
const int NMAX = 55;
int n, m;
int a[NMAX][NMAX];
int fre[NMAX];
void dfs(int u) {
    fre[u] = 0;
    for (int v = 1; v <= n; v++)
        if (a[u][v] && fre[v]) dfs(v);
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) a[i][j] = 0;
    for (int i = 1; i <= n; i++) fre[i] = 1;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }
    int v = 0;
    for (int i = 1; i <= n; i++)
        if (fre[i]) {
            dfs(i);
            v++;
        }
    long long res = 1;
    for (int i = 1; i <= n - v; i++) res *= 2;
    cout << res;
    return 0;
}
