/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        if (n == 0) return res;
        // res.reserve(n);
        stack<int> stk; // 单调不增的栈
        for (int i = 0; i < 2 * n - 1; i++) {
            while (!stk.empty() && nums[stk.top()] < nums[i % n]) {
                res[stk.top()] = nums[i % n];
                stk.pop();
            }
            stk.push(i % n);
        }
        return res;
    }
};
// @lc code=end

int main() {
    //
    int a = 3;
    cout << a++ % 2;
    return 0;
}