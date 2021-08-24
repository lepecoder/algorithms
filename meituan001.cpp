#include <bits/stdc++.h>
using namespace std;

int check(char c) {
    // 数字返回0
    // 字母返回1
    // 其它返回-1
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
        return 1;
    } else if (c >= '0' && c <= '9') {
        return 0;
    }
    return -1;
}

int main() {
    //
    int t;
    cin >> t;
    string s;
    cout << "hello world\n";
    int a;
    cout << x;
WH:
    while (t--) {
        cin >> s;
        if (check(s[0]) != 1) {
            cout << "Wrong\n";
            goto WH;
        }
        bool digit = false;

        for (int i = 1; i < s.size(); i++) {
            if (check(s[i]) == -1) {
                cout << "Wrong\n";
                goto WH;
            } else if (check(s[i]) == 0) {
                digit = true;
            }
        }
        if (digit)
            cout << "Accept\n";
        else
            cout << "Wrong\n";
    }

    return 0;
}