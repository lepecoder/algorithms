#include <bits/stdc++.h>
using namespace std;
class CQueue {
  public:
    stack<int> appendStack;
    stack<int> deleteStack;

    CQueue() {}

    void appendTail(int value) { appendStack.emplace(value); }

    int deleteHead() {
        int res = -1;
        if (!deleteStack.empty()) { // 删除栈中有元素，直接删除
            res = deleteStack.top();
            deleteStack.pop();
        } else if (!appendStack.empty()) { // 删除栈中没有元素，但是添加栈中有元素
            // 把appendstack中元素搬到deletestack
            while (!appendStack.empty()) {
                deleteStack.emplace(appendStack.top());
                appendStack.pop();
            }
            res = deleteStack.top();
            deleteStack.pop();
        }
        return res;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
int main() {
    //
    return 0;
}