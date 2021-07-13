/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k%=n;
        int count = gcd(k,n);
        for (int start=0; start < count; start++){
            int current = start;
            do {
                int next = (current+k)%n;
                swap(nums[next], nums[start]);
                current = next;
            }while(current != start);
        }
    }
};
// @lc code=end

