class Solution {
  public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        if (s.length() != t.length()) return false;
        for (int i = 0; i < s.length(); i++) {
            if (mp.count(s[i]) == 0) {
                mp[s[i]] = t[i];
            } else {
                if (t[i] != mp[s[i]]) { return false; }
            }
        }
        unordered_map<char, char> mp1;
        for (int i = 0; i < s.length(); i++) {
            if (mp1.count(t[i]) == 0) {
                mp1[t[i]] = s[i];
            } else {
                if (s[i] != mp1[t[i]]) { return false; }
            }
        }

        return true;
    }
};
