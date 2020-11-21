# %%
d2 = {
    'IV': 4,
    'IX': 9,
    'XL': 40,
    'XC': 90,
    'CD': 400,
    'CM': 900
}

d1 = {
    'I': 1,
    'V': 5,
    'X': 10,
    'L': 50,
    'C': 100,
    'D': 500,
    'M': 1000
}


class Solution:
    def romanToInt(self, s: str) -> int:
        n = len(s)
        i = 0
        ans = 0
        while i < n:
            if (i+1) < n and s[i:i+2] in d2:
                ans += d2[s[i:i+2]]
                i += 1
            elif s[i] in d1:
                ans += d1[s[i]]
            i += 1
        return ans


so = Solution()
print(so.romanToInt("III"))
print(so.romanToInt("IV"))
print(so.romanToInt("LVIII"))


# %%
