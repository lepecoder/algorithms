# %%
from typing import List, Set
result = []
n = 3


def backtrack(path: List[int], node: List[int]):
    if len(path) == n:
        result.append(path)
        return

    for x in node:
        path_ = path.copy()
        path_.append(x)
        node_ = node.copy()
        node_.remove(x)
        backtrack(path_, node_)


backtrack([], list(range(n)))
print(result)
