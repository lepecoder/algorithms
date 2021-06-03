/*
 * @lc app=leetcode.cn id=525 lang=cpp
 *
 * [525] 连续数组
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int findMaxLength(vector<int> &nums) {
        /*
        为了使得0和1的数量相同，也就是0的数量等于1的数量，
        将0视为-1，也就是【求最长连续子数组，其元素和为0】
        */
        /* 另一个思路 */
        /*
        因为除了0就是1，所以0的数量就等于子数组长度减去1的数量
         另一个思路错了，
         */
        int n = nums.size();
        int maxLength = 0;
        int count = 0;              // 记录前n项和
        unordered_map<int, int> mp; // <前n项和，下标>
        mp[0] = -1;                 // 为什么前0项和是-1??
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                count++;
            } else {
                count--;
            }
            if (mp.count(count)) {
                int preIndex = mp[count];
                maxLength = max(maxLength, i - preIndex);
            } else {
                mp[count] = i;
            }
        }
        return maxLength;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}