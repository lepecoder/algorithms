//Definition for singly-linked list.
#ifndef _LISTNODE
#define _LISTNODE
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
>>>>>>> a12f0b29c40e57472c725840d0c3af08cd2f46eb
#endif