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
int n;
int a[nmax], b[nmax];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    for (int i = 1; i <= n; i++) 
        b[i] = sum / n;
    for (int i = 1; i <= sum % n; i++)
        b[i]++;
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    int res = 0;
    for (int i = 1; i <= n; i++)
        res += abs(a[i] - b[i]);
    printf("%d", res / 2);
    return 0;
}
