/*
    MAXCUB : http://vn.spoj.com/problems/MAXCUB/
    Explanation and Complexity are below
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int NMAX      =   35;
const int oo        =   1e9;
int n;
int a[NMAX][NMAX][NMAX];
int f[NMAX][NMAX][NMAX];
void readInp() {
    cin >> n;
    for (int x = 1; x <= n; x++)
    for (int y = 1; y <= n; y++)
    for (int z = 1; z <= n; z++)
        cin >> a[x][y][z];
}
void process() {
    for (int x = 1; x <= n; x++)
    for (int y = 1; y <= n; y++)
    for (int z = 1; z <= n; z++)
        f[x][y][z] = 0;
    for (int x = 1; x <= n; x++)
    for (int y = 1; y <= n; y++)
    for (int z = 1; z <= n; z++)
        f[x][y][z] = f[x - 1][y][z] + f[x][y - 1][z] + f[x][y][z - 1]
                    -f[x - 1][y - 1][z] - f[x][y - 1][z - 1] - f[x - 1][y][z - 1] + f[x - 1][y - 1][z - 1] + a[x][y][z];
    int res = -oo;
    for (int x = 1; x <= n; x++)
    for (int y = 1; y <= n; y++)
    for (int z = 1; z <= n; z++) {
        int tmin = min(x, min(y, z));
        for (int t = 1; t <= tmin; t++) {
            int xt = x - t;
            int yt = y - t;
            int zt = z - t;
            int sum = f[x][y][z] - f[xt][y][z] - f[x][yt][z] - f[x][y][zt] + f[xt][yt][z] + f[xt][y][zt] + f[x][yt][zt] - f[xt][yt][zt];
            if (sum > res) res = sum;
        }
    }
    cout << res << "\n";
}
int main() {
    int test;
    cin >> test;
    while (test-- > 0) {
        readInp();
        process();
    }
    return 0;
}
/*
    We DP with the 3D - array F[NMAX][NMAX][NMAX] : the sum of number in the (1,1,1) -> (x,y,z) in 3D. 
    F[x][y][z] = F[x - 1][y][z] + F[x][y - 1][z] + F[x][y][z - 1] 
                - F[x - 1][y - 1][z] - F[x][y - 1][z - 1] - F[x - 1][y][z - 1] + F[x - 1][y - 1][z - 1]
    We will calculate the sum of cub t * t * t from position (x - t, y - t, z - t) to position (x, y, z) 
    with formula : sum = f[x][y][z] - f[x - t][y][z] - f[x][y - t][z] - f[x][y][z - t] 
    
*/