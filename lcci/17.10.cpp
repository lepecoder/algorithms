class Solution {
  public:
    int majorityElement(vector<int> &nums) {
        int n = nums.size();
        int res;
        int count = 0;
        for (int &x : nums) {
            if (count == 0) {
                count = 1;
                res = x;
            } else if (x == res) {
                count++;
            } else {
                count--;
            }
        }
        if (count == 0) {
            return -1;
        } else {
            return res;
        }
    }
};
