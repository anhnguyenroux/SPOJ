#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int NMAX      =   1e5 + 10;
string a, b;
int n;
int nxt[2 * NMAX];
int main() {
    cin >> a;
    cin >> b;
    string s = b + "#" + a;
    nxt[0] = 0;
    int j = 0, i = 1;
    int n = s.length();
    while (i < n) {
        while (j > 0 && s[j] != s[i]) {
            j = nxt[j - 1];
        }
        if (s[j] == s[i]) {
            nxt[i] = ++j;
            i++;
        }
        else {
            nxt[i] = 0;
            i++;
        }
    }
    
    int pos = nxt[n - 1];
    cout << a + b.substr(pos, b.length() - pos);
    return 0;
}