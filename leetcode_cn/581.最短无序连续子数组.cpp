/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int findUnsortedSubarray(vector<int> &nums) {
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        int i = 0, j = nums.size() - 1;
        int n = nums.size();
        while (i < n && nums[i] == arr[i]) { i++; }
        while (j > i && nums[j] == arr[j]) { j--; }
        return j - i + 1;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}