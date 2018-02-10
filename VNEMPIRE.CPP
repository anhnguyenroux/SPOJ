#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
struct coordinate {
    int loc, pre;
};
struct Edge { 
    int u, v;
    int w;
};
const int NMAX = 1e5 + 100;
const int MMAX = 3 * NMAX;
int N;
int M = 0;
coordinate x[NMAX], y[NMAX], z[NMAX];
Edge E[MMAX];
int Lab[NMAX];
void inpProcess() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d %d %d", &x[i].loc, &y[i].loc, &z[i].loc);
        x[i].pre = i;
        y[i].pre = i;
        z[i].pre = i;
    }
}
void addEdge(int u, int v, int w) {
    M++;
    E[M].u = u; 
    E[M].v = v;
    E[M].w = w;
}
int cmpCo (coordinate a, coordinate b) {
    return (a.loc < b.loc);
}
int cmpEdge(Edge a, Edge b) {
    return (a.w < b.w);
}
int getRoot(int u) {
    while (Lab[u] > 0) u = Lab[u];
    return u;
}
void Union(int r1, int r2) {
    int tmp = Lab[r1] + Lab[r2];
    if (Lab[r1] > Lab[r2]) {
        Lab[r1] = r2;
        Lab[r2] = tmp;
    }
    else {
        Lab[r2] = r1;
        Lab[r1] = tmp;
    }
}
void Process() {
    sort(x + 1, x + 1 + N, cmpCo);
    sort(y + 1, y + 1 + N, cmpCo);
    sort(z + 1, z + 1 + N, cmpCo);
    for (int i = 1; i <= N - 1; i++) {
        addEdge(x[i].pre, x[i + 1].pre, abs(x[i].loc - x[i + 1].loc));
        addEdge(y[i].pre, y[i + 1].pre, abs(y[i].loc - y[i + 1].loc));
        addEdge(z[i].pre, z[i + 1].pre, abs(z[i].loc - z[i + 1].loc));
    }
    sort(E + 1, E + 1 + M, cmpEdge);
    for (int i = 1; i <= N; i++) Lab[i] = -1;
    int cost = 0;
    int cnt = 0;
    for (int i = 1; i <= M; i++) {
        if (cnt == N - 1) break;
        int r1 = getRoot(E[i].u);
        int r2 = getRoot(E[i].v);
        if (r1 != r2) {
            cost += E[i].w;
            cnt++;
            Union(r1, r2);
        }
    }
    printf("%d", cost);
}
int main() {
    inpProcess();
    Process();
    return 0;
}