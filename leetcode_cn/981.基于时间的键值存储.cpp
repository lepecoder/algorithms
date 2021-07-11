/*
 * @lc app=leetcode.cn id=981 lang=cpp
 *
 * [981] 基于时间的键值存储
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class TimeMap {
    unordered_map<string, vector<pair<int, string>>> mp;
public:
    /** Initialize your data structure here. */
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        m[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {

    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end


int main(){
    // 
    return 0;
}