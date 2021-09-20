#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
  public:
    int getMaxSubstrLenProd(string inputStr) {
        // write code here

        set<char> set;
        int maxValue = -1;
        for (int i = 0; i < inputStr.length(); i++) {
            set.clear();
            for (int j = i; j < inputStr.length(); j++) {
                set.insert(inputStr[j]);
                int a = j - i + 1;
                int left = j + 1;
                int right = j + 1;
                while (right < inputStr.length()) {
                    if (set.count(inputStr[right]) == 0) {
                        right++;
                    } else {
                        // if ((right - left) * a > maxValue) { cout << i << " " << j << "--" << left << " " << right << ":" << maxValue << endl; }
                        maxValue = max(maxValue, (right - left) * a);
                        right++;
                        left = right;
                    }
                }
                if (set.count(inputStr[right - 1]) == 0) {
                    // cout << i << " " << j << "--" << left << " " << right << ":" << maxValue << endl;
                    maxValue = max(maxValue, (right - left) * a);
                }
            }
        }
        // cout << maxValue << endl;
        return maxValue;
    }
};

int main() {
    //
    return 0;
}