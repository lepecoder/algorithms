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
    int rangeSum(vector<int> &nums, int n, int left, int right) {
        // int n = nums.size();
        vector<int> res(n * (n + 1) / 2);
        int idx = 0;
        for (int i = 0; i < n; i++) {
            // int temp = nums[i];
            // res.push_back(temp);
            int temp = 0;
            for (int j = i; j < n; j++) {
                temp += nums[j];
                // res.push_back(temp);
                res[idx++] = temp;
            }
        }
        sort(res.begin(), res.end());
        long long ans = 0;
        for (int i = left - 1; i < right; i++) { ans += res[i]; }
        return ans % (1000000007);
    }
};
// @lc code=end

int main() {
    Solution so;
    vector<int> v{1, 2, 3, 4};
    int ans = so.rangeSum(v, 4, 1, 5);
    cout << ans;
    return 0;
}