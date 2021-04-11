/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start

//   Definition for a binary tree node.
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
    vector<vector<int>> res;
    void backtrack(vector<int> path, TreeNode *root, int targetSum) {
        if (!root) return;                                     // 空树
        if (root->left == nullptr && root->right == nullptr) { // 叶子节点，判断值是否等于targetSum
            if (root->val == targetSum) {
                path.emplace_back(root->val);
                res.emplace_back(path);
            }
        } else { // 非叶子节点
            path.emplace_back(root->val);
            backtrack(path, root->left, targetSum - root->val);
            backtrack(path, root->right, targetSum - root->val);
        }
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        // if (!root) return res;
        vector<int> path;
        backtrack(path, root, targetSum);
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}