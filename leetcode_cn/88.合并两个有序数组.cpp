/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    void merge1(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int k = m;        // 末尾指针
        int i = 0, j = 0; // 两个数组的头指针
        while (j < n) {
            // 找到第一个nums1[i]>nums[j]的位置
            while (i <= k && nums1[i] <= nums2[j]) { i++; }
            // nums2[j]插入到i之前
            int t = k++;
            while (t > i) {
                nums1[t] = nums1[t - 1];
                t--;
            }
            nums1[t] = nums2[j++];
        }
    }
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int k = n + m - 1;
        int i = m - 1, j = n - 1;
        while (k >= 0) {
            if (j < 0 || i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
            if (j < 0) { break; }
        }
    }
};
// @lc code=end

int main() {
    Solution so;
    vector<int> v1 = {1}, v2 = {};
    so.merge(v1, 1, v2, 0);
    for (auto &x : v1) { cout << x << ' '; }
    return 0;
}