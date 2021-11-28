// @algorithm @lc id=783 lang=cpp
// @title search-in-a-binary-search-tree

#include "algm/algm.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @test([4,2,7,1,3],2)=[2,1,3]
// @test([4,2,7,1,3],5)=[]
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
class Solution {
  public:
    TreeNode *searchBST(TreeNode *root, int val) {
        if (root == nullptr) return nullptr;
        if (root->val == val) { return root; }
        TreeNode *l = searchBST(root->left, val);
        TreeNode *r = searchBST(root->right, val);
        if (l) { return l; }
        if (r) { return r; }
        return nullptr;
    }
};
