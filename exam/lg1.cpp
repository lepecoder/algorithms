#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 输入一个带字符宽度控制的字符串和文本框宽度， 返回文本框内的最后一个可见字符
     * @param inputText string字符串 输入的字符串
     * @param limitSize int整型 文本框宽度
     * @return char字符型
     */
    int update(stack<int> &st, int idx, string &inputText) {
        int i;
        int w = 0;
        for (i = idx + 1; inputText[i] != '>'; i++) {
            if (inputText[i] == '/') {
                st.pop();
            } else if (inputText[i] >= '0' && inputText[i] <= '9') {
                w = w * 10 + inputText[i] - '0';
            }
        }
        if (w > 0) { st.emplace(w); }
        return i; // >所在位置
    }
    char GetLastVisibleCharInBox(string inputText, int limitSize) {
        // write code here
        int n = inputText.size();
        int res = 0;
        int i;
        char pre;
        for (i = 0; i < n; i++) {
            if (inputText[i] >= 'a' && inputText[i] <= 'z' || inputText[i] >= 'A' && inputText[i] <= 'Z') {
                pre = inputText[i];
                break;
            }
        }
        stack<int> st;
        st.emplace(16);
        int t;
        for (int i = 0; i < n; i++) {
            if (inputText[i] >= 'a' && inputText[i] <= 'z' || inputText[i] >= 'A' && inputText[i] <= 'Z') {
                // t++;
                res += st.top();
                if (res > limitSize) return pre;
                pre = inputText[i];
            } else if (inputText[i] == ' ') {
                // t++;
                res += st.top();
                if (res > limitSize) return pre;
                pre = inputText[i];
            } else if (inputText[i] == '<') {
                // res+=t* st.top();
                // t=0;
                i = update(st, i, inputText);
            }
        }
        return pre;
    }
};
int main() {
    //

    return 0;
}