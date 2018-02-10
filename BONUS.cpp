#include <stdio.h>
#include <algorithm>
using namespace std;
const int MAX = 1100;
int N, k;
int f[MAX][MAX];
void inpProcess() {
    scanf("%d %d", &N, &k);
    for (int i = 1; i <= N; i++) 
        for (int j = 1; j <= N; j++) {
            scanf("%d", &f[i][j]);
            f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
        }
}
int get(int x1, int y1, int x2, int y2) {
    return f[x2][y2] - f[x2][y1 - 1] - f[x1 - 1][y2] + f[x1 - 1][y1 - 1];
}
void Process() {
    int res = 0;
    for (int i = 1; i <= N - k + 1; i++)
        for (int j = 1; j <= N - k + 1; j++) 
            res = max(res, get(i, j, i + k - 1, j + k - 1));
    printf("%d", res);
}
int main() {
    inpProcess();
    Process();
    return 0;
}