# %%
from typing import List


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        @lru_cache(None)
        def backtrack(index: int) -> List[List[str]]:
            """可以把返回的类型List[str]"""
            if index == len(s):
                return [[]]
            ans = list()
            for i in range(index + 1, len(s) + 1):
                word = s[index:i]
                if word in wordSet:
                    nextWordBreaks = backtrack(i)
                    for nextWordBreak in nextWordBreaks:
                        ans.append(nextWordBreak.copy() + [word])
            return ans

        wordSet = set(wordDict)
        breakList = backtrack(0)
        return [" ".join(words[::-1]) for words in breakList]


s = "catsand"
wordDict = ["cat", "cats", "and", "sand"]

so = Solution()
print(so.wordBreak(s, wordDict))


# %%
s = "qwer"
print(s[2:4])
print(s[4:])

# %%
wordDict = ["cat", "cats", "and", "sand", "dog"]
s_ = "1"
for i in range(5):
    wordDict[i] = s_+wordDict[i]
print(wordDict)
w = ['awd']
print(w+wordDict)
# %%
s = "qwe"
ans = s[3:]
print(ans == "")
print(s[3:])
print("")
# %%
s = [""]
for i in range(len(s)):
    s[i] = "1"+s[i]
print(s)

# %%
for i in range(1):
    print(i)
