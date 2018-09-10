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
const int MAX = 1010;
int n, m;
int a[MAX][MAX];
vector <int> row[MAX], col[MAX];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
        cin >> a[i][j];
        if (a[i][j]) {
            row[i].push_back(j);
            col[j].push_back(i);
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) 
    for (int j = 0; j < m; j++)
        if (a[i][j] == 0) {
            int rsz = row[i].size();
            int csz = col[j].size();
            if (rsz > 0)
            if (j < row[i][0] || j > row[i][rsz - 1]) res++;
            else {
                for (int t = 0; t < row[i].size() - 1; t++)
                    if (row[i][t] < j && j < row[i][t + 1]) {
                        res += 2;
                        break;
                    }
            }
            if (csz > 0)
            if (i < col[j][0] || i > col[j][csz - 1]) res++;
            else {
                int sz = col[j].size();
                for (int t = 0; t < sz - 1; t++)
                    if (col[j][t] < i && i < col[j][t + 1]) {
                        res += 2;
                        break;
                    }
            }
        }
    cout << res;
    return 0;
}
