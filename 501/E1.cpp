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
const int nmax = 110;
struct star {
    int x, y, l;
};
int n, m;
string s[nmax];
string s1[nmax];
vector <star> res;
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = "#" + s[i];
        s1[i] = s[i];
    }
    for (int i = 1; i <= n; i++) 
    for (int j = 1; j <= m; j++) 
        if (s[i][j] == '*') {
            int len = 1;
            int found = 0;
            while (i + len <= n && j + len <= m && i - len >= 1 && j - len >= 1) {
                if (s[i][j - len] == '*' && s[i + len][j] == '*' && s[i - len][j] == '*' && s[i][j + len] == '*') {
                    s1[i][j] = '.';
                    s1[i][j - len] = '.';
                    s1[i + len][j] = '.';
                    s1[i - len][j] = '.';
                    s1[i][j + len] = '.';
                    len++;
                    found = 1;
                }
                else break;
            }
            if (found) {
                star a;
                a.x = i;
                a.y = j;
                a.l = len - 1;
                res.push_back(a);
            }
        }
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        if (s1[i][j] == '*') {
            cout << "-1";
            return 0;
        }
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++)
        cout << res[i].x << " " << res[i].y << " " << res[i].l << "\n";
    return 0;
}
