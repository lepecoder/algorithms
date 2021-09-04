#include <bits/stdc++.h>
using namespace std;

int main() {
    // 进行最少的操作，把A变成B
    int n;
    string a, b;
    cin >> n;
    cin >> a >> b;
    string c = a; // 异或操作，相同为0 不同为1
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            c[i] = '1';
        } else {
            c[i] = '0';
        }
    }

    vector<pair<int, int>> vec; // 记录不同的边界
    int begin, end;
    bool is_begin = false;
    int res = 0;
    // 找到有多少段连续的1
    // for(int i=0;i<n;i++){
    int i = 0;
    while (i < n) {
        if (c[i] == '1') {
            while (i < n && c[i] == '1') i++;
            res++;
        } else {
            i++;
        }
    }
    // cout << c << endl;
    cout << res << endl;

    return 0;
}