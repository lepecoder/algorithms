/*
 * @lc app=leetcode.cn id=1379 lang=cpp
 *
 * [1379] 找出克隆二叉树中的相同节点
 */

// @lc code=start
//  * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target) {
        if (cloned == nullptr) return nullptr;
        if (cloned->val == target->val) return cloned;
        auto leftNode = getTargetCopy(original, cloned->left, target);
        auto rightNode = getTargetCopy(original, cloned->right, target);
        if (leftNode) return leftNode;
        return rightNode;
    }
};
// @lc code=end
