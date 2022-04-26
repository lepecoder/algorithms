// @algorithm @lc id=1791 lang=cpp 
// @title richest-customer-wealth


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include "algm/algm.h"
using namespace std;
// @test([[1,2,3],[3,2,1]])=6
// @test([[1,5],[7,3],[3,5]])=10
// @test([[2,8,7],[7,1,3],[1,9,5]])=17
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxsum=0;
        for (auto &v:accounts){
            maxsum = max(maxsum, accumulate(v.begin(), v.end(),0));
        }
        return maxsum;
    }
};