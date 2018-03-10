#include <stdio.h>
#include <algorithm>
using namespace std;
const int HMAX = 5e5 + 10;
int N, h;
int a[HMAX], b[HMAX];
void add(int x, int y) {
    b[x]++;
    b[y + 1]--;
}
void Process() {
    scanf("%d %d", &N, &h);
    for (int i = 1; i <= h; i++)
        b[i] = 0;
    for (int i = 1; i <= N; i++) {
        int x;
        scanf("%d", &x);
        if (i % 2 == 1) add(1, x);
        else add(h - x + 1, h);
    }
    a[0] = 0;
    for (int i = 1; i <= h; i++)
        a[i] = b[i] + a[i - 1];
    int res = N, cnt = 0;
    for (int i = 1; i <= h; i++)
        if (a[i] < res) {
            res = a[i];
            cnt = 1;
        }
        else if (a[i] == res) cnt++;
    printf("%d %d", res, cnt);
}
int main() {
    Process();
    return 0;
}
