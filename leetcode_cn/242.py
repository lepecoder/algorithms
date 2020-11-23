# %%
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        a = "".join((lambda x: (x.sort(), x)[1])(list(s)))
        b = "".join((lambda x: (x.sort(), x)[1])(list(t)))
        return (a == b)
