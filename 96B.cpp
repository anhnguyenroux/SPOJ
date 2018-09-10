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
int n;
int getlength(ll x) {
    int cnt = 0;
    while (x) x /= 10, cnt++;
    return cnt;
}
int main() {
    IO;
    ll n;
    cin >> n;
    int len = getlength(n);
    if (len % 2 == 1) {
        for (int i = 1; i <= (len + 1) / 2; i++) cout << 4;
        for (int i = 1; i <= (len + 1) / 2; i++) cout << 7;
    }
    else {
        vector <ll> a;
        queue <li> q;
        q.push(li(4, 1));
        q.push(li(7, 1));
        while (!q.empty()) {
            li cur = q.front(); q.pop();
            int len = cur.se;
            ll x = cur.fi;
            ll tmp = x;
            int d4 = 0, d7 = 0;
            while (tmp) {
                if (tmp % 10 == 4) d4++; else d7++;
                tmp /= 10;
            }
            if (d4 == d7) a.push_back(x);
            if (len > 10) continue;
            q.push(li(x * 10 + 4, len + 1));
            q.push(li(x * 10 + 7, len + 1));
        }
        sort(all(a));
        cout << *lower_bound(a.begin(), a.end(), (ll) n);
    }
    return 0;
}
