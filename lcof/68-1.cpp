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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        // 假定p小于q
        if (p->val > q->val) swap(p, q);
        if (root->val >= p->val && root->val <= q->val) { return root; }
        if (root->val < p->val) { return lowestCommonAncestor(root->right, p, q); }
        return lowestCommonAncestor(root->left, p, q);
    }
};
int main() {
    //
    return 0;
}