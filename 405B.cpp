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
    s = "#" + s;
    int left = 1, right = n;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '.') continue;
        if (s[i] == 'L') {
            left = i;
            break;
        }
        if (s[i] == 'R') break;
    }
    for (int i = n; i >= 1; i--) {
        if (s[i] == '.') continue;
        if (s[i] == 'R') {
            right = i;
            break;
        }
        if (s[i] == 'L') break;
    }
    //cout << left << " " << right << "\n";
    int res = 0;
    for (int i = left; i <= right; i++)
    if (s[i] == '.') {
        int x, y;
        for (x = i - 1; x >= left; x--) {
            if (s[x] == '.') continue;
            else break;
        }
        for (y = i + 1; y <= right; y++) {
            if (s[y] == '.') continue;
            else break;
        }
        if (x < left || y > right) res++;
        else 
            if (s[x] == 'L' && s[y] == 'R') res++;
            else 
                if (s[x] == 'R' && s[y] == 'L' && i - x == y - i) res++; 
    }
    cout << res;
    return 0;
}
