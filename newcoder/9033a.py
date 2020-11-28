import math


class Stu:
    def __init__(self, a, b) -> None:
        self.a = a
        self.b = b
        self.c = a*0.85+b*0.15


s = input()
s = s.split(' ')
n, m, p = map(int, s)

stus = list()
for i in range(n):
    a, b = map(int, input().split())
    t_stu = Stu(a, b)
    stus.append(t_stu)

stus.sort(key=lambda x: x.c)
stus = stus[::-1]

# %%
# c = stus[m-1].c
c = 99
p = 100
ans = (c - p*0.15)/0.85
print(max(0, math.ceil(ans)))
