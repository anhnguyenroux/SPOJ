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
ll up1[26], up2[26], up3[26];
ll low1[26], low2[26], low3[26];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    ll n;
    cin >> n;
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int len = s1.length();
    ll a = 0, b = 0, c = 0;
    for (int i = 0; i < len; i++) {
        if (s1[i] >= 'a' && s1[i] <= 'z') low1[s1[i] - 'a']++;
        if (s1[i] >= 'A' && s1[i] <= 'Z') up1[s1[i] - 'A']++;
        if (s2[i] >= 'a' && s2[i] <= 'z') low2[s2[i] - 'a']++;
        if (s2[i] >= 'A' && s2[i] <= 'Z') up2[s2[i] - 'A']++;
        if (s3[i] >= 'a' && s3[i] <= 'z') low3[s3[i] - 'a']++;
        if (s3[i] >= 'A' && s3[i] <= 'Z') up3[s3[i] - 'A']++;
    }
    for (int i = 0; i < 26; i++) {
        a = max(a, low1[i]);
        a = max(a, up1[i]);
        b = max(b, low2[i]);
        b = max(b, up2[i]);
        c = max(c, low3[i]);
        c = max(c, up3[i]);
    }
    if (a + n <= len) a = a + n;
    else {
        a = len;
        if (n == 1) a--; 
    }
    if (b + n <= len) b = b + n;
    else {
        b = len;
        if (n == 1) b--;
    }
    if (c + n <= len) c = c + n;
    else {
        c = len;
        if (n == 1) c--;
    }
    ll res = max(a, max(b, c));
    if (res == a) {
        if (res != b && res != c) cout << "Kuro";
        else cout << "Draw";
    }
    else
    if (res == b) {
        if (res != a && res != c) cout << "Shiro";
        else cout << "Draw";
    }
    else 
    if (res == c) {
        if (res != a && res != b) cout << "Katie";
        else cout << "Draw";
    }
    return 0;
}
