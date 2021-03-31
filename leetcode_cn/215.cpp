/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
  int findKthLargest(vector<int> nums, int k) {
    /*
    众所周知，快速排序每一轮都有一个元素到达自己的最终位置
    也就是说我们可以采用类似分治的方法，确定一个元素的位置
    后进一步确定需要找的元素是在左侧还是右侧
     */
    int temp = nums[0];
    int i = 0, j = nums.size();
    while (i < j) { // 逆序
      while (i < j && nums[j] <= temp)
        j--;
      nums[i] = nums[j];
      while (i < j && nums[i] >= temp)
        i++;
      nums[j] = nums[i];
    }
    // 此时i就是nums[0]的位置
    nums[i] = temp;
    if (i == k - 1)
      return temp;
    if (i > k - 1) {
      vector<int> v(nums.begin(), nums.begin() + i);
      return findKthLargest(v, k);
    } else {
      vector<int> v(nums.begin() + i + 1, nums.end());
      return findKthLargest(v, k - i);
    }
  }
};
// @lc code=end

int main() {
  Solution so;
  vector<int> v = {3, 2, 3, 1, 2, 4, 5, 5, 6};
  int ans = so.findKthLargest(v, 4);
  cout << ans;
  return 0;
}