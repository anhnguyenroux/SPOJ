/*
    MPILOT : http://vn.spoj.com/problems/MPILOT/
    Explanation and Complexity are below
*/
#include <stdio.h>
#include <algorithm>
using namespace std;
const int NMAX      =   10010;
const int oo        =   1e9;
int N;
int x[NMAX], y[NMAX];
int f[NMAX][NMAX];
void readInp() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d %d", &x[i], &y[i]);
}
void process() {
    f[1][0] = 0;
    f[1][1] = y[1];
    for (int i = 2; i <= N; i++) {
        f[i][0] = f[i - 1][1] + x[i];
        f[i][i] = f[i - 1][i - 1] + y[i];
        for (int j = 1; j < i; j++)
            f[i][j] = min(f[i - 1][j + 1] + x[i], f[i - 1][j - 1] + y[i]);
    }
    printf("%d", f[N][0]);
}
int main() {
    readInp();
    process();
    return 0;
}
/*
    Because ages are sort by ascending order, so we can DP with an array F[i - 1] and then we can calculate F[i]
    DP : A 2D - array F[i][j] : the money we pay when we have i people and j vice-pilots. 
    when j = 0, which mean we have sorted i to i/2 pairs then f[i][0] = f[i - 1][1] + x[i]. 
    when i == j, which mean we have i - 1 vice-pilots already, we add 1 more then f[i][i] = f[i - 1][i - 1] + y[i]
    for every j that 1 < j < i 
        f[i][j] = f[i - 1][j + 1] + x[i] which means we pay money for one more pilot, that we need 1 more vice-pilots 
                                            in previous steps.
                = f[i - 1][j - 1] + y[i] which means we pay money for one more vice-pilot.
    The answer is f[N][0]
    Complexity : O(N^2)
*/