# %%
from typing import List


class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        def union(a: List[int], b: List[int]):
            # 求ab的相交部分
            if a[1] < b[0]:
                return False
            return [max(a[0], b[0]), min(a[1], b[1])]
        if len(points) == 0:
            return 0
        points.sort(key=lambda x: x[0])
        ans = 1
        n = len(points)
        t = points[0]
        for i in range(1, n):
            u_region = union(t, points[i])
            if not u_region:  # t和points[i]没有相交区域
                ans += 1
                t = points[i]
            else:  # t和points有相交区域
                t = u_region
        return ans


so = Solution()
points = [[1, 2], [1, 2]]
ans = so.findMinArrowShots(points)
print(ans)
