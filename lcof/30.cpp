#include <stack>
using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
	stack<int> stk;
	stack<int> min_stk;  // 单调栈，
    MinStack() {
    }
    
    void push(int x) {
		stk.emplace(x);
		if (min_stk.empty() || x <= min_stk.top()){
			min_stk.emplace(x);
		}
    }
    
    void pop() {
		if (stk.top() == min_stk.top()){
			min_stk.pop();
		}
		stk.pop();
    }
    
    int top() {
		return stk.top();
    }
    
    int min() {
		return min_stk.top();
    }
};
int main(){



    return 0;
}
