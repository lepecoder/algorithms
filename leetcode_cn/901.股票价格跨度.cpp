/*
 * @lc app=leetcode.cn id=901 lang=cpp
 *
 * [901] 股票价格跨度
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class StockSpanner {
  public:
    stack<pair<int, int>> st; // <股票价格,<=最大连续天数>
    StockSpanner() {}

    int next(int price) {
        int value = 1;
        // pop出小于等于price的元素
        while (!st.empty() && st.top().first <= price) {
            value += st.top().second;
            st.pop();
        }
        st.emplace(price, value);
        return value;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end

int main() {
    //
    return 0;
}