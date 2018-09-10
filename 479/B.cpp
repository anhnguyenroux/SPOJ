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
    string s;
    cin >> n;
    cin >> s;
    s = "#" + s;
    int f[110];
    for (int i = 1; i <= n; i++) f[i] = 0;
    for (int i = 1; i < n; i++) {
        f[i] =  1;
        for (int j = i + 1; j < n; j++)
            if (s[i] == s[j] && s[i + 1] == s[j + 1]) f[i]++;
    }
    int pos = 1;
    for (int i = 1; i <= n; i++)
        if (f[i] > f[pos]) pos = i;
    cout << s[pos] << s[pos + 1];
    return 0;
}
