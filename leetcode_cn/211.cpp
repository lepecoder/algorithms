/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start
struct Trie {
    bool end = false;
    array<Trie *, 26> next{nullptr};
};

class WordDictionary {
  private:
    Trie dictTree;
    bool res = false;

  public:
    /** Initialize your data structure here. */
    WordDictionary() {}

    void addWord(string word) {
        Trie *p = &dictTree;
        for (int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if (p->next[idx] == nullptr) {
                Trie *t = new Trie;
                p->next[idx] = t;
            }
            p = p->next[idx];
        }
        p->end = true;
    }
    void search(string &word, int k, Trie *d) {
        /*  检查word的第k个字母是否匹配d */
        if (d == nullptr) return;
        if (k == word.size()) {
            res = d->end == true || res;
            return;
        }
        if (word[k] == '.') {
            for (int i = 0; i < 26; i++) { search(word, k + 1, d->next[i]); }
        } else {
            int idx = word[k] - 'a';
            search(word, k + 1, d->next[idx]);
        }
    }
    bool search(string word) {
        res = false;
        search(word, 0, &dictTree);
        return res;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

int main() {
    WordDictionary wordD;
    wordD.addWord("bad");
    wordD.addWord("dad");
    wordD.addWord("mad");
    wordD.search("abd");
    wordD.search("bad");
    return 0;
}