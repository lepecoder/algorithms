#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, ans;
    char c;
    cin >> a >> c >> b;
    switch (c) {
    case '+':
        ans = a + b;
        break;
    case '-':
        ans = a - b;
        break;
    case '*':
        ans = a * b;
        break;
    case '/':
        ans = a / b;
        break;
    case '%':
        ans = a % b;
        break;
    default:
        cout << "ERROR";
        return 0;
        }
    cout << ans;
    return 0;
}