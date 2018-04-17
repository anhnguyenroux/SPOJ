#include <stdio.h>
#include <vector>
using namespace std;
const int NMAX = 1e4 + 100;
int N;
int k;
vector <int> adj[NMAX];
int avail[NMAX];
int f[NMAX];
int capture[NMAX];
void inpProcess() {
    scanf("%d", &k);
    scanf("%d", &N);
    int u;
    for (int i = 2; i <= N; i++) {
        scanf("%d", &u);
        adj[i].push_back(u);
        adj[u].push_back(i);
    }
}
void dfs(int u) {
    f[u] = 1;
    avail[u] = 0;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (avail[v]) {
            dfs(v);
            f[u] += f[v];
        }
    }
    if (f[u] >= k) {
        capture[u] = true;
        f[u] = 0;
    }
}
void Process() {
    for (int i = 1; i <= N; i++) {
        capture[i] = false;
        avail[i] = 1;
    }
    dfs(1);
    int res = 0;
    for (int i = 1; i <= N; i++)
        if (capture[i]) res++;
    printf("%d", res);
}
int main() {
    inpProcess();
    Process();
    return 0;
}
