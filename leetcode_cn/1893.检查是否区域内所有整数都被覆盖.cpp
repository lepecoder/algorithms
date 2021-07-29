/*
 * @lc app=leetcode.cn id=1893 lang=cpp
 *
 * [1893] 检查是否区域内所有整数都被覆盖
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    bool isCovered(vector<vector<int>> &ranges, int left, int right) {
        bool bs[right - left + 1];
        memset(bs, false, sizeof(bs));
        for (auto &range : ranges) {
            for (int i = range[0]; i <= range[1]; i++) {
                if (i >= left && i <= right) bs[i - left] = true;
            }
        }
        for (int i = 0; i <= right - left; i++) {
            if (bs[i] == false) return false;
        }
        return true;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}