class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n == 0) return 0;
        int premin = prices[0];
        int res = 0;
        for (int i = 1; i < n; i++) {
            res = max(res, prices[i] - premin);
            premin = min(premin, prices[i]);
        }
        return res;
    }
};
