#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
const int NMAX = 1e4 + 100;
int N;
int a[NMAX];
void inpProcess() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &a[i]);
}
int test(int x) {
    int k = sqrt(2 * x);
    return ((k * (k + 1) / 2) == x);
}
void Process() {
    int i = 0;
    int Lmax = 0;
    while (i < N) {
        if (test(a[i])) {
            int j = i;
            while (j + 1 < N && test(a[j + 1]) && a[j + 1] >= a[j]) j++;
            if (j > i) Lmax = max(Lmax, j -  i + 1);
            i = j + 1;    
        }
        else i++;
    }
    printf("%d", Lmax);
}
int main() {
    inpProcess(); 
    Process();
    return 0;
}