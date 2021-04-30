/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
  public:
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node *_left, Node *_right, Node *_next) : val(_val), left(_left), right(_right), next(_next) {}
};

// @lc code=start

class Solution {
  public:
    Node *connect(Node *root) {
        queue<Node *> que; //层序遍历一定要用队列数据结构
        Node *temp;
        Node *result;
        if (root != nullptr) que.emplace(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i != size; i++) {
                temp = que.front();
                que.pop();
                if (i == size - 1)
                    temp->next = nullptr;
                else
                    temp->next = que.front();
                if (temp->left) que.emplace(temp->left);
                if (temp->right) que.emplace(temp->right);
            }
        }
        return root;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}