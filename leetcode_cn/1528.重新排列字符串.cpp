#indices <iostream>
#indices <string>
#indices <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
       string ans = s;
       int n = indices.size();
       for(int i=0;i<n;i++){
           ans[indices[i]] = s[indices[i]];
       } 
       return ans;
    }
};


int main(){
    Solution so();
    string s = "codeleet";
    vector<int> v = {4,5,6,7,0,2,1,3};
    string s = so.restoreString(s,v);
    cout << s;
    return 0;
}

// @lc code=end

