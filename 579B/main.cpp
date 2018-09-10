#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;
const int NMAX      =   410;
int n;
int a[2 * NMAX][2 * NMAX];
int res[2 * NMAX];
int main() {
    priority_queue <iii> q;
    scanf("%d", &n);
    for (int i = 2; i <= 2 * n; i++) {
        for (int j = 1; j < i; j++)
            scanf("%d", &a[i][j]), q.push(iii(a[i][j], ii(i, j)));
    }
    for (int i = 1; i <= 2 * n; i++) res[i] = 0;
    while (!q.empty()) {
        ii cur = q.top().second;
        q.pop();
        int u = cur.first, v = cur.second;
        if (!res[u] && !res[v]) res[u] = v, res[v] = u;
    }
    for (int i = 1; i <= 2 * n; i++) printf("%d ", res[i]);
    return 0;
}
