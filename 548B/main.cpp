#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int a[510][510];
int g[510];
int main() {
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; i++) {
        g[i] = 0;
        for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
        int cnt = 0;
        for (int j = 1; j <= m; j++) {
            if (a[i][j]) cnt++;
            else cnt = 0;
            if (cnt > g[i]) g[i] = cnt;
        }
    }
    while (q-- > 0) {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u][v] = !a[u][v];
        int maxC = 0, cnt = 0;
        for (int j = 1; j <= m; j++) {
            if (a[u][j]) cnt++;
            else cnt = 0;
            if (cnt > maxC) maxC = cnt;
        }
        g[u] = maxC;
        int res = 0;
        for (int i = 1; i <= n; i++)
            res = max(res, g[i]);
        printf("%d\n", res);
    }
    return 0;
}
