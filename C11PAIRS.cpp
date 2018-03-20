/*
    C11PAIRS : vn.spoj.com/problems/C11PAIRS
    Explanation and Complexity are below
*/
#include <iostream>
#include <stack>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
int N;
void process() {
    cin >> N;
    stack <ii> S;
    ll res = 0;
    for (int i = 1; i <= N; i++) {
        int x; 
        cin >> x;
        while (!S.empty() && S.top().first < x) {
            res += S.top().second;
            S.pop();
        }
        if (!S.empty()) {
            if (x == S.top().first) {
                res += S.top().second;
                S.top().second++;
                if (S.size() > 1) res++;
            }
            else {
                res++;
                S.push(ii(x, 1));
            }
        }
        else S.push(ii(x, 1));
    }
    cout << res;
}
int main() {
    process();
    return 0;
}
/*
    We use stack to solve this problem.
    The stack will become a non-increase array.
    When we want to push some person with height x, we have to delete all the lower ones in the top of the stack.
    for each time we see, we add the result. 
    Complexity : O(N)
*/