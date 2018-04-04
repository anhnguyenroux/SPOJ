#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int NMAX          =   50010;
int n;
string a;
string s;
int next[NMAX];
string preProcess(string s, int &n) {
    string res;
    if (n == 0) return "$#";
    res = "$";
    for (int i = 0; i < n; i++) {
        res += "#" + s.substr(i, 1);
    }
    res += "#$";
    n = res.length();
    return res;
}
int LongestPalindrome(string s, int n) {
    int* f = new int[n];
    int C = 0, R = 0;
    int res = 0;
    for (int i = 1; i < n - 1; i++) {
        int j = 2 * C - i;
        f[i] = (R > i) ? min(f[j], R - i) : 0;
        while (s[i + 1 + f[i]] == s[i - 1 - f[i]]) 
            f[i]++;
        if (i + f[i] > R) {
            C = i;
            R = i + f[i];
        }
        res = max(res, f[i]);
    }
    delete[] f;
    return res;
}
int main() {
    cin >> n;
    cin >> s;
    a = preProcess(s, n);
    cout << LongestPalindrome(a, n);
    return 0;
}