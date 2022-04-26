// @algorithm @lc id=138 lang=cpp 
// @title copy-list-with-random-pointer


#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

#include "algm/algm.h"
using namespace std;
// @test([[7,null],[13,0],[11,4],[10,2],[1,0]])=[[7,null],[13,0],[11,4],[10,2],[1,0]]
// @test([[1,1],[2,1]])=[[1,1],[2,1]]
// @test([[3,null],[3,0],[3,null]])=[[3,null],[3,0],[3,null]]
/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *res = new Node(-1);
        Node *h = res;
        Node *cur = head;
        unordered_map<Node*,Node*> mp;
        while (cur!=NULL){
            Node *t = new Node(cur->val);  // new
            t->random = cur->random;
            mp[cur] = t;
            h->next = t;
            h = t;
            cur = cur->next;
        }
        h = res->next;
        while (h!=NULL){
            h->random = mp[h->random];
            h=h->next;
        }
        return res->next;
    }
};