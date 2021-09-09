#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x, idx, n)                                                                                                                                        \
    for (int i = idx; i < n; i++) cout << x[i] << ' ';                                                                                                         \
    cout << endl;
int f(int a, int b) {
    int c;
    do {
        c = a ^ b;
        b = a & b << 1;
        a = c;
    } while (b != 0);
    return c;
}
int main() {
    //
    // cout << __gcd(3, 3);
    // cout << f(47, -42);
    int a = 3, *p1 = &a;
    int b = 4, *p2 = &b;
    int c = 5, *p3 = &c;
    *p1 *= *p1 * *p2 * *p3;
    cout << a;
    return 0;
}