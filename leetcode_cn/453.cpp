class Solution {
  public:
    int minMoves(vector<int> &nums) {
        int sum_ = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int t = sum_ + 1 - n;
        int min_ = *min_element(nums.begin(), nums.end());
        return t - min_;
    }
};
