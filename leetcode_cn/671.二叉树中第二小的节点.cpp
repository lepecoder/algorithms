/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
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
    int findSecondMinimumValue(TreeNode *root) {
        int ans = -1;
        int rootval = root->val;
        function<void(TreeNode *)> dfs = [&](TreeNode *node) {
            // 要找一个数，比rootval大的最小的数
            if (node == nullptr)
                return;
            else if (ans != -1 && node->val > ans)
                return;
            else if (node->val > rootval)
                ans = node->val;
            dfs(node->left);
            dfs(node->right);
        };
        dfs(root);
        return ans;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}