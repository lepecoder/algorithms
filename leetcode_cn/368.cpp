/*
 * @lc app=leetcode.cn id=368 lang=cpp
 *
 * [368] 最大整除子集
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
struct comp {
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) const { return p1.second < p2.second; }
};

class Solution {
  public:
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        // 定义优先队列，按照值降序；
        // priority_queue<pair<int, int>, vector<pair<int, int>>, comp> priq;
        // <子集数，key>, 按照子集数从大到小排序
        multimap<int, int, greater<int>> mmp;
        // 源容器排序
        sort(nums.begin(), nums.end());
        for (int &x : nums) {
            int max_divis = 1; // 子集数，至少是它本身
            // 找到子集最多的因子
            for (auto it = mmp.begin(); it != mmp.end(); it++) {
                if (x % it->second == 0) { // 能被整除
                    max_divis = max(max_divis, it->first + 1);
                    break;
                }
            }
            mmp.emplace(max_divis, x);
        }
        auto it = mmp.begin();
        vector<int> res(it->first);
        int k = it->first;
        int pre_i = it->second;
        int pre_c = it->first;
        // res.emplace_back(pre_i);
        res[--k] = pre_i;
        it++;
        for (; it != mmp.end(); it++) {
            if (pre_i % it->second == 0 && pre_c - 1 == it->first) {
                --pre_c;
                pre_i = it->second;
                // res.emplace_back(it->second);
                res[--k] = it->second;
            }
        }
        return res;
    }
};

// @lc code=end
int main() {
    //
    Solution so;
    vector<int> nums = {1, 2, 3};
    so.largestDivisibleSubset(nums);
    return 0;
}