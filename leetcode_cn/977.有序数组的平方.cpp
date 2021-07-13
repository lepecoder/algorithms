/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        res.reserve(n);
        // 找到绝对值最小的元素的位置,可能好好几个，返回任意个都可以
        int idx = n-1;
        for (int i=0;i<n-1;i++){
            if (abs(nums[i]) < abs(nums[i+1])){
                idx = i;
            }
        }
        int l=idx, r=idx+1;
        while (l>=0 && r<n){
            if (abs(nums[l]) < abs(nums[r])){
                res.push_back(nums[l]*nums[l]);
                l--;
            }else{
                res.push_back(nums[r]*nums[r]);
                r++;
            }
        }

        while (l>=0){
            res.push_back(nums[l]*nums[l]);
            l--;
        }
        while (r<n){
            res.push_back(nums[r]*nums[r]);
            r++;
        }
        return res;
    }
};
// @lc code=end

