/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 *
 * https://leetcode-cn.com/problems/house-robber-ii/description/
 *
 * algorithms
 * Medium (40.94%)
 * Likes:    499
 * Dislikes: 0
 * Total Accepted:    82.6K
 * Total Submissions: 200.7K
 * Testcase Example:  '[2,3,2]'
 *
 * 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都
 * 围成一圈
 * ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警
 * 。
 *
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下
 * ，能够偷窃到的最高金额。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [2,3,2]
 * 输出：3
 * 解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）,
 * 因为他们是相邻的。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1,2,3,1]
 * 输出：4
 * 解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
 * 偷窃到的最高金额 = 1 + 3 = 4 。
 *
 * 示例 3：
 *
 *
 * 输入：nums = [0]
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 0
 *
 *
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int rob1(vector<int> &nums) {
    int n = nums.size();
    if (n == 0)
      return 0;
    int *dp = new int[n];
    for (int i = 0; i < n; i++)
      dp[i] = 0;
    if (n >= 1)
      dp[0] = nums[0];
    if (n >= 2)
      dp[1] = max(nums[1], nums[0]);

    for (int i = 2; i < n; i++) {
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    return dp[n - 1];
  }
  int rob(vector<int> &nums) {
    if (nums.size() == 0)
      return 0;
    if (nums.size() == 1)
      return nums[0];
    vector<int> v1(nums.begin() + 1, nums.end());
    vector<int> v2(nums.begin(), nums.end() - 1);

    return max(rob1(v1), rob1(v2));
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  Solution so;
  vector<int> v = {5, 2, 4, 10};
  cout << so.rob(v);
  return 0;
}
