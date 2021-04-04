/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        int max_count = 0; // 最大出现次数
        unordered_map<int, int> map_fre;
        for (auto &num : nums) { max_count = max(max_count, ++map_fre[num]); }
        // 建立max_count+1个桶, 第k个桶装出现k次的数字的集合
        vector<set<int>> buckets(max_count + 1);
        for (auto &m : map_fre) { buckets[m.second].insert(m.first); }
        vector<int> ans;
        for (int i = max_count; i >= 0 && ans.size() < k; i--) {
            for (auto &m : buckets[i]) {
                ans.push_back(m);
                if (ans.size() == k) break;
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