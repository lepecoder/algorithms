/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        // if(!root) return res;
        stack<TreeNode *> stk;
        while (!stk.empty() || root) {
            while (root) {
                stk.push(root);
                res.emplace_back(root->val);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            root = root->right;
        }
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}