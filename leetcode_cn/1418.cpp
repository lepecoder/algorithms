#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
class Solution {
  public:
    vector<vector<string>> displayTable(vector<vector<string>> &orders) {
        set<string> foodList;
        map<int, map<string, int>> tableList;
        for (auto &o : orders) {
            foodList.insert(o[2]);
            tableList[stoi(o[1])][o[2]]++;
        }
        vector<vector<string>> res;
        vector<string> title = {"Table"};
        for (auto &s : foodList) { title.push_back(s); }
        res.push_back(title);
        for (auto &p : tableList) {
            vector<string> t = {to_string(p.first)};
            for (auto &s : foodList) { t.push_back(to_string(p.second[s])); }
            res.push_back(t);
        }
        return res;
    }
};
