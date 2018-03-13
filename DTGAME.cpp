
/*
    DTGAME : vn.spoj.com/problems/DTGAME
    Explanation and Complexity are below
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int NMAX      =   2010;
int N;
int a[NMAX];
int f[NMAX][NMAX];
int k[NMAX][NMAX];
void process() {
    cin >> N;
    a[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i = 0; i <= N; i++)
    for (int j = 0; j <= N; j++)
        f[i][j] = 0;
    for (int i = 1; i <= N; i++) {
        f[i][i] = 0;
        k[i][i] = i;
    }
    for (int j = 1; j <= N; j++) 
    for (int i = j - 1; i >= 1; i--) {
        f[i][j] = 0;
        for (int t = k[i][j - 1]; t <= k[i + 1][j]; t++) {
            int ans = min(f[i][t] + a[t] - a[i - 1], f[t + 1][j] + a[j] - a[t]);
            if (ans > f[i][j]) {
                f[i][j] = ans;
                k[i][j] = t;
            }
        }
    }
    cout << f[1][N];
}
int main() {
    process();
    return 0;
}
/*
    We have an array A[i] which denotes the sum of p[i] from 1->i
    We have formula for DP : 
    F[i][j] : maximum money that we have when we optimize from i to j. 
    F[i][i] = 0
    F[i][j] = max(F[i][k] + a[k] - a[i - 1], F[k + 1][j] + a[j] - a[k]), i <= j < k
    We have to speed up DP with K[i][j] : the optimization position when we divide the array from i to j
    Complexity : O(N^2)
*/