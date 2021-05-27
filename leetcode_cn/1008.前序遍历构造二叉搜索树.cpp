/*
 * @lc app=leetcode.cn id=1008 lang=cpp
 *
 * [1008] 前序遍历构造二叉搜索树
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
    TreeNode *bstBuild(vector<int> &preorder, int l, int r) {
        /* 边界左闭右开 */
        if (l >= r) return nullptr;
        int root_val = preorder[l];
        // 建立根节点
        TreeNode *res = new TreeNode(root_val);
        // 找到左右子树的边界
        int mid = l;
        // mid指向区间lr中第一个大于mid的节点，如果没有就指向r
        while (mid < r && preorder[mid] <= root_val) mid++;
        res->left = bstBuild(preorder, l + 1, mid);
        res->right = bstBuild(preorder, mid, r);
        return res;
    }

    TreeNode *bstFromPreorder(vector<int> &preorder) {
        /* 前序遍历构造二叉搜索树 */
        if (preorder.empty()) return nullptr;
        TreeNode *res = bstBuild(preorder, 0, preorder.size());
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}
