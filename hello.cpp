#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

int main(){
    // 
    vector<int> v;
    int res=0;
    v.push_back(1);
    v.push_back(2);
    for(auto x:v){
        cout << x;
    }
    return 0;
}