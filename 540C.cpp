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
const int nmax = 510;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
int n, m;
char a[nmax][nmax];
int r1, c1, r2, c2;
int fre[nmax][nmax];
int bfs() {
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) 
        fre[i][j] = 1;
    fre[r1][c1] = 0;
    queue <ii> q;
    q.push(ii(r1, c1));
    while (!q.empty()) {
        ii cur = q.front(); q.pop();
        int u = cur.fi;
        int v = cur.se;
        for (int k = 0; k < 4; k++) {
            int u1 = u + dx[k];
            int v1 = v + dy[k];
            if (u1 >= 0 && u1 < n && v1 >= 0 && v1 < m) {
                if (u1 == r2 && v1 == c2) return 1;
                if (a[u1][v1] == '.' && fre[u1][v1]) {
                    fre[u1][v1] = 0;
                    q.push(ii(u1, v1));
                }
            }
        }
    }
    return 0;
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) 
            a[i][j] = s[j];
    }
    cin >> r1 >> c1;
    cin >> r2 >> c2;
    c1--; r1--; r2--; c2--;
    if (r1 == r2 && c1 == c2) {
        for (int k = 0; k < 4; k++) {
            int u = r1 + dx[k];
            int v = c1 + dy[k];
            if (a[u][v] == '.') {
                cout << "YES";
                return 0;
            }
        }
        cout << "NO";
        return 0;
    }
    if (abs(r2 - r1) + abs(c2 - c1) == 1) {
        if (a[r2][c2] == 'X') {
            cout << "YES";
            return 0;
        }
        else {
            for (int k = 0; k < 4; k++) {
                int u = r2 + dx[k];
                int v = c2 + dy[k];
                if (a[u][v] == '.') {
                    cout << "YES";
                    return 0;
                }
            }
            cout << "NO";
            return 0;
        }
    }
    if (bfs()) {
        if (a[r2][c2] == 'X') cout << "YES";
        else {
            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                int u = r2 + dx[k];
                int v = c2 + dy[k];
                if (a[u][v] == '.') cnt++;
            }
            if (cnt > 1) cout << "YES";
            else cout << "NO";
        }
    }
    else cout << "NO";
    return 0;
}
