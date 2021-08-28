/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool findx(TreeNode *r, int x) {
        if (r == nullptr) return false;
        if (r->val == x) return true;
        return findx(r->left, x) || findx(r->right, x);
    }
    bool findTarget(TreeNode *root, int k) {
        if (root == nullptr) return false;
        queue<TreeNode *> q;
        q.emplace(root);
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                auto r = q.front();
                q.pop();
                if (r->val + r->val != k && findx(root, k - r->val)) return true;
                if (r->left) q.emplace(r->left);
                if (r->right) q.emplace(r->right);
            }
        }
        return false;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}