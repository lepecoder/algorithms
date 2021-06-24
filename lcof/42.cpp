class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		int n = nums.size();
		int dp[n+1];
		dp[0] = 0;
		int res = nums[0];
		for(int i=0;i<n;i++){
			dp[i+1] = max(dp[i]+nums[i], nums[i]);
			res = max(res, dp[i+1]);
		}
		return res;
    }
};
