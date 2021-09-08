/*
 * @lc app=leetcode.cn id=969 lang=cpp
 *
 * [969] 煎饼排序
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// @lc code=start
class Solution {
  public:
    vector<int> res;
    void reser(vector<int> &arr, int k) {
        if (k == 0) return;
        int l = 0, r = k;
        while (l < r) { swap(arr[l++], arr[r--]); }
        res.emplace_back(k + 1);
    }
    vector<int> pancakeSort(vector<int> &arr) {
        res.clear();
        vector<int> a(arr);
        sort(a.begin(), a.end());
        int n = arr.size();
        for (int i = n - 1; i > 0; i--) {
            if (arr[i] == a[i]) continue;
            for (int j = 0; j < i; j++) {
                if (arr[j] == a[i]) {
                    reser(arr, j);
                    break;
                }
            }
            reser(arr, i);
        }
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}