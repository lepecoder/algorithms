#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
  int candy(vector<int> &ratings) {
    int n = ratings.size();
    int *ans = new int[n];
    for (int i = 0; i < n; i++)
      ans[i] = 1;
    // memset(ans, int(1), sizeof(int) * n);
    // 分两次考虑，先左边比右边高，再右边比左侧高
    for (int i = 0; i < n - 1; i++) {
      if (ratings[i] < ratings[i + 1])
        ans[i + 1] = ans[i] + 1; // 如果右边比左边大
    }
    for (int i = n - 2; i >= 0; i--) {
      if (ratings[i] > ratings[i + 1])
        ans[i] = max(ans[i], ans[i + 1] + 1); // 如果左边比右边大
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
      cout << ans[i] << ' ';
      sum += ans[i];
    }
    return sum;
  }
};
// @lc code=end

int main() {

  vector<int> rat{1, 2, 2};
  Solution so;
  cout << endl << so.candy(rat) << endl;

  return 0;
}
