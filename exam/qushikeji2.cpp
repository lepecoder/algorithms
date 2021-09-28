#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    //
    unordered_map<char, int> mp = {{'A', 1}, {'2', 2}, {'3', 3},  {'4', 4},  {'5', 5},  {'6', 6}, {'7', 7},
                                   {'8', 8}, {'9', 9}, {'T', 10}, {'J', 11}, {'Q', 12}, {'K', 13}};
    char card[14] = {'x', 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    int n = 7;
    set<pair<int, char>> st;
    map<char, int> mp2 = {{'s', 4}, {'d', 3}, {'c', 2}, {'h', 1}};
    char co[5] = {'x', 'h', 'c', 'd', 's'};
    set<char> color = {'s', 'd', 'c', 'h'};
    vector<pair<int, char>> v;
    v.reserve(10);
    char a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (mp.count(a) == 0 || color.count(b) == 0) {
            cout << "Error"; // 不是去掉大小王的扑克牌
            return 0;
        }
        pair<int, char> t = {mp[a], mp2[b]};
        if (st.count(t)) {
            cout << "Error";
            return 0;
        }
        st.emplace(t);
        v.emplace_back(t);
    }
    sort(v.begin(), v.end());
    int pre = v[0].first;
    int preidx = 0;
    int count = 1;
    for (int i = 1; i < n; i++) {
        if (v[i].first == v[i - 1].first && v[i].second == v[i - 1].second) { // 有重复
            cout << "Error";
            return 0;
        }
        if (count == 5) break;
        if (v[i].first == pre) {

        } else if (v[i].first == pre + 1) {
            count++;
            pre = v[i].first;
        } else {
            pre = v[i].first;
            count = 1;
            preidx = i;
        }
    }
    vector<pair<int, char>> res;
    if (count == 5) { // 有顺子
        res.emplace_back(v[preidx]);
        int pre = v[preidx].first;
        for (int i = preidx + 1; i < n; i++) {
            if (v[i].first == pre + 1) {
                res.emplace_back(v[i]);
                pre++;
            }
            if (res.size() == 5) break;
        }
        for (auto &p : res) { cout << card[p.first] << co[p.second] << ' '; }
    } else { // 没有顺子
        cout << "False";
    }
    return 0;
}