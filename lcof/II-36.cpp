#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool isNumber(string str) {
        if (str == "+" || str == "-" || str == "*" || str == "/") {
            return false;
        } else {
            return true;
        }
    }
    int evalRPN(vector<string> &tokens) {
        stack<int> st;
        // int res = 0;
        for (string &s : tokens) {
            if (isNumber(s)) { // 数字入栈
                st.emplace(stoi(s));
            } else { // 运算符，从栈顶取两个数计算
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int c;
                if (s == "+") {
                    c = a + b;
                } else if (s == "-") {
                    c = a - b;
                } else if (s == "*") {
                    c = a * b;
                } else {
                    c = a / b;
                }
                st.emplace(c);
            }
        }
        return st.top();
    }
};
int main() {
    //
    return 0;
}