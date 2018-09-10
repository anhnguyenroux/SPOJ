#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector <string> turn;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        turn.push_back(s);
    }
    set <string> fl;
    reverse(turn.begin(), turn.end());
    for (int i = 0; i < turn.size(); i++) {
        if (fl.find(turn[i]) == fl.end())
            cout << turn[i] << "\n", fl.insert(turn[i]);
    }
    return 0;
}
