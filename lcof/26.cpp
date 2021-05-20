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
    bool isTopStructure(TreeNode *A, TreeNode *B) {
        /* 判断B是不是A根节点开始的子结构 */
        if (B == nullptr) return true;
        if (A == nullptr) return false;
        if (A->val != B->val) return false;
        bool b_left = isTopStructure(A->left, B->left);
        bool b_right = isTopStructure(A->right, B->right);
        return b_left && b_right;
    }

  public:
    bool isSubStructure(TreeNode *A, TreeNode *B) {
        if (B == nullptr || A == nullptr) return false;
        // if (A->val == B->val) {
        return isTopStructure(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
        // } else {
        // return isSubStructure(A->left, B) || isSubStructure(A->right, B);
        // }
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