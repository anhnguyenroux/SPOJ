#include <bits/stdc++.h>
using namespace std;
const int MAX   =   110;
int n, m;
char a[MAX][MAX];
bool del[MAX];
int main() {
    string s;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++)
            a[i][j] = s[j];
    }
    for (int j = 0; j < m; j++) {
        for (int i = 1; i < n; i++)
        if (a[i][j] < a[i - 1][j]) {
            int flag = 1;
            for (int k = 0; k < j; k++)
            if (del[k] == 0)
            if (a[i][k] > a[i - 1][k]) {
                flag = 0;
                break;
            }
            if (flag) del[j] = 1;
        }
    }
    int res = 0;
    for (int j = 0; j < m; j++)
        if (del[j]) res++;
    cout << res;
    return 0;
}
