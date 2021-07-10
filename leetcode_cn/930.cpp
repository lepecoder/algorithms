class Solution {
  public:
    int numSubarraysWithSum(vector<int> &nums, int goal) {
        int sum = 0;
        unordered_map<int, int> mp;
        int res = 0;
        for (int &x : nums) {
            mp[sum]++;
            sum += x;
            res += mp[goal - sum];
        }
        return res;
    }
};
