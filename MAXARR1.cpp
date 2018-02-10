#include <stdio.h>
#include <algorithm>
using namespace std;
const int MAX = 1e5;
int a[MAX + 100];
int f[MAX + 100];
void PreCal() {
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i <=MAX; i++)
        if (i % 2 == 0) a[i] = a[i / 2];
        else a[i] = a[i / 2] + a[i / 2 + 1];
    f[0] = 0;
    for (int i = 1; i <= MAX; i++)
        f[i] = max(f[i - 1], a[i]);
}
void Cal() {
    int Test;
    scanf("%d", &Test);
    while (Test > 0) {
        int n;
        scanf("%d", &n);
        printf("%d\n", f[n]);
        Test--;
    }
}
int main() {
    PreCal();
    Cal();
    return 0;
}