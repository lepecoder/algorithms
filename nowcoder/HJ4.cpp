#include <iostream>
using namespace std;

int main() {
    string str;
    int n, i, k;
    while (cin >> str) {
        n = str.length();
        k = 0;
        while (k < n) {
            for (int i = 0; i < 8; i++) {
                if (k + i < n) {
                    cout << str[k + i];
                } else {
                    cout << '0';
                }
            }
            k += 8;
            cout << endl;
        }
    }

    return 0;
}