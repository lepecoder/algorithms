/*
 * @lc app=leetcode.cn id=1686 lang=cpp
 *
 * [1686] 石子游戏 VI
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int stoneGameVI(vector<int> &aliceValues, vector<int> &bobValues) {
        vector<pair<int, int>> mp;
        int n = aliceValues.size();
        for (int i = 0; i < n; i++) { mp.emplace_back(aliceValues[i] + bobValues[i], i); }
        sort(mp.rbegin(), mp.rend()); // 从大到小排序
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                sum1 += aliceValues[mp[i].second];
            } else
                sum2 += bobValues[mp[i].second];
        }
        if (sum1 == sum2)
            return 0;
        else if (sum1 > sum2)
            return 1;
        else
            return -1;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}