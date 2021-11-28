/*
 * @lc app=leetcode.cn id=703 lang=cpp
 *
 * [703] 数据流中的第 K 大元素
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// @lc code=start
class KthLargest {
  public:
    // vector<int> arr;
    priority_queue<int, vector<int>, greater<int>> que_k;
    priority_queue<int> que;
    int k;
    KthLargest(int k, vector<int> &nums) {
        this->k = k;
        for (int &x : nums) { que.emplace(x); }
        while (que_k.size() < k - 1) {
            que_k.emplace(que.top());
            que.pop();
        }
    }

    int add(int val) {
        que_k.emplace(val);
        que.emplace(que_k.top());
        que_k.pop();
        return que.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

int main() {
    //
    return 0;
}