#include <bits/stdc++.h>
using namespace std;
const int KMAX = 1e4;
int a, b, f, k;
int need[KMAX + 10];
int main() {
    cin >> a >> b >> f >> k;
    if (b < f) {
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= k; i++)
        if (i % 2 == 1) need[i] = f; else need[i] = a - f;
    int fuel = b;
    int res = 0;
    int pos = 0;
    for (int i = 1; i <= k; i++) {
    bool flag = 0;
    if (i % 2 == 1) {
        if (a + need[i + 1] <= fuel) fuel -= a, flag = 1;
        else
        if (fuel >= f && (a - f) + need[i + 1] <= fuel - f + b) {
            res++;
            fuel = b - (a - f);
            flag = 1;
        }
    }
    else {
        if (a + need[i + 1] <= fuel) fuel -= a, flag = 1;
        else
        if (fuel >= a - f && f + need[i + 1] <= fuel - (a - f) + b) {
            res++;
            fuel = b - f;
            flag = 1;
        }
    }
    if (flag == 0 || fuel < 0) {
        cout << -1;
        return 0;
    }
    }
    cout << res;
    return 0;
}
/*

*/
