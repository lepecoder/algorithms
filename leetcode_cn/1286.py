# %%
from typing import List


class CombinationIterator:

    def __init__(self, characters: str, combinationLength: int):
        self.s = characters
        self.m = combinationLength
        # 生成第一个排列
        self.pos = [x for x in range(combinationLength)]
        self.finish = False

    def next(self) -> str:
        ans = "".join(self.s[x] for x in self.pos)
        b = True
        for k in range(len(self.pos)-1, -1, -1):
            if self.pos[k] != len(self.s)-self.m + k:
                b = False
                self.pos[k] += 1
                for i in range(k+1, self.m):
                    self.pos[i] = self.pos[i-1]+1
                break
        self.finish = b
        return ans

    def hasNext(self) -> bool:
        return not self.finish


so = CombinationIterator("abc", 2)
print(so.next())
print(so.next())
print(so.hasNext())
print(so.next())


# %%
for i in range(2, 3):
    print(i)
