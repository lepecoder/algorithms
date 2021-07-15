/*
 * @lc app=leetcode.cn id=1818 lang=cpp
 *
 * [1818] 绝对差值和
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int minAbsoluteSumDiff(vector<int> &nums1, vector<int> &nums2) {
        vector<int> n1 = nums1;
        vector<int> n2 = nums1;
        int res = 0;
        int n = nums1.size();
        sort(n1.begin(), n1.end());
        sort(n2.begin(), n2.end(), greater<int>());
        int d_max = 0; // 维护一个最大差值
        for (int i = 0; i < n; i++) {
            int t = abs(nums1[i] - nums2[i]);
            res += t;
            if (res > 1010000007) { res %= 1000000007; }
            // 找到离nums2[i] 最近的左右两个元素
            auto g_than = lower_bound(n1.begin(), n1.end(), nums2[i]);
            auto l_than = lower_bound(n2.begin(), n2.end(), nums2[i], greater<int>());
            if (g_than != n1.end()) { d_max = max(d_max, t - (*g_than - nums2[i])); }
            if (l_than != n2.end()) { d_max = max(d_max, t - (nums2[i] - *l_than)); }
        }
        return (res - d_max) % 1000000007;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}