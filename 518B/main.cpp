#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 10;
string s1, s2;
int c[256];
int fre[MAX];
int main() {
    cin >> s1;
    cin >> s2;
    for (int i = 0; i < s2.length(); i++) c[s2[i]]++;
    for (int i = 0; i < s1.length(); i++) fre[i] = 1;
    int t1 = 0, t2 = 0;
    for (int i = 0; i < s1.length(); i++) {
        if (c[s1[i]]) c[s1[i]]--, t1++, fre[i] = 0;
    }
    for (int i = 0; i < s1.length(); i++)
    if (fre[i]) {
        int tmp;
        if (s1[i] >= 'a' && s1[i] <= 'z') tmp = s1[i] - 32;
        else tmp = s1[i] + 32;
        if (c[tmp]) c[tmp]--, t2++;
    }
    cout << t1 << " " << t2;
    return 0;
}
