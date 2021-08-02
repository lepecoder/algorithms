from typing import List


class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        # res = list()
        v = list()
        v = [[i, sum(t)] for (i, t) in enumerate(mat)]
        # for i in range(len(mat)):
        # t = sum(mat[i])
        # v.append([i, t])
        v = sorted(v, key=lambda x: (x[1], x[0]))
        # for i in range(k):
        # res.append(v[i][0])
        res = [x[0] for x in v[:k]]
        return res
