/*
 * @lc app=leetcode.cn id=1111 lang=cpp
 *
 * [1111] 有效括号的嵌套深度
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    vector<int> maxDepthAfterSplit(string seq) {
        int d = 0;
        vector<int> ans;
        for (char &c : seq) {
            if (c == '(') {
                d++;
                ans.emplace_back(d % 2);
            } else {
                ans.emplace_back(d % 2);
                d--;
            }
        }
        return ans;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}