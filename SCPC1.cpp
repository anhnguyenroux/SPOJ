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
const int nmax = 2e5 + 10;
int n, k;
int a[nmax];
int f[nmax];
void solver(int test_case) {
    sort(a + 1, a + 1 + n);
    set <int> s;
    s.insert(a[1]);
    set <int> :: iterator it;
    for (int i = 2; i <= n; i++) {
        it = s.begin();
        if (a[i] - (*it) <= k) s.insert(a[i]);
        else {
            s.erase(it);
            s.insert(a[i]);
        }
    } 
    cout << "Case #" << test_case << "\n";
    cout << s.size() << "\n";
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    int test; 
    cin >> test;
    for (int t = 1; t <= test; t++) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> a[i];
        solver(t);
    }
    return 0;
}