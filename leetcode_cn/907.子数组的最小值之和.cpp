/*
 * @lc app=leetcode.cn id=907 lang=cpp
 *
 * [907] 子数组的最小值之和
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    const int mod = 1000000007;
    int sumSubarrayMins(vector<int> &arr) {
        int n = arr.size();
        int res = 0;
        int min_;
        for (int i = 0; i < n; i++) {
            // res += arr[i];
            // if(res>=mod) res-=mod;
            min_ = arr[i];
            for (int j = i; j < n; j++) {
                min_ = min(min_, arr[j]);
                res += min_;
                if (res >= mod) res -= mod;
            }
        }
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}
