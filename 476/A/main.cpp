#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int k, n, s, p;
    cin >> k >> n >> s >> p;
    for (int i = 1; i <= 1e9; i++) {
        if (((i * p) / k) * s >= n) {
            cout << i;
            return 0;
        }
    }
    return 0;
}
