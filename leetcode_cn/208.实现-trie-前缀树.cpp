/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Trie {
  public:
    bool end = false;
    Trie *child[26]; // 建立一个指针数组
    /** Initialize your data structure here. */
    Trie() {
        // for (int i = 0; i < 26; i++) { child[i] = nullptr; }
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *p = this;
        for (int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if (p->child[idx] == nullptr) { // 没有节点
                // 建立节点
                Trie *t = new Trie;
                p->child[idx] = t;
                p = t; // 指向新节点
            } else {   // 有节点
                p = p->child[idx];
            }
        }
        p->end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *p = this;
        for (int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if (p->child[idx] == nullptr) {
                return false;
            } else {
                p = p->child[idx];
            }
        }
        return p->end == true;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *p = this;
        for (int i = 0; i < prefix.size(); i++) {
            int idx = prefix[i] - 'a';
            if (p->child[idx] == nullptr) {
                return false;
            } else {
                p = p->child[idx];
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

int main() {
    //
    return 0;
}