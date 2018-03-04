/*
    ROBOCON : http://vn.spoj.com/problems/ROBOCON/
    Explanation and Complexity are below
*/
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
const int NMAX      =   510;
const int oo        =   1e9;
const int k0x[3]    =   {0, 1, 1};
const int k0y[3]    =   {1, 1, 0};
const int k1x[3]    =   {0, 1, 1};
const int k1y[3]    =   {-1, -1, 0};
struct node {
    int u, v;
    node(int _u, int _v) {
        u = _u;
        v = _v;
    }
};
int N, k;
int a[NMAX][NMAX];
int f0[NMAX][NMAX], f1[NMAX][NMAX];
void readInp() {
    scanf("%d %d", &N, &k);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            a[i][j] = 1;
            f0[i][j] = 0;
            f1[i][j] = 0;
        }
    for (int i = 1; i <= k; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        a[x][y] = 0;
    }
}
void bfs() {
    queue <node> q;
    int d1 = 1, d2 = 1;
    q.push(node(1, 1));
    q.push(node(1, N));
    int t = 0;
    while (!q.empty()) {
        t++;
        int cnt = 0;
        for (int i = 1; i <= d1; i++) {
            node cur = q.front();
            q.pop();
            int u = cur.u;
            int v = cur.v;
            for (int k = 0; k < 3; k++) {
                int ux = u + k0x[k];
                int vy = v + k0y[k];
                if (ux < 1 || ux > N || vy < 1 || vy > N) continue;
                if (a[ux][vy]) {
                    if (f0[ux][vy] == 0 || f0[ux][vy] != t) {
                        q.push(node(ux, vy));
                        f0[ux][vy] = t;
                        cnt++;
                    }
                }
            }
        }
        d1 = cnt; 
        cnt = 0;
        for (int i = 1; i <= d2; i++) {
            node cur = q.front();
            q.pop();
            int u = cur.u;
            int v = cur.v;
            for (int k = 0; k < 3; k++) {
                int ux = u + k1x[k];
                int vy = v + k1y[k];
                if (ux < 1 || ux > N || vy < 1 || vy > N) continue;
                if (a[ux][vy]) {
                    if (f0[ux][vy] == t) {
                        printf("%d", t);
                        return;
                    }
                    if (f1[ux][vy] == 0 || f1[ux][vy] != t) {
                        q.push(node(ux, vy));
                        f1[ux][vy] = t;
                        cnt++;
                    }
                }
            }
        }
        d2 = cnt;
    }
}
int main() {
    readInp();
    bfs();
    return 0;
}
/*
    We will use BFS - algorithm in this case.
    For each step, we will find positions that can go from recent position in Queue.
    When 2 robots meet at time in the same position, we stop BFS and output the time we count for each time.
*/