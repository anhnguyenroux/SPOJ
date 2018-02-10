#include <stdio.h>
#include <algorithm>
using namespace std;
const int NMAX = 5e4 + 100;
int N, p;
int a[NMAX];
void inpProcess() {
    scanf("%d %d", &N, &p);
    a[0] = 0;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &a[i]);
        a[i] += a[i - 1];                        
    }
}
void Process() {
    int lenMax = 0;
    for (int j = 1; j <= N; j++) 
        for (int i = 1; i <= j; i++) {
            if (j - i + 1 < lenMax) break;
            if (a[j] - a[i - 1] >= p) lenMax = max(lenMax, j - i + 1);
        }
    if (lenMax == 0) lenMax = -1;
    printf("%d", lenMax);
}
int main() {
    inpProcess();
    Process();
    return 0;
}