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
string s1, s2;
int n;
int a[26][26];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> s1 >> s2;
    int n = s1.length();
    s1 = "#" + s1;
    s2 = "#" + s2;
    for (int i = 0; i < 26; i++) 
    for (int j = 0; j < 26; j++)
        a[i][j] = 0;
    for (int i = 1; i <= n; i++) {
        int x = s1[i] - 'a';
        int y = s2[i] - 'a';
        a[x][y] = 1;
    }
    set <ii> res;
    for (int i = 0; i < 26; i++) 
    for (int j = 0; j < 26; j++) 
        if (a[i][j] && i != j) {
            for (int k = 0; k < 26; k++)
                if (k != j) {
                    if (a[i][k] || a[k][i]) {
                    cout << -1;
                    return 0;
                }
                }
            for (int k = 0; k < 26; k++)
                if (k != i) {
                    if (a[k][j] || a[j][k]) {
                        cout << -1;
                        return 0;
                    }
                }
            if (find(all(res), ii(j, i)) == res.end()) {
                res.insert(ii(i, j));
            }
        }
    cout << res.size() << "\n";
    set <ii> :: iterator it;
    for (it = res.begin(); it != res.end(); it++) 
        cout << char(it->first + 'a') << " " << char(it->second + 'a') << "\n";
    return 0;
}
