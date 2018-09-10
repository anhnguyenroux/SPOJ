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
const int kmax = 2e5 + 10;
ll n, k, s;
ll step(ll& cur, ll dist) {
    if (cur + dist <= n) cur += dist;
    else cur -= dist;
    return cur;
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> k >> s;
    if (s > (n - 1) * k || s < k) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << "\n";
    ll f;
    if (k == 1) f = min(n - 1, s);
        else 
            f = min(n - 1, s / (k - 1));
    if (f * (k - 1) == s) f--;
    if (f * k >= s) {
        ll cur = 1;
        for (int i = 1; i < k; i++) cout << step(cur, f) << " ";
        cout << step(cur, s - f * (k - 1)); 
    }
    else {
        for (int x = 1; x <= k; x++) {
            int y = k - x;
            if (f * x + (f + 1) * y == s) {
                ll cur = 1;
                for (int i = 1; i <= y; i++)
                    cout << step(cur, f + 1) << " ";
                for (int i = 1; i <= x; i++)
                    cout << step(cur, f) << " ";
            }
        }
    }
    return 0;
}
