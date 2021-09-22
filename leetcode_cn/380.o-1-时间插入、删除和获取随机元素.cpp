/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x, idx, n)                                                                                                                                        \
    for (int i = idx; i < n; i++) cout << x[i] << ' ';                                                                                                         \
    cout << endl;
// @lc code=start
class RandomizedSet {
  public:
    /** Initialize your data structure here. */
    vector<int> v;
    unordered_map<int, int> mp;
    RandomizedSet() {}

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (mp.count(val)) { return false; }
        v.emplace_back(val);
        mp[val] = v.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (mp.count(val)) {
            int idx = mp[val];
            mp[v.back()] = idx;
            swap(v[idx], v[v.size() - 1]);
            mp.erase(val);
            v.pop_back();
            return true;
        }
        return false;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int idx = rand() % v.size();
        return v[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

int main() {
    //
    return 0;
}
