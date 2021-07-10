class Solution {
  public:
    vector<int> findErrorNums(vector<int> &nums) {
        int n = nums.size();
        int xorSum = 0;
        for (int &x : nums) { xorSum ^= x; }
        for (int i = 1; i <= n; i++) { xorSum ^= i; }
        int lowbit = xorSum & (-xorSum);
        // int lowbit = xorSum &(xorSum-1);
        int num1 = 0, num2 = 0;
        for (int &x : nums) {
            if ((x & lowbit) == 0) {
                num1 ^= x;
            } else {
                num2 ^= x;
            }
        }
        for (int x = 1; x <= n; x++) {
            if ((x & lowbit) == 0) {
                num1 ^= x;
            } else {
                num2 ^= x;
            }
        }
        for (int &x : nums) {
            if (x == num1) { return vector<int>{num1, num2}; }
        }
        return vector<int>{num2, num1};
    }
};
