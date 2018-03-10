/*
    C11KM : http://vn.spoj.com/problems/C11KM/
    Explanation is below 
*/
#include <stdio.h>
#include <algorithm>
using namespace std;
const int NMAX  =   1e3 + 100;
const int oo    =   NMAX * 300;
int N;
int a[NMAX];
int f[NMAX];
int d[NMAX][NMAX];
void readInp() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &a[i]);
}
void process() {
    f[0] = 0;
    for (int i = 1; i <= N; i++) {
        f[i] = f[i - 1];
        if (a[i] > 100) f[i]++;
    } 
    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= f[N]; j++)
            d[i][j] = oo;
    d[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= f[i]; j++) {
            if (j <= f[i - 1]) d[i][j] = min(d[i][j], d[i - 1][j] + a[i]);
            if (a[i] > 100 && j > 0) d[i][j] = min(d[i][j], d[i - 1][j - 1] + a[i]);
            if (j < f[i - 1]) d[i][j] = min(d[i][j], d[i - 1][j + 1]);
        }
    }
    int res = oo;
    for (int j = 0; j <= f[N]; j++)
        res = min(res, d[N][j]);
    printf("%d", res);
}
int main() {
    readInp();
    process();
    return 0;
}
/*
    We have an array for counting ticket we have from 1->n, with F(i) is the number of tickets we have from 1 -> i
    DP 2D - array D(i, j) is the money we pay to buy things from 1->i with j tickets. 
    1. We buy i-gooods D[i][j] = D[i - 1][j] + a[i] without using a ticket
    2. We have another ticket because value of i-goods >= 100, and then we buy it D[i][j] = D[i - 1][j - 1] + a[i]
    3. We use a ticket which means when we buy i-1 goods we have j + 1 tickets, D[i][j] = D[i - 1][j + 1]
*/