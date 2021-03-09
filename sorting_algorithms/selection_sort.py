# %%
import random
from typing import List
"""
选择排序

首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置。
再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。
重复第二步，直到所有元素均排序完毕。
"""


def selection_sort(arr: List[int]) -> None:
    n = len(arr)
    for i in range(n - 1):
        min_idx = i
        for j in range(i + 1, n):
            if arr[min_idx] > arr[j]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
    return arr


num = random.choices(range(100), k=20)  # 生成随机数
print(num)
selection_sort(num)  # 冒泡排序
print(num)
num.sort()  # 内置排序方法
print(num)
