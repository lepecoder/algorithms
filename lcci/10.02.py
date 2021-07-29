from typing import List


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = dict()
        for s in strs:
            if sorted(s) in d:
                d[sorted(s)].append(s)
            else:
                d[sorted(s)] = [s]
        res = list()
        for k, v in d.items():
            res.append(v)
        return res
