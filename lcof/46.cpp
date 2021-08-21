#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int translateNum(int num) {
        string nums = to_string(num);
        int n = nums.size();
        if (n == 1) return 1;
        int dp[n + 1]; // dp[i] 前i
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 1; i < n; i++) {
            dp[i + 1] = dp[i];
            if (nums[i - 1] == '1' || nums[i - 1] == '2' && nums[i] >= '0' && nums[i] <= '5') { // 和前一个可以组成10,11,12,...,25
                dp[i + 1] += dp[i - 1];
            }
        }
        return dp[n];
    }
};
int main() {
    //
    return 0;
}