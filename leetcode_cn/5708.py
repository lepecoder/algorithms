from typing import List


class Solution:
    def rev(self, num: int) -> int:
        s = str(num)
        s = s[::-1]
        # i = 0
        # while i < len(s) and s[i] == '0':
        # i += 1
        ans = int(s)
        return int(ans)

    def countNicePairs(self, nums: List[int]) -> int:
        from scipy.special import comb
        # n = len(nums)
        a1 = nums
        b1 = list(map(self.rev, nums))
        # print(a1)
        # print(b1)
        c1 = [a - b for a, b in list(zip(a1, b1))]
        dic = dict()
        for x in c1:
            dic[x] = dic.get(x, 0) + 1
        print(c1)
        print(dic)
        ans = 0
        for key, val in dic.items():
            if val > 1:
                ans += comb(val, 2)
        return int(ans % (1e9 + 7))


so = Solution()
nums = [13, 10, 35, 24, 76]
print(so.countNicePairs(nums))
