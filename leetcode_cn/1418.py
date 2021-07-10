from typing import List


class Solution:
    def displayTable(self, orders: List[List[str]]) -> List[List[str]]:
        bar = ['Table']
        dic = dict()
        for order in orders:
            # name, tableID, food
            name, tableID, food = order
            if food not in bar
