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
string a, b;
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n;
    cin >> a;
    cin >> b;
    a = "#" + a, b = "#" + b;
    int cnt = 0;
    for (int i = 1; i <= n / 2; i++) {
        set <char> s;
        s.insert(a[i]);
        s.insert(a[n - i + 1]);
        s.insert(b[i]);
        s.insert(b[n - i + 1]);
        int sl = s.size();
        if (sl == 2) {
            int c[26];
            for (int i = 0; i < 26; i++) c[i] = 0;
            c[a[i] - 'a']++;
            c[a[n - i + 1] - 'a']++;
            c[b[i] - 'a']++;
            c[b[n - i + 1] - 'a']++;
            for (int i = 0; i < 26; i++) 
                if (c[i] == 3) {
                    cnt++;
                    break;
                }
        }
        if (sl == 3) {
            if (a[i] == a[n - i + 1]) cnt += 2;
            else cnt += 1;
        }
        if (sl == 4) cnt += 2;
    }
    if (n % 2 == 1) 
        if (a[n / 2 + 1] != b[n / 2 + 1]) cnt++;
    cout << cnt;
    return 0;
}
