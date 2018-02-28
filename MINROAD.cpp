#include <stdio.h>
#include <algorithm>
using namespace std;
const int NMAX      =   300010;
const int oo        =   1e9 + 100;
struct Tree {
    int d;
    int tp;
};
int N, a, b;
Tree T[NMAX];
int f1[NMAX], f2[NMAX];
void readInp() {
    scanf("%d %d %d", &N, &a, &b);
    for (int i = 1; i <= N; i++) 
        scanf("%d %d", &T[i].d, &T[i].tp);
}
int cmp(Tree x, Tree y) {
    return x.d < y.d;
}
void process() {
    sort(T + 1, T + 1 + N, cmp);
    f1[0] = 0;
    f2[0] = 0;
    for (int i = 1; i <= N; i++) {
        f1[i] = f1[i - 1] + (T[i].tp == 1 ? 1 : 0);
        f2[i] = f2[i - 1] + (T[i].tp == 2 ? 1 : 0);
    }
    int first = 0;
    int ans = oo;
    for (int i = a + b; i <= N; i++) 
        for (int j = first + 1; j <= i - (a + b) + 1; j++) {
            if (f1[i] - f1[j - 1] >= a && f2[i] - f2[j - 1] >= b) {
                ans = min(ans, T[i].d - T[j].d);
                first = j;
            }
            else break;
        }
    if (ans == oo) ans = -1;
    printf("%d", ans);
}
int main() {
    readInp();
    process();
    return 0;
}