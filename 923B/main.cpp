#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int nmax = 1e5 + 10;
int n;
ll a[nmax], t[nmax];
ll f[nmax], p[nmax];
ll m[nmax];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    t[0] = 0;
    for (int i = 1; i <= n; i++) cin >> t[i], t[i] += t[i - 1];
    for (int i = 1; i <= n; i++) {
        f[i] = 0;
        m[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        int left = i, right = n;
        int j = n + 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (t[mid] > t[i - 1] + a[i]) {
                j = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }
        f[j]--;
        f[i]++;
        m[j] += a[i] - (t[j - 1] - t[i - 1]);
    }
    for (int i = 1; i <= n; i++)
        f[i] += f[i - 1];
    for (int i = 1; i <= n; i++)
        cout << f[i] * (t[i] - t[i - 1]) + m[i] << " ";
    return 0;
}
