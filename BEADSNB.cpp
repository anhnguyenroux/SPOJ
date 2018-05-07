#include <bits/stdc++.h>
using namespace std;
const int NMAX =    1e5 + 10;
int n;
int a[NMAX];
int f[NMAX];
int d1[NMAX], d2[NMAX];
int res;
int search1(int i) {
    int left = 1, right = res;
    while (left < right) {
        int mid = (left + right) >> 1;
        if (a[i] > a[f[mid]]) left = mid + 1;
        else right = mid;
    }
    return left;
}
int search2(int i) {
    int left = 1, right = res;
    while (left < right) {
        int mid = (left + right) >> 1;
        if (a[i] < a[f[mid]]) left = mid + 1;
        else right = mid;
    }
    return left;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    res = 1;
    f[1] = n;
    d1[n] = 1;
    for (int i = n - 1; i >= 1; i--)
        if (a[i] > a[f[res]]) {
            f[++res] = i;
            d1[i] = res;
        }
        else {
            int v = search1(i);
            f[v] = i;
            d1[i] = v;
        }
    res = 1;
    f[1] = n;
    d2[n] = 1;
    for (int i = n - 1; i >= 1; i--)
        if (a[i] < a[f[res]]) {
            f[++res] = i;
            d2[i] = res;
        }
        else {
            int v = search2(i);
            f[v] = i;
            d2[i] = v;
        }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, d1[i] + d2[i] - 1);
    printf("%d", ans);
    return 0;
}