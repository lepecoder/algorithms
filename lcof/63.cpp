#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n==0) return 0;
        int min_ = prices[0];
        int res=0;
        for(int i=1;i<n;i++){
            res = max(res, prices[i]-min_);
            min_ = min(min_, prices[i]);
        }
        return res;
    }
};
int main(){
    // 
    return 0;
}
//IO
int _IO=[](){
    std::ios::sync_with_stdio(0);
    cin.tie(0); //cout.tie(0);
    return 0;
}();