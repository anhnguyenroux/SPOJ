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
const int MAX = 110;
const int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int n, m;
string s[MAX];
int check(int i, int j) {
    int res = 0;
    for (int k = 0; k < 8; k++) {
        int u = i + dx[k];
        int v = j + dy[k];
        if (u >= 0 && u < n && v >= 0 && v < m && s[u][v] == '*') res++;
    }
    return res;
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];
    if (n == 1 && m == 1 && s[0][0] == '.') {
        cout << "YES";
        return 0;
    }
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
        if (s[i][j] == '*') continue;
        if (s[i][j] == '.' && check(i, j) != 0) {
            cout << "NO";
            return 0;
        }
        if (s[i][j] != '.')  
            if ((s[i][j] - '0') != check(i, j)) {
                cout << "NO";
                return 0;
            }
    } 
    cout << "YES";
    return 0;
}
