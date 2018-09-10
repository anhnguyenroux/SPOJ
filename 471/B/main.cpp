#include <bits/stdc++.h>
#define IO ios::sync_with_stdio(false); cin.tie(0);
using namespace std;
const int nmax = 1e5 + 10;
int main() {
    IO;
    string s;
    cin >> s;
    set <char> a;
    set <char> :: iterator it;
    for (int i = 0; i < s.length(); i++)
        a.insert(s[i]);
    if (a.size() > 4) {
        cout << "No";
        return 0;
    }
    if (a.size() == 4) {
        cout << "Yes";
        return 0;
    }
    if (a.size() == 1) {
        cout << "No";
        return 0;
    }
    vector <char> v;
    for (it = a.begin(); it != a.end(); it++) v.push_back(*it);
    int c[nmax];
    for (int i = 0; i < s.length(); i++)
        for (int j = 0; j < v.size(); j++)
            if (s[i] == v[j]) c[j]++;
    if (a.size() == 3) {
        if (c[0] > 1 || c[1] > 1 || c[2] > 1) {
            cout << "Yes";
            return 0;
        }
        else {
            cout << "No";
            return 0;
        }
    }
    if (a.size() == 2) {
        if (c[0] >= 2 && c[1] >= 2) {
            cout << "Yes";
            return 0;
        }
        else {
            cout << "No";
            return 0;
        }
    }
    return 0;
}

