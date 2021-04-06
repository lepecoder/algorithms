/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 */
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        // 有序数组，使得最多有两个重复元素
        // 可以使用双指针，i指向当前遍历的元素，j指向新的数组的结尾，
        // 通常i>=j
        int i = 0, j = 0;
        int n = nums.size();
        if (n <= 2) { return n; }
        int pre_num = nums[0]; // 前一个数字
        int pre_count = 0;     // 前一个数字出现的次数
        for (i = 0; i < n; i++) {
            if (nums[i] == pre_num) { // 重复出现
                if (pre_count < 2) {  // 但是小于2次
                    pre_count++;
                    nums[j++] = nums[i];
                }
            } else { // 和前一个数字不同
                pre_num = nums[i];
                pre_count = 1;
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};
// @lc code=end

int main() {
    Solution so;
    vector<int> v = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    int ans = so.removeDuplicates(v);
    cout << ans << endl;
    for (auto &x : v) { cout << x << ' '; }
    return 0;
}