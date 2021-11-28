#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int a=0,b=0;
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i]) a++;
        }
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[secret[i]]++;
        }
        for(int i=0;i<n;i++){
            if (mp[guess[i]]){
                mp[guess[i]]--;
                b++;
            }
        }
        string ans = str(a)+'A'+str(b)+'B';
        return ans;
    }
};
int main(){
    // 

    return 0;
}