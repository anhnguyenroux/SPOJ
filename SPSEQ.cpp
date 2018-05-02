#include <stdio.h>
#include <math.h>
const int NMAX = 100000 + 100;
int N;
int a[NMAX];
int F1[NMAX], F2[NMAX];
int res;
int l[NMAX], r[NMAX];
int bsearch1(int v){
    int left = 1, right = res;
    while (left < right) {
        int mid = (left + right) >> 1;
        if (a[v] > a[F1[mid]]) left = mid + 1;
            else right = mid;
    }
    return left;
}

int bsearch2(int v){
    int left = 1, right = res;
    while (left < right){
        int mid = (left + right) >> 1;
        if (a[v] > a[F2[mid]]) left = mid + 1;
            else right = mid;
    }
    return left;
}
int maximum(int a, int b){
    return (a > b) ? a : b;
}
int minimum(int a, int b){
    return (a < b) ? a : b;
}
int main (){
    scanf("%d",&N);
    for (int i = 1; i <= N; i++)
        scanf("%d",&a[i]);
    //1 --> N
    res = 1;
    F1[1] = 1;
    for (int i = 2; i <= N; i++)
    if (a[i] > a[F1[res]]) {
            F1[++res] = i;
            l[i] = res;
    }
    else {
            int v = bsearch1(i);
            F1[v] = i;
            l[i] = v;
    }
    //N --> 1
    res = 1;
    F2[1] = N;
    for (int i = N - 1; i > 0; i--)
    if (a[i] > a[F2[res]]) {
            F2[++res] = i;
            r[i] = res;
    }
    else {
            int v = bsearch2(i);
            F2[v] = i;
            r[i] = v;
    }
    //lay ket qua MAX(min(r[i],l[i]) * 2 - 1)
    int ans = 1;
    for (int i = 1; i <= N; i++)
        ans = maximum(ans, minimum(r[i],l[i]) * 2 - 1);
    printf("%d",ans);
    return 0;
}
