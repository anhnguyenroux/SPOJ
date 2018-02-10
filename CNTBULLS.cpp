#include <stdio.h>
const int modulo    =   2111992;
const int NMAX      =   1e5 + 10;
int N, k;
int f[NMAX];
void readInp() {
    scanf("%d %d", &N, &k);
}
void process() {
    for (int i = 1; i <= k + 1; i++)
        f[i] = (i + 1) % modulo;
    for (int i = k + 2; i <= N; i++)
        f[i] = (f[i - 1] + f[i - k - 1]) % modulo;
    printf("%d", f[N]);
}
int main() {
    readInp();
    process();
    return 0;
}