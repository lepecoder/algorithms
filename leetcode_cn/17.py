# %%
class Solution:
    def letterCombinations(self, digits: str):
        # 可以用矩阵实现,更加的快
        # 但元素是字符,不太好实现,懒得写
        d = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz'
        }
        n = len(digits)
        if n == 0:
            return []
        ans = []
        temp = []

        def backtrack(ind: int):
            if ind == n:
                ans.append("".join(temp))
            else:
                dig = digits[ind]
                for letter in d[dig]:
                    temp.append(letter)
                    backtrack(ind+1)
                    temp.pop()
        backtrack(0)
        return ans


so = Solution()
print(so.letterCombinations('23'))
