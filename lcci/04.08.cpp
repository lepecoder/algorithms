#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  private:
    TreeNode *res;
    bool dfs(TreeNode *r, TreeNode *p, TreeNode *q) {
        /* 判断r的子树是否包含p或是q */
        if (r == nullptr) return false;
        bool lson = dfs(r->left, p, q);
        bool rson = dfs(r->right, p, q);
        if ((lson && rson) || ((r->val == p->val || r->val == q->val) && (lson || rson))) {
            res = r;
        } else {
            lson || rson || (r->val == p->val || r->val == q->val);
        }
    }

  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        dfs(root, p, q);
        return res;
    }
};
int main() {
    //
    return 0;
}
// IO
int _IO = []() {
    std::ios::sync_with_stdio(0);
    cin.tie(0); // cout.tie(0);
    return 0;
}();