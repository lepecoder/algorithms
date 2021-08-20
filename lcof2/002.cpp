class Solution {
  public:
    char add_f(char a, char b, char &add) {
        int res = 0;
        if (a == '1') res++;
        if (b == '1') res++;
        if (add == '1') res++;
        if (res == 0) {
            add = '0';
            return '0';
        } else if (res == 1) {
            add = '0';
            return '1';
        } else if (res == 2) {
            add = '1';
            return '0';
        } else {
            add = '1';
            return '1';
        }
    }
    string addBinary(string a, string b) {
        int an = a.size();
        int bn = b.size();
        string res;
        res.reserve(max(an, bn) + 1);
        int i = an - 1;
        int j = bn - 1;
        int k = 0;
        char add = '0';
        char ac, bc, t;
        while (i >= 0 || j >= 0) {
            ac = i >= 0 ? a[i] : '0';
            bc = j >= 0 ? b[j] : '0';
            t = add_f(ac, bc, add);
            res += t;
            i--, j--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

