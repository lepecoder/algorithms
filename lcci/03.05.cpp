#include <bits/stdc++.h>
using namespace std;
#define ll long long
class SortedStack {
  public:
    stack<int> st;
    stack<int> tmp;
    SortedStack() {}

    void push(int val) {
        while (!st.empty() && st.top() < val) {
            tmp.emplace(st.top());
            st.pop();
        }
        st.emplace(val);
        while (!tmp.empty()) {
            st.emplace(tmp.top());
            tmp.pop();
        }
    }

    void pop() {
        if (!st.empty()) st.pop();
    }

    int peek() {
        if (st.empty()) return -1;
        return st.top();
    }

    bool isEmpty() { return st.empty(); }
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */
int main() {
    //
    return 0;
}