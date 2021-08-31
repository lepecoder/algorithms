#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    int a, b, c, d;
    int x = 256;
    int n;
    while (getline(cin, s)) {
        if (s.size == 0) break;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '.') s[i] = ' ';
        }
        istringstream ss(s);
        ss >> a >> b >> c >> d;
        cout << a * x * x * x + b * x * x + c * x + d << endl;
        cin >> n;
        d = n & 0x000000FF;
        c = (n & 0x0000FF00) >> 8;
        b = (n & 0x00FF0000) >> 16;
        a = (n & 0xFF000000) >> 24;
        cout << a << '.' << b << '.' << c << '.' << d << endl;
    }

    return 0;
}