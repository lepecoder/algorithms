#include <bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node {
  public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution {
  public:
    Node *copyRandomList(Node *head) {
        unordered_map<Node *, Node *> mp; // 建立个源节点到新节点的映射
        Node *dummy = new Node(0);
        Node *cur = dummy;
        Node *h = head;
        int idx = 0;
        while (h) {
            Node *t_node = new Node(h->val);
            cur->next = t_node;
            cur = cur->next;
            // mp.emplace(h, t_node);
            mp.insert({h, t_node});
            h = h->next;
        }
        h = head;
        cur = dummy->next;
        while (h) {
            // if (h->random == nullptr) {
            // cur->random = nullptr;
            // } else {
            if (h->random != nullptr) { cur->random = mp[h->random]; }
            h = h->next;
            cur = cur->next;
        }
        return dummy->next;
    }
};
int main() {
    //
    return 0;
}