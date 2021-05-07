/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int n = nums.size();
        int left_prod[n + 1];
        int right_prod[n + 1];
        left_prod[0] = 1;
        for (int i = 0; i < n; i++) { left_prod[i + 1] = left_prod[i] * nums[i]; }
        right_prod[n] = 1;
        for (int i = n - 1; i >= 0; i--) { right_prod[i] = right_prod[i + 1] * nums[i]; }
        vector<int> res(n);
        for (int i = 0; i < n; i++) { res[i] = left_prod[i] * right_prod[i + 1]; }
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}