#include <iostream>
using namespace std;
const int MAX       =   510;
const int oo        =   1e9 + 10;
int N, M;
int k;
int a[MAX][MAX];
void readInp() {
    cin >> N >> M >> k;
    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= M; j++)
            a[i][j] = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
            cin >> a[i][j];
            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + a[i][j];
        }
}
int get(int x1, int y1, int x2, int y2) {
    return a[x2][y2] - a[x2][y1 - 1] - a[x1 - 1][y2] + a[x1 - 1][y1 - 1];
}
void process() {
    int res = oo;
    int x1, y1, x2, y2;
    for (int i = 1; i <= M; i++)
        for (int j = i; j <= M; j++) {
            int c = 1, d = 1;
            int sum = get(c, i, d, j);
            while (c <= d && d <= N) {
                if (sum < k) {
                    d++;
                    sum = get(c, i, d, j);
                }
                else {
                    if ((d - c + 1) * (j - i + 1) < res) {
                        res = (d - c + 1) * (j - i + 1);
                        x1 = c;
                        y1 = i;
                        x2 = d;
                        y2 = j;
                    }
                    c++;
                    sum = get(c, i, d, j);
                }
            }
        }
    if (res == oo) cout << "-1";
    else {
        cout << res << "\n";
        cout << x1 << " " << y1 << " " << x2 << " " << y2;
    }
}
int main() {
    readInp();
    process();
    return 0;
}