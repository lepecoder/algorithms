#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    /**
     * max sum of the subarray
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxsumofSubarray(vector<int> &arr) {
        // write code here
        int n = arr.size();
        int dp[n + 1];
        dp[0] = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            dp[i + 1] = max(arr[i], dp[i] + arr[i]);
            res = max(res, dp[i + 1]);
        }
        return res;
    }
};
int main() {
    //
    return 0;
}