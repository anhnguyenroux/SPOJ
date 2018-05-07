#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
const int MAX       =   1010;
const int base      =   1e9;
struct bigInt {
    int len;
    ll d[1000];
};
int n, m;
int S = 0;
bigInt c[MAX];
bigInt addbigInt(bigInt a, bigInt b) {
    bigInt c;
    c.len = max(a.len, b.len);
    for (int i = 0; i < 1000; i++)
        c.d[i] = 0;
    ll cr = 0;
    for (int i = 0; i < c.len; i++) {
        if (i < a.len) cr += a.d[i];
        if (i < b.len) cr += b.d[i];
        c.d[i] = cr % base;
        cr /= base;
    }
    if (cr > 0) c.d[c.len++] = cr;
    return c;
}
void printbigInt(bigInt a) {
    cout << a.d[a.len - 1];
    string s;
    for (int i = a.len - 2; i >= 0; i--)
        cout << setfill('0') << setw(9) << a.d[i];
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x; cin >> x;
        S += x;
    }
    if (n < S + m - 1) {
        cout << 0;
        return 0;
    }
    c[0].len = 1;
    c[0].d[0] = 1;
    for (int i = 1; i <= n - S + 1; i++)
        for (int j = min(i, m); j >= 1; j--)
            c[j] = addbigInt(c[j],c[j - 1]);
    printbigInt(c[m]);
    return 0;
}