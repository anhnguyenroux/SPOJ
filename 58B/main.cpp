#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int cnt = 0;
    while (n != 1) {
        cout << n << " ";
        int j;
        for (int j = n - 1; j >= 1; j--)
        if (n % j == 0) {
            n = j;
            break;
        }
    }
    cout << 1;
    return 0;
}
