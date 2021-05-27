/*
 * @lc app=leetcode.cn id=449 lang=cpp
 *
 * [449] 序列化和反序列化二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
class Codec {
  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        /* 使用前序遍历序列化二叉搜索树 */
        if (!root) return "";
        stringstream ss;
    }
    void getPreorder(TreeNode *root, stringstream &ss) {
        /* 前序字符串 */
        if (!root) {
            ss << "# ";
            return;
        }
        ss << to_string
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {}
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end

int main() {
    //
    return 0;
}