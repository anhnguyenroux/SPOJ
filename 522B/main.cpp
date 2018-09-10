#include <bits/stdc++.h>
using namespace std;
const int nmax =    2e5 + 10;
const int hmax =    1010;
int w[nmax], h[nmax];
int f1[hmax], f2[hmax];
int d[hmax];
int main() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= hmax; i++)
        d[i] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> h[i];
        sum += w[i];
        d[h[i]]++;
    }
    for (int hi = 1; hi <= hmax; hi++) {
        int flag = 0;
        for (int hj = hmax; hj > hi; hj--)
        if (d[hj]) {
            flag = 1;
            f1[hi] = hj;
            break;
        }
        if (!flag)
            if (d[hi] > 1) f1[hi] = hi, f2[hi] = hi;
        for (int hj = hi - 1; hj >= 1; hj--)
        if (d[hj]) {
            flag = 1;
            f2[hi] = hj;
            break;
        }
    }
    for (int i = 1; i <= n; i++) {
        int tw = sum - w[i];
        int th = max(f1[h[i]], f2[h[i]]);
        cout << tw * th << " ";
    }
    return 0;
}
