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
const int nmax = 1e4 + 10;
int np = 0;
int palin[nmax];
int n;
int f[nmax];
int trace[nmax];
int palindrome(int x) {
    int t = x;
    int d = 0;
    while (t > 0) {
        d = d * 10 + (t % 10);
        t /= 10;
    }
    if (d == x) return 1; 
    else return 0;
}
void solver(int test_case) {
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = nmax;
        for (int j = 0; j < np; j++)
            if (i >= palin[j] && f[i] > f[i - palin[j]] + 1) {
                f[i] = f[i - palin[j]] + 1;
                trace[i] = palin[j];
            } 
    }
    cout << "Case #" << test_case << "\n";
    if (f[n] <= 3) {
        cout << f[n] << " ";
        vector <int> res;
        while (n > 0) {
            res.push_back(trace[n]);
            n -= trace[n];
        }
        sort(all(res));
        for (int i = res.size() - 1; i >= 0; i--)
            cout << res[i] << " ";
    }
    else cout << 0;
    cout << "\n";
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
    int cnt = 0;
    for (int i = 1; i <= 10000; i++) 
        if (palindrome(i)) palin[np++] = i;
    int test;
    cin >> test;
    for (int t = 1; t <= test; t++) {
        cin >> n;
        solver(t);
    }
    return 0;
}
