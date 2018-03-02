/*
    COLOREC http://vn.spoj.com/problems/COLOREC/
    Explanation and Complexity is below
*/
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const int NMAX      =   1e5 + 100;
const int PMAX      =   200;
int N;
int D[2 * PMAX + 100][2 * PMAX + 100];
ll c[5][5];
void readInp() {
    scanf("%d", &N);
    for (int x = -PMAX; x <= PMAX; x++)
        for (int y = -PMAX; y <= PMAX; y++)
            D[x + PMAX][y + PMAX] = 0;
    for (int i = 0; i < N; i++) {
        int x, y, color;
        scanf("%d %d %d", &x, &y, &color);
        D[x + PMAX][y + PMAX] = color;
    }
}
void process() {   
    ll res = 0;
    for (int i = -PMAX; i <= PMAX; i++) 
    for (int j = i + 1; j <= PMAX; j++) {
        for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            c[i][j] = 0;
        for (int y = -PMAX; y <= PMAX; y++) {
            if (D[i + PMAX][y + PMAX] * D[j + PMAX][y + PMAX] > 0) {
                int c1 = D[i + PMAX][y + PMAX], c2 = D[j + PMAX][y + PMAX];
                c[min(c1, c2)][max(c1, c2)]++;
            }
        }
        res += c[1][2] * c[3][4] + c[1][3] * c[2][4] + c[1][4] * c[2][3];
    }
    printf("%lld", res);
}
int main() {
    readInp();
    process();
    return 0;
}
/*
    We have D2-Array D[x + PMAX][y + PMAX] to save the color of each point (PMAX = 200; -PMAX <= x <= PMAX; -PMAX <= y <= PMAX)
    For every i, j (i < j) in x - axis, we will count how many rectangles with 4 colors by using an D2-Array C[c1][c2], 
    For every existed point in i and j, we will count how many 2 points with different colors, and then adding it to the result.
    Complexity : O(PMAX^3) 
*/