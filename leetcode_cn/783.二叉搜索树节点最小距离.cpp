/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树节点最小距离
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
// @lc code=start

class Solution {
  public:
    vector<int> preorder;
    void genPreorder(TreeNode *root) {
        stack<TreeNode *> s;
        while (root || !s.empty()) {
            if (root) {
                s.emplace(root);
                root = root->left;
            } else {
                root = s.top();
                s.pop();
                preorder.emplace_back(root->val);
                root = root->right;
            }
        }
    }
    int minDiffInBST(TreeNode *root) {
        int res = 20000;
        genPreorder(root);
        for (auto it = preorder.begin(); it != preorder.end() - 1; it++) { res = min(res, *(it + 1) - *it); }
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}