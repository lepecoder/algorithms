#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int romanToInt(string s) {
        int digit[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        vector<string> roman = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        int res = 0;
        enum { Start, I, II, X, C } state;
        state = Start;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            switch (state) {
            case Start:
                switch (c) {
                case 'I': state = I; break;
                case 'V':
                    state = Start;
                    res += 5;
                    break;
                case 'X': state = X; break;
                case 'L':
                    state = Start;
                    res += 50;
                    break;
                case 'C': state = C; break;
                case 'D':
                    state = Start;
                    res += 500;
                    break;
                case 'M':
                    state = Start;
                    res += 1000;
                    break;
                }
                break;
            case I:
                switch (c) {
                case 'I': state = II; break;
                case 'V':
                    state = Start;
                    res += 4;
                    break;
                case 'X':
                    state = Start;
                    res += 9;
                    break;
                default: state = Start; res += 1;
                }
                break;
            case II:
                switch (c) {
                case 'I':
                    state = Start;
                    res += 3;
                    break;
                default: state = Start; res += 2;
                }
                break;
            case X:
                switch (c) {
                case 'L':
                    state = Start;
                    res += 40;
                    break;
                case 'C':
                    state = Start;
                    res += 90;
                    break;
                default: state = Start; res += 10;
                }
                break;
            case C:
                switch (c) {
                case 'D':
                    state = Start;
                    res += 400;
                    break;
                case 'M':
                    state = Start;
                    res += 900;
                    break;
                default:
                    state = Start;
                    res += 100;
                    i--;
                }
                break;
            }
        }
        return res;
    }
};
int main() {
    Solution so;
    int res = so.romanToInt("DCXXI");
    cout << res;
    return 0;
}
// IO
int _IO = []() {
    std::ios::sync_with_stdio(0);
    cin.tie(0); // cout.tie(0);
    return 0;
}();