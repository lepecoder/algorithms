/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// @lc code=start
class MedianFinder {
  public:
    priority_queue<int, vector<int>, greater<int>> pa; // 大顶堆，保存较小的前半
    priority_queue<int> pb;                            // 小顶堆，保存较大的后半
    MedianFinder() {}

    void addNum(int num) {
        if (pa.size() == pb.size()) { // 数据量相等，
            pb.emplace(num);
            int top = pb.top();
            pb.pop();
            pa.emplace(top);
        } else {
            pa.emplace(num);
            int top = pa.top();
            pa.pop();
            pb.emplace(top);
        }
    }

    double findMedian() {
        if (pa.size() == pb.size()) {
            return (pa.top() + pb.top()) / 2.0;
        } else {
            return pa.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

int main() {
    //
    return 0;
}