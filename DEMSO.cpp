#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int LMAX      =   16;
ll L, R;
int D, K;
ll f[LMAX + 5][20][LMAX + 5];
int abs(int x) {
    return x >= 0 ? x : -x;
}
ll Cal(int pos, int d, int k) {
    if (pos == 1) {
        if (k <= K) f[pos][d][k] = 1;
        else 
            f[pos][d][k] = 0;
    }
    if (f[pos][d][k] == -1) {
        ll res = 0;
        for (int j = 0; j < 10; j++)
                res += Cal(pos - 1, j, k + (abs(j - d) <= D));
        f[pos][d][k] = res;
    }
    return f[pos][d][k];
}
ll Solve(ll n) {
    vector <int> digit;
    while (n > 0) {
        digit.push_back(n % 10);
        n /= 10;
    }
    int m = digit.size();
    int pos = m;
    ll res = 0;
    int prev = 0;
    int k = 0;
    for (int i = m; i >= 1; i--) {
        int d = digit[i - 1];
        for (int j = 0; j < d; j++) {
            if (pos == m) {
                if (pos > 1 && j == 0) {
                    for (int z = 0; z < 10; z++)
                        res += Cal(pos - 1, z, 0);
                }
                else 
                    res += Cal(pos, j, 0);
            }
            else {
                res += Cal(pos, j, k + (abs(j - prev) <= D));
            }
        }
        if (pos != m) k += (abs(d - prev) <= D);
        pos--;
        prev = d;
    }
    return res;
}
int main() {
    cin >> L >> R >> D >> K;
    for (int i = 0; i <= LMAX; i++)
    for (int j = 0; j < 10; j++)
    for (int z = 0; z <= LMAX; z++)
        f[i][j][z] = -1; 
    ll a1 = Solve(L);
    ll a2 = Solve(R + 1);
    cout << a2 - a1;
    return 0;
}