#include <iostream>
#include <string>
using namespace std;
int main() {
    string str;
    getline(cin, str);
    // cin >> str;
    int n = str.size() - 1;
    int i = n;
    while (i >= 0 && str[i] != ' ') --i;
    cout << n - i;

    return 0;
}