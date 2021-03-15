# %%
from typing import List
from random import choices


def shell_sort(arr: List[int]) -> List[int]:
    gap = 1
    n = len(arr)
    while gap < n / 3:
        gap = gap * 3 + 1
    while gap > 0:
        for i in range(gap, n, gap):
            t = arr[i]
            j = i - gap
            while j >= 0 and arr[j] > t:
                arr[j + gap] = arr[j]
                j -= gap
            arr[j + gap] = t
        gap //= 3
    return arr


nums = choices(range(100), k=80)  # 生成随机数
print(nums)
ans = shell_sort(nums)
print(ans)
print(sorted(nums))
