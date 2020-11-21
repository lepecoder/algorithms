// #include <iostream>
// #include <string>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string longestCommonPrefix(vector<string> &strs) {
    int n = strs.size();
    if (n == 0) return string("");
    int i, j, max_pre;
    // 先找到最短str的长度
    int min_length = strs[0].size();
    for (i = 0; i < n; i++) {
      if (strs[i].size() < min_length) min_length = strs[i].size();
    }
    for (i = 0; i < min_length; i++) {  // 比较所有字符串的第i个字符
      char s = strs[0][i];  // 获取第0个字符串的第i个字符
      for (j = 1; j < n; j++) {
        if (strs[j][i] != s) {
          max_pre = i - 1;
          i = min_length;
          break;
        }
      }
    }
    max_pre++;
    max_pre = min(max_pre, min_length);
    if (max_pre == 0) return string("");
    string subs = strs[0].substr(0, max_pre);
    return subs;
  }
};

int main() {
  Solution s;
  vector<string> v;
  string s1 = string("ab");
  string s2 = string("a");
  string s3 = string("a");
  v.push_back(s1);
  v.push_back(s2);
  v.push_back(s3);

  string x = s.longestCommonPrefix(v);
  cout << x;

  return 0;
}