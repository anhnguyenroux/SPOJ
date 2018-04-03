#include <stdio.h>
#include <string.h>
const int MAX   =   1e6 + 10;
char a[MAX], b[MAX];
int next[MAX];
int n, m;
int main() {
    gets(a);
    gets(b);
    n = strlen(a);
    m = strlen(b);
    next[0] = 0;
    int j = 0, i = 1;
    while (i < m) {
        while (j > 0 && b[j] != b[i]) {
            j = next[j - 1];
        }
        if (b[j] == b[i]) {
            next[i] = ++j;
            i++;
        }
        else {
            next[i] = 0;
            i++;
        }
    }
    j = 0, i = 0;
    while (i < n) {
        if (b[j] == a[i]) {
            j++;
            i++;
        }
        if (j == m) {
            printf("%d ", i - j + 1);
            j = next[j - 1];
        }
        else if (i < n && b[j] != a[i]) {
            if (j != 0) j = next[j - 1];
            else i++;
        }
    }
    puts("");
    return 0;
}