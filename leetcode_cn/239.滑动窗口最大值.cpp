/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// @lc code=start
class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        int n = nums.size();
        deque<int> q;
        int idx = 0;
        int x;
        while (idx < n && idx < k) {
            x = nums[idx++];
            while (!q.empty() && q.back() < x) q.pop_back();
            q.emplace_back(x);
        }
        vector<int> res;
        res.reserve(n - k + 1);
        while (true) {
            res.emplace_back(q.front());
            if (idx >= n) break;
            x = nums[idx];
            while (!q.empty() && q.back() < x) q.pop_back();
            q.emplace_back(x);
            if (nums[idx - k] == q.front()) q.pop_front();
            idx++;
        }
        // res.emplace_back(q.front());

        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}
