/*
 * @lc app=leetcode.cn id=421 lang=cpp
 *
 * [421] 数组中两个数的最大异或值
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Trie {
  public:
    vector<Trie *> children;
    Trie() : children(2) {}
};
class Solution {
  public:
    Trie *root;
    int findMaximumXOR(vector<int> &nums) {
        int len = nums.size();
        root = new Trie();
        int res = 0;
        for (int i = 0; i < len; i++) {
            build(nums[i]);
            int t = query(nums[i]);
            res = max(res, t);
        }
        return res;
    }
    void build(int x) {
        Trie *r = root;
        for (int i = 30; i >= 0; i--) {
            int u = x >> i & 1;
            if (r->children[u] == nullptr) { r->children[u] = new Trie; }
            r = r->children[u];
        }
    }
    int query(int x) {
        /* 查找x的另一分支是否存在 */
        Trie *r = root;
        int res = 0;
        for (int i = 30; i >= 0; i--) {
            int u = x >> i & 1;
            if (r->children[u ^ 1]) {
                res += 1 << i;
                r = r->children[u ^ 1];
            } else {
                r = r->children[u];
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