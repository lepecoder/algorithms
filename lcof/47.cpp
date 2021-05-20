#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int n = grid.size(),m=grid[0].size();
        int dp[n][m];
        memset(dp,0,sizeof(dp));
        dp[n-1][m-1]=grid[n-1][m-1];
        for(int i=n-1;i>=0;i--){
            dp[i][m-1]=grid[i][m-1]+dp[i+1][m-1];
        }
        for(int j=m-1;j>=0;j--){
            dp[n-1][j] = grid[n-1][j]+dp[n-1][j+1];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                dp[i][j] = max(dp[i+1][j],dp[i][j+1])+grid[i][j];
            }
        }
        return dp[0][0];
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