/*
    C11ID : http://vn.spoj.com/problems/C11ID
    Explanation and Complexity are below
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int NMAX      =   1e5 + 10;
const int modulo    =   1e9 + 7;
int N; 
int a[NMAX];
void process() {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> a[i];
    sort(a, a + N);
    long long res = a[0];
    for (int i = 1; i < N; i++)
        res = (res * (a[i] - i) % modulo) % modulo;
    cout << res;
}
int main() {
    process();
    return 0;
}
/*
    We sort the array by ascending order which mean we will allocate ID for each person from lowest to highest. 
    For example : 
        a_i < a_i+1 < a_i+2 
    there are a_i * (a_i+1 - 1) * (a_i+2 - 1) ways to allocate ID for each person.
    Complexity : O(NlogN)
*/