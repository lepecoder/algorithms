#include <bits/extc++.h>
using namespace std;

int main() {
    //
    string s1;
    string s2;
    cin >> s1;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == 'O')
            s1[i] == '1';
        else
            s1[i] = '0'; // 不能按
    }
    int n;
    cin >> n;
    while (n--) {
        cin >> s2;
        int i;
        for (i = 0; i < s2.size(); i++) {
            if (s1[i] == '0' && s2[i] == '1') {
                cout << "NO\n";
                break;
            }
        }
        if (i == s2.size()) { cout << "YES\n"; }
    }
    return 0;
}