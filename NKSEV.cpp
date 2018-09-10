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
const int modulo = 1337377;
const int nmax = 300010;
struct node {
    node* c[26];
    int u;
};
node* getnode() {
    node* newnode = new node;
    for (int i = 0; i < 26; i++)
        newnode->c[i] = NULL;
    newnode->u = 0;
    return newnode;
}
string s;
int n;
node* root;
int f[nmax];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> s;
    n = s.length();
    s = "#" + s;
    int m;
    cin >> m;
    root = getnode();
    for (int i = 1; i <= m; i++) {
        string x;
        cin >> x;
        node* p;
        p = root;
        for (int i = 0; i < x.length(); i++) {
            int index = x[i] - 'a';
            if (p->c[index] == NULL) p->c[index] = getnode();
            p = p->c[index];
        }
        p->u = 1;
    }
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        f[i] = 0;
    for (int i = 1; i <= n; i++) {
        node* p;
        p = root;
        for (int j = i; j <= n; j++) {
            int index = s[j] - 'a';
            if (p->c[index] == NULL) break;
            p = p->c[index];
            if (p->u == 1) f[j] = (f[j] + f[i - 1]) % modulo;
        }
    }
    cout << f[n];
    return 0;
}
