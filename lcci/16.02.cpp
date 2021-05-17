#include <bits/stdc++.h>
using namespace std;
class WordsFrequency {
  private:
    unordered_map<string, int> mp;

  public:
    WordsFrequency(vector<string> &book) {
        for (string &w : book) { mp[w]++; }
    }

    int get(string word) { return mp[word]; }
};

int main() {
    //
    return 0;
}
// IO
int _IO = []() {
    std::ios::sync_with_stdio(0);
    cin.tie(0); // cout.tie(0);
    return 0;
}();