/*
 * @lc app=leetcode.cn id=306 lang=cpp
 *
 * [306] 累加数
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
  bool isAdd(string num, long long x) {
    // 判断num的开头是不是x
    string str_x = to_string(x);
    if (num.size() < str_x.size()) {
      return false;
    }
    return (num.substr(0, str_x.size()) == str_x);
  }
  bool isAddi(string num, int i, int j) {
    //   输入是前两个数的分割点，注意不是长度，是位置
    int t = 0;
    int n = num.size();
    while (j < n) {
      long long xi = stoll(num.substr(t, i - t));
      long long xj = stoll(num.substr(i, j - i));
      if (isAdd(num.substr(j), xi + xj) == false) {
        return false;
      }
      t = i;
      i = j;
      j = to_string(xi + xj).size() + j;
    }
    return j == n;
  }
  bool isAdditiveNumber(string num) {
    //   先找满足条件的前3个数，如果找不到直接false
    int n = num.size();
    int i = 1, j = 1; // 定义前两个字符串的长度
    long long xi, xj;
    bool ans = false; // 默认不可以
    for (i = 1; i < n - 1; i++) {
      if (num[0] == '0' && i > 1) {
        break;
      }
      xi = stoll(num.substr(0, i));
      for (j = 1; i + j < n; j++) {
        //   不能以0结尾，因为这样下一个数就只能以0开头
        if (num[i] == '0' && j > 1) { // 以0开头，j就不能>1
          break;
        }
        xj = stoll(num.substr(i, j));
        if (isAdd(num.substr(i + j), xi + xj)) {
          // 起码前3个是可以了，检查之后是否可以
          ans = ans || isAddi(num, i, i + j);
          if (ans) {
            return ans;
          }
        }
      }
    }
    return ans;
  }
};
// @lc code=end

int main() {
  Solution so;
  bool ans = so.isAdditiveNumber("0235813");
  cout << ans;
  return 0;
}