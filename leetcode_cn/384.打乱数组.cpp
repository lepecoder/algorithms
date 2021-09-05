/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    vector<int> nums;
    vector<int> res;
    int n;
    Solution(vector<int> &nums) {
        this->nums = nums;
        this->res = nums;
        n = nums.size();
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        res = nums;
        return res;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for (int i = n; i > 0; i--) {
            int idx = rand() % i;
            swap(res[idx], res[i - 1]);
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end

int main() {
    //
    return 0;
}