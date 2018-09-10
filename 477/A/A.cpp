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
int gettime(int h1, int m1, int h2, int m2) {
    int time = m2 - m1;
    if (time < 60) time += 60, time += (h2 - h1 - 1) * 60;
    else time += (h2 - h1) * 60;
    return time;
}
int main() {
    IO;
    int n, s;
    cin >> n >> s;
    vector <ii> land;
    for (int i = 0; i < n; i++) {
        ii x;
        cin >> x.fi >> x.se;
        land.push_back(x);
    }
    for (int h = 0; h <= 25; h++)
    for (int m = 0; m <= 59; m++) {
        if (gettime(h, m + 1, land[0].fi, land[0].se) >= s) {
            cout << h << " " << m;
            return 0;
        }
        for (int i = 0; i < n - 1; i++)
            if (gettime(land[i].fi, land[i].se + 1, h, m) >= s
        && gettime(h, m + 1, land[i + 1].fi, land[i + 1].se) >= s) {
            cout << h << " " << m;
            return 0;
        }
        if (gettime(land[n - 1].fi, land[n - 1].se + 1, h, m) >= s) {
            cout << h << " " << m;
            return 0;
        }
    }
    return 0;
}
/*
    25 60
0 1
1 1
2 1
3 1
4 1
5 1
6 1
7 1
8 1
9 1
10 1
11 1
12 1
13 1
14 1
15 1
16 1
17 1
18 1
19 1
20 1
21 1
22 1
23 1
23 59
*/

