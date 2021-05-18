#include <bits/stdc++.h>
using namespace std;

// IO
int _IO = []() {
    std::ios::sync_with_stdio(0);
    cin.tie(0); // cout.tie(0);
    return 0;
}();
class MaxQueue {
  private:
    queue<int> q;  // 存储插入的队列
    deque<int> dq; // 单调的双端队列
                   /* dq是单调的双端队列，
                   x尾部入队列的时候删除尾部所有<x的元素
                   当前的最大值是队列头部元素，
                   pop的时候如果等于头部，就pop出去
                    */

  public:
    MaxQueue() {}

    int max_value() {
        if (dq.empty()) return -1;
        return dq.front();
    }

    void push_back(int value) {
        q.emplace(value);
        while (!dq.empty() && dq.back() < value) { dq.pop_back(); }
        dq.emplace_back(value);
    }

    int pop_front() {
        if (q.empty()) return -1;
        if (q.front() == max_value()) { dq.pop_front(); }
        int res = q.front();
        q.pop();
        return res;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
int main() {
    MaxQueue mq;
    mq.push_back(1);
    mq.push_back(2);
    cout << mq.max_value() << ' ';
    cout << mq.pop_front() << ' ';
    cout << mq.max_value() << ' ';
    return 0;
}