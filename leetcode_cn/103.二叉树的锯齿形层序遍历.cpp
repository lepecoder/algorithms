/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode *> q;
        q.emplace(root);
        TreeNode *t;
        int n;
        bool b = false;
        while (!q.empty()) {
            vector<int> inres;
            n = q.size();
            while (n--) {
                t = q.front();
                inres.emplace_back(t->val);
                q.pop();
                if (t->left) { q.emplace(t->left); }
                if (t->right) { q.emplace(t->right); }
            }
            if (b) {
                reverse(inres.begin(), inres.end());
                b = !b;
            } else {
                b = !b;
            }
            res.emplace_back(inres);
        }
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}