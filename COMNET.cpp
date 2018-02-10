#include <stdio.h>
const int NMAX = 1e5 + 100;
const int MMAX = 1e6 + 100;
int N, M, Q;
int a[MMAX], b[MMAX], c[MMAX], cPrime[MMAX];
int Lab[NMAX];
int getRoot(int u) {
    while (Lab[u] > 0) u = Lab[u];
    return u;
}
void Union(int u, int v) {
    int r1 = getRoot(u);
    int r2 = getRoot(v);
    if (r1 != r2) {
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
}
void Process() {
    scanf("%d %d %d", &N, &M, &Q);
    for (int i = 1; i <= M; i++) 
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
    while (Q > 0) {
        for (int i = 1; i <= M; i++) 
            cPrime[i] = c[i];
        for (int i = 1; i <= N; i++)
            Lab[i] = -1;
        int k, s;
        scanf("%d %d", &k, &s);
        for (int i = 1; i <= s; i++) {
            int tp, cp;
            scanf("%d %d", &tp, &cp);
            cPrime[tp] = cp;
        }
        for (int i = 1; i <= M; i++) 
            if (cPrime[i] < cPrime[k]) Union(a[i], b[i]);
        int r1 = getRoot(a[k]);
        int r2 = getRoot(b[k]);
        if (r1 == r2) printf("YES"); else printf("NO");
        printf("\n");
        Q--;
    }
}
int main() {
    int Test;
    scanf("%d", &Test);
    while (Test > 0) {
        Process();
        Test--;
    }
    return 0;
}