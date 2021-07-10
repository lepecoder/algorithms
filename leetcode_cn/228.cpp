class Solution {
  public:
    string getRange(int a, int b) {
        if (a == b)
            return to_string(a);
        else {
            return to_string(a) + "->" to_string(b);
        }
    }
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> res;
        int n = nums.size();
        if (n == 0) return res;
        int pre = nums[0];
        int a = pre, b;
        for (int i = 1; i < n; i++) {
            if (pre + 1 == nums[i]) {
                pre = nums[i];
            } else {
                b = pre;
                string s = getRange(a, b);
                res.emplace_back(s);
                a = nums[i];
                pre = a;
            }
        }
        return res;
    }
};
