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
typedef pair<int, ll> il;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const int nmax = 1010;
const int pmax = 1e5;
int n, s;
ll ord[2][pmax + 10];
vector <il> buy, sell;
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> s;
    map <int, int> buy, sell;
    for (int i = 1; i <= n; i++) {
        string d;
        int p, q;
        cin >> d >> p >> q;
        if (d[0] == 'B') buy[p] += q;
        else sell[p] += q;
    }
    while (sell.size() > s) sell.erase(--sell.end());
    while (buy.size() > s) buy.erase(buy.begin());
    map <int, int> :: iterator it;
    for (it = sell.begin(); it != sell.end(); it++) 
        cout << "S" << " " << it->fi << " " << it->se << "\n";
    for (it = buy.begin(); it != buy.end(); it++) 
        cout << "B" << " " << it->fi << " " << it->se << "\n";
    return 0;
}
