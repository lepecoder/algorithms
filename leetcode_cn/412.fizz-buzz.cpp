/*
 * @lc app=leetcode.cn id=412 lang=cpp
 *
 * [412] Fizz Buzz
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// @lc code=start
class Solution {
  public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        res.reserve(n);
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 && i % 5 == 0) {
                res.emplace_back("FizzBuzz");
            } else if (i % 3 == 0) {
                res.emplace_back("Fizz");
            } else if (i % 5 == 0) {
                res.emplace_back("Buzz");
            } else {
                res.emplace_back(to_string(i));
            }
        }
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}
