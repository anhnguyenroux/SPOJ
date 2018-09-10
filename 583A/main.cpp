#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> ii;
typedef long long ll;
const int nmax = 3e5 + 10;
struct ord {
    int pos, c;
};
int n, k;
ord a[nmax];
int newtime[nmax];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].c;
        a[i].pos = i;
    }
    priority_queue <ii> q;
    for (int i = 1; i <= k; i++) q.push(ii(a[i].c, a[i].pos));
    int time;
    ll res = 0;
    for (time = k + 1; time <= n; time++) {
        q.push(ii(a[time].c, a[time].pos));
        ii choose = q.top(); q.pop();
        res += (ll) choose.first * (time - choose.second);
        newtime[choose.second] = time;
    }
    while (!q.empty()) {
        ii choose = q.top(); q.pop();
        res += (ll) choose.first * (time - choose.second);
        newtime[choose.second] = time;
        time++;
    }
    cout << res << "\n";
    for (int i = 1; i <= n; i++)
        cout << newtime[i] << " ";
    return 0;
}
/*
    The solution is greedy.
    We will choose the maximum cost in k moments.
*/
