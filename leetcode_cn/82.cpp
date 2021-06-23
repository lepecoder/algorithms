#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
		ListNode *dummy = new ListNode(0,head);
		ListNode *cur = dummy;
		ListNode *h = head;
		while(h){
			if (h->next == nullptr || h->next->val != h->val){
				cur->next = h;
				cur = cur->next;
				h = h->next;
			}else{
				// 越过和h相等的节点
				ListNode *p = h->next;
				while(p!=nullptr && p->val == h->val)p=p->next;
				// 即便找到了也不一定要加到cur后面，因为p可能和之后相等
				h = p;  // p有可能是nullptr
			}
		}
		cur->next = nullptr;
		return dummy->next;
    }
};
int main(){



    return 0;
}
