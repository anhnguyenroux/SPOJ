#include <stdio.h>
#include <algorithm>
using namespace std;
const int LMAX = 1100;
int N, M;
int a[LMAX][LMAX];
int h[LMAX][LMAX];
void inpProcess() {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            scanf("%d", &a[i][j]);
}
void findMin(int b[], int &curAns) {
    int D[LMAX], L[LMAX], R[LMAX];
    int top;
    top = 0;
    D[top] = 0;
    for (int i = 1; i <= M; i++) {
        while (top > 0 && b[D[top]] >= b[i]) top--;
        L[i] = D[top] + 1;
        D[++top] = i;
    }
    top = 0;
    D[top] = M + 1;
    for (int i = M; i > 0; i--) {
        while (top > 0 && b[D[top]] >= b[i]) top--;
        R[i] = D[top] - 1;
        D[++top] = i;
    }
    for (int i = 1; i <= M; i++)
        curAns = max(curAns, (R[i] - L[i] + 1) * b[i]);
}
void Process() {
    int b[LMAX];
    for (int i = 1; i <= M; i++)
        h[0][i] = 0;
    int res = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++)
            if (a[i][j] == 0) h[i][j] = 0;
                else h[i][j] = h[i - 1][j] + 1;
        for (int j = 1; j <= M; j++)
            b[j] = h[i][j];
        findMin(b, res);
    }
    printf("%d", res);
}
int main() {
    inpProcess();
    Process();
    return 0;
}
