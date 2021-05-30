/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int subarraySum(vector<int> &nums, int k) {
        /*
        假定用pre记录前n项和，那么j...i的前n项和等于k就是
        pre[i]-pre[j-1] == k
        也就是说，在遍历到i的时候，我们希望找到之前的前n项和满足
        pre[j-1] = pre[i]-k
        使用mp记录前n项和出现的次数，
        */
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, pre = 0;
        for (int &x : nums) {
            pre += x;
            if (mp.find(pre - k) != mp.end()) { count += mp[pre - k]; }
            mp[pre]++;
        }
    }
};
// @lc code=end

int main() {
    //
    return 0;
}