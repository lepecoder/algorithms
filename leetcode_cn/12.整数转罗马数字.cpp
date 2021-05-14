/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */
#include <bits/stdc++.h>
using namespace std;

// IO
int _IO = []() {
    std::ios::sync_with_stdio(0);
    cin.tie(0); // cout.tie(0);
    return 0;
}();
// @lc code=start
class Solution {
  public:
    string intToRoman(int num) {
        int digit[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        vector<string> roman = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        string res;
        while (num) {
            for (int i = 12; i >= 0; i++) {
                if (num > digit[i]) {
                    res += roman[i];
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}