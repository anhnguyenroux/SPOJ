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
int n;
string s;
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
    cin >> n;
    cin >> s;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n - 1; i++)
        if (s[i] == '0' && s[i + 1] == '1') {
            s[i] = '1';
            s[i + 1] = '0';
        }
    }
    while (n >= 2) {
        if (s[0] == '1' && s[1] == '1') {
            for (int i = 0; i < n - 1; i++)
                s[i] = s[i + 1];
            n--;
        }
        else break;
    }
    for (int i = 0; i < n; i++) cout << s[i];
    return 0;
}
