// @algorithm @lc id=89 lang=cpp 
// @title gray-code


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test(2)=[0,1,3,2]
// @test(1)=[0,1]
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        ret.reserve(1<<n);
        ret.push_back(0);
        for(int i=1;i<=n;i++){
            int m = ret.size();
            for (int j=m-1;j>=0;j--){
                ret.push_back(ret[j] | (1<<(i-1)));
            }
        }
        return ret;
    }
};