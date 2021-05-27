/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  private:
    bool isNumber(string &token) { return !(token == "+" || token == "-" || token == "*" || token == "/"); }

  public:
    int evalRPN(vector<string> &tokens) {
        int n = tokens.size();
        stack<int> stk;
        for (string &c : tokens) {
            if (isNumber(c)) {
                stk.emplace(atoi(c.c_str()));
            } else {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                switch (c[0]) {
                case '+': stk.emplace(a + b); break;
                case '-': stk.emplace(a - b); break;
                case '*': stk.emplace(a * b); break;
                case '/': stk.emplace(a / b); break;
                }
            }
        }
        return stk.top();
    }
};
// @lc code=end

int main() {
    //
    return 0;
}
