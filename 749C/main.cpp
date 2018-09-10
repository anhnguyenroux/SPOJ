#include <bits/stdc++.h>
using namespace std;
const int MAX   =   2e5 + 10;
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    deque <int> d;
    deque <int> r;
    for (int i = 0; i < n; i++)
        if (s[i] == 'D') d.push_back(i); else r.push_back(i);
    while (!d.empty() && !r.empty()) {
        int ud = d.front();
        int ur = r.front();
        //cout << ud << " " << ur << "\n";
        r.pop_front();
        d.pop_front();
        if (ud < ur) d.push_back(ud + n); else r.push_back(ur + n);
    }
    if (d.empty()) cout << "R"; else cout << "D";
    return 0;
}
