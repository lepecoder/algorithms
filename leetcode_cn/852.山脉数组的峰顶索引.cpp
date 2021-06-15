/*
 * @lc app=leetcode.cn id=852 lang=cpp
 *
 * [852] 山脉数组的峰顶索引
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int peakIndexInMountainArray(vector<int> &arr) {
        int i = 0;
        while (i + 1 < arr.size() && arr[i] < arr[i + 1]) { i++; }
        // while(i+1<arr.size() && arr[i]>arr[i+1]){
        // i++;
        // }
        return i;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}
