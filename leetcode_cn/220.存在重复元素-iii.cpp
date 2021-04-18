/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
// @lc code=start
class Solution {
  public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        /*
        map<val,index>，由于map里的元素能自动排序，所以我们每次需要删除index最小的，
        然后插入新的pair，此时只需要比较pair左右的元素就可以。
        */
        int n = nums.size();
        multimap<int, int> mm;
        for (int i = 0; i < k; i++) { mm.emplace(nums[i], i); }
        for (auto i = mm.begin(); (i++) < (mm.end()); i++) {}
    }
};
// @lc code=end

int main() {
    //
    return 0;
}