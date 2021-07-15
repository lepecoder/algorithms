/*
 * @lc app=leetcode.cn id=1846 lang=cpp
 *
 * [1846] 减小和重新排列数组后的最大元素
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        int pre = arr[0];
        int res = 1;
        for (int i = 1; i < n; i++) {
            if (pre + 1 < arr[i]) { arr[i] = pre + 1; }
            res = max(res, arr[i]);
            pre = arr[i];
        }
        for (int i = 0; i < n; i++) { cout << arr[i] << ' '; }
        return arr[n - 1];
    }
};
// @lc code=end

int main() {
    //
    return 0;
}