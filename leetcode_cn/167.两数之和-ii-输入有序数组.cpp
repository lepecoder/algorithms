/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    int i = 0, j = numbers.size() - 1;
    // int t;
    // vector<int> ans(2);
    while (i < j) {
      if (numbers[i] + numbers[j] == target) {
        // ans[0] = i+1, ans[1] = j+1;
        return {i + 1, j + 1};
      } else if (numbers[i] + numbers[j] < target) {
        i++;
      } else {
        j--;
      }
    }
    return {i + 1, j + 1};
  }
};
// @lc code=end

int main() { return 0; }