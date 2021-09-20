#include <bits/extc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * @param a ListNode类vector 所有的无序单链表
     * @return ListNode类
     */
    ListNode *solve(vector<ListNode *> &a) {
        // write code here
        vector<int> res;
        res.reserve(100010);
        for (ListNode *node : a) {
            while (node) {
                res.emplace_back(node->val);
                node = node->next;
            }
        }
        sort(res.begin(), res.end());

        auto end = unique(res.begin(), res.end());
        ListNode *ans = new ListNode(0);
        ListNode *p = ans;
        for (auto it = res.begin(); it != end; it++) {
            ListNode *t = new ListNode(*it);
            p->next = t;
            p = t;
        }
        return ans->next;
    }
};
int main() {
    //
    return 0;
}