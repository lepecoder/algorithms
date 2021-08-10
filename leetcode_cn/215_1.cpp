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
    int findKthLargest(vector<int> &nums, int k) {
        int n = nums.size();
        // 从后往前挨个调整堆
        for (int i = n / 2; i >= 0; i--) { adjust(nums, n, i); }
        for (int i = n - 1; i >= 0; i--) {
            if (k-- == 0) return nums[0];
            // cout << nums[0] << ' ';
            swap(nums[0], nums[i]);
            adjust(nums, i, 0);
        }
        return nums[0];
    }
    void adjust(vector<int> &nums, int len, int idx) {
        /** 调整第idx个节点，使它的左右子节点都比他小
         * 由于可能导致节点互换，因此这是一个递归的调整
         */
        int l = 2 * idx + 1;
        int r = 2 * idx + 2;
        int maxid = idx;
        if (l < len && nums[l] > nums[maxid]) maxid = l;
        if (r < len && nums[r] > nums[maxid]) maxid = r;
        if (maxid != idx) {
            swap(nums[idx], nums[maxid]);
            adjust(nums, len, maxid);
        }
    }
};
// @lc code=end

int main() {
    Solution so;
    vector<int> v{8, 1, 14, 3, 21, 5, 7, 10};
    so.findKthLargest(v, 5);
    //
    return 0;
}