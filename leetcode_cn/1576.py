# %%
class Solution:
    def modifyString(self, s: str) -> str:
        alpha_bet = list('abcdefghijklmnopqrstuvwxyz')
        s_list = list(s)
        n = len(s)
        for i, v in enumerate(s_list):
            a = '_' if i == 0 else s[i-1]
            b = '_' if i == n-1 else s[i+1]
            for x in alpha_bet:
                if x!=a and x!=b


# %%
a = 'a'
a += 1
print(a)
