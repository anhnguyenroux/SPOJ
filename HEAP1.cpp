/*
    HEAP1 : http://vn.spoj.com/problems/HEAP1/
    Explanation and Complexity are below
*/
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
void process() {
    int N;
    cin >> N;
    priority_queue <ll, vector <ll>, greater <ll> > q;
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        q.push(x);
    }
    ll res = 0;
    while (q.size() != 1) {
        ll x1 = q.top();
        q.pop();
        ll x2 = q.top();
        q.pop();
        res += x1 + x2;
        q.push(x1 + x2);
    }
    cout << res << "\n";
}
int main() {
    int test;
    cin >> test;
    while (test-- > 0) 
        process();
    return 0;
}
/*
    We put all the element in a min - heap. 
    For each step, we choose 2 smallest elements and then add them to the result, delete them and adding the sum of 2 element in to heap.
    Complexity : O(NlogN);
*/