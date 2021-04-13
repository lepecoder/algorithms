/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    void flatten(TreeNode *root) {
        if (!root) return;
        // if (!root->right){
        //     root->right = root->left;
        //     root->left = nullptr;
        // }
        auto leftNode = root->left;
        auto rightNode = root->right;
        flatten(leftNode);
        flatten(rightNode);
        root->right = leftNode;
        root->left = nullptr;
        TreeNode *r = root;
        while (r->right) { r = r->right; }
        r->right = rightNode;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}