/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    void findIdx(TreeNode *r, int k, TreeNode *target, int &t) {
        // 在root里查找target，假定root的序号是k，返回target的序号，按照完全
        // 二叉树的层次遍历标号
        if (r == nullptr) return;
        if (r->val == target->val) t = k;
        findIdx(r->left, 2 * k, target, t);
        findIdx(r->right, 2 * k + 1, target, t);
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        int idx_p = 0, idx_q = 0;
        findIdx(root, 1, p, idx_p);
        findIdx(root, 1, q, idx_q);
        while (idx_p != idx_q) {
            if (idx_p > idx_q) {
                idx_p /= 2;
            } else {
                idx_q /= 2;
            }
        }
        // 找到第idx_p个节点
        int i = 1;
        TreeNode *r = root;
        stack<int> stk;
        while (idx_p) {
            stk.push(idx_p & 1);
            idx_p = idx_p >> 1;
        }
        while (!stk.empty()) {
            stk.pop();
            if (stk.top()) {
                r = r->right;
            } else {
                r = r->left;
            }
        }
        return r;
    }
};
// @lc code=end

int main() {
    cout << (5 & 1);
    return 0;
}