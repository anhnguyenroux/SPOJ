#include <bits/stdc++.h>
using namespace std;
const int nmax = 1010;
int main() {
    int n;
    cin >> n;
    int a[nmax];
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[0] = 0;
    a[n + 1] = 0;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int cntl = 0, cntr = 0;
        for (int pos = i - 1; pos >= 1; pos--)
            if (a[pos] <= a[pos + 1]) cntl++; else break;
        for (int pos = i + 1; pos <= n; pos++)
            if (a[pos] <= a[pos - 1]) cntr++; else break;
        res = max(res, 1 + cntl + cntr);
    }
    cout << res;
    return 0;
}
