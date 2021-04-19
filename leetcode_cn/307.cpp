/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 */
#include <bits/stdc++.h>
using namespace std;
class SegmentTree {
  private:
    int *tr;
    const vector<int> *arr;

  public:
    SegmentTree(const vector<int> &nums) {
        int n = nums.size();
        arr = &nums;
        tr = new int[4 * n];
        memset(tr, 0, sizeof(tr));
        build_tree(0, 0, n - 1);
    }
    ~SegmentTree() { delete[] tr; }
    void build_tree(int node, int start, int end) {
        /*
        建立线段树
        node是要建立的当前节点，start和end是节点的范围,两端包含
        注意：下标从0开始
        */
        if (start == end) {
            tr[node] = arr->at(start);
        } else {
            int left_node = 2 * node + 1;
            int right_node = 2 * node + 2;
            int mid = (start + end) / 2;
            build_tree(left_node, start, mid);
            build_tree(right_node, mid + 1, end);
            tr[node] = tr[left_node] + tr[right_node];
        }
    }
    void update_tree(int node, int start, int end, int idx, int val) {
        /*
        修改线段树
        将下标idx改为val,node是线段树节点序号，start和end是线段树节点在原数组的范围
         */
        if (start == end) {
            tr[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;
        if (idx < start || idx > end) { // 节点范围不包含idx
            return;
        }
        if (start <= idx && idx <= mid) { // idx位于左分支
            update_tree(left_node, start, mid, idx, val);
        } else { // idx位于右分支
            update_tree(right_node, mid + 1, end, idx, val);
        }
        tr[node] = tr[left_node] + tr[right_node];
    }
    int query_tree(int node, int start, int end, int L, int R) {
        /*
        线段树查询，
        查询区间L,R的和，两端包含
         */
        if (R < start || L > end) // node不在求和范围
            return 0;
        else if (start == end)
            return tr[node];
        else if (start >= L && end <= R) {
            return tr[node];
        } else {
            int mid = (start + end) / 2;
            int left_node = 2 * node + 1;
            int right_node = 2 * node + 2;
            int sum_left = query_tree(left_node, start, mid, L, R);
            int sum_right = query_tree(right_node, mid + 1, end, L, R);
            return sum_left + sum_right;
        }
    }
};
// @lc code=start
class NumArray {
    /* 两类操作
    1. 更新数组下标对应的值
    2. 返回某个范围内的元素总和
    // 但节点修改的线段树，不需要设置懒标记
    */
  private:
    int n;
    SegmentTree *sg;

  public:
    NumArray(vector<int> &nums) {
        /* 使用nums初始化线段树，下标从0开始 */
        n = nums.size();
        sg = new SegmentTree(nums);
    }
    ~NumArray() { delete sg; }

    void update(int index, int val) {
        /* 更新对象中的值 */
        sg->update_tree(0, 0, n - 1, index, val);
    }

    int sumRange(int left, int right) {
        /* 区域求和 */
        int res = sg->query_tree(0, 0, n - 1, left, right);
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end

int main() {
    vector<int> v{1, 3, 5};
    NumArray na(v);
    cout << na.sumRange(0, 2);
    na.update(1, 2);
    cout << na.sumRange(0, 2);

    return 0;
}