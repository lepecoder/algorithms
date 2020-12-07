# %%
import random
from typing import List
"""
冒泡排序
重复遍历n次要排序的序列，每次比较相邻两个元素，如果顺序错误就交换，
当遍历到序列末尾时应当有一个有一个元素会“冒泡”到最终位置。
直到遍历一次后没有元素再被交换，表示序列已经有序。

步骤：
比较相邻的元素。如果第一个比第二个大，就交换他们两个。
对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。这步做完后，最后的元素会是最大的数。
针对所有的元素重复以上的步骤，除了最后一个。
持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。

分析：
当序列已经有序时最快，只需要遍历一次，时间复杂度O(n)
当序列是逆序时每次都需要交换相邻元素，总共需要交换(1+n)*n/2次，时间复杂度O(n^2)
平均时间复杂度O(n^2)
原地排序，空间复杂度O(1)
不会改变相同元素的相对位置，稳定
"""


def bubble_sort(arr: List[int]) -> None:
    n = len(arr)-1
    for i in range(n):
        for j in range(n-i):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]


num = random.choices(range(100), k=20)  # 生成随机数
print(num)
bubble_sort(num)  # 冒泡排序
print(num)
num.sort()  # 内置排序方法
print(num)
