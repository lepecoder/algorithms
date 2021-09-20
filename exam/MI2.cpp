#include <bits/stdc++.h>
using namespace std;

int fun(int n) {
    if (n == 1) return 0;
    return (fun(n - 1) + 3) % n;
}

int main() {
    int n;
    cin >> n;
    cout << fun(n) + 1;
    return 0;
}