#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算最小航行费用
     * @param input int整型vector<vector<>> 二维网格
     * @return int整型
     */
    int minSailCost(vector<vector<int>> &input) {
        // write code here
        int n = input.size();
        int m = input[0].size();
        long long int dp[n][m];
        dp[0][0] = 0;
        int t;
        for (int i = 1; i < n; i++) {
            if (input[i][0] == 0) {
                t = 2;
            } else if (input[i][0] == 1) {
                t = 1;
            } else {
                t = -1;
            }
            if (t == -1 || dp[i - 1][0] == -1) {
                dp[i][0] = -1;
            } else {
                dp[i][0] = dp[i - 1][0] + t;
            }
        }

        for (int j = 1; j < m; j++) {
            if (input[0][j] == 0) {
                t = 2;
            } else if (input[0][j] == 1) {
                t = 1;
            } else {
                t = -1;
            }
            if (t == -1 || dp[0][j - 1] == -1) {
                dp[0][j] = -1;
            } else {
                dp[0][j] = dp[0][j - 1] + t;
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (input[i][j] == 0) {
                    t = 2;
                } else if (input[i][j] == 1) {
                    t = 1;
                } else {
                    t = -1;
                }
                if (t == -1 || (dp[i - 1][j] == -1 && dp[i][j - 1] == -1)) {
                    dp[i][j] = -1;
                } else if (dp[i - 1][j] == -1) {
                    dp[i][j] = dp[i][j - 1] + t;
                } else if (dp[i][j - 1] == -1) {
                    dp[i][j] = dp[i - 1][j] + t;
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + t;
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};

int main() {
    //
    return 0;
}