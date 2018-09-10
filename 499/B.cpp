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
const int nmax = 110;
int n, m;
int a[nmax], b[nmax];
int cmp(int x, int y) {
    return x > y;
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= 100; i++) b[i] = 0;
    for (int i = 1; i <= m; i++) {
        int x;
        scanf("%d", &x);
        b[x]++;
    }
    sort(b + 1, b + 1 + 100, cmp);
    int res = 0;
    for (int x = 1; x <= 100; x++) {
        for (int i = 1; i <= 100; i++) a[i] = b[i];
        int food = 1;
        for (int i = 1; i <= n; i++) {
            int flag = 0;
            for (int j = 1; j <= 100; j++)
                if (a[j] >= x) {
                    a[j] -= x;
                    flag = 1;
                    break;
                } 
            if (flag == 0) {
                food = 0;
                break;
            }
        }
        if (food) res = max(res, x);
    }
    printf("%d", res);
    return 0;
}
