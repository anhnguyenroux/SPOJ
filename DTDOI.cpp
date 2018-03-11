/*
    DTDOI : http://vn.spoj.com/problems/DTDOI/
    Explanation and Complexity are below
*/
#include <stdio.h>
#include <math.h>
const int NMAX = 100 + 10;
const int LMAX = 1e6 + 100;
const int oo = 1e9 + 100;
int N, L;
int a[NMAX];
int f[LMAX];
int max(int a, int b){
    return (a > b) ? a : b;
}
int min(int a, int b){
    return (a < b) ? a : b;
}
int main(){
    scanf("%d %d", &N, &L);
    int maxPrice;
    for (int i = 1; i <= N; i++){
        scanf("%d", &a[i]);
        maxPrice = max(maxPrice, a[i]);
    }
    int res = 0;
    while (L > 1e6){
        res++;
        L -= maxPrice;
    }
    f[0] = 0;
    for (int i = 1; i <= L; i++){
        f[i] = oo;
        for (int j = 1; j <= N; j++)
            if (i >= a[j]) f[i] = min(f[i], f[i - a[j]] + 1);
    }
    printf("%d", f[L] + res);
    return 0;
}
/*
    First, we need to greedy to minimize the L (money we need to change) (L <= 10^6)
    Then we can DP with the rest of them. 
    Complexity : O(10^6*N)
*/