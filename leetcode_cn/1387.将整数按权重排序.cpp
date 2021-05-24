/*
 * @lc app=leetcode.cn id=1387 lang=cpp
 *
 * [1387] 将整数按权重排序
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    unordered_map<int, int> f;
    int getF(int x) {
        if (x == 1) return 0;
        if (f.find(x) != f.end()) return f[x];
        if (x & 1)
            return f[x] = getF(3 * x + 1) + 1;
        else
            return f[x] = getF(x / 2) + 1;
    }
    int getKth(int lo, int hi, int k) {
        vector<int> v;
        for (int i = lo; i <= hi; i++) v.emplace_back(i);
        sort(v.begin(), v.end(), [&](int u, int v) {
            if (getF(u) != getF(v))
                return getF(u) < getF(v);
            else
                return u < v;
        });
        return v[k - 1];
    }
};
// @lc code=end

int main() {
    //
    return 0;
}