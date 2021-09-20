#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
  public:
    /**
     * max increasing subsequence
     * @param arr int整型vector the array
     * @return int整型
     */
    int MLS(vector<int> &arr) {
        // write code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int dp[n];
        // memset(dp, 1, sizeof(dp));
        dp[0] = 1;
        int res = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i - 1] + 1) {
                dp[i] = dp[i - 1] + 1;
                res = max(res, dp[i]);
            } else {
                dp[i] = 1;
            }
        }
        return res;
    }
};
int main() {
    //
    vector<int> arr = {100, 4, 200, 1, 3, 2};
    Solution so;
    cout << so.MLS(arr);
    return 0;
}