#include <stdio.h>
const int NMAX = 17000 + 100;
void Query() {
    int N, k;
    int a[NMAX];
    scanf("%d %d", &N, &k);
    for (int i = 1; i <= N; i++)
        scanf("%d", &a[i]);
    int D[NMAX], L[NMAX], R[NMAX];
    int top;
    top = 0;
    D[top] = 0;
    for (int i = 1; i <= N; i++) {
        while (top > 0 && a[D[top]] >= a[i]) top--;
        L[i] = D[top] + 1;
        D[++top] = i;
    }
    top = 0;
    D[top] = N + 1;
    for (int i = N; i > 0; i--) {
        while (top > 0 && a[D[top]] >= a[i]) top--;
        R[i] = D[top] - 1;
        D[++top] = i;
    }
    int left = 1, right = k;
    int i = 1;
    int cnt = 0;
    while (i <= N) {
        while (i <= N && L[i] <= left && right <= R[i] && left <= i && i <= right) {
            printf("%d ", a[i]);
            left++;
            right++;
            cnt++;
            if (cnt == N - k + 1) break;
        }
        if (cnt == N - k + 1) break;
        i++;
    }
    printf("\n");
}
int main() {
    int Test;
    scanf("%d", &Test);
    while (Test > 0) {
        Query();
        Test--;
    }
    return 0;
}
