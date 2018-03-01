#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int NMAX      =   1010;   
const int KMAX      =   110;
int n, m, k;
string s1;
int main() {
    int res = NMAX;
    cin >> n >> m >> k;
    cin >> s1;
    string s2;
    for (int i = 1; i <= k; i++) {
        cin >> s2;
        int first = 0;
        do {
            int count = 0;
            for (int x = 0; x < m; x++) {
                int loc = first + x;
                if (first + x > n - 1) loc -= n;
                if (s1[loc] != s2[x]) count++;
            }
            res = min(res, count);
            first++;
            if (first == n) first = 0;
        } while (first != 0);
    }
    cout << res;
    return 0;
}