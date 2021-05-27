/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class MinStack {
  public:
    stack<int> stk;
    // 单调栈存储当前和之前最小的元素
    stack<int> min_stk;

    /** initialize your data structure here. */
    MinStack() {}

    void push(int val) {
        stk.emplace(val);
        if (val <= min_stk.top()) { min_stk.emplace(val); }
    }

    void pop() {
        if (stk.top() == min_stk.top()) { min_stk.pop(); }
        stk.pop();
    }

    int top() { return stk.top(); }

    int getMin() { return min_stk.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

int main() {
    //
    return 0;
}