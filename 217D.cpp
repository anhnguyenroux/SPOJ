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
const int nmax = 1600;
struct node {
    node* c[26];
    int u;
};
struct Trie {
    node* root;
    node* getnode() {
        node* newnode = new node;
        for (int i = 0; i < 26; i++)
            newnode->c[i] = NULL;
        newnode->u = 0;
        return newnode;
    }
};
string s;
int n, k;
string t;
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.inp", "r", stdin);
		freopen("output.out", "w", stdout);
	#endif
    cin >> s;
    n = s.length();
    s = "#" + s;
    cin >> t;
    cin >> k;
    Trie* T = new Trie;
    T->root = T->getnode();
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        node* p;
        p = T->root;
        for (int j = i; j <= n; j++) {
            int index = s[j] - 'a';
            cnt += (t[s[j] - 'a'] == '0');
            if (p->c[index] == NULL) p->c[index] = T->getnode();
            p = p->c[index];
            p->u++;
            //cout << i << " " << j << " " << p->u << " " << cnt << "\n";
            if (p->u == 1 && cnt <= k) {
                //cout << "!" << "\n";
                res++;
                //cout << "!" << i << " " << j << " " << p->u << " " << cnt << "\n";
            }
        }
    }
    cout << res;
    return 0;
}