/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 */
#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
class Solution {
  public:
    vector<TreeNode *> res;
    vector<TreeNode *> generateTrees(int l, int r) {
        if (l >= r) return {nullptr};
        vector<TreeNode *> res;
        for (int i = l; i < r; i++) {
            auto leftTrees = generateTrees(l, i);
            auto rightTrees = generateTrees(i + 1, r);
            for (auto &l_t : leftTrees) {
                for (auto &r_t : rightTrees) {
                    TreeNode *t = new TreeNode(i);
                    t->left = l_t;
                    t->right = r_t;
                    res.emplace_back(t);
                }
            }
        }
        return res;
    }
    vector<TreeNode *> generateTrees(int n) {
        auto res = generateTrees(1, n + 1);
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}