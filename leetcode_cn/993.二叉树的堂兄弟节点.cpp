/*
 * @lc app=leetcode.cn id=993 lang=cpp
 *
 * [993] 二叉树的堂兄弟节点
 */

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

#include <bits/stdc++.h>
using namespace std;

// IO
int _IO = []() {
    std::ios::sync_with_stdio(0);
    cin.tie(0); // cout.tie(0);
    return 0;
}();
class Solution {
  private:
    void find(int *res, TreeNode *r, int x, int deep) {
        /* 在r子树中查找x，deep是x的深度
        返回x的父节点值和x的深度 */
        if (r == nullptr) return;
        if (r->left && r->left->val == x) {
            res[0] = r->val;
            res[1] = deep + 1;
        }
        if (r->right && r->right->val == x) {
            res[0] = r->val;
            res[1] = deep + 1;
        }
        find(res, r->left, x, deep + 1);
        find(res, r->right, x, deep + 1);
    }

  public:
    bool isCousins(TreeNode *root, int x, int y) {
        int *resx = new int[2];
        int *resy = new int[2];
        find(resx, root, x, 0);
        find(resy, root, y, 0);
        return (resx[1] == resy[1] && resx[0] != resy[0]);
    }
};
// @lc code=end

int main() {
    //
    return 0;
}