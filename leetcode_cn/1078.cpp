#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
  public:
    vector<string> findOcurrences(string text, string first, string second) {
        istringstream record(text);
        string one, two, three;
        record >> one >> two;
        vector<string> res;
        while (record >> three) {
            if (one == first && two == second) { res.emplace_back(three); }
            one = two;
            two = three;
        }
        return res;
    }
};
int main() {
    //
    return 0;
}