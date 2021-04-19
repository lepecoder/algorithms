/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 */
#include <bits/stdc++.h>
using namespace std;
class BIT {
  private:
    int *tr; // 树状数组
    int n;

  public:
    BIT(vector<int> &nums) {
        n = nums.size() + 1; // 树状数组的下标从1开始
        tr = new int[n];
        memset(tr, 0, sizeof(int) * n);
        for (int i = 0; i < nums.size(); i++) { add(i + 1, nums[i]); }
    }
    ~BIT() { delete[] tr; }
    inline int lowbit(int x) { return x & -x; }
    inline int query(int n) {
        /* 计算前n项和 */
        int res = 0;
        for (int i = n; i > 0; i -= lowbit(i)) res += tr[i];
        return res;
    }
    inline void add(int idx, int val) {
        /* 在第idx个数增加val */
        for (int i = idx; i < n; i += lowbit(i)) tr[i] += val;
    }
};

// @lc code=start
class NumArray {
  public:
    BIT *bit_;
    vector<int> *nums_;
    NumArray(vector<int> &nums) {
        nums_ = &nums;
        bit_ = new BIT(nums);
    }

    void update(int index, int val) {
        bit_->add(index + 1, val - nums_->at(index));
        nums_->at(index) = val;
    }

    int sumRange(int left, int right) { return bit_->query(right + 1) - bit_->query(left); }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end

int main() {
    //
    return 0;
}