#include <iostream>
using namespace std;

int main() {
    //
    string str;
    getline(cin, str);
    char c1, c2;
    cin >> c1;
    int res = 0;
    if (c1 >= 'a' && c1 <= 'z') { c2 = c1 - 'a' + 'A'; }
    if (c1 >= 'A' && c1 <= 'Z') { c2 = c1 - 'A' + 'a'; }
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == c1 || str[i] == c2) { res++; }
    }
    cout << res;
    return 0;
}