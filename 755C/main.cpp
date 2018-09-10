#include <bits/stdc++.h>
using namespace std;
const int NMAX  =   1e4 + 10;
int main() {
    int n;
    cin >> n;
    vector <int> p;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (x == i) res++;
        else p.push_back(x);
    }
    sort(p.begin(), p.end());
    int cnt = 1;
    for (int i = 1; i < p.size(); i++)
        if (p[i] != p[i - 1]) cnt++;
    cout << res + (cnt / 2);
    return 0;
}
/*
    for every p[i] = i => tree has 1 node
    we can prove that a tree would only have 2 last nodes, suppose they are A and B.
    for every node in that tree will only have 2 value, they are A and B.
    So we can count the distinct values and then divide it by 2.
*/
