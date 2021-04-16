/*
 * @lc app=leetcode.cn id=648 lang=cpp
 *
 * [648] 单词替换
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Trie {
  public:
    bool end;
    // vector<Trie *> child;
    Trie *child[26];
    Trie() : end(false) { memset(child, 0, sizeof(child)); }
    ~Trie() {
        for (auto &x : child) { delete x; }
    }
};

class Solution {
  public:
    Trie *root;
    void insert(string str) {
        Trie *r = root;
        for (int i = 0; i < str.size(); i++) {
            int idx = str[i] - 'a';
            if (r->child[idx] == nullptr) { r->child[idx] = new Trie; }
            r = r->child[idx];
        }
        r->end = true;
    }
    string search(string str) {
        /* 查到前缀返回前缀，找不到返回空 */
        Trie *r = root;
        for (int i = 0; i < str.size(); i++) {
            int idx = str[i] - 'a';
            if (r->end == true) return string(str.begin(), str.begin() + i);
            if (r->child[idx] == nullptr) return str;

            r = r->child[idx];
        }
        return str;
    }
    std::vector<std::string> split(std::string str, std::string pattern) {
        std::string::size_type pos;
        std::vector<std::string> result;
        str += pattern; //扩展字符串以方便操作
        int size = str.size();
        for (int i = 0; i < size; i++) {
            pos = str.find(pattern, i);
            if (pos < size) {
                std::string s = str.substr(i, pos - i);
                result.push_back(s);
                i = pos + pattern.size() - 1;
            }
        }
        return result;
    }
    string replaceWords(vector<string> &dictionary, string sentence) {
        /*  */
        root = new Trie;
        for (auto &s : dictionary) { insert(s); }
        auto vecstr = split(sentence, " ");
        string res = "";
        for (int i = 0; i < vecstr.size(); i++) {
            res += search(vecstr[i]);
            if (i != vecstr.size() - 1) { res += " "; }
        }
        delete root;
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}