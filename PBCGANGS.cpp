#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int NMAX = 1100;
int N;
int M;
int Lab[NMAX];
vector <int> Enemy[NMAX];
set <int> GangNum;
int getRoot(int u) {
    while (Lab[u] > 0) u = Lab[u];
    return u;
}
void Union(int u, int v) {
    int r1 = getRoot(u);
    int r2 = getRoot(v);
    if (r1 == r2) return;
    int tmp = Lab[r1] + Lab[r2];
    if (Lab[r1] > Lab[r2]) {
        Lab[r1] = r2;
        Lab[r2] = tmp;
    }
    else {
        Lab[r2] = r1;
        Lab[r1] = tmp;
    }
}
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++)
        Lab[i] = -1;
    cin >> M;
    char c;
    int p, q;
    for (int i = 1; i <= M; i++) {
        cin >> c >> p >> q;
        if (c == 'F') Union(p, q);
        if (c == 'E') {
            for (int j = 0; j < Enemy[q].size(); j++) 
                Union(p, Enemy[q][j]);
            for (int j = 0; j < Enemy[p].size(); j++)
                Union(q, Enemy[p][j]);
            Enemy[p].push_back(q);
            Enemy[q].push_back(p);
        }
    }
    for (int i = 1; i <= N; i++) {
        int r = getRoot(i);
        GangNum.insert(r);
    }
    cout << GangNum.size();
    return 0;
}