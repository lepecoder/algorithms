#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    string s1,s2;
    cin >> s1 >> s2;
    // cout << s1 << endl << s2 << endl;

    char map[26];
    memset(map,0,sizeof(map));
    int n = s1.length();
    int res=0;
    for(int i=0;i<n;i++){
        if (s1[i]==s2[i]){
            // 不需要映射
            continue;
        }
        if (map[s1[i]-'a'] == s2[i]){
            // 正确映射
            continue;
        }
        if (map[s1[i]-'a']==0){
            // 还没有映射
            map[s1[i]-'a'] = s2[i];
            res++;
            continue;
        }
        cout << -1;
        return 0;
    }
    cout << res;

    return 0;
}