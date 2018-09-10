#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
const int MAX       =   410;
int M, N;
int a[MAX][MAX];
void readInp() {
    cin >> M >> N;
    for (int i = 1; i <= M; i++) {
        string s;
        for (int j = 1; j <= N; j++)
            a[i][j] = s[j - 1];
    }
}
void process() {
    int h[MAX];
    ll res = 0;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++)
    }
}
int main() {
    readInp();
    process();
    return 0;
}