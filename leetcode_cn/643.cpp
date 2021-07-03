class Solution {
  public:
    double findMaxAverage(vector<int> &nums, int k) {
        int n = nums.size();
        if (n <= k) { return (accumulate(nums.begin(), nums.end(), 0) / double(n)); }
        double sum = 0;
        for (int i = 0; i < k; i++) { sum += nums[i]; }
        double res = sum / k;
        double t;
        for (int i = 0, j = k; j < n; i++, j++) {
            sum = sum + nums[j] - nums[i];
            t = sum / k;
            res = max(res, t);
        }
        return res;
    }
};
