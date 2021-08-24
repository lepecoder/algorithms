#include <bits/stdc++.h>
using namespace std;

bool f(int n) {
    // 能否一次拿完
    if (n <= 0) return false;
    // int i = 1;
    int x = sqrt(n);
    return x * x == n;
    // while (i * i < n) i++;
    // return i * i == n;
}

int main() {
    // int n;
    // cin >> n;
    for (int i = 1; i < 12; i++) { cout << "i=" << i << ',' << f(i) << endl; }

    return 0;
}