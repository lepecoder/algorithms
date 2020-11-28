# %%
from typing import List


class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        stack_ = list()
        dict_ = dict()
        for x in nums2:
            if len(stack_) == 0:
                stack_.append(x)
                continue
            while len(stack_) > 0 and x > stack_[-1]:
                t = stack_.pop()
                dict_[t] = x
            stack_.append(x)

        ans = list()
        for x in nums1:
            ans.append(dict_.get(x, -1))
        return ans


so = Solution()
nums1 = [2, 4]
nums2 = [1, 2, 3, 4]
print(so.nextGreaterElement(nums1, nums2))
