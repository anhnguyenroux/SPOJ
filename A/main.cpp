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
const int nmax = 1e3 + 10;
int n;
char s[nmax][nmax];
bool compare(char s1[], char s2[]) {
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    if (l1 != l2) return 0;
    for (int i = 0; i < l1; i++)
        if (s1[i] != s2[i]) return 0;
    return 1;
}
int cmp(char s1[], char s2[]) {
    int lmin = min(strlen(s1), strlen(s2));
    for (int i = 0; i < lmin; i++)
        if (s1[i] != s2[i]) return (s1[i] < s2[i]);
    if (strlen(s1) != strlen(s2)) return strlen(s1) < strlen(s2);
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char x[nmax];
        scanf("%s", &x);
        int c[26] = {0};
        int len = 0;
        for (int j = 0; j < strlen(x); j++)
            if (c[x[j] - 'a'] == 0) {
                c[x[j] - 'a'] = 1;
                s[i][len] = x[j];
                len++;
            }
        sort(s[i], s[i] + len);
        s[i][len] = '\0';
    }
    sort(s, s + n, cmp);
    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
        if (compare(s[i], s[i + 1]) == 0) cnt++;
    printf("%d", cnt + 1);
    return 0;
}

