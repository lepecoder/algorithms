/*
 * @lc app=leetcode.cn id=921 lang=cpp
 *
 * [921] 使括号有效的最少添加
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        int res = 0;
        for (char &c : s) {
            if (c == '(') {
                stk.emplace('(');
            } else {
                if (stk.top() == '(') { stk.pop(); }
            }
        }
        return stk.size();
    }
};
// @lc code=end

int main() {
    //
    return 0;
}