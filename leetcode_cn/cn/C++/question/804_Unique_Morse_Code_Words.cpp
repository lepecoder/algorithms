// @algorithm @lc id=822 lang=cpp 
// @title unique-morse-code-words


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
#include <unordered_set>
using namespace std;
// @test(["gin","zen","gig","msg"])=2
// @test(["a"])=1
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> m = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> res;
        for (string &w:words){
            string t;
            for (char &c:w){
                t+=m[c-'a'];
            }
            res.emplace(t);
        }
        return res.size();
    }
};