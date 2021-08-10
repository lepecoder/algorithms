#include <iostream>
using namespace std;

int main() {
    string str;
    int res;
    while (cin >> str) {
        res = 0;
        for (int i = 2; i < str.size(); i++) {
            res *= 16;
            if (str[i] >= 'A') {
                res += str[i] - 'A';
            } else {
                res += str[i] - '0';
            }
        }
        cout << res << endl;
    }

    return 0;
}