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
    string a, b;
    cin >> a >> b;
    if (a.length() != b.length()) {
        cout << "NO";
        return 0;
    }
    int n = a.length();
    bool res = 1;
    int d = 0, z = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '1') d++;
        if (b[i] == '0') z++;
        if (a[i] != b[i]) res = 0;
    }
    if (res) cout << "YES"; 
    else {
        if (d > 0 && z != n) cout << "YES";
        else cout << "NO"; 
    }
    return 0;
}
