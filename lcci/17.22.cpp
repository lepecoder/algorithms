#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
  public:
    vector<string> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        unordered_map<string, int> mp;
        bool bs = false;
        for (string &s : wordList) {
            mp[s] = INT_MAX;
            if (s == endWord) bs = true;
        }
        // if(bs==false) return
        // 广度优先搜索
        queue<string> q;
        q.emplace(beginWord);
        for (auto p : mp) {
            if (p.first == beginWord) { p.second = 0; }
        }
    }
};
int main() {
    //
    return 0;
}