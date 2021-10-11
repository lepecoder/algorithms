#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
  public:
    ListNode *removeDuplicateNodes(ListNode *head) {
        unordered_map<int, int> mp;
        ListNode *p = head;
        while (p) {
            mp[p->val]++;
            p = p->next;
        }
        ListNode *res = new ListNode(0);
        p = res;
        ListNode *cur = res;
        while (p) {
            int v = p->val;
            if (mp[v]) {
                mp[v] = 0;
                cur->next = p;
                cur = cur->next;
            }
            p = p->next;
        }
        cur->next = nullptr;
        return res->next;
    }
};
int main() {
    //
    return 0;
}