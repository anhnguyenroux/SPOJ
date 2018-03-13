/*
    OPTCUT : vn.spoj.com/problems/OPTCUT
    Explanation and Complexity are below
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int NMAX      =   2010;
const int oo        =   1e9 + 10;
int a[NMAX];
int N;
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
        for (int j = 0; j <= N; j++) {
            f[i][j] = 0;
            k[i][i] = i;
        }
    for (int j = 1; j <= N; j++)
    for (int i = j - 1; i >= 1; i--) {
        f[i][j] = oo;
        for (int t = k[i][j - 1]; t <= k[i + 1][j]; t++) {
            if (a[j] - a[i - 1] + f[i][t] + f[t + 1][j] < f[i][j]) {
                f[i][j] = a[j] - a[i - 1] + f[i][t] + f[t + 1][j];
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
    We use K[i][j] to speed up DP in this problem 
    K[i][j] : optimization position when we cut the log from i to j
    S[i] : length of the log from 1 to i
    F[i][i] = 0, K[i][i] = i;
    F[i][j] = S[j] - S[i - 1] + min(F[i][k], F[k + 1][j]) K[i][j - 1] <= k <= k[i + 1][j];
    Result : F[1][N];
    Complexity : O(N^2)
*/