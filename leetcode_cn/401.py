from typing import List, Set


class Solution:
    def sort_key(s: str) -> bool:
        h

    def readBinaryWatch(self, num: int) -> List[str]:
        # 创建二进制 时分集合
        hour = {1, 2, 4, 8}
        minutes = {1, 2, 4, 8, 16, 32}
        ans = []

        def backtrack(h: int, m: int, num: int, hour: Set, minutes: Set) -> None:
            if num == 0:
                s = "%d:%02d" % (h, m)
                ans.append(s)
                return
            for h_ in hour:
                if h + h_ < 12:
                    backtrack(h + h_, m, num - 1, hour - {h_}, minutes)
            for m_ in minutes:
                if m + m_ < 60:
                    backtrack(h, m + m_, num - 1, hour, minutes - {m_})
        backtrack(0, 0, num, hour, minutes)
        ans = sort(ans, lambda x: )
        return ans


so = Solution()
print(so.readBinaryWatch(2))
