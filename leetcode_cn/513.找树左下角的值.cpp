/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    TreeNode *res;
    int deep;
    void dfs(TreeNode *r, int k) {
        /* 记录深度，如果深度大于当前搜索的最大深度，替换res */
        if (!r) return;
        if (k > deep) {
            deep = k;
            res = r;
        }
        dfs(r->left, k + 1);
        dfs(r->right, k + 1);
    }
    int findBottomLeftValue(TreeNode *root) {
        res = root;
        deep = 1;
        dfs(root, 1);
        return res->val;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}