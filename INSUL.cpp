/*
    INSUL : http://vn.spoj.com/problems/INSUL/
    Explanation and Complexity are below
*/
#include <stdio.h>
#include <algorithm>
using namespace std;
const int NMAX = 1e5 + 100;
int N;
int a[NMAX];
int res = 0;
void inpProcess() {
    scanf("%d", &N);
    for (int i =  0; i < N; i++) {
        scanf("%d", &a[i]);
        res += a[i];
    }
}
int get(int x, int y) {
    return max(0, y - x);
}
void Process() {
    sort(a, a + N);
    int j = N - 1;
    for (int i = 0; i <= N / 2; i++) {
        res += get(a[i], a[j]);
        if (i + 1 <= N / 2) 
            res += get(a[j], a[i + 1]);
        j--;        
    }
    printf("%d", res);
}
int main() {
    inpProcess();
    Process();
    return 0;
}
/*
    In this problem, we will sort in ascending order. 
    We will divide the array in 2 parts, the bigger part we will insert each of them between 2 elements in smaller part. 
    Then we can calculate the result with the best solution.
    Complexity : O(NlogN);
*/