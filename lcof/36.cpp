#include <bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node {
  public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node *_left, Node *_right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
class Solution {
  public:
    Node *treeToDoublyList(Node *root) {
        /* 中序遍历后可以组成单向链表 */
        Node *r = root;
        Node *dummy = new Node(0);
        Node *cur = dummy;
        stack<Node *> stk;
        if (root) { stk.emplace(root); }
        while (r || !stk.empty()) {
            while (r) {
                stk.emplace(r);
                r = r->left;
            }
            r = stk.top();
            cur->right = r;
            cur = cur->right;
            stk.pop();
            r = r->right;
        }
        Node *p1 = dummy;
        Node *p2 = p1->right;
        while (p2) {
            p2->left = p1;
            p1 = p2;
            p2 = p2->right;
        }

        return dummy->right;
    }
};
int main() {
    //
    return 0;
}