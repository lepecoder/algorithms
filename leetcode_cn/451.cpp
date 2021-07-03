class Solution {
  public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        string res = "";
        vector<char> v;
        for (char &c : s) {
            if (mp.count(c) == 0) {
                mp[c] = 1;
                v.emplace_back(c);
            } else {
                mp[c]++;
            }
        }
        sort(v.begin(), v.end(), [&](char &a, char &b) { return mp[a] > mp[b]; });
        for (char &c : v) {
            int n = mp[c];
            while (n--) { res += c; }
        }
        return res;
    }
};
