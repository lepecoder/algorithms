/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int removeElement(vector<int> &nums, int val) {
        int i, j;
        for (i = 0, j = 0; j < nums.size(); j++) {
            if (nums[j] != val) { nums[i++] = nums[j]; }
        }
        return i;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}