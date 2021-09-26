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
int main() {
    //
    int n, a, b;
    cin >> n >> a >> b;

    ListNode *head = new ListNode(0);
    ListNode *p = head;
    for (int i = 1; i <= n; i++) {
        ListNode *t = new ListNode(i);
        p->next = t;
        p = t;
    }
    p->next = head->next;
    p = head;
    int k = 1;
    int count = 1;
    while (true) {
        k = 1;
        while (k != a) {
            p = p->next;
            k++;
        }
        // cout << "del " << p->next->val << endl;
        ListNode *del;
        del = p->next;
        p->next = del->next;
        delete del;

        count++;
        if (count == n) {
            cout << p->val;
            return 0;
        }

        k = 1;
        while (k != b) {
            p = p->next;
            k++;
        }
        // cout << "del " << p->next->val << endl;
        del = p->next;
        p->next = del->next;
        delete del;

        count++;
        if (count == n) {
            cout << p->val;
            return 0;
        }
    }
    // cout << p->val;

    return 0;
}