# %%
d_roman = ['I', 'IV', 'V', 'IX', 'X', 'XL', 'L', 'XC', 'C', 'CD', 'D', 'CM', 'M']
d_int = [1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000]

d2 = {
    'IV': 4,
    'IX': 9,
    'XL': 40,
    'XC': 90,
    'CD': 400,
    'CM': 900
}

d1 = {
    'I': 1,
    'V': 5,
    'X': 10,
    'L': 50,
    'C': 100,
    'D': 500,
    'M': 1000
}


class Solution:
    def intToRoman(self, num: int) -> str:
        ans = ""
        while num:
            for d in range(12, -1, -1):
                if num >= d_int[d]:
                    num -= d_int[d]
                    ans = ans+d_roman[d]
                    # print(num)
                    # print(d_roman[d])
                    break
        return ans


so = Solution()
print(so.intToRoman(3))
print(so.intToRoman(4))
print(so.intToRoman(9))
print(so.intToRoman(58))
print(so.intToRoman(1994))


# %%
