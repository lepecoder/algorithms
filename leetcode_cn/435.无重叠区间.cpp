/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    // 对区间结尾排序，结尾越小留给后面的空间越大
    sort(intervals.begin(), intervals.end(),
         [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });
    int n = intervals.size();
    if (n < 2)
      return 0;
    int ans = 0;
    int pre = intervals[0][1]; // 开始区间的结尾
    for (int i = 1; i < n; ++i) {
      if (intervals[i][0] >= pre) { // 这个区间可以加上
        pre = intervals[i][1];
      } else {
        ++ans;
      }
    }
    return ans;
  }
};
// @lc code=end

int main() { return 0; }