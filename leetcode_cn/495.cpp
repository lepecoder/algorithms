class Solution {
  public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration) {
        int res = 0;
        int n = timeSeries.size();
        if (n == 0) return 0;
        int right = timeSeries[0];
        for (int &x : timeSeries) {
            int y = x + duration;
            right = max(right, x);
            res += (y - right);
            right = y;
        }
        return res;
    }
};
