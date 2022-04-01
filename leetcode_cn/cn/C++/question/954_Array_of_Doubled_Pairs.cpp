// @algorithm @lc id=991 lang=cpp 
// @title array-of-doubled-pairs


#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include "algm/algm.h"
using namespace std;
// @test([3,1,3,6])=false
// @test([2,1,2,6])=false
// @test([4,-2,2,-4])=true
// @test([0,0,0,0,0,0])=true
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int,int> h;
        for (int x:arr) {
            h[x]++;
        }
        vector<int>v;
        v.reserve(h.size());
        for(auto [x,_]:h){v.push_back(x);};
        sort(v.begin(), v.end(), [](int a,int b){return abs(a)<abs(b);});
        for(int x:v){
            if(h[2*x] < h[x]) return false;
            else h[2*x] -= h[x];
        }
        return true;
    }
};