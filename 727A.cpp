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
    int a, b;
    cin >> a >> b;
    int x = b;
    vector <int> q;
    while (true) {
        if (b < a) {
            cout << "NO";
            return 0;
        }
        if (b == a) break;
        if (b % 2 == 0) {
            q.push_back(b / 2);
            b = b / 2;
        }
        else {
            int d = b % 10;
            if (d > 1) {
                cout << "NO";
                return 0;
            }
            q.push_back(b / 10);
            b /= 10;
        }
    }
    cout << "YES" << "\n";
    cout << q.size() + 1 << "\n";
    for (int i = q.size() - 1; i >= 0; i--)
        cout << q[i] << " ";
    cout << x;
    return 0;
}
