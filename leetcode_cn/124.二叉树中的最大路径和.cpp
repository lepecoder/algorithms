/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
#define ll long long
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
    int res = INT_MIN;
    int fun(TreeNode *r) {
        if (r == nullptr) return 0;
        int left = max(fun(r->left), 0);
        int right = max(fun(r->right), 0);
        int x = r->val + left + right;
        res = max(x, res);
        int res = r->val + max(left, right);
        return res;
    }
    int maxPathSum(TreeNode *root) {
        fun(root);
        return res;
    }
};
// @lc code=end

int main() {
    //
    int a;
    int b = 3;
    cout << (a = b);
    return 0;
}