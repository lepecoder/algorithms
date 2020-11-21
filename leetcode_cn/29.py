# %%
from typing import List


class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        ans = self.div(abs(dividend), abs(divisor))
        if dividend < 0 and divisor > 0:
            ans = -ans
        if dividend > 0 and divisor < 0:
            ans = -ans
        if ans > ((1 << 31)-1):
            return (1 << 31)-1
        if ans < -(1 << 31):
            return (1 << 31)-1
        return ans

    def div(self, dividend: int, divisor: int) -> int:
        if divisor == 1:
            return dividend
        if dividend < divisor:
            return 0
        if dividend >= divisor and dividend < divisor << 1:
            return 1
        ans = 1
        d = divisor << 1
        while d <= dividend:
            ans = ans << 1
            d = d << 1
        d = d >> 1
        return ans + self.div(dividend-d, divisor)


so = Solution()

print(so.divide(-2147483648, 1))

# if dividend >= divisor << 2:
# return 2*self.divide(dividend, divisor << 1)


# %%
print(((1) << 31)-1)
