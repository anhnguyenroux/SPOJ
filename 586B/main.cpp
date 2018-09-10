#include <bits/stdc++.h>
using namespace std;
const int oo =  1e9;
int n;
int a[55], b[55];
int c[55];
int main() {
    scanf("%d", &n);
    a[1] = 0;
    for (int i = 2; i <= n; i++) scanf("%d", &a[i]), a[i] += a[i - 1];
    b[1] = 0;
    for (int i = 2; i <= n; i++) scanf("%d", &b[i]), b[i] += b[i - 1];
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
    int res = oo;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
        if (i != j) {
            int cp = a[i] + c[i] + b[n] - b[i];
            cp += b[n] - b[j] + c[j] + a[j];
            res = min(res, cp);
        }
    printf("%d", res);
    return 0;
}
