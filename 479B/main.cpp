#include <bits/stdc++.h>
using namespace std;
const int nmax = 110;
typedef pair <int, int> ii;
int a[nmax];
vector <ii> oper;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << 0 << " " << 0;
        return 0;
    }
    int res;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int t = 1; t <= k; t++) {
        int pos_max = 0, pos_min = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > a[pos_max]) pos_max = i;
            if (a[i] < a[pos_min]) pos_min = i;
        }
        res = a[pos_max] - a[pos_min];
        if (res <= 1) break;
        a[pos_max]--;
        a[pos_min]++;
        oper.push_back(ii(pos_max + 1, pos_min + 1));
    }
    int pmax = 0, pmin = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > a[pmax]) pmax = i;
        if (a[i] < a[pmin]) pmin = i;
    }
    cout <<  a[pmax] - a[pmin] << " " << oper.size() << "\n";
    for (int i = 0; i < oper.size(); i++)
        cout << oper[i].first << " " << oper[i].second << "\n";
    return 0;
}
