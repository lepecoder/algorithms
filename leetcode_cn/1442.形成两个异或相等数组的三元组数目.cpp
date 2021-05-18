/*
 * @lc app=leetcode.cn id=1442 lang=cpp
 *
 * [1442] 形成两个异或相等数组的三元组数目
 */
#include <bits/stdc++.h>
using namespace std;

// IO
int _IO = []() {
    std::ios::sync_with_stdio(0);
    cin.tie(0); // cout.tie(0);
    return 0;
}();
// @lc code=start
class Solution {
  public:
    int countTriplets(vector<int> &arr) {
        int n = arr.size();
        int prexor[n + 1];
        prexor[0] = 0;
        int res = 0;
        int a, b;
        for (int i = 1; i <= n; i++) { prexor[i] = prexor[i - 1] ^ arr[i - 1]; }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // a = prexor[i]^prexor[j];
                for (int k = j; k < n; k++) {
                    // b = prexor[j]^prexor[k+1];
                    // if (a==b){
                    if (prexor[i] == prexor[k + 1]) { res++; }
                }
            }
        }
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}