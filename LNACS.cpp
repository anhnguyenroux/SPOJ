#include <stdio.h>
#include <algorithm>
using namespace std;
const int MAX = 1e3 + 100;
int N, M;
int a[MAX], b[MAX];
int f[MAX][MAX];
void inpProcess() {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= M; i++)
        scanf("%d", &b[i]);
}
void Process() {
    f[0][0] = 0;
    for (int i = 1; i <= M; i++)
        if (a[1] == b[i]) f[1][i] = 1;
        else f[1][i] = f[1][i - 1];
    for (int i = 1; i <= N; i++)
        if (a[i] == b[1]) f[i][1] = 1;
        else f[i][1] = f[i - 1][1];
    for (int i = 2; i <= N; i++)
    for (int j = 2; j <= M; j++) {
        f[i][j] = max(f[i - 1][j - 1], max(f[i - 1][j], f[i][j - 1]));
        if (a[i] == b[j])
            f[i][j] = max(f[i][j], f[i - 2][j - 2] + 1);
    }
    printf("%d", f[N][M]);
}
int main() {
    inpProcess();
    Process();
    return 0;
}
/*
    Similar to LCS, We have the formula for this problem 
    Initialize :
        F[1][i] = 1 for every a[1] = b[i];
        F[i][1] = 1 for every a[i] = b[1];
    Formula : 
        F[i][j] = max(F[i - 1][j - 1], F[i - 1][j], F[i][j - 1]);
        if (a[i] == b[i]) F[i][j] = max(F[i][j], F[i - 2][j - 2] + 1)
*/