#include <bits/stdc++.h>
using namespace std;
const int NMAX  =   3e5;
struct t {
    int v, pos;
};
int n;
int b[NMAX];
t a[NMAX];
int cmp(t a, t b) {
    return (a.v < b.v);
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i].v), a[i].pos = i;
    sort(a, a + n, cmp);
    b[a[0].pos] = a[0].v;
    for (int i = 1; i < n; i++) {
        if (a[i].v > b[a[i - 1].pos]) b[a[i].pos] = a[i].v;
        else b[a[i].pos] = b[a[i - 1].pos] + 1;
    }
    for (int i = 0; i < n; i++)
        printf("%d ", b[i]);
    return 0;
}
/*
    We sort the array by
*/
