# %%
from typing import List, Set
import copy


class Solution:

    def readBinaryWatch(self, num: int) -> List[str]:
        # 创建二进制 时分集合
        hour = [1, 2, 4, 8]
        minutes = [1, 2, 4, 8, 16, 32]
        ans = []

        def backtrack(h: int, m: int, num: int, hour: Set, minutes: Set, switch: bool) -> None:
            # swith = False 则不能选择时
            if num == 0:
                s = "%d:%02d" % (h, m)
                ans.append(s)
                return

            if switch:
                for i in range(len(hour)):
                    h_ = hour[i]
                    if h + h_ < 12:
                        backtrack(h + h_, m, num - 1, hour[i + 1:], minutes, True)

            for i in range(len(minutes)):
                m_ = minutes[i]
                if m + m_ < 60:
                    backtrack(h, m + m_, num - 1, hour, minutes[i + 1:], False)

        backtrack(0, 0, num, hour, minutes, True)
        return ans


so = Solution()
ans = sorted(so.readBinaryWatch(2))
print(ans)
print(len(ans))

# %%
import copy
hour = [1, 2, 3]
h = copy.copy(hour)
hour.pop()
print(h)
