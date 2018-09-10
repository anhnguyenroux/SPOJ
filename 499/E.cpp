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
int n, k;
int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    scanf("%d %d", &n, &k);
    int g = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        g = gcd(g, x);
    }
    set <ll> res;
    for (int i = 1; i <= k; i++) 
        res.insert((1ll * i * g) % k);
    printf("%d\n", res.size());
    set <ll> :: iterator it;
    for (it = res.begin(); it != res.end(); it++) 
        printf("%d ", *it);
    return 0;
}
