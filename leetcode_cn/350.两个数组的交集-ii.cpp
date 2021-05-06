/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int idx1 = 0, idx2 = 0;
        vector<int> res;
        while (idx1 < nums1.size() && idx2 < nums2.size()) {
            if (nums1[idx1] == nums2[idx2]) {
                res.emplace_back(nums1[idx1]);
                idx1++;
                idx2++;
            } else if (nums1[idx1] < nums2[idx2])
                idx1++;
            else
                idx2++;
        }
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}