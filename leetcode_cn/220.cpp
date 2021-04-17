/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    bool containsNearbyAlmostDuplicat(vector<int> &nums, int k, int t) {
        /*
        使用k-1个元素的有序集合，每次有集合中判定是否有差小于t的元素，如果没有
        抛出一个元素，放入另一个元素，由于元素本身是有序的，所以插入排序的时间复杂度是
        O(nlogk)
        */
        set<int> set_;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            // 查找set_里大于nums[i]的最小元素
            auto it = set_.lower_bound(max(nums[i], INT_MIN + t) - t);
            if (it != set_.end() && *it <= min(nums[i], INT_MAX - t) + t) { return true; }
            set_.insert(nums[i]);
            if (i >= k) set_.erase(nums[i - k]);
        }
        return false;
    }
    int getID(int x, long len) {
        /* len是桶的范围 */
        if (x >= 0)
            return x / len;
        else {
            return (x + 1) / len - 1;
        }
    }
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        /*
        使用桶排序的思想, 桶的大小是t+1
        如果桶内有元素，那么一定满足abs(nums[i]-nums[j]<=t)
        如果桶内没有元素，检查相邻桶，如果相邻桶有元素，同样有可能满足条件
        如果相邻桶也不能满足条件，将元素放入对应桶中
        移除k之前的桶
        由于每个桶最多只有一个元素，可能用unorder_map实现
         */
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int id = getID(nums[i], t + 1);
            if (mp.count(id))
                return true;
            else if (mp.count(id - 1) && nums[i] - mp[id - 1] <= t)
                return true;
            else if (mp.count(id + 1) && mp[id + 1] - nums[i] <= t)
                return true;
            mp.emplace(id, nums[i]);
            if (i >= k) mp.erase(getID(nums[i - k], t + 1));
        }
        return false;
    }
};
// @lc code=end

int main() {
    cout << INT_MIN;
    return 0;
}
