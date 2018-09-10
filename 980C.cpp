#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0);
#define all(v) (v).begin(), (v).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const int nmax = 1e5 + 10;
int n, k;
int a[nmax];
int fre[256];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i < 256; i++) fre[i] = -1;
    for (int i = 1; i <= n; i++) 
    if (fre[a[i]] == -1) {
        int x = a[i];
        for (int j = x - 1; j >= max(0, x - k + 1); j--) 
            if (fre[j] != -1 && (!j || fre[j - 1] != fre[j])) {
                for (int y = j + 1; y <= x; y++)
                    fre[y] = j;
                break;
            }
        if (fre[x] == -1) {
            for (int j = max(0, x - k + 1); j <= x; j++)
                if (fre[j] == -1) {
                    for (int y = j; y <= x; y++)
                        fre[y] = j;
                    break;
                }
        }
    }
    for (int i = 1; i <= n; i++) cout << fre[a[i]] << " ";
    return 0;
}
