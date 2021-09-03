/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        int left_min = prices[0];
        int res = 0;
        for (int i = 1; i < n; i++) {
            res = max(res, prices[i] - left_min);
            left_min = min(left_min, prices[i]);
        }
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}
