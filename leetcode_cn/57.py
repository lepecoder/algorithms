# %%
from typing import List


class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        def isinter(a: List[int], b: List[int]) -> bool:
            # 如果有交集,那么至少一个集合的边界在另一个集合里
            if a[0] <= b[1] and a[0] >= b[0]:
                return True
            if a[1] <= b[1] and a[1] >= b[0]:
                return True
            if b[0] <= a[1] and b[0] >= a[0]:
                return True
            if b[1] <= a[1] and b[1] >= a[0]:
                return True
            return False

        def union(a: List[int], b: List[int]) -> List[int]:
            ans = [a[0], a[1], b[0], b[1]]
            return [min(ans), max(ans)]
        if len(intervals) == 0:
            intervals.append(newInterval)
            return intervals
        b = True
        for i in range(len(intervals)):
            if isinter(intervals[i], newInterval):
                b = False
                intervals[i] = union(intervals[i], newInterval)
        if b:  # 新区间和原区间没有交集,需要插入到合适的位置
            # 寻找插入位置
            k = 0
            while k < len(intervals) and intervals[k][0] < newInterval[1]:
                k += 1
            intervals.insert(k, newInterval)
            return intervals
        i = 0
        while i < len(intervals)-1:
            if isinter(intervals[i], intervals[i+1]):
                intervals[i] = union(intervals[i], intervals[i+1])
                del intervals[i+1]
            else:
                i += 1
        return intervals


so = Solution()
intervals = []
newInterval = [4, 8]
print(so.insert(intervals, newInterval))


# %%
x = [1, 2, 3, 4]
x.insert(1, -1)
print(x)
