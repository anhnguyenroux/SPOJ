#include <bits/stdc++.h>
#define IO ios::sync_with_stdio(false); cin.tie(0);
using namespace std;
int main() {
    IO;
    int hh, mm;
    int H, D, C, N;
    cin >> hh >> mm;
    cin >> H >> D >> C >> N;
    float res = 1e9;
    for (int _hh = 0; _hh <= 23; _hh++)
    for (int _mm = 0; _mm <= 59; _mm++)
    if (_hh > hh || (_hh == hh && _mm >= mm)) {
        int time = (_mm - mm);
        if (time < 0) time += 60 + (_hh - 1 - hh) * 60;
        else time += (_hh - hh) * 60;
        int tmpH = H + D * time;
        int buns = tmpH / N;
        if (tmpH % N != 0) buns++;
        float cost = C * buns;
        if (_hh >= 20) cost = cost * 4 / 5;
        res = min(res, cost);
    }
    printf("%.4f", res);
    return 0;
}
