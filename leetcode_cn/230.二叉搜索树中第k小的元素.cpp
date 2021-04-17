/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
    int countTree(TreeNode *root) {
        if (!root) return 0;
        return 1 + countTree(root->left) + countTree(root->right);
    }
    int kthSmallest(TreeNode *root, int k) {

        int leftCount = countTree(root->left);
        if (leftCount + 1 == k)
            return root->val;
        else if (leftCount + 1 < k)
            return (kthSmallest(root->right, k - leftCount - 1));
        else
            return kthSmallest(root->left, k);
    }
};
// @lc code=end

int main() {
    //
    return 0;
}