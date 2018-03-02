#include <stdio.h>
#include <queue>
using namespace std;
const int NMAX      =   510;
const int oo        =   1e9;
const int k0x[3]    =   {0, 1, 1};
const int k0y[3]    =   {1, 1, 0};
const int k1x[3]    =   {0, 1, 1};
const int k1y[3]    =   {-1, -1, 0};
struct node {
    int u, v;
    int turn;
    node(int _u, int _v, int _turn) {
        u = _u;
        v = _v;
        turn = _turn;
    }
};
int N, k;
int a[NMAX][NMAX];
int f[NMAX][NMAX][2];
void readInp() {
    scanf("%d %d", &N, &k);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            a[i][j] = 1;
    for (int i = 1; i <= k; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        a[x][y] = 0;
    }
}
void bfs() {
    for (int u = 1; u <= N; u++)
        for (int v = 1; v <= N; v++) {
            f[u][v][0] = oo;
            f[u][v][1] = oo;
        }
    queue <node> q;
    node r1 = node(1, 1, 0);
    node r2 = node(1, N, 1);
    q.push(r1);
    q.push(r2);
    f[1][1][0] = 0;
    f[1][N][1] = 0;
    while (!q.empty()) {
        node cur = q.front();
        q.pop();
        int u = cur.u, v = cur.v;
        if (f[u][v][0] == f[u][v][1]) {
            printf("%d", f[u][v][0]);
            return;
        }
        int turn = cur.turn;
        if (!turn) {
            for (int k = 0; k < 3; k++) {
                int ux = u + k0x[k];
                int vy = v + k0y[k];
                if (ux < 1 || ux > N || vy < 1 || vy > N) continue;
                if (a[ux][vy] && f[ux][vy][0] == oo) {
                    f[ux][vy][0] = f[u][v][0] + 1;
                    q.push(node(ux, vy, 0));
                }
            }
        }
        if (turn) {
            for (int k = 0; k < 3; k++) {
                int ux = u + k1x[k];
                int vy = v + k1y[k];
                if (ux < 1 || ux > N || vy < 1 || vy > N) continue;
                if (a[ux][vy] && f[ux][vy][1] == oo) {
                    f[ux][vy][1] = f[u][v][1] + 1;
                    q.push(node(ux, vy, 1));
                }
            }
        }
    }
}
int main() {
    readInp();
    bfs();
    return 0;
}