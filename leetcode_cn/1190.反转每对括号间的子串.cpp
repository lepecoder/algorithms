/*
 * @lc app=leetcode.cn id=1190 lang=cpp
 *
 * [1190] 反转每对括号间的子串
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    string reverseParentheses(string s) {
        stack<string> stk;
        string str = "";
        for (char &c : s) {
            if (c == '(') {
                stk.emplace(str);
                str.clear();
            } else if (c == ')') {
                reverse(str.begin(), str.end());
                str = stk.top() + str;
                stk.pop();
            } else {
                str.push_back(c);
            }
        }
        return str;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}
