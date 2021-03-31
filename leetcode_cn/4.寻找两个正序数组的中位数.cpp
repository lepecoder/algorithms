/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
    /*
    两个正序数的中位数，对于奇数序列，是(m+n)/2,对于偶数序列，是(m+n/2)和(m+n/2)+1的平均值
    令k = (m+n)/2, 也就是说我们要找两个有序序列的第k小的元素
    可以在每个序列找第(k/2)个元素A[k/2-1]和B[k/2-1]
    找AB中较小的元素，假设位于A序列，那么在A序列之前有(k/2)-1个元素
    B序列上最少可以有0个元素，最多也只能有(k/2)-1个元素比A[k/2-1]小
    所以A[k/2-1]最多是第k-2个数，那么一定不是我们要找的中位数
    因此我们可以去掉A序列的前k/2个数,

    我们可以归纳为以下3中情况：
    1. A[k/2-1]<B[k/2-1],可以排除A[0]-A[k/2-1]
    2. A[k/2-1]>B[k/2-1]
    3. A[k/2-1]=B[k/2-1]，那么A[k/2-1]就是我们要找的第k个元素
    特殊情况：
    1. 如果有一个序列很小，k/2-1是有可能越界的，这时候我们直接定位为最后一个元素
       这时候去除前面元素的个数需要注意
    2. 如果一个数组是空，直接返回另一个数组的A[k-1]
    3. k=1,直接返回两个序列最小的首元素
    */
  public:
    int getKthElement(const vector<int> &nums1, const vector<int> &nums2, int k) {
        //   找两个有序数组的第k个数, k从1开始
        int n = nums1.size(), m = nums2.size();
        int idx1 = 0, idx2 = 0;
        while (true) {
            if (idx1 == n) return nums2[idx2 + k - 1];
            if (idx2 == m) return nums1[idx1 + k - 1];
            if (k == 1) return min(nums1[idx1], nums2[idx2]);

            // 正常情况
            int newidx1 = min(idx1 + k / 2 - 1, n - 1);
            int newidx2 = min(idx2 + k / 2 - 1, m - 1);
            int pivot1 = nums1[newidx1];
            int pivot2 = nums2[newidx2];
            if (pivot1 <= pivot2) {
                k -= newidx1 - idx1 + 1;
                idx1 = newidx1 + 1;
            } else {
                k -= newidx2 - idx2 + 1;
                idx2 = newidx2 + 1;
            }
        }
    }
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int totalLength = nums1.size() + nums2.size();
        if (totalLength % 2 == 1) { // 基数
            return getKthElement(nums1, nums2, (totalLength + 1) / 2);
        } else {
            return (getKthElement(nums1, nums2, totalLength / 2) + getKthElement(nums1, nums2, totalLength / 2 + 1) / 2.0);
        }
    }
};
// @lc code=end

int main() {
    //
    return 0;
}