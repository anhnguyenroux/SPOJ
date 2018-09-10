#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> ii;
const int NMAX      = 110;
const int MMAX      = 210;
int n, m;
int a[NMAX], b[NMAX];
vector <int> adj[NMAX];
int free[NMAX];
int cmp(ii a, ii b) {
    return a.first > b.first;
}
int main() {
    scanf("%d %d", &n, &m);
    int suma = 0, sumb = 0;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]), suma += a[i];
    for (int i = 0; i < n; i++) scanf("%d", &b[i]), sumb += b[i];
    if (suma != sumb) {
        printf("NO");
        return 0;
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    priority_queue <ii> q;
    for (int i = 0; i < n; i++) q.push(ii(a[i], i));
    for (int i = 0; i < n; i++) free[i] = 1;
    while (!q.empty()) {
        int u = q.top();
        free[u] = 0;
        q.pop();
        vector <ii> neig;
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (free[v])
                neig.push_back(ii(a[v], v));
        }
        sort(neig.begin(), neig.end(), cmp);
        for (int i = neig.begin(); i <= neig.end(); i++) {
            int dis = b[u] - a[u];
            if (dis == 0) break;
            if (a[v] > dis) {
                a[v] -= dis;
                a[u] += dis;
            }
        }
    }
    return 0;
}
