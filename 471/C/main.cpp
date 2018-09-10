#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include<vector>

using namespace std;
typedef unsigned long long ll;
int sz;
vector<ll> g;

ll solve(ll x) {
   ll l = 0, r= 1e9+1,ans = 0;
   while(l <= r) {
        ll mid = (l+r)>>1;
        if (mid*mid <= x) { ans = mid; l = mid+1; }
        else r = mid-1;
   }
   return ans;
}

void init() {
    for (ll i = 2; i <= 1e6; i++) {
        ll x = i*i*i;
        while(x <= 2e18) {
            ll sq = solve(x);
            if (sq*sq != x) g.push_back(x);
            if (2e18/i < x) break;
            x *= i;
        }
    }
    sort(g.begin(),g.end());
    sz = unique(g.begin(),g.end())-g.begin();
}

int main() {
    int t;
    cin >> t;
    init();
    ll l,r;
    while(t--) {
        cin >> l >> r;
        ll ans1 = solve(r)-solve(l-1);
        ll ans2 = upper_bound(g.begin(),g.end(),r)-lower_bound(g.begin(),g.end(),l);
        cout << ans1 + ans2 << endl;
    }
    return 0;
}
