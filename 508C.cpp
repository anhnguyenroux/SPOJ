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
const int mmax = 310;
int m, t, r;
int w[mmax];
int mark[10000];
int cnt[10000];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    scanf("%d %d %d", &m, &t, &r);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &w[i]);
        w[i] += 300;
    }
    for (int i = 0; i < 1000; i++) mark[i] = 0;
    for (int i = 1; i <= m; i++) cnt[i] = 0;
    int res = 0;
    for (int i = 1; i <= m; i++) 
        while (cnt[w[i]] < r) {
            int g = w[i] - 1;
            while (mark[g]) g--;
            mark[g] = 1;
            res++;
            if (g + t < w[i]) {
                printf("-1");
                return 0;
            }
            for (int j = g + 1; j <= g + t; j++)
                cnt[j]++;
        }
    printf("%d", res);
    return 0;
}
