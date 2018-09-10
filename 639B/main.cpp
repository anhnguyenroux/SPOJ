#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, d, h;
    cin >> n >> d >> h;
    if (d > 2 * h || (d == 1 && n != 2)) {
        cout << "-1";
        return 0;
    }
    for (int i = 1; i <= h; i++) cout << i << " " << i + 1 << "\n";
    int idx = h + 2;
    int pre = 1;
    for (int i = 1; i <= d - h; i++) {
        cout << pre << " " << idx << "\n";
        pre = idx;
        idx++;
    }
    pre = 1;
    if (d == h) pre = 2;
    for (int i = idx; i <= n; i++) cout << pre << " " << i << "\n";
    return 0;
}
/*
    make a path with length h from 1, also make a path from 1 with length d - h.
    Then we have a graph with height h and diameter d.
    Adding other nodes to complete the graph which doesnt break the height and diameter.
    If the d == h then we add edges (2, i), otherwise we add edges (1, i)
*/
