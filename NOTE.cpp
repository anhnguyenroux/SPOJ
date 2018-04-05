/*
    NOTE : http://vn.spoj.com/problems/NOTE/
    Explanation and Complexity are below
*/
#include <stdio.h>
bool find(int f, int p) {
    if (p == (1 << (f - 1))) return 0;
    if (p > (1 << (f - 1))) return find(f - 1, p - (1 << (f - 1)));
    if (p < (1 << (f - 1))) return !find(f - 1,(1 << (f - 1)) - p);
}
int main() {
    int f, p;
    while (true) {
        scanf("%d %d", &f, &p);
        if (f == 0 && p == 0) break;
        if (find(f, p)) printf("U\n");
        else printf("D\n");
    }
    return 0;
}
/*
    We create find(f, p). find(f, p) = 1 means the pleat in position p after f times collapse is up, otherwise it is down.
    There are more 2^(f - 1) pleats then the previous we collapse the paper, totally we have 2^f - 1 pleats after f times we collapse the paper.
    If p in the middle of pleats (which means p = 2^(f - 1)), it must be a down pleat.
    if p in the right side of the middle (which means p > 2^(f - 1)), then the pleat is find(f - 1, p - 2^(f - 1)). 
    if p in the left side of the middle (which means p < 2^(f - 1)), then the pleat is opposite of find(f - 1, p - 2^(f - 1)).
    Complexity : O(f).
*/