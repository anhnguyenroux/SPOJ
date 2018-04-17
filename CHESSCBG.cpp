#include <iostream>
#include <string>
#include <queue>
using namespace std;
const int BITMAX = (1 << 16) + 100;
string st;
int dd[4] = {1,4,-4,-1};
int d[BITMAX];
int avail[BITMAX];
int s = 0, t = 0;
void inpProcess() {
    for (int i = 1; i <= 4; i++) {
        cin >> st;
        for (int j = 1; j <= 4; j++)
            s = s * 2 + (st[j - 1] - 48);
    }
    for (int i = 1; i <= 4; i++) {
        cin >> st;
        for (int j = 1; j <= 4; j++)
            t = t * 2 + (st[j - 1] - 48);
    }
}
int getbit(int x, int i) {
    return (x >> i) & 1;
}
int ke(int x, int y) {
    if (y < 1 || y > 16) return false;
    if (x % 4 == 0 && x + 1 != y) return true;
    if (x % 4 == 1 && x - 1 != y) return true;
    if (x % 4 == 2 || x % 4 == 3) return true;
    return false;
}
void turnoff(int &x, int i) {
    x ^= (1 << i);
}
void turnon(int &x, int i) {
    x |= (1 << i);
}
void Process() {
    queue <int> q;
    for (int i = 0; i <= (1 << 16) - 1; i++) {
        avail[i] = 1;
        d[i] = 0;
    }
    avail[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 1; i <= 16; i++)
        if (getbit(u, i - 1)) {
            for (int j = 0; j <= 3; j++)
            if (ke(i, i + dd[j]) && getbit(u, i + dd[j] - 1) == 0) {
                int tmp = u;
                turnoff(tmp, i - 1);
                turnon(tmp, i + dd[j] - 1);
                d[tmp] = d[u] + 1;
                if (tmp == t) {
                    cout << d[tmp];
                    return;
                }
                if (avail[tmp]) {
                    avail[tmp] = 0;
                    q.push(tmp);
                }
            }
        }
    }
}
int main() {
    inpProcess();
    Process();
    return 0;
}
