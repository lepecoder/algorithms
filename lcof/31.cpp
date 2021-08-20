#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
        int n = pushed.size();
        stack<int> st;
        int k = 0;
        for (int &x : pushed) {
            st.emplace(x);
            while (k < n && !st.empty() && popped[k] == st.top()) {
                k++;
                st.pop();
            }
        }
        return st.empty();
    }
};
int main() {
    //
    return 0;
}