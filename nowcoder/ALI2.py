import math
a = int(input())
b = int(input())
c = int(input())

# print(a, b, c)

xbegin = int(math.sqrt(a))
if(xbegin * xbegin < a):
    xbegin += 1
xend = int(math.sqrt(b))

ybegin = int(a**(1 / 3))
if(ybegin * ybegin < a):
    ybegin += 1
yend = int(b**(1 / 3))

res = 0
for x in range(xbegin, xend + 1):
    for y in range(ybegin, yend + 1):
        if abs(x * x - y**3) <= c:
            res += 1

print(res)
