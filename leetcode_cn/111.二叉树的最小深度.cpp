/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        queue<TreeNode *> q;
        q.emplace(root);
        int depth = 1;
        while (!q.empty()) {
            int count = q.size();
            while (count--) {
                TreeNode *r = q.front();
                if (!r->left && !r->right) return depth;
                q.pop();
                if (r->left) q.emplace(r->left);
                if (r->right) q.emplace(r->right);
            }
            ++depth;
        }
        return -1;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}