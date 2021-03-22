#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  string reverseWords(string s) {
    s.append(" ");
    vector<string> ans;
    int a = 0, b = 0, n = s.size();
    // a移动到第一个非0字符
    while (a < n && s[a] == ' ')
      a += 1;
    b = a;
    while (b < n) {
      if (s[b] != ' ') { // 移动到单词末尾的空格
        b += 1;
      } else {
        string temp = s.substr(a, b - a); // ab之间的子串
        ans.push_back(temp);
        while (b < n && s[b] == ' ')
          b += 1;
        a = b; // 移动前指针
      }
    }
    string str;
    for (auto it = ans.rbegin(); it != ans.rend(); ++it) {
      str.append(*it);
      str.append(" ");
      // cout << (*it) << ' ';
    }
    return str.substr(0, str.size() - 1);
  }
};

int main() {
  Solution so;
  string s = "   hello     world";
  // so.reverseWords(s);
  cout << so.reverseWords(s);
}

// @lc code=end
