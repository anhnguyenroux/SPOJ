#include <iostream>
#include <algorithm>
using namespace std;
const int MAX       =   1010;
const int oo        =   1e9 + 10;
int M, N;
int a[MAX][MAX];
int b[MAX][MAX];
void readInp() {
    cin >> M >> N;
    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++)
            cin >> a[i][j];
}
void process() {
    int h[MAX];
    int res = 1;
    for (int i = 1; i <= M; i++) {
        int cnt = 1;
        for (int j = 1; j < N; j++)
            if (a[i][j] <= a[i][j + 1]) {
                cnt++;
                res = max(res, cnt);
            }
            else cnt = 1;
    }
    for (int j = 1; j <= N; j++) {
        int cnt = 1;
        for (int i = 1; i < M; i++) 
            if (a[i][j] <= a[i + 1][j]) {
                cnt++;
                res = max(res, cnt);
            }
            else cnt = 1;
    }
    for (int i = 1; i < M; i++)
        for (int j = 1; j < N; j++)
            b[i][j] = a[i][j] <= a[i + 1][j] && a[i][j] <= a[i][j + 1] && a[i][j + 1] <= a[i + 1][j + 1] && a[i + 1][j] <= a[i + 1][j + 1] ? 1 : 0;
    for (int j = 1; j < N; j++) 
        h[j] = 0;
    for (int i = 1; i < M; i++) {
        for (int j = 1; j < N; j++)
            if (b[i][j]) h[j]++;
            else h[j] = 0;
        int D[MAX];
        int L[MAX], R[MAX];
        int top;
        top = 0;
        D[top] = 0;
        for (int j = 1; j < N; j++) {
            while (top > 0 && h[D[top]] >= h[j]) top--;
            L[j] = D[top] + 1;
            D[++top] = j;
        }
        top = 0;
        D[top] = N;
        for (int j = N - 1; j >= 1; j--) {
            while (top > 0 && h[D[top]] >= h[j]) top--;
            R[j] = D[top] - 1;
            D[++top] = j;
        }
        for (int j = 1; j < N; j++)
            if (h[j] > 0)
                res = max(res, (h[j] + 1) * (R[j] - L[j] + 2));
    }
    cout << res;
}
int main() {
    readInp();
    process();
    return 0;
}