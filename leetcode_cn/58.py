# %%
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = s.rstrip()
        t = s[::-1]
        idx = t.find(' ')
        if idx == -1:
            return len(s)
        return idx


so = Solution()
s = "a  "
print(so.lengthOfLastWord(s))
