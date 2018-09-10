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
    string s;
    cin >> s;
    int t = 0;
    int carry = 0;
    char obj = '#';
    for (int i = 0; i < s.length(); i++) {
        if (obj == '#') {
            carry++;
            obj = s[i];
        }
        else {
            if (obj != s[i]) {
                t++;
                carry = 1;
                obj = s[i];
            }
            else 
                if (carry < 5) {
                    carry++;
                }
                else {
                    t++;
                    carry = 1;
                    obj = s[i];
                }
        }
    }
    if (carry > 0) t++;
    cout << t;
    return 0;
}
