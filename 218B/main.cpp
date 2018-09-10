#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1100];
int main() {
    scanf("%d %d", &n, &m);
    int cnt;
    for (int i = 0; i < m; i++) scanf("%d", &a[i]);
    priority_queue <int> q1;
    for (int i = 0; i < m; i++) q1.push(a[i]);
    int maxRes = 0;
    cnt = 1;
    while(cnt <= n) {
        int u = q1.top();
        q1.pop();
        maxRes += u;
        cnt++;
        if (u - 1) q1.push(u - 1);
    }

    priority_queue <int, vector <int>, greater <int> > q2;
    for (int i = 0; i < m; i++) q2.push(a[i]);
    int minRes = 0;
    cnt = 1;
    while(cnt <= n) {
        int u = q2.top();
        q2.pop();
        minRes += u;
        cnt++;
        if (u - 1) q2.push(u - 1);
    }
    printf("%d %d", maxRes, minRes);
    return 0;
}
