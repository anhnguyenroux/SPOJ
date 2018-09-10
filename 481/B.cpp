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
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    int n;
    cin >> n;
    string s;
    cin >> s;
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (i + 2 < n) {
            if (s[i] == 'x' && s[i + 1] == 'x' && s[i + 2] == 'x') {
                res++;
                for (int j = i + 1; j < n; j++)
                    s[j - 1] = s[j];
                i--;
                n--;
            }
        }
    }
    cout << res;
    return 0;
}
