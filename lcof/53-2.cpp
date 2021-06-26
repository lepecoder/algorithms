class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
		int sum_n = n*(n+1)/2;       
		int sum = accumulate(nums.begin(),nums.end());
		int res = sum_n-sum;
		return res;
    }
};
