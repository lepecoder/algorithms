/*
 * @lc app=leetcode.cn id=1508 lang=cpp
 *
 * [1508] 子数组和排序后的区间和
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    //   非空连续子数组的和
    vector<int> ans;
    void backtrack(vector<int> path, vector<int> &nums, int k) {
        int t = accumulate(path.begin(), path.end(), 0);
        ans.push_back(t);
        if (k < nums.size()) {
            path.push_back(nums[k]);
            backtrack(path, nums, k + 1);
        }
        // for (int i = k; i < nums.size(); i++) {
        // path.push_back(nums[i]);
        // backtrack(path, nums, i + 1);
        // path.pop_back();
        // }
    }
    int rangeSum(vector<int> &nums, int n, int left, int right) {
        vector<int> path;
        for (int i = 0; i < n; i++) {
            path.push_back(nums[i]);
            backtrack(path, nums, i + 1);
            path.pop_back();
        }
        sort(ans.begin(), ans.end());
        long long res = 0;
        for (int i = left - 1; i < right && i < ans.size(); i++) { res += ans[i]; }
        res = res % (1000000007);
        return res;
    }
};
// @lc code=end

int main() {
    Solution so;
    vector<int> v = {1, 2, 3, 4};
    int ans = so.rangeSum(v, 4, 1, 5);
    cout << ans;
    return 0;
}