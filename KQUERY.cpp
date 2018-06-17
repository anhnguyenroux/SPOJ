#include <stdio.h>
#include <algorithm>
using namespace std;

const int NMAX = 30000 + 100;
const int QMAX = 200000 + 100;
struct Query {
    int l, r;
    int k;
    int pre;
};
struct Element {
    int v;
    int pre;
};
int N;
Element a[NMAX];
int b[NMAX];
int it[4 * NMAX];
int queries;
Query q[QMAX];
int ans[QMAX];

int compQueries(Query i, Query j) {
    return (i.k < j.k);
}
int compElement(Element i, Element j) {
    return (i.v < j.v);
}
void itBuild(int k, int l, int r) {
    if (l == r) {
        it[k] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    itBuild(k << 1 | 0, l, mid);
    itBuild(k << 1 | 1, mid + 1, r);
    it[k] = it[k << 1 | 0] + it[k << 1 | 1];
}
void itUpdate(int k, int l, int r, int pre) {
    if (pre < l || pre > r) return;
    if (l == r) {
        it[k] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    itUpdate(k << 1 | 0, l, mid, pre);
    itUpdate(k << 1 | 1, mid + 1, r, pre);
    it[k] = it[k << 1 | 0] + it[k << 1 | 1];
}
int Get(int k, int l, int r, int left, int right) {
    if (l > right || r < left) return 0;
    if (left <= l && r <= right) return it[k];
    int mid = (l + r) >> 1;
    return Get(k << 1 | 0, l, mid, left, right)
         + Get(k << 1 | 1, mid + 1, r, left, right);
}
void inpProcess() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &a[i].v);
        a[i].pre = i;
    }
    scanf("%d", &queries);
    for (int i = 1; i <= queries; i++) {
        scanf("%d %d %d", &q[i].l, &q[i].r, &q[i].k);
        q[i].pre = i;
    }
}
void Process() {
    sort(q + 1, q + 1 + queries, compQueries);
    sort(a + 1, a + 1 + N, compElement);
    for (int i = 1; i <= N; i++) b[i] = 1;
    itBuild(1, 1, N);
    int lastPre = 1;
    for (int i = 1; i <= queries; i++){
        for (int j = lastPre; j <= N; j++)
            if (a[j].v <= q[i].k) {
                b[a[j].pre] = 0;
                itUpdate(1, 1, N, a[j].pre);
            }
            else {
                lastPre = j;
                break;
            }
        ans[q[i].pre] = Get(1, 1, N, q[i].l, q[i].r);
    }
}
void outProcess() {
    for (int i = 1; i <= queries; i++)
        printf("%d\n", ans[i]);
}
int main() {
    inpProcess();
    Process();
    outProcess();
    return 0;
}
