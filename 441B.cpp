#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0);
#define all(v) (v).begin(), (v).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pi;
const int INF = (int) 1e9;
const ll LINT = (ll) 1e18;
const int nmax = 3e3;
int n, v;
int d[nmax + 10];
int main() {
    IO; 
    cin >> n >> v;
    memset(d, 0, nmax + 1);
    int daymax = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        d[a] += b;
        daymax = max(daymax, a);
    }
    int res = 0, pre = 0;
    for (int i = 1; i <= daymax + 1; i++) {
        int now = d[i];
        if (now + pre <= v) res += now + pre, pre = 0;
        else {
            res += v;
            int lt = max(v - pre, 0);
            pre = now - lt;
        }
    }
    cout << res;
    return 0;
}
