/*
    DISNEY1 : vn.spoj.com/problems/DISNEY1
    Explanation and Complexity are below
*/
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int NMAX      =   210;
const int oo        =   1e9;
int N;
int a[NMAX][NMAX];
int f[NMAX][NMAX];
void readInp() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            scanf("%d", &a[i][j]);
}
void process() {
    for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
        f[i][j] = oo;
    f[1][1] = 0;
    int res = oo;
    for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
        if (f[i][j] < oo) {
            int next = max(i, j) + 1;
            if (next == N + 1) res = min(res, f[i][j] + a[i][1] + a[j][1]);
            else {
                f[i][next] = min(f[i][next], f[i][j] + a[j][next]);
                f[next][j] = min(f[next][j], f[i][j] + a[i][next]);
                f[next][next] = min(f[next][next], f[i][j] + a[i][next] + a[j][next]);
            }
        }
    printf("%d", res);
}
int main() {
    readInp();
    process();
    return 0;
}
/*
    F[i][j] : the time for 1 person go to i and 1 person go to j
    next : the next postion that i and j can go to. next = max(i, j) + 1
    f[i][next] = min(f[i][next], f[i][j] + a[j][next]);
    f[next][j] = min(f[next][j], f[i][j] + a[i][next]);
    f[next][next] = min(f[next][next], f[i][j] + a[i][next] + a[j][next]);
    result : min (f[i][j] (i == N || j == N) + a[i][0] + a[j][0]) (1 <= i <= j <= N)
    Complexity : O(N^2)
*/