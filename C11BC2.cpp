#include <stdio.h>
const int MAX = 1e4 + 100;
int N, M;
int Lab[MAX];
int getRoot(int u) {
    while (Lab[u] > 0) u = Lab[u];
    return u;
}
void Union(int u, int v) {
    int r1 = getRoot(u);
    int r2 = getRoot(v);
    if (r1 == r2) return;
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
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
        Lab[i] = -1;
    for (int i = 2; i <= N; i++) {
        int v, k;
        scanf("%d %d", &v, &k);
        if (k == 1) Union(i, v);
    }
    for (int i = 1; i <= M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (getRoot(u) == getRoot(v)) printf("NO\n");
        else printf("YES\n");
    }
}
int main() {
    Process();
    return 0;
}