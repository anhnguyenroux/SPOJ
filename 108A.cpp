#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0);
#define all(v) (v).begin(), (v).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
bool ispalin(int h, int m) {
    char x[4];
    x[0] = '0' + h / 10;
    x[1] = '0' + h % 10;
    x[2] = '0' + m / 10;
    x[3] = '0' + m % 10;
    char y[4];
    y[0] = '0' + m % 10;
    y[1] = '0' + m / 10;
    y[2] = '0' + h % 10;
    y[3] = '0' + h / 10;
    for (int i = 0; i < 4; i++)
        if (x[i] != y[i]) return 0;
    return 1;
}
int main() {
    IO;
    int h1, m1;
    char s[5];
    scanf("%s", &s);
    h1 = (s[0] - '0') * 10 + (s[1] - '0');
    m1 = (s[3] - '0') * 10 + (s[4] - '0');
    int hour = 23, min = 59;
    for (int hh = 0; hh <= 23; hh++) 
    for (int mm = 0; mm <= 59; mm++)
        if (hh > h1 || (hh == h1 && mm > m1))
        if (ispalin(hh, mm)) {
            //if (hh == 23 && mm == 32) printf("%d %d", hh, mm);
            if (hh < hour || (hh == hour && mm < min)) 
                hour = hh, min = mm;
        }
    if (hour == 23 && min == 59) printf("00:00");
    else 
        printf("%02d:%02d", hour, min);
    return 0;
}
