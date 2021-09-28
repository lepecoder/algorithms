/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// @lc code=start
class Solution {
  public:
    int longestValidParentheses(string s) {
        int res = 0;

        int left_c = 0;
        int t = 0;
        for (char c : s) {
            if (c == '(') {
                left_c++;
            } else {               // 右括号
                if (left_c == 0) { // 有效括号重新开始
                    res = max(res, t);
                    t = 0;
                } else {
                    left_c--;
                    t += 2;
                }
            }
        }
        res = max(res, t);
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}
