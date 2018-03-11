#include <iostream>
using namespace std;
long long f[35];
int main() {
    f[0] = 1;
    f[1] = 0;
    f[2] = 3;
    f[3] = 0;
    for (int i = 4; i <= 30; i++)
        if (i % 2 == 1) f[i] = 0;
        else f[i] = 4 * f[i - 2] - f[i - 4];
    while (true) {
        int x;
        cin >> x;
        if (x == -1) break;
        cout << f[x] << "\n";
    }
    return 0;
}