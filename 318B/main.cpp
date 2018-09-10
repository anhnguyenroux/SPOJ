#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9;
const int nmax = 1e6 + 10;
ll hashS[nmax];
ll hash1, hash2;
ll P[nmax];
int f1[nmax], f2[nmax];
ll gethash(int i, int j) {
    ll res = (hashS[j] - hashS[i - 1] * P[j - i + 1] + (ll) MOD * MOD) % MOD;
    return res;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    s = "#" + s;
    string a1 = "heavy";
    string a2 = "metal";
    P[0] = 1;
    for (int i = 1; i <= max(n, 5); i++) P[i] = (P[i - 1] * 26) % MOD;
    hashS[0] = 0;
    for (int i = 1; i <= n; i++) hashS[i] = (hashS[i - 1] * 26 + s[i] - 'a') % MOD;
    hash1 = 0, hash2 = 0;
    for (int i = 0; i < 5; i++) {
        hash1 = (hash1 * 26 + a1[i] - 'a') % MOD;
        hash2 = (hash2 * 26 + a2[i] - 'a') % MOD;
    }
    for (int i = 0; i <= 4; i++) f1[i] = 0, f2[i] = 0;
    for (int i = 5; i <= n; i++) {
        if (gethash(i - 5 + 1, i) == hash1) f1[i] = f1[i - 5 + 1] + 1;
        else f1[i] = f1[i - 1];
        if (gethash(i - 5 + 1, i) == hash2) f2[i] = f2[i - 5 + 1] + 1;
        else f2[i] = f2[i - 1];
    }
    ll cnt = 0;
    for (int i = 5; i <= n; i++) {
        if (gethash(i - 5 + 1, i) == hash1) cnt += f2[n] - f2[i];
    }
    cout << cnt;
    return 0;
}
