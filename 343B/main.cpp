#include <bits/stdc++.h>
using namespace std;
const int nmax = 1e5 + 10;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    stack <char> st;
    st.push(s[0]);
    for (int i = 2; i <= n; i++) {
        if (!st.empty() && s[i - 1] == st.top()) {
            st.pop();
        }
        else st.push(s[i - 1]);
    }
    if (!st.empty()) cout << "NO"; else cout << "YES";
    return 0;
}
