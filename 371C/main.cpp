#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int rB, rS, rC;
int pB, pS, pC;
int nB = 0, nS = 0, nC = 0;
ll money;
ll max(ll a, ll b) {
    return (a > b) ? a : b;
}
int main() {
    cin >> s;
    cin >> rB >> rS >> rC;
    cin >> pB >> pS >> pC;
    cin >> money;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'B') nB++;
        if (s[i] == 'S') nS++;
        if (s[i] == 'C') nC++;
    }
    ll ans = -1;
    ll left = 0, right = 1e13;
    while (left <= right) {
        ll mid = (left + right) >> 1;
        ll f = money - max(mid * nB - rB, 0 * 1ll) * pB;
        f -= max(mid * nS - rS, 0 * 1ll) * pS;
        f -= max(mid * nC - rC, 0 * 1ll) * pC;
        if (f >= 0) {
            ans = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }
    cout << ans;
    return 0;
}
/*
    Suppose we x hamburgers already.
    The bread we need to buy : max(x * nB - rB, 0) (nB is the number of bread in recipe, rB is the number of hamburgers we have.
    Similar to sausages and chesses are max(x * nS - rS, 0) and max(x * nC - rC, 0)
    so let f(x) is the money to buy all the things for x hamburgers,
    that f(x) = max(x * nB - rB, 0) * pB + max(x * nS - rS, 0) * pC + max(x * nC - rC, 0) * pC.
    f(x) is a monotonic function, that we can use binary search to find x such that f(x) <= money we have.
    Complexity : O(NlogN) with N <= 1e13.
*/
