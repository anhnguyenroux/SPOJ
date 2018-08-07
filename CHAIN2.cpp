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
struct node {
    int f, u;
    node* c[26];
};
struct Trie {
    node* root;
    node* getnode() {
        node* newnode = new node;
        for (int i = 0; i < 26; i++)
            newnode->c[i] = NULL;
        newnode->f = 0;
        newnode->u = 0;
        return newnode;
    }
    void insert(string x) {
        node* p;
        p = root;
        for (int i = 0; i < x.length(); i++) {
            int index = x[i] - 'a';
            if (p->c[index] == NULL) p->c[index] = getnode();
            p = p->c[index];
        }
        p->u = 1;
    }
};
void dfs(node* p) {
    for (int i = 0; i < 26; i++)
        if (p->c[i] != NULL) {
            dfs(p->c[i]);
            p->f = max(p->f, p->c[i]->f);
        }
    p->f += p->u;
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    int n;
    cin >> n;
    Trie* T = new Trie;
    T->root = T->getnode();
    for (int i = 1; i <= n; i++) {
        string x;
        cin >> x;
        T->insert(x);
    }
    dfs(T->root);
    cout << T->root->f;
    return 0;
}
