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
struct song {
    int a, b;
};
int n;
int m;
song s[nmax];
ll fa[nmax], fb[nmax];
int cmp(song x, song y) {
    return ((x.a - x.b) > (y.a - y.b));
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) 
        scanf("%d %d", &s[i].a, &s[i].b);
    sort(s + 1, s + 1 + n, cmp);
    fa[0] = 0;
    fb[0] = 0;
    for (int i = 1; i <= n; i++) {
        fa[i] = fa[i - 1] + s[i].a;
        fb[i] = fb[i - 1] + s[i].b;
    }
    if (fb[n] > m) printf("-1");
    else {
        if (fa[n] <= m) printf("0");
        else {
            for (int i = 1; i <= n; i++) 
                if (fb[i] + fa[n] - fa[i] <= m) {
                    printf("%d", i);
                    return 0;
                }
        }
    }
    return 0;
}
