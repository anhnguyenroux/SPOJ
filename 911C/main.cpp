#include <bits/stdc++.h>
using namespace std;
bool check(int a,int b,int c) {
    if(a==1 || b==1 || c==1)
        return 1;
    if((a==2 && b==2) || (a==2 && c==2) || (b==2 && c==2))
        return 1;
    if((a==2 && b==4 && c==4) || (a==4 && b==2 && c==4) || ((a==4 && b==4 && c==2)))
        return 1;
    if(a==3 && b==3 && c==3)
        return 1;
    else
        return 0;


}
int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (check(a, b, c)) {
        printf("YES");
    }
    else printf("NO");
    return 0;
}
