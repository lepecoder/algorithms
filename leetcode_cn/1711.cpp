class Solution {
  public:
    int countPairs(vector<int> &deliciousness) {
        vector<int> st;
        st.push_back(1);
        int res = 0, n = deliciousness.size();
        for (int i = 1; i < 22; i++) { st.push_back(1 << i); }
        unordered_map<int, int> mp;
        for (int &x : deliciousness) { mp[x]++; }
        for (int i = 0; i < n; i++) {
            int x = deliciousness[i];
            mp[x]--;
            for (int &s : st) {
                if (s >= x) {
                    res += mp[s - x];
                    if (mp[s - x]) { cout << x << ',' << mp[s - x] << endl; }
                }
            }
        }
        return res;
    }
};
