/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        int tails[n]; // tail[k] 表示长度为k+1的子序列尾部元素的值
        memset(tails, 0, sizeof(tails));
        // 我们希望在长度相同的条件下，尽量加入小的字符
        int res = 0; // tails长度，直到当前的最长上升子序列的长度，
        for (int &num : nums) {
            int i = 0, j = res;
            // int *it = upper_bound(tails, tails + res + 1, num);
            // if (*it==0) res++;
            // *it = num;
            while (i < j) { // 在tails里找到大于等于num的第一个
                int m = (i + j) / 2;
                if (tails[m] < num)
                    i = m + 1;
                else
                    j = m;
            }
            tails[i] = num;
            if (j == res) res++;
        }
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}