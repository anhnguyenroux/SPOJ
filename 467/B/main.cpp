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
bool isprime(int x) {
    if (x <= 1) return 0;
    if (x == 2) return 1;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return 0;
    return 1;
}
int get(int x) {
    if (isprime(x)) return x;
    for (int j = 2; j * j <= x; j++)
        if (x % j == 0) return j;
}
int main() {
    IO;
    int p, y;
    cin >> p >> y;
    for (int i = y; i >= p; i--) {
        int j = get(i);
        if (j > p) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
