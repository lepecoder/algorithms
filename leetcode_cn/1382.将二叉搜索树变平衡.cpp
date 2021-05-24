/*
 * @lc app=leetcode.cn id=1382 lang=cpp
 *
 * [1382] 将二叉搜索树变平衡
 */

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
  private:
    // vector<int>inorder;
    void getInorder(TreeNode *r, vector<int> &inorder) {
        // 中序遍历
        if (r == nullptr) return;
        getInorder(r->left, inorder);
        inorder.emplace_back(r->val);
        getInorder(r->right, inorder);
    }
    TreeNode *build(int l, int r, vector<int> &inorder) {
        // 所有的边界都应该是左闭右开
        if (l >= r) return nullptr;
        int mid = (l + r) / 2;
        TreeNode *root = new TreeNode(inorder[mid]);
        root->left = build(l, mid, inorder);
        root->right = build(mid + 1, r, inorder);
        return root;
    }

  public:
    TreeNode *balanceBST(TreeNode *root) {
        /* 将二叉搜索树中序遍历，结果是升序数组，
        此时就是使用有序数组构建二叉树 */
        // inorder.clear();
        vector<int> inorder;
        getInorder(root, inorder);
        TreeNode *res = build(0, inorder.size(), inorder);
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}