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
int main() {
    IO;
    int n, m;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m;
    if (n >= m) {
        for (int i = 1; i <= m; i++)
            cout << "BG";
        for (int i = 1; i <= n - m; i++)
            cout << "B";
    }
    else {
        for (int i = 1; i <= n; i++)
            cout << "GB";
        for (int i = 1; i <= m - n; i++)
            cout << "G";
    }
    return 0;
}
