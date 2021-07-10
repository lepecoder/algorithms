class MyQueue {
  public:
    stack<int> stk_in, stk_out;
    /** Initialize your data structure here. */
    MyQueue() {
        // 两个栈实现队列
    }

    /** Push element x to the back of queue. */
    void push(int x) { stk_in.emplace(x); }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res = peek();
        stk_out.pop();
        return res;
    }

    /** Get the front element. */
    int peek() {
        if (stk_out.empty()) {
            while (!stk_in.empty()) {
                stk_out.emplace(stk_in.top());
                stk_in.pop();
            }
        }
        int res = stk_out.top();
        return res;
    }

    /** Returns whether the queue is empty. */
    bool empty() { return stk_in.empty() && stk_out.empty(); }
};
