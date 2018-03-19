/*
    CREC01 : http://vn.spoj.com/problems/CREC01/
    Explanation and Complexity are below
*/
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
const int MAX       =   1010;
int M, N;
int a[MAX][MAX];
void readInp() {
    cin >> M >> N;
    for (int i = 1; i <= M; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= N; j++)
            a[i][j] = s[j - 1] - '0';
    }
}
void process() {
    int h[MAX];
    int D[MAX];
    int L[MAX];
    int top;
    ll f[MAX];
    ll res = 0;
    for (int j = 1; j <= N; j++)
        h[j] = 0;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++)
            if (a[i][j] == 0) h[j] = 0;
            else h[j]++;
        top = 0;
        D[0] = 0;
        for (int j = 1; j <= N; j++) {
            while (top > 0 && h[D[top]] >= h[j]) top--;
            L[j] = D[top] + 1;
            D[++top] = j;
        }
        f[0] = 0;
        for (int j = 1; j <= N; j++)
            if (h[j]) {
                f[j] = (ll) (j - L[j] + 1) * h[j] + f[L[j] - 1];
                res += f[j];
            }
            else f[j] = 0;
    }
    cout << res;
}
int main() {
    readInp();
    process();
    return 0;
}
/*
    We use Deque for finding L[i] that for each h[i] (the height of 1s from 1->i continuos) is smallest from L[i] to i
    We have a DP - formula : 
    for every row, F[i] : number of sub-rectangle that have full of 1. 
    F[i] = (i - L[i] + 1) * h[i] + F[L[i - 1]];
    Complexity : O(N^2)
*/