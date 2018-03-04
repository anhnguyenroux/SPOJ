/*
    CAR : http://vn.spoj.com/problems/CAR/
    Explanation and Complexity are below
*/
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int NMAX      =   1e4 + 10;
struct car {
    int a, b;
    int pos;
};
int N;
car c[NMAX];
int cmp(car x, car y) {
    return x.a * y.b > y.a * x.b;
}
void process() {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> c[i].a;
    for (int i = 0; i < N; i++)
        cin >> c[i].b;
    for (int i = 0; i < N; i++)
        c[i].pos = i;
    sort(c, c + N, cmp);
    ll res = 0;
    ll day = 0;
    for (int i = 0; i < N; i++) {
        day += c[i].b;
        res += c[i].a * day;
    }
    cout << res << "\n";
    for (int i = 0; i < N; i++)
        cout << c[i].pos + 1 << " ";
}
int main() {
    process();
    return 0;
}
/*
    We will sort the list of cars in descending order by value ai/bi and then calculate the result. 
    The reason why we sort like that is because we want to minimize the money to pay back. If 2 car share the same fee, we will sort 
    by b_i, b_i < b_i + 1; if 2 car share the same day to fix, we will sort by a_i. 
    We can easily improve that if a_i / b_i > a_i+1 / b_i+1, the money to pay back is less than we fix the car in the order a_i / b_i then a_i + 1/ b_i + 1
    Complexity : O(NlogN)
*/