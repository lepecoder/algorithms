/*
 * @lc app=leetcode.cn id=665 lang=cpp
 *
 * [665] 非递减数列
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
  int isPossi(vector<int> &nums) {
    //  检查是否是非递减序列
    // 返回第一个不是递减的数字的位置
    // 如果是递减序列，返回-1
    int idx = 0, n = nums.size();
    while (idx < n - 1 && nums[idx] <= nums[idx + 1]) {
      ++idx;
    }
    if (idx == n - 1)
      return -1;
    return idx;
  }
  bool checkPossibility(vector<int> &nums) {

    int n = nums.size();
    if (n < 3)
      return true;
    int idx = isPossi(nums);
    if (idx == -1)
      return true;
    int temp = nums[idx];
    nums[idx] = idx == 0 ? nums[idx + 1] : nums[idx - 1];
    int t = isPossi(nums);
    if (t == -1)
      return true;
    nums[idx] = temp;
    if (idx == n - 1)
      return false;
    nums[idx + 1] = temp;
    t = isPossi(nums);
    if (t == -1)
      return true;
    return false;
  }
};
// @lc code=end

int main() {
  vector<int> v = {4, 2, 1};
  Solution so;

  auto ans = so.checkPossibility(v);
  cout << ans;
  return 0;
}
