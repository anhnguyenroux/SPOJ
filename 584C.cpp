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
const int nmax = 1e5 + 10;
int n, t;
char res[nmax];
string s1, s2;
char another(char x, char y) {
    for (char z = 'a'; z <= 'z'; z++)
        if (z != x && z != y) return z;
    return 'z';
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> t;
    cin >> s1 >> s2;
    int k = n - t;
    vector <int> same, diff;
    for (int i = 0; i < n; i++)
        res[i] = '#';
    for (int i = 0; i < n; i++)
        if (s1[i] == s2[i]) same.push_back(i);
        else diff.push_back(i);
    int q = same.size();
    if (k <= q) {
        for (int i = 0; i < k; i++) {
            int x = same[i];
            res[x] = s1[x];
        }
        for (int i = 0; i < n; i++)
            if (res[i] == '#') cout << another(s1[i], s2[i]);
            else cout << res[i];
    }
    else {
        if (n - q < 2 * (k - q)) {
            cout << -1;
            return 0;
        }
        for (int i = 0; i < q; i++) {
            int x = same[i];
            res[x] = s1[x];
        }
        for (int i = 1; i <= k - q; i++) {
            int x = diff.back(); diff.pop_back();
            int y = diff.back(); diff.pop_back();
            res[x] = s1[x];
            res[y] = s2[y];
        }
        for (int i = 0; i < n; i++)
            if (res[i] == '#') cout << another(s1[i], s2[i]);
            else cout << res[i];
    }
    return 0;
}
