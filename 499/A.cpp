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
const int nmax = 55;
char s[nmax];
int n, k;
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    scanf("%d %d", &n, &k);
    scanf("%s", &s);
    sort(s, s + n);
    int res = s[0] - 'a' + 1;
    int cnt = 1;
    int cur = 0;
    if (cnt < k)
    for (int i = 1; i < n; i++) 
        if (abs(s[i] - s[cur]) >= 2) {
            res += s[i] - 'a' + 1;
            cnt++;
            cur = i;
            if (cnt == k) break;
        }
    if (cnt == k) printf("%d", res);
    else printf("-1");
    return 0;
}
