#include <bits/stdc++.h>
using namespace std;
int n, k;
int main() {
    scanf("%d %d", &n, &k);
    if (k > n || (n > 1 && k == 1)) {
        printf("-1");
        return 0;
    }
    char* s = new char[n];
    s[0] = 'a';
    int i = 1;
    while (i < n) {
        if (k - 2 == n - i) break;
        for (int j = 0; j < 26; j++)
        if ('a' + j != s[i - 1]) {
            s[i] = 'a' + j;
            break;
        }
        i++;
    }
    char c = 'c';
    while (i < n) {
        s[i] = c;
        c++;
        i++;
    }
    for (int i = 0; i < n; i++)
        printf("%c", s[i]);
    return 0;
}
