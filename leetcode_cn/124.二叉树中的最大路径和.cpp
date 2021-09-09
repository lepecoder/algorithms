/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
#define ll long long
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
  public:
    unordered_map<TreeNode *, int> mp;
    int res;
    int getmp(TreeNode *t) {
        // 左右子树的最大子树
        if (t == nullptr) return 0;
        if (mp.count(t) != 0) return 0;
        mp[t] = max(getmp(t->left), getmp(t->right)) + t->val;
        return mp[t];
    }
    void dfs(TreeNode *t) {
        if (t == nullptr) return;
        int left = getmp(t->left);
        int right = getmp(t->right);
        res = max(res, left + right + t->val);
        dfs(t->left);
        dfs(t->right);
    }
    int maxPathSum(TreeNode *root) {
        res = 0;
        dfs(root);
        return res;
    }
};
// @lc code=end

int main() {
    //
    int a;
    int b = 3;
    cout << (a = b);
    return 0;
}