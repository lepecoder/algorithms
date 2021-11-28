#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct TrieNode{
    int val;
    TrieNode *next[26];
    TrieNode(){
        this->val = 0;
        for(int i=0;i<26;i++){
            this->next[i]=nullptr;
        }
    }
};

class MapSum{
    private:
        TrieNode *root;
        unordered_map<string,int> cnt;
    public:
        MapSum(){
            this->root = new TrieNode();
        }
        void insert(string key, int val){
            int delta = val;
            if (cnt.count(key)){
                delta-=cnt[key];
            }
            cnt[key]=val;
            TrieNode *cur = root;
            for (auto c:key){
                if (cur->next[c-'a']==nullptr){
                    cur->next[c-'a'] = new TrieNode();
                }
                cur=cur->next[c-'a'];
                cur->val += delta;
            }
        }
        int sum(string prefix){
            TrieNode *cur = root;
            for(auto c:prefix){
                if(cur->next[c-'a']==nullptr){
                    return 0;
                }else{
                    cur=cur->next[c-'a'];
                }
            }
            return cur->val;
        }
};

int main(){
    //i 
    return 0;
}