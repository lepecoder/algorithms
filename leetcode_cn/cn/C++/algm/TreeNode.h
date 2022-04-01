
// Definition for a binary tree node.
#ifndef _TREENODE
#define _TREENODE
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
>>>>>>> a12f0b29c40e57472c725840d0c3af08cd2f46eb
#endif