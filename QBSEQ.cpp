#include <stdio.h>
#include <algorithm>
using namespace std;
const int NMAX      =   1010;
const int KMAX      =   55;
int N, k;
int a[NMAX];
int f[NMAX][KMAX];
void readInp() {
    scanf("%d %d", &N, &k);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &a[i]);
        a[i] %= k;
    }
}
void process() {
    for (int m = 0; m < k; m++)
        f[0][m] = -NMAX;
    f[0][0] = 0;
    for (int i = 1; i <= N; i++)
        for (int m = 0; m < k; m++)
            f[i][m] = max(f[i - 1][m], f[i - 1][(m - a[i] + k) % k] + 1);
    printf("%d", f[N][0]);
}
int main() {
    readInp();
    process();
    return 0;
}