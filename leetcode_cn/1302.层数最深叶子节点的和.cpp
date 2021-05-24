/*
 * @lc app=leetcode.cn id=1302 lang=cpp
 *
 * [1302] 层数最深叶子节点的和
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
  public:
    int deepestLeavesSum(TreeNode *root) {
        queue<TreeNode *> q;
        q.emplace(root);
        TreeNode *t;
        int res;
        int N;
        while (!q.empty()) {
            N = q.size();
            res = 0;
            while (N--) {
                t = q.front();
                res += t->val;
                q.pop();
                if (t->left) {
                    q.emplace(t->left);
                    // res += t->left->val;
                }
                if (t->right) {
                    q.emplace(t->right);
                    // res += t->right->val;
                }
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