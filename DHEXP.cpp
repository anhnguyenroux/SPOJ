/*
    DHEXP : http://vn.spoj.com/problems/DHEXP/
    Explanation and Complexity are below
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int NMAX      =   1e5 + 10;
int N, k;
int a[NMAX];
int cmp(int x, int y) {
    return x > y;
}
void process() {
    cin >> N >> k;
    for (int i = 0; i < N; i++)
        cin >> a[i];
    sort(a + 1, a + N, cmp);
    long long res = a[0];
    for (int i = 1; i < N; i++) {
        if (k > 0) {
            res += a[i];
            k--;
        }
        else res -= a[i];
    }
    cout << res;
}
int main() {
    process();
    return 0;
}
/*
    We will greedy k maximum value of the array to add "+", the others we will put "-" 
    Sort the array from 2 to N (not from 1 to N because the first value is default with "+") in descending order. 
    Complexity : O(NlogN)
*/