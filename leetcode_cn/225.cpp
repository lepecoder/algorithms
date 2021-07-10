class MyStack {
  public:
    queue<int> q;
    /** Initialize your data structure here. */
    MyStack() {
        //使用两个队列模拟栈的操作
        // 其实一个队列就够
    }

    /** Push element x onto stack. */
    void push(int x) {
        int n = q.size();
        q.push(x);
        while (n--) {
            int t = q.front();
            q.pop();
            q.push(t);
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res = q.front();
        q.pop();
        return res;
    }

    /** Get the top element. */
    int top() { return q.front(); }

    /** Returns whether the stack is empty. */
    bool empty() { return q.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
