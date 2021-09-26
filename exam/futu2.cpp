#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 两次交易所能获得的最大收益
     * @param prices int整型vector 股票每一天的价格
     * @return int整型
     */
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        int dp[4];
        dp[0] = -prices[0]; // 第一次买入
        dp[1] = 0;          // 第一次买入后又卖出
        dp[2] = -prices[0];
        dp[3] = 0;
        for (int i = 1; i < n; i++) {
            dp[0] = max(dp[0], -prices[i]);
            dp[1] = max(dp[1], dp[0] + prices[i]);
            dp[2] = max(dp[2], dp[1] - prices[i]);
            dp[3] = max(dp[3], dp[2] + prices[i]);
        }
        cout << dp[3];
    }
};
int main() {
    //
    return 0;
}