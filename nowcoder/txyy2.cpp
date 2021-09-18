#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    //
    string str;
    cin >> str;
    int n = str.size();
    int idx = 0;
    while (idx < n && str[idx] == '1') idx++;
    while (idx < n && str[idx] != '1') {
        str[idx] = '1';
        idx++;
    }
    cout << str;
    return 0;
}