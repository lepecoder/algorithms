/*
 * @lc app=leetcode.cn id=1305 lang=cpp
 *
 * [1305] 两棵二叉搜索树中的所有元素
 */

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
class BSTIterator {
  private:
    TreeNode *cur;
    stack<TreeNode *> stk;

  public:
    BSTIterator(TreeNode *r) : cur(r) {}
    TreeNode *next() {
        if (!hasNext()) return nullptr;
        while (cur != nullptr) {
            stk.emplace(cur);
            cur = cur->left;
        }
        cur = stk.top();
        stk.pop();
        TreeNode *ret = cur;
        cur = cur->right;
        return ret;
    }
    bool hasNext() { return cur != nullptr || !stk.empty(); }
};
class Solution {
  public:
    vector<int> getAllElements(TreeNode *r1, TreeNode *r2) {
        vector<int> res;
        BSTIterator it1 = BSTIterator(r1);
        BSTIterator it2 = BSTIterator(r2);
        TreeNode *t1 = it1.next();
        TreeNode *t2 = it2.next();
        while (t1 || t2) {
            if (!t1) {
                res.emplace_back(t2->val);
                t2 = it2.next();
            } else if (!t2) {
                res.emplace_back(t1->val);
                t1 = it1.next();
            } else if (t1->val < t2->val) {
                res.emplace_back(t1->val);
                t1 = it1.next();
            } else {
                res.emplace_back(t2->val);
                t2 = it2.next();
            }
        }
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}