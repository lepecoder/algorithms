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
  bool checkPossibility(vector<int> &nums) {
    //   找第一个不符合递增的位置
    int k = 0, n = nums.size();
    if (n == 1)
      return true;
    while (k < n - 1 && nums[k] <= nums[k + 1])
      ++k;
    // 此时k之前的都是非递减，有可能去掉k，也有可能去掉k+1
    // 此时需要考虑 k-1, k, k+1, k+2
    // 如果k=n-1，返回true
    if (k == n - 1 || k == n - 2)
      return true;
    // 如果去掉k
    int temp = nums[k];
    nums[k] = k == 0 ? nums[k + 1] : nums[k - 1];
    int t = k;
    while (k < n - 1 && nums[k] <= nums[k + 1])
      ++k;
    if (k == n - 2)
      return true;
    // 如果去掉k+1
    nums[t] = temp;
    nums[t + 1] = temp;
    while (t < n - 1 && nums[t] <= nums[t + 1])
      ++t;
    if (t == n - 2)
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