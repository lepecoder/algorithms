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
  private:
    bool isSym(TreeNode *l, TreeNode *r) {
        if (l == nullptr && r == nullptr) return true;
        if (l == nullptr || r == nullptr) return false;
        return l->val == r->val && isSym(l->left, r->right) && isSym(l->right, r->left);
    }

  public:
    bool isSymmetric(TreeNode *root) { isSym(root, root); }
};
int main() {
    //
    return 0;
}