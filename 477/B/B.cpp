#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0);
#define all(v) (v).begin(), (v).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const float e = 1e-8;
const int nmax = 1e5 + 10;
int n, a, b;
int s[nmax];
int cmp(int a, int b) {
    return (a > b);
}
int main() {
    IO;
    cin >> n >> a >> b;
    ll sum = 0;
    for (int i = 0; i < n; i++) cin >> s[i], sum += s[i];
    if (s[0] * a >= sum * b) {
        cout << 0;
        return 0;
    }
    sort(s + 1, s + n, cmp);
    for (int i = 1; i < n; i++) s[i] += s[i - 1];
    for (int i = 1; i < n; i++) {
        ll S = (sum - (s[i] - s[0]));
        ll tmp1 = s[0] * a;
        ll tmp2 = S * b;
        if (tmp1 >= tmp2) {
            cout << i;
            return 0;
        }
    }
    return 0;
}

