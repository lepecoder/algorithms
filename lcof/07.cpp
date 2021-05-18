//   Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty()) return nullptr;
        TreeNode *r = new TreeNode(preorder[0]);
        // if (preorder.size()==1) return r;
        auto root_it = find(inorder.begin(), inorder.end(), r->val);
        // 如果存在左子树
        if (root_it != inorder.begin()) {
            vector<int> inorder_left(inorder.begin(), root_it);
            vector<int> preorder_left(preorder.begin() + 1, preorder.begin() + 1 + inorder_left.size());
            r->left = buildTree(preorder_left, inorder_left);
        }
        if (root_it + 1 != inorder.end()) {
            vector<int> inorder_right(root_it + 1, inorder.end());
            vector<int> preorder_right(preorder.end() - inorder_right.size(), preorder.end());
            r->right = buildTree(preorder_right, inorder_right);
        }
        // 如果存在右子树
        return r;
    }
};
int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    Solution so;
    so.buildTree(preorder, inorder);
    return 0;
}