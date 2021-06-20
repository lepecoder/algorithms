/*
 * @lc app=leetcode.cn id=1239 lang=cpp
 *
 * [1239] 串联字符串的最大长度
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int maxLength(vector<string> &arr) {
        vector<int> masks;
        for (string &s : arr) {
            int mask = 0;
            for (char ch : s) {
                ch -= 'a';
                if ((mask >> ch) & 1) { // 本身就包括重复字符
                    mask = 0;
                    break;
                }
                mask |= 1 << ch;
            }
            if (mask > 0) { masks.emplace_back(mask); }
        }
        int ans = 0;
        function<void(int, int)> backtrack = [&](int pos, int mask) {
            if (pos == masks.size()) {
                ans = max(ans, __builtin_popcount(mask));
                return;
            }
            if ((mask & masks[pos]) == 0) { backtrack(pos + 1, mask | masks[pos]); }
            backtrack(pos + 1, mask);
        };
        backtrack(0, 0);
        return ans;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}