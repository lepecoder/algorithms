/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (p->val > q->val) swap(p, q);
        TreeNode *r = root;
        while (r->val < p->val || r->val > q->val) {
            if (r->val < p->val) r = r->right;
            if (r->val > q->val) r = r->left;
        }
        return r;
        // int val = root->val;
        // if(val >= p->val && val <= q->val) return root;
        // if (val < p->val) return lowestCommonAncestor(root->right, p, q);
    }
};
// @lc code=end

int main() {
    //
    return 0;
}