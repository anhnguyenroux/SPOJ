#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0);
#define all(v) (v).begin(), (v).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pi;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
int main() {
    IO;
    int n;
    cin >> n;
    string s;
    cin >> s;
    int dA = 0, dF = 0, dI = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') dA++;
        if (s[i] == 'F') dF++;
        if (s[i] == 'I') dI++; 
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) 
        if (s[i] == 'A' || s[i] == 'I') {
            if (s[i] == 'A' && dA - 1 + dF == n - 1) cnt++;
            if (s[i] == 'I' && dA + dF == n - 1) cnt++; 
        }
    cout << cnt;
    return 0;
}
