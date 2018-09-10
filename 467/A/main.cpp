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
const int nmax = 110;
int n;
int a[nmax];
int f[601];
int main() {
    IO;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i], f[a[i]]++;
    int cnt = 0;
    for (int i = 1; i <= 600; i++)
        if (f[i]) cnt++;
    cout << cnt;
    return 0;
}

