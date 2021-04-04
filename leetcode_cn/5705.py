class Solution:
    def squareIsWhite(self, coordinates: str) -> bool:
        hang = ['1', '3', '5', '7']
        lie = ['a', 'c', 'e', 'g']
        h = coordinates[1]
        l = coordinates[0]
        if h in hang:
            if l in lie:
                return False
            else:
                return True
        else:
            if l in lie:
                return True
            else:
                return False


so = Solution()
print(so.squareIsWhite('a1'))
print(so.squareIsWhite('h3'))
print(so.squareIsWhite('c7'))
