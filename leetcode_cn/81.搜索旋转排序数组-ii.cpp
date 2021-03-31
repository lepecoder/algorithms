/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
  public:
    bool search(vector<int> &nums, int target)
    {
        // 旋转排序数组，
        // 如果mid>left,左边是排好序的，右边是乱序的，这样就可以判断是target在哪部分
        // 但是如果mid=left. 比如2 5 6 2 2 2 1左边可能是有序
        // 2 5 1 2 2 2 2  左边是无序的
        // 此时没有办法二分，技巧是既然mid==left而left!=target
        // 那么我们可以将left++

        int left = 0, right = nums.size() - 1;
        int mid;
        while (left <= right) {
            if (left == right) 
           return nums[left] == target;
            mid = (left + right) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[mid] > nums[left]) {                          // 左侧递增
                if (nums[mid] > target && target >= nums[left]) {  // target在左侧
                    right = mid - 1;
                } else {  // target在右侧
                    left = mid + 1;
                }
            } else if (nums[mid] < nums[left]) {  // 右侧递增
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {  // nums[mid] = numd[left]
                left++;
            }
        }
        return nums[left] == target;
    }
};
// @lc code=end

int main()
{
    //
    Solution so;
    vector<int> v{1, 0, 1, 1, 1};
    bool ans = so.search(v, 0);
    cout << ans;
    return 0;
}