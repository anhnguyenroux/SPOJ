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
string s;
vector <int> a;
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> s;
    for (int i = 0; i < s.length(); i++)
        a.push_back((s[i] - '0') % 3);
    int n = a.size();
    int res = 0;
    int i = 0;
    while (i < n)
        if (a[i] == 0) {
            res++;
            i++;
        }
        else {
            int j = i + 1;
            int z1 = 0;
            while (a[j] == 0 && j < n) {
                j++;
                z1++;
            }
            int k = j + 1;
            int z2 = 0;
            while (a[k] == 0 && k < n) {
                k++;
                z2++;
            }
            if (k > n) k--;
            if ((a[i] + a[j] + a[k]) % 3 == 0) res++;
            else 
                if ((a[i] + a[j]) % 3 == 0) res += 1 + z2;
                else 
                    if ((a[j] + a[k]) % 3 == 0) res += 1 + z1;
            if (j == k) res--;
            i = k + 1;
        }
    cout << res;
    return 0;
}
