#include <bits/stdc++.h>
using namespace std;
#define ll long long

int res = 0;
int l1, l2, m;

void show_(list<pair<char, int>> &node) {
    for (auto p : node) { cout << p.first << p.second << ','; }
    cout << endl;
}

void check_(list<pair<char, int>> &node, list<pair<char, int>>::iterator it) {
    // 删除node的it节点
    if (it->second < m) return;
    list<pair<char, int>>::iterator pre(it);
    pre--;
    res += it->second;
    node.erase(it);
    list<pair<char, int>>::iterator nex(pre);
    nex++;
    if (nex != node.end() && pre->first == nex->first) {
        pre->second += nex->second;
        node.erase(nex);
        check_(node, pre);
    }
}

void put_(list<pair<char, int>> &node, char c) {
    // 把c插入到node中最长的c
    // pair<char,int> *max_p = node[0];
    auto it = node.begin();
    int max_c = 0;
    for (auto no = node.begin(); no != node.end(); no++) {
        // no->second++;
        if (no->first == c && no->second > max_c) {
            max_c = no->second;
            it = no;
        }
    }
    it->second++;
    check_(node, it);
    show_(node);
}

int main() {
    //
    // res = 0;
    cin >> l1 >> l2 >> m;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    list<pair<char, int>> node;
    pair<char, int> pre(s1[0], 1);
    for (int i = 1; i < l1; i++) {
        if (s1[i] == pre.first) {
            pre.second++;
        } else {
            node.emplace_back(pre);
            pre.first = s1[i];
            pre.second = 1;
        }
    }
    node.emplace_back(pre);
    int idx = 0;
    show_(node);
    while (idx < l2) {
        char x = s2[idx];
        // 找到最长的x插入进去
        put_(node, x);
        // show_(node);
        idx++;
    }
    cout << res;

    return 0;
}