#include <stdio.h>
#include <algorithm>
using namespace std;
const int NMAX      =   110;
const int TMAX      =   110;
long long f[NMAX];
int a[TMAX];
int main() {
    int test;
    int tmax = 0;
    scanf("%d", &test);
    for (int i = 0; i < test; i++) {
        scanf("%d", &a[i]);
        tmax = max(tmax, a[i]);
    }
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i <= tmax; i++)
        f[i] = f[i - 1] + f[i - 2];
    for (int i = 0; i < test; i++) 
        printf("%d\n", f[a[i]]);
    return 0;
}