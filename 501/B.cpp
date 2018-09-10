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
string s1, s2;
int ch1[26], ch2[26];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n;
    cin >> s1 >> s2;
    s1 = "#" + s1;
    s2 = "#" + s2;
    for (int i = 1; i <= n; i++) {
        ch1[s1[i] - 'a']++;
        ch2[s2[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) 
        if (ch1[i] != ch2[i]) {
            cout << -1;
            return 0;
        }
    vector <int> res;
    for (int i = 1; i <= n; i++)
        if (s2[i] == s1[i]) continue;
        else {
            int pos = i;
            while (s1[pos] != s2[i] && pos <= n) pos++;
            for (int j = pos - 1; j >= i; j--) {
                res.push_back(j);
                swap(s1[j], s1[j + 1]);
            }
        }
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    return 0;
}
