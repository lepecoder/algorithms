/*
 * @lc app=leetcode.cn id=894 lang=cpp
 *
 * [894] 所有可能的满二叉树
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
    vector<TreeNode *> allPossibleFBT(int n) {
        vector<vector<TreeNode *>> f(n + 1, vector<TreeNode *>());
        f[1].emplace_back(new TreeNode(0));
        for (int i = 3; i <= n; i++) {
            if (!(i & 1)) continue;
            for (int j = 1; j < i; j++) {
                for (auto &left : f[j]) {
                    for (auto &right : f[i - j - 1]) {
                        TreeNode *r = new TreeNode();
                        r->left = left;
                        r->right = right;
                        f[i].emplace_back(r);
                    }
                }
            }
        }
        return f[n];
    }
};
// @lc code=end

int main() {
    //
    return 0;
}