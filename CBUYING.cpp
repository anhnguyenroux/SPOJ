/*
    CBUYING : http://vn.spoj.com/problems/CBUYING/
    Complexity : O(NlogN)
*/
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int NMAX      =   1e5 + 10;
struct chocolate {
    ll p;
    ll c;
};
int N;
ll B;
chocolate a[NMAX];
void readInp() {
    cin >> N >> B;
    for (int i = 0; i < N; i++)
        cin >> a[i].p >> a[i].c;
}
int cmp(chocolate x, chocolate y) {
    return x.p < y.p;
}
void process() {
    sort(a, a + N, cmp);
    ll res = 0;
    for (int i = 0; i < N; i++) {
        if (B / a[i].p >= a[i].c) {
            res += a[i].c;
            B -= a[i].p * a[i].c;
        }
        else {
            res += B / a[i].p;
            break;
        }
    }
    cout << res;
}
int main() {
    readInp();
    process();
    return 0;
}