#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    if (s.length() == 1) {
        cout << 0;
        return 0;
    }
    int S = 0;
    for (int i = 0; i < s.length(); i++)
        S += s[i] - '0';
    int res = 1;
    while (!(S >= 0 && S <= 9)) {
        int tmp = S;
        int a = 0;
        while (tmp) {
            a += tmp % 10;
            tmp /= 10;
        }
        S = a;
        res++;
    }
    cout << res;
    return 0;
}
