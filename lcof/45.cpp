#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string minNumber(vector<int> &nums) {
        int n = nums.size();
        vector<string> vec_nums;
        vec_nums.reserve(n);
        for (int &x : nums) { vec_nums.emplace_back(to_string(x)); }
        sort(vec_nums.begin(), vec_nums.end(), [](const string &a, const string &b) { return a + b < b + a; });
        string res = "";
        for (string &s : vec_nums) { res += s; }
        return res;
    }
};
int main() {
    //
    return 0;
}