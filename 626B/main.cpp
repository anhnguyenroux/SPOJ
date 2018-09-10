#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int dB = 0, dR = 0, dG = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'B') dB++;
        if (s[i] == 'R') dR++;
        if (s[i] == 'G') dG++;
    }
    set <string> r;
    set <string> :: iterator t;
    if (dB >= 1 && dR >= 1 && dG >= 1) cout << "BGR";
    if (dB == 0 && dR > 1 && dG > 1) cout << "BGR";
    if (dR == 0 && dB > 1 && dG > 1) cout << "BGR";
    if (dG == 0 && dR > 1 && dB > 1) cout << "BGR";

    if (dB > 0 && dR == 0 && dG == 0) cout << "B";
    if (dR > 0 && dB == 0 && dG == 0) cout << "R";
    if (dG > 0 && dR == 0 && dB == 0) cout << "G";

    if (dB == 1 && dR == 1 && dG == 0) cout << "G";
    if (dB == 1 && dG == 1 && dR == 0) cout << "R";
    if (dR == 1 && dG == 1 && dB == 0) cout << "B";

    if (dB > 1 && dR == 1 && dG == 0) cout << "GR";
    if (dR > 1 && dB == 1 && dG == 0) cout << "BG";
    if (dG > 1 && dB == 1 && dR == 0) cout << "BR";
    return 0;
}
