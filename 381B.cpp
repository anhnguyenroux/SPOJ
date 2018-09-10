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
const int vmax = 5000 + 10;
int n;
int a[nmax];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    deque <int> st;
    for (int i = n - 1; i >= 0; i--) {
        if (st.empty()) st.push_back(a[i]);
        else {
            if (a[i] < st.front()) st.push_front(a[i]);
            else 
                if (a[i] < st.back()) st.push_back(a[i]);
        }
    }
    cout << st.size() << "\n";
    while (!st.empty()) {
        cout << st.back() << " ";
        st.pop_back();
    }
    return 0;
}
