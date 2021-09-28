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
        stack<int> st;
        for (char c : s) {
            if (c == '(')
                st.emplace('(');
            else {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                    res += 2;
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
