/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
  public:
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        if (root == nullptr) return new TreeNode(val);
        TreeNode *cur = root;
        TreeNode *res;
        while (cur) {
            res = cur;
            if (cur->val < val) {
                cur = cur->right;
            } else {
                cur = cur->left;
            }
        }
        // cur = new TreeNode(val);
        if (res->val < val) {
            res->right = new TreeNode(val);
        } else {
            res->left = new TreeNode(val);
        }
        return root;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}