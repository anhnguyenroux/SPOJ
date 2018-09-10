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
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    double p = (double) a / b;
    double q = (1 - (double) a / b) * (1 - (double) c / d);
    double res = p / (1 - q);
    printf("%0.6lf", res);
    return 0;
}
