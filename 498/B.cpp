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
const int nmax = 2010;
struct pl {
    int v;
    int pos;
};
int n, k;
int a[nmax];
pl b[nmax];
int fre[nmax];
int cmp(pl x, pl y) {
    return (x.v > y.v);
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
        b[i].v = a[i];
        b[i].pos = i;
    }
    sort(b + 1, b + 1 + n, cmp);
    for (int i = 1; i <= n; i++) fre[i] = 0;
    for (int i = 1; i <= k; i++)
        fre[b[i].pos] = 1;
    int sum = 0;
    vector <int> ret;
    int cur = 0;
    for (int i = 1; i <= n; i++) 
        if (fre[i]) {
            sum += a[i];
            ret.push_back(cur + 1);
            cur = 0;
        }
        else cur++;
    if (cur > 0) ret[ret.size() - 1] += cur;
    printf("%d\n", sum);
    for (int i = 0; i < ret.size(); i++) 
        printf("%d ", ret[i]);
    return 0;
}
