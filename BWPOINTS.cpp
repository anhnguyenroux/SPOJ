/*
    BWPOINTS : http://vn.spoj.com/problems/BWPOINTS/
    Explanation and Complexity are below
*/
#include <stdio.h>
#include <algorithm>
using namespace std;
struct point {
    int vt;
    int type;
};
const int NMAX = 2e5 + 100;
int N;
point p[NMAX];
void inpProcess() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &p[i].vt);
        p[i].type = -1;
    }
    for (int i = 1; i <= N; i++) {
        scanf("%d", &p[N + i].vt);
        p[N + i].type = 1;
    }
}
int cmp(point a, point b) {
    return a.vt < b.vt;
}
void Process() {
    sort(p + 1, p + 1 + 2 * N, cmp);
    int cur = 0;
    int res = 0;
    for (int i = 1; i <= 2 * N; i++) {
        if (cur + p[i].type == 0) {
            res++;
            cur = 0;
        }
        else
        if (cur == 0) cur = p[i].type;
    }
    printf("%d", res);
}
int main() {
    inpProcess();
    Process();
    return 0;
}
/*
    We will sort 2N points with black points and white points by their positions in axis. 
    Then we will check how many line segment that connect 2 points of 2 types. 
    Complexity : O(2N*log(2N))
*/