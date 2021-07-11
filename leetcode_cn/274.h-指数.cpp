/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        int res = 0;
        for(int &x:citations){
            res = max(res, max(x, n));
            n--;
        }
        return res;
    }
};
// @lc code=end


int main(){
    // 
    return 0;
}