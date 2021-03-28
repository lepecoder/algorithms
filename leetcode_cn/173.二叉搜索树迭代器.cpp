/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
//  Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
class BSTIterator {
private:
  TreeNode *cur;
  stack<TreeNode *> stk; // 用一个栈存储经过的节点
public:
  BSTIterator(TreeNode *root) : cur(root) {}

  int next() {
    while (cur != nullptr) {
      stk.push(cur);
      cur = cur->left;
    }
    cur = stk.top();
    stk.pop();
    int ret = cur->val;
    cur = cur->right;
    return ret;
  }

  bool hasNext() { return cur != nullptr || !stk.empty(); }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

int main() { return 0; }