#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int high, up, down;
    cin >> high >> up >> down;
    int res = 105;
    int diff = up - down;
    int t = high / diff;
    for (int i = 1; i < INT_MAX; i++) {
        if (diff * (i - 1) + up >= high) {
            cout << i;
            break;
        }
    }

    return 0;
}