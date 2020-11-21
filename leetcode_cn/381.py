# %%
from typing import List
import random


class RandomizedCollection:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.data = list()  # 存储数据
        self.dict = dict()  # 存储数据的下标集合
        self.n = 0

    def insert(self, val: int) -> bool:
        """
        Inserts a value to the collection. Returns true if the collection did not already contain the specified element.
        """
        self.data.append(val)
        s = self.dict.get(val)
        if s is None or len(s) == 0:
            self.dict[val] = [self.n]
            self.n += 1
            return True
        else:
            s.append(self.n)
            self.n += 1
            return False

    def remove(self, val: int) -> bool:
        """
        Removes a value from the collection. Returns true if the collection contained the specified element.
        """
        s1 = self.dict.get(val)
        if s1 is None or len(s1) == 0:
            return False
        last_val = self.data[-1]
        s2 = self.dict.get(last_val)
        del_pos = s1[-1]
        s2.remove(self.n-1)
        s2.append(del_pos)
        self.data[del_pos] = last_val
        del s1[-1]
        del self.data[-1]
        self.n -= 1

        return True

    def getRandom(self) -> int:
        """
        Get a random element from the collection.
        """
        x = random.randint(0, self.n-1)
        return self.data[x]


obj = RandomizedCollection()
print(obj.insert(4))
print(obj.insert(3))
print(obj.insert(4))
print(obj.insert(2))
print(obj.insert(4))
print(obj.remove(4))
print(obj.remove(3))
print(obj.remove(4))
print(obj.remove(4))

# %%
print(random.randint(2, 3))
d = dict()
