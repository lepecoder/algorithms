from typing import List


class Solution:
    def rev(self, num: int) -> int:
        s = str(num)
        s = s[::-1]
        i = 0
        while i < len(s) and s[i] == '0':
            i += 1
        ans = int(s[i:])
        return int(ans)

    def countNicePairs(self, nums: List[int]) -> int:
        n = len(nums)
        a1 = nums
        b1 = list(map(self.rev, nums))
        # print(a1)
        # print(b1)
        ans = 0
        for i in range(n):
            for j in range(i + 1, n):
                if a1[i] + b1[j] == a1[j] + b1[i]:
                    ans += 1
        return ans % (10**9 + 7)


so = Solution()
nums = [13, 10, 35, 24, 76]
ans = so.countNicePairs(nums)
print(ans)
