/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string> res;
    void dfs(string str, TreeNode *r) {
        str += to_string(r->val);
        if (r->left || r->right) {
            str += "->";
        } else {
            res.emplace_back(str);
        }
        if (r->left) { dfs(str, r->left); }
        if (r->right) { dfs(str, r->right); }
    }
    vector<string> binaryTreePaths(TreeNode *root) {
        res.clear();
        string str;
        dfs(str, root);
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}