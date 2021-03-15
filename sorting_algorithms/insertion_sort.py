# %%
from typing import List
import random


def insertion_sort(arr: List[int]) -> List[int]:
    for i in range(len(arr)):
        t = arr[i]
        pre_i = i - 1
        while pre_i >= 0 and arr[pre_i] > t:
            arr[pre_i + 1] = arr[pre_i]
            pre_i -= 1
        arr[pre_i + 1] = t
    return arr


nums = random.choices(range(100), k=8)  # 生成随机数
print(nums)
ans = insertion_sort(nums)
print(ans)
print(nums)
