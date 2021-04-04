#include <stdio.h>

int main() {
    int n = 2;
    int a[n][n];
    a[0][1] = 3;
    a[1][1] = 1;
    // cout << a[0][1] << ' ' << a[1][1] << endl;
    printf("%d,%d", a[0][1], a[1][1]);
    return 0;
}