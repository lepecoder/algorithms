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
    TreeNode *res;
    bool isIn(TreeNode *r, TreeNode *p, TreeNode *q) {
        if (r == nullptr) return false;
        bool lson = isIn(r->left, p, q);
        bool rson = isIn(r->right, p, q);
        if ((lson && rson) || ((r == p || r == q) && (lson || rson))) { res = r; }
        return lson || rson || r == q || r == p;
    }

  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        res = nullptr;
        isIn(root, p, q);
        return res;
    }
};
int main() {
    //
    return 0;
}