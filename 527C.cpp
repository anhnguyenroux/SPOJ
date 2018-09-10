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
int w, h;
int n;
set <int> wi, he;
multiset <int> qw, qh;
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
    cin >> w >> h >> n;
    wi.insert(0); wi.insert(w);
    he.insert(0); he.insert(h);
    qw.insert(w);
    qh.insert(h);
    set <int> :: iterator i, j, k;
    while (n-- > 0) {
        string ty; 
        int x;
        cin >> ty >> x;
        if (ty[0] == 'H') {
            if (he.find(x) == he.end()) {
                he.insert(x);
                j = he.find(x);
                i = j;
                k = j;
                i--;
                k++;
                //cout << *i << " " << *j << " " << *k << "\n";
                qh.erase(qh.find(*(k) - *(i)));
                qh.insert(*(j) - *(i));
                qh.insert(*(k) - *(j));
            }
        }
        if (ty[0] == 'V') {
            if (wi.find(x) == wi.end()) {
                wi.insert(x);
                j = wi.find(x);
                i = j;
                k = j;
                i--;
                k++;
                //cout << *i << " " << *j << " " << *k << "\n";
                qw.erase(qw.find(*(k) - *(i)));
                qw.insert(*(j) - *(i));
                qw.insert(*(k) - *(j));
            }
        }
        /*
        set <int> :: iterator it;
        for (it = qw.begin(); it != qw.end(); it++)
            cout << *it << " ";
        cout << "\n";
        for (it = qh.begin(); it != qh.end(); it++)
            cout << *it << " ";
        cout << "\n";
        */
        ll mh =*--qh.end();
        ll mw =*--qw.end();
        cout << mh * mw << "\n";
    }
    return 0;
}
