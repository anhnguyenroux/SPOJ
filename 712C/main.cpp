#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int x, y;
    cin >> x >> y;
    int turn = 0;
    int a[3] = {y, y, y};
    while (!(a[0] >= x && a[1] >= x && a[2] >= x)) {
        if (turn % 3 == 0) a[0] = a[1] + a[2] - 1;
        if (turn % 3 == 1) a[1] = a[0] + a[2] - 1;
        if (turn % 3 == 2) a[2] = a[0] + a[1] - 1;
        //cout << a[0] << " " << a[1] << " " << a[2] << "\n";
        turn++;
    }
    cout << turn;
    return 0;
}
