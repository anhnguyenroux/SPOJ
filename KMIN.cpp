/*
    KMIN : vn.spoj.com/problems/KMIN
    Explanation and Complexity are below
*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX       =   50010;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;
int M, N, K;
int a[MAX], b[MAX];
void readInp() {
    cin >> M >> N >> K;
    for (int i = 0; i < M; i++)
        cin >> a[i];
    for (int i = 0; i < N; i++)
        cin >> b[i];
}
void process() {
    sort(a, a + M);
    sort(b, b + N);
    priority_queue <iii, vector <iii>, greater <iii> > q;
    int cnt = 0;
    for (int i = 0; i < M; i++)
        q.push(iii(a[i] + b[0], ii(i, 0)));
    for (int i = 1; i <= K; i++) {
        iii cur = q.top();
        q.pop();
        cout << cur.first << "\n";
        int x = cur.second.first;
        int y = cur.second.second;
        if (y + 1 < N) q.push(iii(a[x] + b[y + 1], ii(x, y + 1)));
    }
}
int main() {
    readInp();
    process();
    return 0;
}
/*
    We will use a min - heap to save the K - smallest sums. 
    Sort array a and b by ascending order.
    First, we add M sums a[i] + b[0] (0 <= i < M) 
    We will print K times the top of the heap. 
    For each sum of a[i] + b[j], we add the sum of the next element a[i] + b[j + 1] to min heap.
    Complexity : O(K * NlogN)
*/