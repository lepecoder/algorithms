/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

// @lc code=start
//  Definition for a binary tree node.
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

class Solution {
  public:
    TreeNode *prev = nullptr; //记录前驱结点
    bool isValidBST(TreeNode *root) {
        if (root != NULL) {
            if (!isValidBST(root->left)) { // 1.验证左子树
                return false;
            }

            // 2.验证当前两个相邻的元素是否升序
            if (prev != nullptr && prev->val >= root->val) return false;
            prev = root; //记录当前节点

            if (!isValidBST(root->right)) { // 3.验证右子树
                return false;
            }
        }

        return true;
    }
};
;
// @lc code=end

int main() {
    int min_ = -(1 << 31);
    int max_ = (1 << 31) - 1;
    cout << min_ << endl;
    cout << max_ << endl;
    cout << "int: \t\t"
         << "所占字节数：" << sizeof(int);
    cout << "\t最大值：" << (numeric_limits<int>::max)();
    cout << "\t最小值：" << (numeric_limits<int>::min)() << endl;
    return 0;
}
