/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    unordered_map<TreeNode *, int> mp_false, mp_true;

    int dfs(TreeNode *r, bool b) {
        // if (mp.find(r) != mp.end()) return mp.at(r);
        if (r == nullptr) return 0;
        int res;
        if (b == true) {
            if (mp_true.find(r) != mp_true.end()) return mp_true.at(r);
            res = max(r->val + dfs(r->left, false) + dfs(r->right, false), dfs(r->left, true) + dfs(r->right, true));
            mp_true.emplace(r, res);
        } else {
            if (mp_false.find(r) != mp_false.end()) return mp_false.at(r);
            res = dfs(r->left, true) + dfs(r->right, true);
            mp_false.emplace(r, res);
        }
        return res;
    }

  public:
    int rob(TreeNode *root) {
        int res = dfs(root, true);
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}