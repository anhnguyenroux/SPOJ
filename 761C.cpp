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
const int MAX = 55;
int n, m;
string s[MAX];
int d[MAX], c[MAX], spec[MAX];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) {
        d[i] = MAX;
        c[i] = MAX;
        spec[i] = MAX;
        for (int j = 0; j < m; j++) {
            if (s[i][j] >= '0' && s[i][j] <= '9') d[i] = min(d[i], min(j, m - j));
            else 
                if (s[i][j] >= 'a' && s[i][j] <= 'z') c[i] = min(c[i], min(j, m - j));
                else 
                    if (s[i][j] == '#' || s[i][j] == '*' || s[i][j] == '&') 
                        spec[i] = min(spec[i], min(j, m - j));
        }
    }
    int res = INF;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    for (int k = 0; k < n; k++)
        if (i != j && i != k && k != j) 
            res = min(res, d[i] + c[j] + spec[k]);
    cout << res;
    return 0;
}
