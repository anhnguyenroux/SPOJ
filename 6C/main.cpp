#include <bits/stdc++.h>
using namespace std;
const int nmax = 1e5 + 10;
int main() {
    int n;
    cin >> n;
    int t[nmax];
    for (int i = 1; i <= n; i++) cin >> t[i];
    int i = 1, j = n;
    int s1 = 0, s2 = 0;
    int r1 = 0, r2 = 0;
    while (i <= j) {
        //if (s1 == s2) s1 += t[i], i++, r1++;
        while (s1 <= s2 && i <= j) s1 += t[i], i++, r1++;
        while (s2 < s1 && i <= j) s2 += t[j], j--, r2++;
    }
    cout << r1 << " " << r2;
    return 0;
}
