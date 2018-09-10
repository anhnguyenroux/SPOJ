#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int nmax = 1e5 + 10;
struct ord {
    int pos, v;
};
int n;
ord a[nmax];
int m;
int cmp(ord a, ord b) {
    return a.v < b.v;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].v;
        a[i].pos = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    cin >> m;
    ll r1 = 0, r2 = 0;
    for (int i = 1; i <= m; i++) {
        int v; cin >> v;
        int left = 1, right = n;
        int ans = -1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (a[mid].v == v) {
                ans = mid;
                break;
            }
            if (a[mid].v > v) right = mid - 1; else left = mid + 1;
        }
        r1 += a[ans].pos;
        r2 += n - a[ans].pos + 1;
    }
    cout << r1 << " " << r2;
    return 0;
}
